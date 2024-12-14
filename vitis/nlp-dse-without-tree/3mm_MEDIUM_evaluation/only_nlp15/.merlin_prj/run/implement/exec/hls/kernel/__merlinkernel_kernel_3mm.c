#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_256_1d.h"
#define SIZE_1 2
#define SIZE_2 25
#define SIZE_3 8
#include "memcpy_256_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 8
#define SIZE_2 95
#define SIZE_3 2
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[95][2],int dst_idx_1,int dst_idx_2,float src[34200],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 95 + dst_idx_1) * 2 + dst_idx_2;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[(total_offset1 + i) / 2][(total_offset1 + i) % 2] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[34200],long dst_idx_0,float src[95][2],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 34200 + dst_idx_0;
  unsigned long total_offset2 = (0 * 95 + src_idx_1) * 2 + src_idx_2;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[total_offset1 + i] = src[(total_offset2 + i) / 2][(total_offset2 + i) % 2];
  }
}

static void merlin_memcpy_2(float dst[95][2][44][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[41800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 95 + dst_idx_0) * 2 + dst_idx_1) * 44 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 41800 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=41800
    dst[(total_offset1 + i) / 5 / 44 / 2][(total_offset1 + i) / 5 / 44 % 2][(total_offset1 + i) / 5 % 44][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_3(float dst[44][5][70][3],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[46200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 44 + dst_idx_0) * 5 + dst_idx_1) * 70 + dst_idx_2) * 3 + dst_idx_3;
  unsigned long total_offset2 = 0 * 46200 + src_idx_0;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=46200
    dst[(total_offset1 + i) / 3 / 70 / 5][(total_offset1 + i) / 3 / 70 % 5][(total_offset1 + i) / 3 % 70][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_4(float dst[70][3],int dst_idx_1,int dst_idx_2,float src[39900],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 70 + dst_idx_1) * 3 + dst_idx_2;
  unsigned long total_offset2 = 0 * 39900 + src_idx_0;
  merlinL4:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=210
    dst[(total_offset1 + i) / 3][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_5(float dst[39900],long dst_idx_0,float src[70][3],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 39900 + dst_idx_0;
  unsigned long total_offset2 = (0 * 70 + src_idx_1) * 3 + src_idx_2;
  merlinL5:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=210
    dst[total_offset1 + i] = src[(total_offset2 + i) / 3][(total_offset2 + i) % 3];
  }
}

static void merlin_memcpy_6(float dst[60][3][38][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[34200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 60 + dst_idx_0) * 3 + dst_idx_1) * 38 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL6:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=34200
    dst[(total_offset1 + i) / 5 / 38 / 3][(total_offset1 + i) / 5 / 38 % 3][(total_offset1 + i) / 5 % 38][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_7(float dst[38][5][70][3],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[39900],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 38 + dst_idx_0) * 5 + dst_idx_1) * 70 + dst_idx_2) * 3 + dst_idx_3;
  unsigned long total_offset2 = 0 * 39900 + src_idx_0;
  merlinL7:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=39900
    dst[(total_offset1 + i) / 3 / 70 / 5][(total_offset1 + i) / 3 / 70 % 5][(total_offset1 + i) / 3 % 70][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_8(float dst[70][3],int dst_idx_1,int dst_idx_2,float src[37800],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 70 + dst_idx_1) * 3 + dst_idx_2;
  unsigned long total_offset2 = 0 * 37800 + src_idx_0;
  merlinL8:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=210
    dst[(total_offset1 + i) / 3][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_9(float dst[37800],long dst_idx_0,float src[70][3],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 37800 + dst_idx_0;
  unsigned long total_offset2 = (0 * 70 + src_idx_1) * 3 + src_idx_2;
  merlinL9:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=210
    dst[total_offset1 + i] = src[(total_offset2 + i) / 3][(total_offset2 + i) % 3];
  }
}

void kernel_3mm(float E[34200],merlin_uint_256 A[4500],merlin_uint_64 B[19000],float F[39900],float C[41800],float D[46200],float G[37800])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=4500 bundle=merlin_gmem_kernel_3mm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=41800 bundle=merlin_gmem_kernel_3mm_32_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=46200 bundle=merlin_gmem_kernel_3mm_32_1
  
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
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
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
    float B_17_0_buf[25][8][95][2];
    
#pragma HLS array_partition variable=B_17_0_buf complete dim=4
    
#pragma HLS array_partition variable=B_17_0_buf complete dim=2
    float A_17_0_buf[90][2][25][8];
    
#pragma HLS array_partition variable=A_17_0_buf complete dim=4
    float D_18_0_buf[44][5][70][3];
    
#pragma HLS array_partition variable=D_18_0_buf complete dim=2
    float C_18_0_buf[95][2][44][5];
    
#pragma HLS array_partition variable=C_18_0_buf complete dim=4
    float F_19_0_buf[38][5][70][3];
    
#pragma HLS array_partition variable=F_19_0_buf complete dim=2
    float E_19_0_buf[60][3][38][5];
    
#pragma HLS array_partition variable=E_19_0_buf complete dim=4
{
      memcpy_wide_bus_read_float_4d_2_25_8_256(A_17_0_buf,0,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      memcpy_wide_bus_read_float_4d_8_95_2_64(B_17_0_buf,0,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )38000L),38000L);
    }
    merlinL33:
    for (i = 0; i < 90; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      float E_buf[2][95][2];
{
        merlinL32:
        for (int i_sub_1 = 0; i_sub_1 < 2; ++i_sub_1) {
          merlin_memcpy_0(E_buf[i_sub_1],0,0,E,((long )i) * 380L + ((long )i_sub_1) * 190L,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
      merlinL31:
      for (int i_sub_1 = 0; i_sub_1 < 2; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL30:
        for (j = 0; j < 95; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
          merlinL29:
          for (int j_sub_1 = 0; j_sub_1 < 2; ++j_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            E_buf[i_sub_1][j][j_sub_1] = ((float )0.0);
            merlinL28:
            for (k = 0; k < 25; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL27:
              for (int k_sub_1 = 0; k_sub_1 < 8; ++k_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
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
        for (int i_sub_1 = 0; i_sub_1 < 2; ++i_sub_1) {
          merlin_memcpy_1(E,((long )i) * 380L + ((long )i_sub_1) * 190L,E_buf[i_sub_1],0,0,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
    }
{
      merlin_memcpy_2(C_18_0_buf,0,0,0,0,C,0,sizeof(float ) * ((unsigned long )41800L),167200UL);
    }
{
      merlin_memcpy_3(D_18_0_buf,0,0,0,0,D,0,sizeof(float ) * ((unsigned long )46200L),184800UL);
    }
    merlinL25:
    for (i = 0; i < 95; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      float F_buf[2][70][3];
{
        merlinL24:
        for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) {
          merlin_memcpy_4(F_buf[i_sub_0],0,0,F,((long )i) * 420L + ((long )i_sub_0) * 210L,sizeof(float ) * ((unsigned long )210L),840UL);
        }
      }
      merlinL23:
      for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL22:
        for (j = 0; j < 70; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
{
          merlinL21:
          for (int j_sub_0 = 0; j_sub_0 < 3; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
            F_buf[i_sub_0][j][j_sub_0] = ((float )0.0);
            merlinL20:
            for (k = 0; k < 44; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL19:
              for (int k_sub_0 = 0; k_sub_0 < 5; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
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
        for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) {
          merlin_memcpy_5(F,((long )i) * 420L + ((long )i_sub_0) * 210L,F_buf[i_sub_0],0,0,sizeof(float ) * ((unsigned long )210L),840UL);
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
    for (i = 0; i < 60; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
{
      float G_buf[3][70][3];
{
        merlinL16:
        for (int i_sub = 0; i_sub < 3; ++i_sub) {
          merlin_memcpy_8(G_buf[i_sub],0,0,G,((long )i) * 630L + ((long )i_sub) * 210L,sizeof(float ) * ((unsigned long )210L),840UL);
        }
      }
      merlinL15:
      for (int i_sub = 0; i_sub < 3; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL14:
        for (j = 0; j < 70; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
{
          merlinL13:
          for (int j_sub = 0; j_sub < 3; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
            G_buf[i_sub][j][j_sub] = ((float )0.0);
            merlinL12:
            for (k = 0; k < 38; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL11:
              for (int k_sub = 0; k_sub < 5; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
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
        for (int i_sub = 0; i_sub < 3; ++i_sub) {
          merlin_memcpy_9(G,((long )i) * 630L + ((long )i_sub) * 210L,G_buf[i_sub],0,0,sizeof(float ) * ((unsigned long )210L),840UL);
        }
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_17_0_buf cyclic factor = 8 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_17_0_buf cyclic factor = 2 dim=4 */
}
