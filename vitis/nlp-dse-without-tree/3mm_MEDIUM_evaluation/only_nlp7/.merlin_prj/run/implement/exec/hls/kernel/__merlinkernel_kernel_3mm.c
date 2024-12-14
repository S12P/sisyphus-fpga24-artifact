#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#define SIZE_1 10
#define SIZE_2 10
#define SIZE_3 22
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 22
#define SIZE_2 35
#define SIZE_3 6
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[18][10][8][25],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[36000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 18 + dst_idx_0) * 10 + dst_idx_1) * 8 + dst_idx_2) * 25 + dst_idx_3;
  unsigned long total_offset2 = 0 * 36000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=36000
    dst[(total_offset1 + i) / 25 / 8 / 10][(total_offset1 + i) / 25 / 8 % 10][(total_offset1 + i) / 25 % 8][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[8][25][38][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[38000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 8 + dst_idx_0) * 25 + dst_idx_1) * 38 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 38000 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=38000
    dst[(total_offset1 + i) / 5 / 38 / 25][(total_offset1 + i) / 5 / 38 % 25][(total_offset1 + i) / 5 % 38][(total_offset1 + i) % 5] = src[total_offset2 + i];
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

static void merlin_memcpy_4(float dst[35][6],int dst_idx_1,int dst_idx_2,float src[39900],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 35 + dst_idx_1) * 6 + dst_idx_2;
  unsigned long total_offset2 = 0 * 39900 + src_idx_0;
  merlinL4:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=210
    dst[(total_offset1 + i) / 6][(total_offset1 + i) % 6] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_5(float dst[39900],long dst_idx_0,float src[35][6],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 39900 + dst_idx_0;
  unsigned long total_offset2 = (0 * 35 + src_idx_1) * 6 + src_idx_2;
  merlinL5:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=210
    dst[total_offset1 + i] = src[(total_offset2 + i) / 6][(total_offset2 + i) % 6];
  }
}

static void merlin_memcpy_6(float dst[30][6][19][10],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[34200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 30 + dst_idx_0) * 6 + dst_idx_1) * 19 + dst_idx_2) * 10 + dst_idx_3;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL6:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=34200
    dst[(total_offset1 + i) / 10 / 19 / 6][(total_offset1 + i) / 10 / 19 % 6][(total_offset1 + i) / 10 % 19][(total_offset1 + i) % 10] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_7(float dst[19][10][10][21],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[39900],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 19 + dst_idx_0) * 10 + dst_idx_1) * 10 + dst_idx_2) * 21 + dst_idx_3;
  unsigned long total_offset2 = 0 * 39900 + src_idx_0;
  merlinL7:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=39900
    dst[(total_offset1 + i) / 21 / 10 / 10][(total_offset1 + i) / 21 / 10 % 10][(total_offset1 + i) / 21 % 10][(total_offset1 + i) % 21] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_8(float dst[10][21],int dst_idx_1,int dst_idx_2,float src[37800],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 10 + dst_idx_1) * 21 + dst_idx_2;
  unsigned long total_offset2 = 0 * 37800 + src_idx_0;
  merlinL8:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=210
    dst[(total_offset1 + i) / 21][(total_offset1 + i) % 21] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_9(float dst[37800],long dst_idx_0,float src[10][21],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 37800 + dst_idx_0;
  unsigned long total_offset2 = (0 * 10 + src_idx_1) * 21 + src_idx_2;
  merlinL9:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=210
    dst[total_offset1 + i] = src[(total_offset2 + i) / 21][(total_offset2 + i) % 21];
  }
}

void kernel_3mm(float E[34200],float A[36000],float B[38000],float F[39900],merlin_uint_64 C[20900],merlin_uint_64 D[23100],float G[37800])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=36000 bundle=merlin_gmem_kernel_3mm_32_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=38000 bundle=merlin_gmem_kernel_3mm_32_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=20900 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=23100 bundle=merlin_gmem_kernel_3mm_64_1
  
#pragma HLS INTERFACE m_axi port=E offset=slave depth=34200 bundle=merlin_gmem_kernel_3mm_32_E
  
#pragma HLS INTERFACE m_axi port=F offset=slave depth=39900 bundle=merlin_gmem_kernel_3mm_32_F
  
#pragma HLS INTERFACE m_axi port=G offset=slave depth=37800 bundle=merlin_gmem_kernel_3mm_32_G
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=D bundle=control
  
#pragma HLS INTERFACE s_axilite port=E bundle=control
  
#pragma HLS INTERFACE s_axilite port=F bundle=control
  
#pragma HLS INTERFACE s_axilite port=G bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=D
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=G depth=180,210 max_depth=180,210
  
#pragma ACCEL interface variable=D depth=220,210 max_depth=220,210
  
#pragma ACCEL interface variable=C depth=190,220 max_depth=190,220
  
#pragma ACCEL interface variable=F depth=190,210 max_depth=190,210
  
#pragma ACCEL interface variable=B depth=200,190 max_depth=200,190
  
#pragma ACCEL interface variable=A depth=180,200 max_depth=180,200
  
#pragma ACCEL interface variable=E depth=180,190 max_depth=180,190
  int i;
  int j;
  int k;
{
    float B_17_0_buf[8][25][38][5];
    
#pragma HLS array_partition variable=B_17_0_buf complete dim=2
    float A_17_0_buf[18][10][8][25];
    
#pragma HLS array_partition variable=A_17_0_buf complete dim=4
    float D_18_0_buf[10][22][35][6];
    
#pragma HLS array_partition variable=D_18_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=D_18_0_buf complete dim=2
    float C_18_0_buf[19][10][10][22];
    
#pragma HLS array_partition variable=C_18_0_buf complete dim=4
    float F_19_0_buf[19][10][10][21];
    
#pragma HLS array_partition variable=F_19_0_buf complete dim=2
    float E_19_0_buf[30][6][19][10];
    
#pragma HLS array_partition variable=E_19_0_buf complete dim=4
{
      merlin_memcpy_0(A_17_0_buf,0,0,0,0,A,0,sizeof(float ) * ((unsigned long )36000L),144000UL);
    }
{
      merlin_memcpy_1(B_17_0_buf,0,0,0,0,B,0,sizeof(float ) * ((unsigned long )38000L),152000UL);
    }
    merlinL33:
    for (i = 0; i < 18; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
      float E_buf[10][38][5];
{
        merlinL32:
        for (int i_sub_1 = 0; i_sub_1 < 10; ++i_sub_1) {
          merlin_memcpy_2(E_buf[i_sub_1],0,0,E,((long )i) * 1900L + ((long )i_sub_1) * 190L,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
      merlinL31:
      for (int i_sub_1 = 0; i_sub_1 < 10; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL30:
        for (j = 0; j < 38; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
{
          merlinL29:
          for (int j_sub_1 = 0; j_sub_1 < 5; ++j_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            E_buf[i_sub_1][j][j_sub_1] = ((float )0.0);
            merlinL28:
            for (k = 0; k < 8; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL27:
              for (int k_sub_1 = 0; k_sub_1 < 25; ++k_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
                
#pragma HLS unroll
                E_buf[i_sub_1][j][j_sub_1] += A_17_0_buf[i][i_sub_1][k][k_sub_1] * B_17_0_buf[k][k_sub_1][j][j_sub_1];
              }
            }
          }
        }
      }
{
        merlinL26:
        for (int i_sub_1 = 0; i_sub_1 < 10; ++i_sub_1) {
          merlin_memcpy_3(E,((long )i) * 1900L + ((long )i_sub_1) * 190L,E_buf[i_sub_1],0,0,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
    }
{
      memcpy_wide_bus_read_float_4d_10_10_22_64(C_18_0_buf,0,0,0,0,(merlin_uint_64 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      memcpy_wide_bus_read_float_4d_22_35_6_64(D_18_0_buf,0,0,0,0,(merlin_uint_64 *)D,(0 * 4),sizeof(float ) * ((unsigned long )46200L),46200L);
    }
    merlinL25:
    for (i = 0; i < 19; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
      float F_buf[10][35][6];
{
        merlinL24:
        for (int i_sub_0 = 0; i_sub_0 < 10; ++i_sub_0) {
          merlin_memcpy_4(F_buf[i_sub_0],0,0,F,((long )i) * 2100L + ((long )i_sub_0) * 210L,sizeof(float ) * ((unsigned long )210L),840UL);
        }
      }
      merlinL23:
      for (int i_sub_0 = 0; i_sub_0 < 10; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL22:
        for (j = 0; j < 35; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
          merlinL21:
          for (int j_sub_0 = 0; j_sub_0 < 6; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
            F_buf[i_sub_0][j][j_sub_0] = ((float )0.0);
            merlinL20:
            for (k = 0; k < 10; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL19:
              for (int k_sub_0 = 0; k_sub_0 < 22; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PARALLEL */
{
                
#pragma HLS unroll
                F_buf[i_sub_0][j][j_sub_0] += C_18_0_buf[i][i_sub_0][k][k_sub_0] * D_18_0_buf[k][k_sub_0][j][j_sub_0];
              }
            }
          }
        }
      }
{
        merlinL18:
        for (int i_sub_0 = 0; i_sub_0 < 10; ++i_sub_0) {
          merlin_memcpy_5(F,((long )i) * 2100L + ((long )i_sub_0) * 210L,F_buf[i_sub_0],0,0,sizeof(float ) * ((unsigned long )210L),840UL);
        }
      }
    }
{
      merlin_memcpy_6(E_19_0_buf,0,0,0,0,E,0,sizeof(float ) * ((unsigned long )34200L),136800UL);
    }
{
      merlin_memcpy_7(F_19_0_buf,0,0,0,0,F,0,sizeof(float ) * ((unsigned long )39900L),159600UL);
    }
    merlinL17:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float G_buf[6][10][21];
{
        merlinL16:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          merlin_memcpy_8(G_buf[i_sub],0,0,G,((long )i) * 1260L + ((long )i_sub) * 210L,sizeof(float ) * ((unsigned long )210L),840UL);
        }
      }
      merlinL15:
      for (int i_sub = 0; i_sub < 6; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL14:
        for (j = 0; j < 10; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=21 */
/* Original: #pragma ACCEL PARALLEL FACTOR=21 */
{
          merlinL13:
          for (int j_sub = 0; j_sub < 21; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=21 */
/* Original: #pragma ACCEL PARALLEL FACTOR=21 */
/* Original: #pragma ACCEL PARALLEL */
{
            G_buf[i_sub][j][j_sub] = ((float )0.0);
            merlinL12:
            for (k = 0; k < 19; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL11:
              for (int k_sub = 0; k_sub < 10; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
                
#pragma HLS unroll
                G_buf[i_sub][j][j_sub] += E_19_0_buf[i][i_sub][k][k_sub] * F_19_0_buf[k][k_sub][j][j_sub];
              }
            }
          }
        }
      }
{
        merlinL10:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          merlin_memcpy_9(G,((long )i) * 1260L + ((long )i_sub) * 210L,G_buf[i_sub],0,0,sizeof(float ) * ((unsigned long )210L),840UL);
        }
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_18_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_18_0_buf cyclic factor = 2 dim=4 */
}
