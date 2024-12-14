#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 64
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 10
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
  float B_5_0_buf[100][64];
  
#pragma HLS array_partition variable=B_5_0_buf cyclic factor=16 dim=2
  
#pragma HLS array_partition variable=B_5_0_buf complete dim=1
  float A_5_0_buf[10][10][100];
  
#pragma HLS array_partition variable=A_5_0_buf complete dim=3
  int i;
  int j;
  int k;
{
    memcpy_wide_bus_read_float_3d_10_100_128(A_5_0_buf,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_2d_64_512(B_5_0_buf,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
  }
  merlinL3:
  for (i = 0; i < 10; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
    float C_buf[10][64];
    
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
{
      memcpy_wide_bus_read_float_2d_64_512(C_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)C,(size_t )(((long )i) * 640L * ((long )4)),sizeof(float ) * ((unsigned long )640L),(size_t )640L);
    }
    merlinL2:
    for (int i_sub = 0; i_sub < 10; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
      merlinL1:
      for (j = 0; j < 64; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=C_buf array inter false
        
#pragma HLS pipeline
        C_buf[((long )i_sub) - 0L][j] = ((float )0);
        merlinL0:
        for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          C_buf[((long )i_sub) - 0L][j] += A_5_0_buf[i][i_sub][k] * B_5_0_buf[k][j];
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
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_0_buf cyclic factor = 4 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_5_0_buf cyclic factor = 16 dim=2 */
