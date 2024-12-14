#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 220
#include "memcpy_128_2d.h"
#undef SIZE_1
#define SIZE_1 240
#include "memcpy_512_2d.h"
#undef SIZE_1
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
    float B_5_0_buf[240][220];
    
#pragma HLS array_partition variable=B_5_0_buf cyclic factor=4 dim=2
    float A_5_0_buf[200][240];
    
#pragma HLS array_partition variable=A_5_0_buf cyclic factor=16 dim=2
    float C_buf[200][220];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 4 dim=2 */
    
#pragma HLS array_partition variable=C_buf cyclic factor=4 dim=2
    memcpy_wide_bus_read_float_2d_220_128(C_buf,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )44000L),44000L);
{
      memcpy_wide_bus_read_float_2d_240_512(A_5_0_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      memcpy_wide_bus_read_float_2d_220_128(B_5_0_buf,0,0,(merlin_uint_128 *)B,(0 * 4),sizeof(float ) * ((unsigned long )52800L),52800L);
    }
    merlinL3:
    for (i = 0; i < 200; i++) {
      merlinL2:
      for (j = 0; j < 220; j++) 
/* Original: #pragma ACCEL PIPELINE AUTO */
{
        
#pragma HLS dependence variable=C_buf array inter false
        
#pragma HLS pipeline
        C_buf[i][j] *= beta;
      }
      merlinL1:
      for (k = 0; k < 240; k++) {
        merlinL0:
        for (j = 0; j < 220; j++) 
/* Original: #pragma ACCEL PIPELINE AUTO */
{
          
#pragma HLS dependence variable=C_buf array inter false
          
#pragma HLS pipeline
          C_buf[i][j] += alpha * A_5_0_buf[i][k] * B_5_0_buf[k][j];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 4 dim=2 */
    memcpy_wide_bus_write_float_2d_220_128((merlin_uint_128 *)C,C_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )44000L),44000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_5_0_buf cyclic factor = 4 dim=2 */
}
