#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 50
#define SIZE_2 240
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"





/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[240][44][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[52800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 240 + dst_idx_0) * 44 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 52800 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=52800
    dst[(total_offset1 + i) / 5 / 44][(total_offset1 + i) / 5 % 44][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[44][5],int dst_idx_1,int dst_idx_2,float src[44000],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 44 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 44000 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=220
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[44000],long dst_idx_0,float src[44][5],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 44000 + dst_idx_0;
  unsigned long total_offset2 = (0 * 44 + src_idx_1) * 5 + src_idx_2;
  merlinL2:
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
    float B_8_0_buf[240][44][5];
    
#pragma HLS array_partition variable=B_8_0_buf complete dim=3
    float A_8_0_buf[4][50][240];
    
#pragma HLS array_partition variable=A_8_0_buf cyclic factor=16 dim=3
{
      memcpy_wide_bus_read_float_3d_50_240_512(A_8_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      merlin_memcpy_0(B_8_0_buf,0,0,0,B,0,sizeof(float ) * ((unsigned long )52800L),211200UL);
    }
    merlinL11:
    for (i = 0; i < 4; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
{
      float C_buf[50][44][5];
      
#pragma HLS array_partition variable=C_buf complete dim=3
{
        merlinL10:
        for (int i_sub = 0; i_sub < 50; ++i_sub) {
          merlin_memcpy_1(C_buf[i_sub],0,0,C,((long )i) * 11000L + ((long )i_sub) * 220L,sizeof(float ) * ((unsigned long )220L),880UL);
        }
      }
      merlinL9:
      for (int i_sub = 0; i_sub < 50; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL8:
        for (j = 0; j < 44; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=C_buf array inter false
          
#pragma HLS pipeline
          merlinL7:
          for (int j_sub_0 = 0; j_sub_0 < 5; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            C_buf[i_sub][j][j_sub_0] *= beta;
          }
        }
        merlinL6:
        for (k = 0; k < 240; k++) {
          merlinL5:
          for (j = 0; j < 44; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS dependence variable=C_buf array inter false
            
#pragma HLS pipeline
            merlinL4:
            for (int j_sub = 0; j_sub < 5; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
              
#pragma HLS unroll
              C_buf[i_sub][j][j_sub] += alpha * A_8_0_buf[i][i_sub][k] * B_8_0_buf[k][j][j_sub];
            }
          }
        }
      }
{
        merlinL3:
        for (int i_sub = 0; i_sub < 50; ++i_sub) {
          merlin_memcpy_2(C,((long )i) * 11000L + ((long )i_sub) * 220L,C_buf[i_sub],0,0,sizeof(float ) * ((unsigned long )220L),880UL);
        }
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 16 dim=3 */
}
