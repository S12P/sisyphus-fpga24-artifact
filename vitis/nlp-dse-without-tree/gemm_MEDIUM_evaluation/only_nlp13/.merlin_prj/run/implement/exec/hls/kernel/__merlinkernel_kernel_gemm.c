#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 50
#define SIZE_2 240
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 220
#include "memcpy_128_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_gemm(float alpha,float beta,merlin_uint_512 C[2750],merlin_uint_512 A[3000],merlin_uint_128 B[13200])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=3000 bundle=merlin_gmem_kernel_gemm_512_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=13200 bundle=merlin_gmem_kernel_gemm_128_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=2750 bundle=merlin_gmem_kernel_gemm_512_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=B depth=240,220 max_depth=240,220
  
#pragma ACCEL interface variable=A depth=200,240 max_depth=200,240
  
#pragma ACCEL interface variable=C depth=200,220 max_depth=200,220
  int i;
  int j;
  int k;
//BLAS PARAMS
//TRANSA = 'N'
//TRANSB = 'N'
// => Form C := alpha*A*B + beta*C,
//A is NIxNK
//B is NKxNJ
//C is NIxNJ
{
    float B_6_0_buf[240][220];
    
#pragma HLS array_partition variable=B_6_0_buf cyclic factor=4 dim=2
    float A_6_0_buf[4][50][240];
    
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=16 dim=3
{
      memcpy_wide_bus_read_float_3d_50_240_512(A_6_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      memcpy_wide_bus_read_float_2d_220_128(B_6_0_buf,0,0,(merlin_uint_128 *)B,(0 * 4),sizeof(float ) * ((unsigned long )52800L),52800L);
    }
    merlinL6:
    for (i = 0; i < 4; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
{
      float C_buf[50][220];
      
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
{
        merlinL5:
        for (int i_sub = 0; i_sub < 50; ++i_sub) {
          memcpy_wide_bus_read_float_512(C_buf[((long )i_sub) - 0L],(merlin_uint_512 *)C,(size_t )((((long )i) * 11000L + ((long )i_sub) * 220L) * ((long )4)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
      }
      merlinL4:
      for (int i_sub = 0; i_sub < 50; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL3:
        for (j = 0; j < 220; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=C_buf array inter false
          
#pragma HLS pipeline
          C_buf[((long )i_sub) - 0L][j] *= beta;
        }
        merlinL2:
        for (k = 0; k < 240; k++) {
          merlinL1:
          for (j = 0; j < 220; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS dependence variable=C_buf array inter false
            
#pragma HLS pipeline
            C_buf[((long )i_sub) - 0L][j] += alpha * A_6_0_buf[i][i_sub][k] * B_6_0_buf[k][j];
          }
        }
      }
{
        merlinL0:
        for (int i_sub = 0; i_sub < 50; ++i_sub) {
          memcpy_wide_bus_write_float_512((merlin_uint_512 *)C,C_buf[((long )i_sub) - 0L],(size_t )(((long )4) * (((long )i) * 11000L + ((long )i_sub) * 220L)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_6_0_buf cyclic factor = 4 dim=2 */
}
