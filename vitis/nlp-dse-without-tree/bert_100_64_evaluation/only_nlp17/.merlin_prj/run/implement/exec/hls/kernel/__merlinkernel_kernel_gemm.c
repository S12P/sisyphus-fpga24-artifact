#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 32
#define SIZE_2 2
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 4
#define SIZE_2 50
#define SIZE_3 2
#include "memcpy_128_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#define SIZE_2 32
#define SIZE_3 2
#include "memcpy_512_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
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
  float B_7_0_buf[50][2][32][2];
  
#pragma HLS array_partition variable=B_7_0_buf complete dim=4
  
#pragma HLS array_partition variable=B_7_0_buf cyclic factor=8 dim=3
  
#pragma HLS array_partition variable=B_7_0_buf complete dim=2
  float A_7_0_buf[25][4][50][2];
  
#pragma HLS array_partition variable=A_7_0_buf complete dim=4
  
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=2 dim=3
  int i;
  int j;
  int k;
{
    memcpy_wide_bus_read_float_4d_4_50_2_128(A_7_0_buf,0,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_4d_2_32_2_512(B_7_0_buf,0,0,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
  }
  merlinL5:
  for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
{
    float C_buf[4][32][2];
    
#pragma HLS array_partition variable=C_buf complete dim=3
    
#pragma HLS array_partition variable=C_buf cyclic factor=8 dim=2
{
      memcpy_wide_bus_read_float_3d_32_2_512(C_buf,(size_t )0,(size_t )0,(size_t )0,(merlin_uint_512 *)C,(size_t )(((long )i) * 256L * ((long )4)),sizeof(float ) * ((unsigned long )256L),(size_t )256L);
    }
    merlinL4:
    for (int i_sub = 0; i_sub < 4; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL */
{
      merlinL3:
      for (j = 0; j < 32; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
        merlinL2:
        for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
          C_buf[i_sub][j][j_sub] = ((float )0);
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
              C_buf[i_sub][j][j_sub] += A_7_0_buf[i][i_sub][k][k_sub] * B_7_0_buf[k][k_sub][j][j_sub];
            }
          }
        }
      }
    }
{
      memcpy_wide_bus_write_float_3d_32_2_512((merlin_uint_512 *)C,C_buf,(size_t )0,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 256L)),sizeof(float ) * ((unsigned long )256L),(size_t )256L);
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 8 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 8 dim=2 */
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_7_0_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_7_0_buf cyclic factor = 8 dim=3 */
