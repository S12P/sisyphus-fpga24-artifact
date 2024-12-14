#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 64
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 10
#define SIZE_2 50
#define SIZE_3 2
#include "memcpy_128_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#define SIZE_2 64
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_gemm(merlin_uint_512 C[400],merlin_uint_128 A[2500],merlin_uint_512 B[400])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=2500 bundle=merlin_gmem_kernel_gemm_128_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=400 bundle=merlin_gmem_kernel_gemm_512_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=400 bundle=merlin_gmem_kernel_gemm_512_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=B depth=100,64 max_depth=100,64
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,64 max_depth=100,64
  float B_6_0_buf[50][2][64];
  
#pragma HLS array_partition variable=B_6_0_buf cyclic factor=16 dim=3
  
#pragma HLS array_partition variable=B_6_0_buf complete dim=2
  float A_6_0_buf[10][10][50][2];
  
#pragma HLS array_partition variable=A_6_0_buf complete dim=4
  
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=2 dim=3
  int i;
  int j;
  int k;
{
    memcpy_wide_bus_read_float_4d_10_50_2_128(A_6_0_buf,0,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_3d_2_64_512(B_6_0_buf,0,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
  }
  merlinL4:
  for (i = 0; i < 10; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
    float C_buf[10][64];
    
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
{
      memcpy_wide_bus_read_float_2d_64_512(C_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)C,(size_t )(((long )i) * 640L * ((long )4)),sizeof(float ) * ((unsigned long )640L),(size_t )640L);
    }
    merlinL3:
    for (int i_sub = 0; i_sub < 10; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
      merlinL2:
      for (j = 0; j < 64; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=64 */
/* Original: #pragma ACCEL PARALLEL FACTOR=64 */
/* Original: #pragma ACCEL parallel */
{
        C_buf[((long )i_sub) - 0L][j] = ((float )0);
        merlinL1:
        for (k = 0; k < 50; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS pipeline
          merlinL0:
          for (int k_sub = 0; k_sub < 2; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            C_buf[((long )i_sub) - 0L][j] += A_6_0_buf[i][i_sub][k][k_sub] * B_6_0_buf[k][k_sub][j];
          }
        }
      }
    }
{
      memcpy_wide_bus_write_float_2d_64_512((merlin_uint_512 *)C,C_buf,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 640L)),sizeof(float ) * ((unsigned long )640L),(size_t )640L);
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_6_0_buf cyclic factor = 16 dim=3 */
