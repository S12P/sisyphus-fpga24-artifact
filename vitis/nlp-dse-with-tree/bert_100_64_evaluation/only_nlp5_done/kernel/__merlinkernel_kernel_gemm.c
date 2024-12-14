#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 4
#define SIZE_2 16
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 50
#define SIZE_2 100
#include "memcpy_128_3d.h"
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
  float B_6_0_buf[100][4][16];
  
#pragma HLS array_partition variable=B_6_0_buf cyclic factor=16 dim=3
  float A_6_0_buf[2][50][100];
  
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=4 dim=3
  int i;
  int j;
  int k;
{
    memcpy_wide_bus_read_float_3d_50_100_128(A_6_0_buf,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_3d_4_16_512(B_6_0_buf,0,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
  }
  merlinL4:
  for (i = 0; i < 2; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
{
    float C_buf[50][4][16];
    
#pragma HLS array_partition variable=C_buf complete dim=3
{
      memcpy_wide_bus_read_float_3d_4_16_512(C_buf,(size_t )0,(size_t )0,(size_t )0,(merlin_uint_512 *)C,(size_t )(((long )i) * 3200L * ((long )4)),sizeof(float ) * ((unsigned long )3200L),(size_t )3200L);
    }
    merlinL3:
    for (int i_sub = 0; i_sub < 50; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL */
{
      merlinL2:
      for (j = 0; j < 4; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
{
        merlinL1:
        for (int j_sub = 0; j_sub < 16; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL */
{
          C_buf[i_sub][j][j_sub] = ((float )0);
          merlinL0:
          for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS pipeline
            C_buf[i_sub][j][j_sub] += A_6_0_buf[i][i_sub][k] * B_6_0_buf[k][j][j_sub];
          }
        }
      }
    }
{
      memcpy_wide_bus_write_float_3d_4_16_512((merlin_uint_512 *)C,C_buf,(size_t )0,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 3200L)),sizeof(float ) * ((unsigned long )3200L),(size_t )3200L);
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=3 */
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 4 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_6_0_buf cyclic factor = 16 dim=3 */
