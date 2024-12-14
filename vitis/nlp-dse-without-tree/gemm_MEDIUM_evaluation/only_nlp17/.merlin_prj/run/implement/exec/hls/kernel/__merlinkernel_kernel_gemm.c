#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 8
#define SIZE_2 240
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 110
#define SIZE_2 2
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
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
    float B_8_0_buf[240][110][2];
    
#pragma HLS array_partition variable=B_8_0_buf complete dim=3
    
#pragma HLS array_partition variable=B_8_0_buf cyclic factor=2 dim=2
    float A_8_0_buf[25][8][240];
    
#pragma HLS array_partition variable=A_8_0_buf cyclic factor=16 dim=3
{
      memcpy_wide_bus_read_float_3d_8_240_512(A_8_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      memcpy_wide_bus_read_float_3d_110_2_128(B_8_0_buf,0,0,0,(merlin_uint_128 *)B,(0 * 4),sizeof(float ) * ((unsigned long )52800L),52800L);
    }
    merlinL8:
    for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
{
      float C_buf[8][110][2];
      
#pragma HLS array_partition variable=C_buf complete dim=3
      
#pragma HLS array_partition variable=C_buf cyclic factor=8 dim=2
{
        merlinL7:
        for (int i_sub = 0; i_sub < 8; ++i_sub) {
          memcpy_wide_bus_read_float_2d_2_512(C_buf[i_sub],(size_t )0,(size_t )0,(merlin_uint_512 *)C,(size_t )((((long )i) * 1760L + ((long )i_sub) * 220L) * ((long )4)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 8 dim=2 */
      }
      merlinL6:
      for (int i_sub = 0; i_sub < 8; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL5:
        for (j = 0; j < 110; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=C_buf array inter false
          
#pragma HLS pipeline
          merlinL4:
          for (int j_sub_0 = 0; j_sub_0 < 2; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            C_buf[i_sub][j][j_sub_0] *= beta;
          }
        }
        merlinL3:
        for (k = 0; k < 240; k++) {
          merlinL2:
          for (j = 0; j < 110; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS dependence variable=C_buf array inter false
            
#pragma HLS pipeline
            merlinL1:
            for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
              
#pragma HLS unroll
              C_buf[i_sub][j][j_sub] += alpha * A_8_0_buf[i][i_sub][k] * B_8_0_buf[k][j][j_sub];
            }
          }
        }
      }
{
        merlinL0:
        for (int i_sub = 0; i_sub < 8; ++i_sub) {
          memcpy_wide_bus_write_float_2d_2_512((merlin_uint_512 *)C,C_buf[i_sub],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 1760L + ((long )i_sub) * 220L)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 8 dim=2 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_8_0_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_8_0_buf cyclic factor = 2 dim=2 */
}
