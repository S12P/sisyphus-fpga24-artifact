#define __constant
#define __kernel
#define __global
#include <string.h> 

#include "merlin_type_define.h"



/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[200][80][3],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[48000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 200 + dst_idx_0) * 80 + dst_idx_1) * 3 + dst_idx_2;
  unsigned long total_offset2 = 0 * 48000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=48000
    dst[(total_offset1 + i) / 3 / 80][(total_offset1 + i) / 3 % 80][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[48000],int dst_idx_0,float src[200][80][3],int src_idx_0,int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 48000 + dst_idx_0;
  unsigned long total_offset2 = ((0 * 200 + src_idx_0) * 80 + src_idx_1) * 3 + src_idx_2;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=48000
    dst[total_offset1 + i] = src[(total_offset2 + i) / 3 / 80][(total_offset2 + i) / 3 % 80][(total_offset2 + i) % 3];
  }
}

void kernel_trmm(float alpha,float A[40000],float B[48000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=40000 bundle=merlin_gmem_kernel_trmm_32_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=48000 bundle=merlin_gmem_kernel_trmm_32_B
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma ACCEL interface variable=B depth=200,240 max_depth=200,240
  
#pragma ACCEL interface variable=A depth=200,200 max_depth=200,200
  int i;
  int j;
  int k;
//BLAS parameters
//SIDE   = 'L'
//UPLO   = 'L'
//TRANSA = 'T'
//DIAG   = 'U'
// => Form  B := alpha*A**T*B.
// A is MxM
// B is MxN
{
    float B_buf[200][80][3];
    
#pragma HLS array_partition variable=B_buf complete dim=3
    merlin_memcpy_0(B_buf,0,0,0,B,0,sizeof(float ) * ((unsigned long )48000L),192000UL);
    merlinL6:
    for (i = 0; i < 100; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      merlinL5:
      for (j = 0; j < 80; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=B_buf array inter false
        
#pragma HLS pipeline
        merlinL4:
        for (int i_sub = 0; i_sub < 2; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL3:
          for (int j_sub = 0; j_sub < 3; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            merlinL2:
            for (k = i * 2 + i_sub + 1; k < 200; k++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=199 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
              
#pragma HLS unroll
              
#pragma HLS LOOP_TRIPCOUNT max=199
              B_buf[((long )i) * 2L + ((long )i_sub)][j][j_sub] += A[((long )k) * 200L + ((long )(i * 2 + i_sub))] * B_buf[k][j][j_sub];
            }
            B_buf[((long )i) * 2L + ((long )i_sub)][j][j_sub] = alpha * B_buf[((long )i) * 2L + ((long )i_sub)][j][j_sub];
          }
        }
      }
    }
    merlin_memcpy_1(B,0,B_buf,0,0,0,sizeof(float ) * ((unsigned long )48000L),192000UL);
  }
}
