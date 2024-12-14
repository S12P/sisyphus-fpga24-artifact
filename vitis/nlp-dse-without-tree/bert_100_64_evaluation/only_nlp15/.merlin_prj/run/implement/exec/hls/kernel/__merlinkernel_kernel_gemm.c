#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 64
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 10
#define SIZE_2 10
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 10
#define SIZE_2 64
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_gemm(merlin_uint_512 C[400],merlin_uint_64 A[5000],merlin_uint_512 B[400])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=5000 bundle=merlin_gmem_kernel_gemm_64_0
  
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
  float B_5_0_buf[10][10][64];
  
#pragma HLS array_partition variable=B_5_0_buf cyclic factor=16 dim=3
  
#pragma HLS array_partition variable=B_5_0_buf complete dim=2
  float A_5_0_buf[100][10][10];
  
#pragma HLS array_partition variable=A_5_0_buf complete dim=3
  float C_buf[100][64];
  
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
  int i;
  int j;
  int k;
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
  memcpy_wide_bus_read_float_2d_64_512(C_buf,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
{
    memcpy_wide_bus_read_float_3d_10_10_64(A_5_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_3d_10_64_512(B_5_0_buf,0,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
  }
  merlinL3:
  for (i = 0; i < 100; i++) {
    merlinL2:
    for (j = 0; j < 64; j++) {
      C_buf[i][j] = ((float )0);
      merlinL1:
      for (k = 0; k < 10; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL0:
        for (int k_sub = 0; k_sub < 10; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          C_buf[i][j] += A_5_0_buf[i][k][k_sub] * B_5_0_buf[k][k_sub][j];
        }
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
  memcpy_wide_bus_write_float_2d_64_512((merlin_uint_512 *)C,C_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )6400L),6400L);
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_5_0_buf cyclic factor = 16 dim=3 */
