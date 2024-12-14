#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 240
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"





/* Original: #pragma ACCEL kernel */

void kernel_gemm_L_1_para_sub(float alpha,float beta,int i,int j,int k,float A_7_0_buf[240],float C_buf[44][5],float B_7_0_buf_dup[240][44][5])
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL parallel */
{
  
#pragma HLS inline off
  merlinL7:
  for (j = 0; j < 44; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS dependence variable=C_buf array inter false
    
#pragma HLS pipeline
    merlinL6:
    for (int j_sub_0 = 0; j_sub_0 < 5; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
      
#pragma HLS unroll
      C_buf[j][j_sub_0] *= beta;
    }
  }
  merlinL5:
  for (k = 0; k < 240; k++) {
    merlinL4:
    for (j = 0; j < 44; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=C_buf array inter false
      
#pragma HLS pipeline
      merlinL3:
      for (int j_sub = 0; j_sub < 5; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        C_buf[j][j_sub] += alpha * A_7_0_buf[k] * B_7_0_buf_dup[k][j][j_sub];
      }
    }
  }
}

void kernel_gemm_L_1_para(float alpha,float beta,int j,int k,float A_7_0_buf[200][240],float C_buf[200][44][5],float B_7_0_buf_dup[200][240][44][5])
{
  
#pragma HLS inline off
  int i;
  merlinL2:
  for (i = 0; i < 200; ++i) {
    
#pragma HLS unroll complete
    kernel_gemm_L_1_para_sub(alpha,beta,i,j,k,A_7_0_buf[i],C_buf[i],B_7_0_buf_dup[i]);
  }
}

static void merlin_memcpy_0(float dst[44][5],int dst_idx_1,int dst_idx_2,float src[44000],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 44 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 44000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=220
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[240][44][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[52800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 240 + dst_idx_0) * 44 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 52800 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=52800
    dst[(total_offset1 + i) / 5 / 44][(total_offset1 + i) / 5 % 44][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[44000],long dst_idx_0,float src[44][5],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 44000 + dst_idx_0;
  unsigned long total_offset2 = (0 * 44 + src_idx_1) * 5 + src_idx_2;
  merlinL8:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=220
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5][(total_offset2 + i) % 5];
  }
}

void kernel_gemm(float alpha,float beta,float C[44000],merlin_uint_512 A[3000],float B[52800])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=3000 bundle=merlin_gmem_kernel_gemm_512_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=52800 bundle=merlin_gmem_kernel_gemm_32_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=44000 bundle=merlin_gmem_kernel_gemm_32_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=A
  
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
    float B_7_0_buf[240][44][5];
    float A_7_0_buf[200][240];
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf dim=1 complete */
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=1
    float C_buf[200][44][5];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf dim=1 complete */
    
#pragma HLS array_partition variable=C_buf complete dim=3
    
#pragma HLS array_partition variable=C_buf complete dim=1
{
      int i;
      merlinL15:
      for (i = 0; i < 200; i++) {
        merlin_memcpy_0(C_buf[i],0,0,C,((long )i) * 220L,sizeof(float ) * ((unsigned long )220L),880UL);
      }
    }
{
      memcpy_wide_bus_read_float_2d_240_512(A_7_0_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      merlin_memcpy_1(B_7_0_buf,0,0,0,B,0,sizeof(float ) * ((unsigned long )52800L),211200UL);
    }
    float B_7_0_buf_dup[200][240][44][5];
/* Existing HLS partition: #pragma HLS array_partition variable=B_7_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=B_7_0_buf_dup complete dim=4
    
#pragma HLS array_partition variable=B_7_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      long _i2;
      long _i3;
      merlinL14:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 239UL; ++_i1) {
        merlinL13:
        for (_i2 = ((long )0); ((unsigned long )_i2) <= 43UL; ++_i2) {
          merlinL12:
          for (_i3 = ((long )0); ((unsigned long )_i3) <= 4UL; ++_i3) {
            
#pragma HLS pipeline
            
#pragma HLS loop_flatten
            merlinL11:
            for (_i0 = ((long )0); ((unsigned long )_i0) <= 199UL; ++_i0) {
              
#pragma HLS unroll
              B_7_0_buf_dup[_i0][_i1][_i2][_i3] = B_7_0_buf[_i1][_i2][_i3];
            }
          }
        }
      }
    }
    kernel_gemm_L_1_para(alpha,beta,j,k,A_7_0_buf,C_buf,B_7_0_buf_dup);
    merlinL10:
    for (i = 0; i < 200; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL parallel */
{
    }{
      int i;
      merlinL9:
      for (i = 0; i < 200; i++) {
        merlin_memcpy_2(C,((long )i) * 220L,C_buf[i],0,0,sizeof(float ) * ((unsigned long )220L),880UL);
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 16 dim=2 */
}
