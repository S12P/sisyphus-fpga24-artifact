#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#define SIZE_1 6
#define SIZE_2 20
#define SIZE_3 10
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 6
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 10
#define SIZE_2 35
#define SIZE_3 6
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 5
#define SIZE_2 22
#define SIZE_3 10
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[20][10][38][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[38000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 20 + dst_idx_0) * 10 + dst_idx_1) * 38 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 38000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=38000
    dst[(total_offset1 + i) / 5 / 38 / 10][(total_offset1 + i) / 5 / 38 % 10][(total_offset1 + i) / 5 % 38][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[38][5],int dst_idx_1,int dst_idx_2,float src[34200],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 38 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[34200],long dst_idx_0,float src[38][5],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 34200 + dst_idx_0;
  unsigned long total_offset2 = (0 * 38 + src_idx_1) * 5 + src_idx_2;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5][(total_offset2 + i) % 5];
  }
}

static void merlin_memcpy_3(float dst[30][6][19][10],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[34200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 30 + dst_idx_0) * 6 + dst_idx_1) * 19 + dst_idx_2) * 10 + dst_idx_3;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=34200
    dst[(total_offset1 + i) / 10 / 19 / 6][(total_offset1 + i) / 10 / 19 % 6][(total_offset1 + i) / 10 % 19][(total_offset1 + i) % 10] = src[total_offset2 + i];
  }
}

void kernel_3mm(float E[34200],merlin_uint_64 A[18000],float B[38000],merlin_uint_64 F[19950],merlin_uint_64 C[20900],merlin_uint_64 D[23100],merlin_uint_64 G[18900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=18000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=38000 bundle=merlin_gmem_kernel_3mm_32_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=20900 bundle=merlin_gmem_kernel_3mm_64_1
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=23100 bundle=merlin_gmem_kernel_3mm_64_2
  
#pragma HLS INTERFACE m_axi port=E offset=slave depth=34200 bundle=merlin_gmem_kernel_3mm_32_E
  
#pragma HLS INTERFACE m_axi port=F offset=slave depth=19950 bundle=merlin_gmem_kernel_3mm_64_F
  
#pragma HLS INTERFACE m_axi port=G offset=slave depth=18900 bundle=merlin_gmem_kernel_3mm_64_G
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=D bundle=control
  
#pragma HLS INTERFACE s_axilite port=E bundle=control
  
#pragma HLS INTERFACE s_axilite port=F bundle=control
  
#pragma HLS INTERFACE s_axilite port=G bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=G
  
#pragma HLS DATA_PACK VARIABLE=D
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma HLS DATA_PACK VARIABLE=F
  
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
    float B_17_0_buf[20][10][38][5];
    
#pragma HLS array_partition variable=B_17_0_buf complete dim=2
    float A_17_0_buf[30][6][20][10];
    
#pragma HLS array_partition variable=A_17_0_buf complete dim=4
    float D_18_0_buf[22][10][35][6];
    
#pragma HLS array_partition variable=D_18_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=D_18_0_buf complete dim=2
    float C_18_0_buf[38][5][22][10];
    
#pragma HLS array_partition variable=C_18_0_buf complete dim=4
    float F_19_0_buf[19][10][35][6];
    
#pragma HLS array_partition variable=F_19_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=F_19_0_buf complete dim=2
    float E_19_0_buf[30][6][19][10];
    
#pragma HLS array_partition variable=E_19_0_buf complete dim=4
{
      memcpy_wide_bus_read_float_4d_6_20_10_64(A_17_0_buf,0,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      merlin_memcpy_0(B_17_0_buf,0,0,0,0,B,0,sizeof(float ) * ((unsigned long )38000L),152000UL);
    }
    merlinL27:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float E_buf[6][38][5];
{
        merlinL26:
        for (int i_sub_1 = 0; i_sub_1 < 6; ++i_sub_1) {
          merlin_memcpy_1(E_buf[i_sub_1],0,0,E,((long )i) * 1140L + ((long )i_sub_1) * 190L,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
      merlinL25:
      for (int i_sub_1 = 0; i_sub_1 < 6; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL24:
        for (j = 0; j < 38; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
{
          merlinL23:
          for (int j_sub_1 = 0; j_sub_1 < 5; ++j_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            E_buf[i_sub_1][j][j_sub_1] = ((float )0.0);
            merlinL22:
            for (k = 0; k < 20; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL21:
              for (int k_sub_1 = 0; k_sub_1 < 10; ++k_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
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
        merlinL20:
        for (int i_sub_1 = 0; i_sub_1 < 6; ++i_sub_1) {
          merlin_memcpy_2(E,((long )i) * 1140L + ((long )i_sub_1) * 190L,E_buf[i_sub_1],0,0,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
    }
{
      memcpy_wide_bus_read_float_4d_5_22_10_64(C_18_0_buf,0,0,0,0,(merlin_uint_64 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      memcpy_wide_bus_read_float_4d_10_35_6_64(D_18_0_buf,0,0,0,0,(merlin_uint_64 *)D,(0 * 4),sizeof(float ) * ((unsigned long )46200L),46200L);
    }
    merlinL19:
    for (i = 0; i < 38; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
{
      float F_buf[5][35][6];
      
#pragma HLS array_partition variable=F_buf cyclic factor=2 dim=3
{
        merlinL18:
        for (int i_sub_0 = 0; i_sub_0 < 5; ++i_sub_0) {
          memcpy_wide_bus_read_float_2d_6_64(F_buf[i_sub_0],(size_t )0,(size_t )0,(merlin_uint_64 *)F,(size_t )((((long )i) * 1050L + ((long )i_sub_0) * 210L) * ((long )4)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
      }
      merlinL17:
      for (int i_sub_0 = 0; i_sub_0 < 5; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL16:
        for (j = 0; j < 35; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
          merlinL15:
          for (int j_sub_0 = 0; j_sub_0 < 6; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
            F_buf[i_sub_0][j][j_sub_0] = ((float )0.0);
            merlinL14:
            for (k = 0; k < 22; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL13:
              for (int k_sub_0 = 0; k_sub_0 < 10; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
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
        merlinL12:
        for (int i_sub_0 = 0; i_sub_0 < 5; ++i_sub_0) {
          memcpy_wide_bus_write_float_2d_6_64((merlin_uint_64 *)F,F_buf[i_sub_0],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 1050L + ((long )i_sub_0) * 210L)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
      }
    }
{
      merlin_memcpy_3(E_19_0_buf,0,0,0,0,E,0,sizeof(float ) * ((unsigned long )34200L),136800UL);
    }
{
      memcpy_wide_bus_read_float_4d_10_35_6_64(F_19_0_buf,0,0,0,0,(merlin_uint_64 *)F,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL11:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float G_buf[6][35][6];
      
#pragma HLS array_partition variable=G_buf cyclic factor=2 dim=3
{
        merlinL10:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_read_float_2d_6_64(G_buf[i_sub],(size_t )0,(size_t )0,(merlin_uint_64 *)G,(size_t )((((long )i) * 1260L + ((long )i_sub) * 210L) * ((long )4)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=3 */
      }
      merlinL9:
      for (int i_sub = 0; i_sub < 6; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL8:
        for (j = 0; j < 35; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
          merlinL7:
          for (int j_sub = 0; j_sub < 6; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
            G_buf[i_sub][j][j_sub] = ((float )0.0);
            merlinL6:
            for (k = 0; k < 19; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL5:
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
        merlinL4:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_write_float_2d_6_64((merlin_uint_64 *)G,G_buf[i_sub],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 1260L + ((long )i_sub) * 210L)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=3 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_17_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_18_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_18_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=F_19_0_buf cyclic factor = 2 dim=4 */
}
