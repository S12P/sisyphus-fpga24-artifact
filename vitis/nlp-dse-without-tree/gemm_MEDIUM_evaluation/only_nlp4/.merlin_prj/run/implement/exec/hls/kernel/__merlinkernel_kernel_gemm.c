#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 220
#include "memcpy_128_2d.h"
#undef SIZE_1
#define SIZE_1 30
#define SIZE_2 8
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 8
#define SIZE_2 220
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_gemm(float alpha,float beta,merlin_uint_128 C[11000],merlin_uint_512 A[3000],merlin_uint_128 B[13200])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=3000 bundle=merlin_gmem_kernel_gemm_512_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=13200 bundle=merlin_gmem_kernel_gemm_128_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=11000 bundle=merlin_gmem_kernel_gemm_128_C
  
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
    float B_6_0_buf[30][8][220];
    
#pragma HLS array_partition variable=B_6_0_buf complete dim=3
    
#pragma HLS array_partition variable=B_6_0_buf complete dim=2
    float A_6_0_buf[200][30][8];
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=2 dim=2
    float C_buf[200][220];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 4 dim=2 */
    
#pragma HLS array_partition variable=C_buf complete dim=2
    memcpy_wide_bus_read_float_2d_220_128(C_buf,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )44000L),44000L);
{
      memcpy_wide_bus_read_float_3d_30_8_512(A_6_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      memcpy_wide_bus_read_float_3d_8_220_128(B_6_0_buf,0,0,0,(merlin_uint_128 *)B,(0 * 4),sizeof(float ) * ((unsigned long )52800L),52800L);
    }
    merlinL4:
    for (i = 0; i < 200; i++) {
      merlinL3:
      for (j = 0; j < 220; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=220 */
/* Original: #pragma ACCEL PARALLEL FACTOR=220 */
/* Original: #pragma ACCEL parallel */
{
        
#pragma HLS unroll
        C_buf[i][j] *= beta;
      }
      merlinL2:
      for (k = 0; k < 30; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL1:
        for (int k_sub = 0; k_sub < 8; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL0:
          for (j = 0; j < 220; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=220 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            C_buf[i][j] += alpha * A_6_0_buf[i][k][k_sub] * B_6_0_buf[k][k_sub][j];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 4 dim=2 */
    memcpy_wide_bus_write_float_2d_220_128((merlin_uint_128 *)C,C_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )44000L),44000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_6_0_buf cyclic factor = 4 dim=3 */
}
