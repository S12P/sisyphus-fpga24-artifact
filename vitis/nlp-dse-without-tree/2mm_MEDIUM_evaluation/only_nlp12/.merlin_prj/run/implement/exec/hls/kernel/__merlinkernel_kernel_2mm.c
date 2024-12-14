#define __constant
#define __kernel
#define __global
#include <string.h> 

#include "merlin_type_define.h"



/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[30][6][42][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[37800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 30 + dst_idx_0) * 6 + dst_idx_1) * 42 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 37800 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=37800
    dst[(total_offset1 + i) / 5 / 42 / 6][(total_offset1 + i) / 5 / 42 % 6][(total_offset1 + i) / 5 % 42][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[42][5][38][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[39900],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 42 + dst_idx_0) * 5 + dst_idx_1) * 38 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 39900 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=39900
    dst[(total_offset1 + i) / 5 / 38 / 5][(total_offset1 + i) / 5 / 38 % 5][(total_offset1 + i) / 5 % 38][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[38][5],int dst_idx_1,int dst_idx_2,float src[34200],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 38 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_3(float dst[34200],long dst_idx_0,float src[38][5],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 34200 + dst_idx_0;
  unsigned long total_offset2 = (0 * 38 + src_idx_1) * 5 + src_idx_2;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5][(total_offset2 + i) % 5];
  }
}

static void merlin_memcpy_4(float dst[30][6][38][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[34200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 30 + dst_idx_0) * 6 + dst_idx_1) * 38 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL4:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=34200
    dst[(total_offset1 + i) / 5 / 38 / 6][(total_offset1 + i) / 5 / 38 % 6][(total_offset1 + i) / 5 % 38][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_5(float dst[38][5][44][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[41800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 38 + dst_idx_0) * 5 + dst_idx_1) * 44 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 41800 + src_idx_0;
  merlinL5:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=41800
    dst[(total_offset1 + i) / 5 / 44 / 5][(total_offset1 + i) / 5 / 44 % 5][(total_offset1 + i) / 5 % 44][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_6(float dst[44][5],int dst_idx_1,int dst_idx_2,float src[39600],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 44 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 39600 + src_idx_0;
  merlinL6:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=220
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_7(float dst[39600],long dst_idx_0,float src[44][5],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 39600 + dst_idx_0;
  unsigned long total_offset2 = (0 * 44 + src_idx_1) * 5 + src_idx_2;
  merlinL7:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=220
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5][(total_offset2 + i) % 5];
  }
}

void kernel_2mm(float alpha,float beta,float tmp[34200],float A[37800],float B[39900],float C[41800],float D[39600])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=37800 bundle=merlin_gmem_kernel_2mm_32_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=39900 bundle=merlin_gmem_kernel_2mm_32_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=41800 bundle=merlin_gmem_kernel_2mm_32_2
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=39600 bundle=merlin_gmem_kernel_2mm_32_D
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=34200 bundle=merlin_gmem_kernel_2mm_32_tmp
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=D bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=tmp bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma ACCEL interface variable=D depth=180,220 max_depth=180,220
  
#pragma ACCEL interface variable=C depth=190,220 max_depth=190,220
  
#pragma ACCEL interface variable=B depth=210,190 max_depth=210,190
  
#pragma ACCEL interface variable=A depth=180,210 max_depth=180,210
  
#pragma ACCEL interface variable=tmp depth=180,190 max_depth=180,190
  int i;
  int j;
  int k;
{
    float B_12_0_buf[42][5][38][5];
    
#pragma HLS array_partition variable=B_12_0_buf complete dim=2
    float A_12_0_buf[30][6][42][5];
    
#pragma HLS array_partition variable=A_12_0_buf complete dim=4
    float C_13_0_buf[38][5][44][5];
    
#pragma HLS array_partition variable=C_13_0_buf complete dim=2
    float tmp_13_0_buf[30][6][38][5];
    
#pragma HLS array_partition variable=tmp_13_0_buf complete dim=4
{
      merlin_memcpy_0(A_12_0_buf,0,0,0,0,A,0,sizeof(float ) * ((unsigned long )37800L),151200UL);
    }
{
      merlin_memcpy_1(B_12_0_buf,0,0,0,0,B,0,sizeof(float ) * ((unsigned long )39900L),159600UL);
    }
    merlinL23:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float tmp_buf[6][38][5];
{
        merlinL22:
        for (int i_sub_0 = 0; i_sub_0 < 6; ++i_sub_0) {
          merlin_memcpy_2(tmp_buf[i_sub_0],0,0,tmp,((long )i) * 1140L + ((long )i_sub_0) * 190L,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
      merlinL21:
      for (int i_sub_0 = 0; i_sub_0 < 6; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL20:
        for (j = 0; j < 38; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
{
          merlinL19:
          for (int j_sub_0 = 0; j_sub_0 < 5; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            tmp_buf[i_sub_0][j][j_sub_0] = ((float )0.0);
            merlinL18:
            for (k = 0; k < 42; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL17:
              for (int k_sub_0 = 0; k_sub_0 < 5; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
                
#pragma HLS unroll
                tmp_buf[i_sub_0][j][j_sub_0] += alpha * A_12_0_buf[i][i_sub_0][k][k_sub_0] * B_12_0_buf[k][k_sub_0][j][j_sub_0];
              }
            }
          }
        }
      }
{
        merlinL16:
        for (int i_sub_0 = 0; i_sub_0 < 6; ++i_sub_0) {
          merlin_memcpy_3(tmp,((long )i) * 1140L + ((long )i_sub_0) * 190L,tmp_buf[i_sub_0],0,0,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
    }
{
      merlin_memcpy_4(tmp_13_0_buf,0,0,0,0,tmp,0,sizeof(float ) * ((unsigned long )34200L),136800UL);
    }
{
      merlin_memcpy_5(C_13_0_buf,0,0,0,0,C,0,sizeof(float ) * ((unsigned long )41800L),167200UL);
    }
    merlinL15:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float D_buf[6][44][5];
{
        merlinL14:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          merlin_memcpy_6(D_buf[i_sub],0,0,D,((long )i) * 1320L + ((long )i_sub) * 220L,sizeof(float ) * ((unsigned long )220L),880UL);
        }
      }
      merlinL13:
      for (int i_sub = 0; i_sub < 6; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL12:
        for (j = 0; j < 44; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
{
          merlinL11:
          for (int j_sub = 0; j_sub < 5; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            D_buf[i_sub][j][j_sub] *= beta;
            merlinL10:
            for (k = 0; k < 38; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL9:
              for (int k_sub = 0; k_sub < 5; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
                
#pragma HLS unroll
                D_buf[i_sub][j][j_sub] += tmp_13_0_buf[i][i_sub][k][k_sub] * C_13_0_buf[k][k_sub][j][j_sub];
              }
            }
          }
        }
      }
{
        merlinL8:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          merlin_memcpy_7(D,((long )i) * 1320L + ((long )i_sub) * 220L,D_buf[i_sub],0,0,sizeof(float ) * ((unsigned long )220L),880UL);
        }
      }
    }
  }
}
