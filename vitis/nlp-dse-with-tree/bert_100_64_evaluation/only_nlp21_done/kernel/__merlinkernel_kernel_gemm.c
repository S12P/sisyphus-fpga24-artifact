#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 64
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 100
#include "memcpy_128_2d.h"
#undef SIZE_1
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
  float B_4_0_buf[100][64];
  
#pragma HLS array_partition variable=B_4_0_buf cyclic factor=16 dim=2
  float A_4_0_buf[100][100];
  
#pragma HLS array_partition variable=A_4_0_buf cyclic factor=4 dim=2
  float C_buf[100][64];
  
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
  int i;
  int j;
  int k;
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
  memcpy_wide_bus_read_float_2d_64_512(C_buf,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
{
    memcpy_wide_bus_read_float_2d_100_128(A_4_0_buf,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_2d_64_512(B_4_0_buf,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
  }
  merlinL2:
  for (i = 0; i < 100; i++) {
    merlinL1:
    for (j = 0; j < 64; j++) {
      C_buf[i][j] = ((float )0);
      merlinL0:
      for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        C_buf[i][j] += A_4_0_buf[i][k] * B_4_0_buf[k][j];
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
  memcpy_wide_bus_write_float_2d_64_512((merlin_uint_512 *)C,C_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )6400L),6400L);
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_0_buf cyclic factor = 4 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_4_0_buf cyclic factor = 16 dim=2 */
