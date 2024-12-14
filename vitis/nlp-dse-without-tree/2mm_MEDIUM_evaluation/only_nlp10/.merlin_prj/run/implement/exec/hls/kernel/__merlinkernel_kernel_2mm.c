#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#define SIZE_1 6
#define SIZE_2 35
#define SIZE_3 6
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 6
#define SIZE_2 19
#define SIZE_3 10
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
#define SIZE_1 10
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[19][10],int dst_idx_1,int dst_idx_2,float src[34200],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 19 + dst_idx_1) * 10 + dst_idx_2;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[(total_offset1 + i) / 10][(total_offset1 + i) % 10] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[34200],long dst_idx_0,float src[19][10],int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 34200 + dst_idx_0;
  unsigned long total_offset2 = (0 * 19 + src_idx_1) * 10 + src_idx_2;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[total_offset1 + i] = src[(total_offset2 + i) / 10][(total_offset2 + i) % 10];
  }
}

static void merlin_memcpy_2(float dst[30][6][38][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[34200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 30 + dst_idx_0) * 6 + dst_idx_1) * 38 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=34200
    dst[(total_offset1 + i) / 5 / 38 / 6][(total_offset1 + i) / 5 / 38 % 6][(total_offset1 + i) / 5 % 38][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

void kernel_2mm(float alpha,float beta,float tmp[34200],merlin_uint_64 A[18900],merlin_uint_64 B[19950],merlin_uint_64 C[20900],merlin_uint_64 D[19800])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=18900 bundle=merlin_gmem_kernel_2mm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19950 bundle=merlin_gmem_kernel_2mm_64_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=20900 bundle=merlin_gmem_kernel_2mm_64_2
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=19800 bundle=merlin_gmem_kernel_2mm_64_D
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=34200 bundle=merlin_gmem_kernel_2mm_32_tmp
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=D bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=tmp bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=D
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=D depth=180,220 max_depth=180,220
  
#pragma ACCEL interface variable=C depth=190,220 max_depth=190,220
  
#pragma ACCEL interface variable=B depth=210,190 max_depth=210,190
  
#pragma ACCEL interface variable=A depth=180,210 max_depth=180,210
  
#pragma ACCEL interface variable=tmp depth=180,190 max_depth=180,190
  int i;
  int j;
  int k;
{
    float B_12_0_buf[35][6][19][10];
    
#pragma HLS array_partition variable=B_12_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=B_12_0_buf complete dim=2
    float A_12_0_buf[30][6][35][6];
    
#pragma HLS array_partition variable=A_12_0_buf complete dim=4
    float C_13_0_buf[38][5][22][10];
    
#pragma HLS array_partition variable=C_13_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=C_13_0_buf complete dim=2
    float tmp_13_0_buf[30][6][38][5];
    
#pragma HLS array_partition variable=tmp_13_0_buf complete dim=4
{
      memcpy_wide_bus_read_float_4d_6_35_6_64(A_12_0_buf,0,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    }
{
      memcpy_wide_bus_read_float_4d_6_19_10_64(B_12_0_buf,0,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL18:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float tmp_buf[6][19][10];
{
        merlinL17:
        for (int i_sub_0 = 0; i_sub_0 < 6; ++i_sub_0) {
          merlin_memcpy_0(tmp_buf[i_sub_0],0,0,tmp,((long )i) * 1140L + ((long )i_sub_0) * 190L,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
      merlinL16:
      for (int i_sub_0 = 0; i_sub_0 < 6; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL15:
        for (j = 0; j < 19; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
          merlinL14:
          for (int j_sub_0 = 0; j_sub_0 < 10; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
            tmp_buf[i_sub_0][j][j_sub_0] = ((float )0.0);
            merlinL13:
            for (k = 0; k < 35; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL12:
              for (int k_sub_0 = 0; k_sub_0 < 6; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
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
        merlinL11:
        for (int i_sub_0 = 0; i_sub_0 < 6; ++i_sub_0) {
          merlin_memcpy_1(tmp,((long )i) * 1140L + ((long )i_sub_0) * 190L,tmp_buf[i_sub_0],0,0,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
    }
{
      merlin_memcpy_2(tmp_13_0_buf,0,0,0,0,tmp,0,sizeof(float ) * ((unsigned long )34200L),136800UL);
    }
{
      memcpy_wide_bus_read_float_4d_5_22_10_64(C_13_0_buf,0,0,0,0,(merlin_uint_64 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
    merlinL10:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float D_buf[6][22][10];
      
#pragma HLS array_partition variable=D_buf cyclic factor=2 dim=3
{
        merlinL9:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_read_float_2d_10_64(D_buf[i_sub],(size_t )0,(size_t )0,(merlin_uint_64 *)D,(size_t )((((long )i) * 1320L + ((long )i_sub) * 220L) * ((long )4)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 2 dim=3 */
      }
      merlinL8:
      for (int i_sub = 0; i_sub < 6; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL7:
        for (j = 0; j < 22; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
          merlinL6:
          for (int j_sub = 0; j_sub < 10; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
            D_buf[i_sub][j][j_sub] *= beta;
            merlinL5:
            for (k = 0; k < 38; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL4:
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
        merlinL3:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_write_float_2d_10_64((merlin_uint_64 *)D,D_buf[i_sub],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 1320L + ((long )i_sub) * 220L)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 2 dim=3 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_12_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_12_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_13_0_buf cyclic factor = 2 dim=4 */
}
