#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#define SIZE_1 10
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 12
#define SIZE_2 19
#define SIZE_3 10
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 12
#define SIZE_2 20
#define SIZE_3 10
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 10
#define SIZE_2 19
#define SIZE_3 10
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 10
#define SIZE_2 21
#define SIZE_3 10
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 11
#define SIZE_2 21
#define SIZE_3 10
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#include <string.h> 

#include "merlin_type_define.h"










/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[19][10][20][11],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[41800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 19 + dst_idx_0) * 10 + dst_idx_1) * 20 + dst_idx_2) * 11 + dst_idx_3;
  unsigned long total_offset2 = 0 * 41800 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=41800
    dst[(total_offset1 + i) / 11 / 20 / 10][(total_offset1 + i) / 11 / 20 % 10][(total_offset1 + i) / 11 % 20][(total_offset1 + i) % 11] = src[total_offset2 + i];
  }
}

void kernel_3mm(merlin_uint_64 E[17100],merlin_uint_64 A[18000],merlin_uint_64 B[19000],merlin_uint_64 F[19950],float C[41800],merlin_uint_64 D[23100],merlin_uint_64 G[18900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=18000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19000 bundle=merlin_gmem_kernel_3mm_64_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=41800 bundle=merlin_gmem_kernel_3mm_32_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=23100 bundle=merlin_gmem_kernel_3mm_64_2
  
#pragma HLS INTERFACE m_axi port=E offset=slave depth=17100 bundle=merlin_gmem_kernel_3mm_64_E
  
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
  
#pragma HLS DATA_PACK VARIABLE=F
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=E
  
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
    float B_17_0_buf[20][10][19][10];
    
#pragma HLS array_partition variable=B_17_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=B_17_0_buf complete dim=2
    float A_17_0_buf[15][12][20][10];
    
#pragma HLS array_partition variable=A_17_0_buf complete dim=4
    float D_18_0_buf[20][11][21][10];
    
#pragma HLS array_partition variable=D_18_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=D_18_0_buf complete dim=2
    float C_18_0_buf[19][10][20][11];
    
#pragma HLS array_partition variable=C_18_0_buf complete dim=4
    float F_19_0_buf[19][10][21][10];
    
#pragma HLS array_partition variable=F_19_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=F_19_0_buf complete dim=2
    float E_19_0_buf[15][12][19][10];
    
#pragma HLS array_partition variable=E_19_0_buf complete dim=4
{
      memcpy_wide_bus_read_float_4d_12_20_10_64(A_17_0_buf,0,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      memcpy_wide_bus_read_float_4d_10_19_10_64(B_17_0_buf,0,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )38000L),38000L);
    }
    merlinL24:
    for (i = 0; i < 15; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
{
      float E_buf[12][19][10];
      
#pragma HLS array_partition variable=E_buf cyclic factor=2 dim=3
{
        merlinL23:
        for (int i_sub_1 = 0; i_sub_1 < 12; ++i_sub_1) {
          memcpy_wide_bus_read_float_2d_10_64(E_buf[i_sub_1],(size_t )0,(size_t )0,(merlin_uint_64 *)E,(size_t )((((long )i) * 2280L + ((long )i_sub_1) * 190L) * ((long )4)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=3 */
      }
      merlinL22:
      for (int i_sub_1 = 0; i_sub_1 < 12; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL21:
        for (j = 0; j < 19; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
          merlinL20:
          for (int j_sub_1 = 0; j_sub_1 < 10; ++j_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
            E_buf[i_sub_1][j][j_sub_1] = ((float )0.0);
            merlinL19:
            for (k = 0; k < 20; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL18:
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
        merlinL17:
        for (int i_sub_1 = 0; i_sub_1 < 12; ++i_sub_1) {
          memcpy_wide_bus_write_float_2d_10_64((merlin_uint_64 *)E,E_buf[i_sub_1],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 2280L + ((long )i_sub_1) * 190L)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=3 */
      }
    }
{
      merlin_memcpy_0(C_18_0_buf,0,0,0,0,C,0,sizeof(float ) * ((unsigned long )41800L),167200UL);
    }
{
      memcpy_wide_bus_read_float_4d_11_21_10_64(D_18_0_buf,0,0,0,0,(merlin_uint_64 *)D,(0 * 4),sizeof(float ) * ((unsigned long )46200L),46200L);
    }
    merlinL16:
    for (i = 0; i < 19; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
      float F_buf[10][21][10];
      
#pragma HLS array_partition variable=F_buf cyclic factor=2 dim=3
{
        merlinL15:
        for (int i_sub_0 = 0; i_sub_0 < 10; ++i_sub_0) {
          memcpy_wide_bus_read_float_2d_10_64(F_buf[i_sub_0],(size_t )0,(size_t )0,(merlin_uint_64 *)F,(size_t )((((long )i) * 2100L + ((long )i_sub_0) * 210L) * ((long )4)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
      }
      merlinL14:
      for (int i_sub_0 = 0; i_sub_0 < 10; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL13:
        for (j = 0; j < 21; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
          merlinL12:
          for (int j_sub_0 = 0; j_sub_0 < 10; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
            F_buf[i_sub_0][j][j_sub_0] = ((float )0.0);
            merlinL11:
            for (k = 0; k < 20; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=11 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=11 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL10:
              for (int k_sub_0 = 0; k_sub_0 < 11; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=11 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=11 */
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
        merlinL9:
        for (int i_sub_0 = 0; i_sub_0 < 10; ++i_sub_0) {
          memcpy_wide_bus_write_float_2d_10_64((merlin_uint_64 *)F,F_buf[i_sub_0],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 2100L + ((long )i_sub_0) * 210L)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
      }
    }
{
      memcpy_wide_bus_read_float_4d_12_19_10_64(E_19_0_buf,0,0,0,0,(merlin_uint_64 *)E,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
    }
{
      memcpy_wide_bus_read_float_4d_10_21_10_64(F_19_0_buf,0,0,0,0,(merlin_uint_64 *)F,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL8:
    for (i = 0; i < 15; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
{
      float G_buf[12][21][10];
      
#pragma HLS array_partition variable=G_buf cyclic factor=2 dim=3
{
        merlinL7:
        for (int i_sub = 0; i_sub < 12; ++i_sub) {
          memcpy_wide_bus_read_float_2d_10_64(G_buf[i_sub],(size_t )0,(size_t )0,(merlin_uint_64 *)G,(size_t )((((long )i) * 2520L + ((long )i_sub) * 210L) * ((long )4)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=3 */
      }
      merlinL6:
      for (int i_sub = 0; i_sub < 12; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL5:
        for (j = 0; j < 21; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
          merlinL4:
          for (int j_sub = 0; j_sub < 10; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
            G_buf[i_sub][j][j_sub] = ((float )0.0);
            merlinL3:
            for (k = 0; k < 19; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL2:
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
        merlinL1:
        for (int i_sub = 0; i_sub < 12; ++i_sub) {
          memcpy_wide_bus_write_float_2d_10_64((merlin_uint_64 *)G,G_buf[i_sub],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 2520L + ((long )i_sub) * 210L)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=3 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_17_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_17_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_18_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=E_19_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=F_19_0_buf cyclic factor = 2 dim=4 */
}
