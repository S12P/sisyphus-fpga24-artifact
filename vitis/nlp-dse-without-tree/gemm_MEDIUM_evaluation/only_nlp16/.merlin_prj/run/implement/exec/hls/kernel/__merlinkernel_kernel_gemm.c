#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 10
#define SIZE_2 22
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 240
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_gemm(float alpha,float beta,merlin_uint_64 C[22000],merlin_uint_512 A[3000],merlin_uint_64 B[26400])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=3000 bundle=merlin_gmem_kernel_gemm_512_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=26400 bundle=merlin_gmem_kernel_gemm_64_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=22000 bundle=merlin_gmem_kernel_gemm_64_C
  
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
    float B_7_0_buf[240][10][22];
    
#pragma HLS array_partition variable=B_7_0_buf complete dim=3
    float A_7_0_buf[200][240];
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=16 dim=2
    float C_buf[200][10][22];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 2 dim=3 */
    
#pragma HLS array_partition variable=C_buf complete dim=3
    memcpy_wide_bus_read_float_3d_10_22_64(C_buf,0,0,0,(merlin_uint_64 *)C,(0 * 4),sizeof(float ) * ((unsigned long )44000L),44000L);
{
      memcpy_wide_bus_read_float_2d_240_512(A_7_0_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      memcpy_wide_bus_read_float_3d_10_22_64(B_7_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )52800L),52800L);
    }
    merlinL5:
    for (i = 0; i < 200; i++) {
      merlinL4:
      for (j = 0; j < 10; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=C_buf array inter false
        
#pragma HLS pipeline
        merlinL3:
        for (int j_sub_0 = 0; j_sub_0 < 22; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          C_buf[i][j][j_sub_0] *= beta;
        }
      }
      merlinL2:
      for (k = 0; k < 240; k++) {
        merlinL1:
        for (j = 0; j < 10; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=C_buf array inter false
          
#pragma HLS pipeline
          merlinL0:
          for (int j_sub = 0; j_sub < 22; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            C_buf[i][j][j_sub] += alpha * A_7_0_buf[i][k] * B_7_0_buf[k][j][j_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_write_float_3d_10_22_64((merlin_uint_64 *)C,C_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )44000L),44000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_7_0_buf cyclic factor = 2 dim=3 */
}
