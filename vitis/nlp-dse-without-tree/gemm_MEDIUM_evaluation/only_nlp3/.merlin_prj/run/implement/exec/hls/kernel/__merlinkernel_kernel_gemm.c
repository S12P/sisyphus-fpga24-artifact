#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 10
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 240
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 22
#define SIZE_2 10
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_gemm_L_1_para_sub(float alpha,float beta,int i,int j,int k,float A_7_0_buf[240],float C_buf[22][10],float B_7_0_buf_dup[240][22][10])
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL parallel */
{
  
#pragma HLS inline off
  merlinL5:
  for (j = 0; j < 22; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS dependence variable=C_buf array inter false
    
#pragma HLS pipeline
    merlinL4:
    for (int j_sub_0 = 0; j_sub_0 < 10; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
      
#pragma HLS unroll
      C_buf[j][j_sub_0] *= beta;
    }
  }
  merlinL3:
  for (k = 0; k < 240; k++) {
    merlinL2:
    for (j = 0; j < 22; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=C_buf array inter false
      
#pragma HLS pipeline
      merlinL1:
      for (int j_sub = 0; j_sub < 10; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        C_buf[j][j_sub] += alpha * A_7_0_buf[k] * B_7_0_buf_dup[k][j][j_sub];
      }
    }
  }
}

void kernel_gemm_L_1_para(float alpha,float beta,int j,int k,float A_7_0_buf[200][240],float C_buf[200][22][10],float B_7_0_buf_dup[200][240][22][10])
{
  
#pragma HLS inline off
  int i;
  merlinL0:
  for (i = 0; i < 200; ++i) {
    
#pragma HLS unroll complete
    kernel_gemm_L_1_para_sub(alpha,beta,i,j,k,A_7_0_buf[i],C_buf[i],B_7_0_buf_dup[i]);
  }
}

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
    float B_7_0_buf[240][22][10];
    
#pragma HLS array_partition variable=B_7_0_buf cyclic factor=2 dim=3
    float A_7_0_buf[200][240];
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf dim=1 complete */
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=1
    float C_buf[200][22][10];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf dim=1 complete */
    
#pragma HLS array_partition variable=C_buf complete dim=3
    
#pragma HLS array_partition variable=C_buf complete dim=1
{
      int i;
      merlinL12:
      for (i = 0; i < 200; i++) {
        memcpy_wide_bus_read_float_2d_10_64(C_buf[i],(size_t )0,(size_t )0,(merlin_uint_64 *)C,(size_t )(((long )i) * 220L * ((long )4)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
      }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 2 dim=3 */
    }
{
      memcpy_wide_bus_read_float_2d_240_512(A_7_0_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      memcpy_wide_bus_read_float_3d_22_10_64(B_7_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )52800L),52800L);
    }
    float B_7_0_buf_dup[200][240][22][10];
/* Existing HLS partition: #pragma HLS array_partition variable=B_7_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=B_7_0_buf_dup complete dim=4
    
#pragma HLS array_partition variable=B_7_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      long _i2;
      long _i3;
      merlinL11:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 239UL; ++_i1) {
        merlinL10:
        for (_i2 = ((long )0); ((unsigned long )_i2) <= 21UL; ++_i2) {
          merlinL9:
          for (_i3 = ((long )0); ((unsigned long )_i3) <= 9UL; ++_i3) {
            
#pragma HLS pipeline
            
#pragma HLS loop_flatten
            merlinL8:
            for (_i0 = ((long )0); ((unsigned long )_i0) <= 199UL; ++_i0) {
              
#pragma HLS unroll
              B_7_0_buf_dup[_i0][_i1][_i2][_i3] = B_7_0_buf[_i1][_i2][_i3];
            }
          }
        }
      }
    }
    kernel_gemm_L_1_para(alpha,beta,j,k,A_7_0_buf,C_buf,B_7_0_buf_dup);
    merlinL7:
    for (i = 0; i < 200; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL parallel */
{
    }{
      int i;
      merlinL6:
      for (i = 0; i < 200; i++) {
        memcpy_wide_bus_write_float_2d_10_64((merlin_uint_64 *)C,C_buf[i],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 220L)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
      }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 2 dim=3 */
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_7_0_buf cyclic factor = 2 dim=3 */
}
