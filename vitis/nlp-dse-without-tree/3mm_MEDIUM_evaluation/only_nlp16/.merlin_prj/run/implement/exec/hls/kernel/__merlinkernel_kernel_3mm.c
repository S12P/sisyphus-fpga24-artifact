#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 20
#define SIZE_2 10
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 10
#define SIZE_2 190
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 220
#include "memcpy_128_2d.h"
#undef SIZE_1
#define SIZE_1 1
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"











/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[220][14][15],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[46200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 220 + dst_idx_0) * 14 + dst_idx_1) * 15 + dst_idx_2;
  unsigned long total_offset2 = 0 * 46200 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=46200
    dst[(total_offset1 + i) / 15 / 14][(total_offset1 + i) / 15 % 14][(total_offset1 + i) % 15] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[15][1],int dst_idx_0,int dst_idx_1,float src[39900],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 15 + dst_idx_0) * 1 + dst_idx_1;
  unsigned long total_offset2 = 0 * 39900 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=15
    dst[(total_offset1 + i) / 1][(total_offset1 + i) % 1] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[39900],long dst_idx_0,float src[15][1],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 39900 + dst_idx_0;
  unsigned long total_offset2 = (0 * 15 + src_idx_0) * 1 + src_idx_1;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=15
    dst[total_offset1 + i] = src[(total_offset2 + i) / 1][(total_offset2 + i) % 1];
  }
}

static void merlin_memcpy_3(float dst[190][14][15],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[39900],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 190 + dst_idx_0) * 14 + dst_idx_1) * 15 + dst_idx_2;
  unsigned long total_offset2 = 0 * 39900 + src_idx_0;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=39900
    dst[(total_offset1 + i) / 15 / 14][(total_offset1 + i) / 15 % 14][(total_offset1 + i) % 15] = src[total_offset2 + i];
  }
}

void kernel_3mm(merlin_uint_64 E[17100],merlin_uint_64 A[18000],merlin_uint_64 B[19000],float F[39900],merlin_uint_128 C[10450],float D[46200],merlin_uint_512 G[2363])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=18000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19000 bundle=merlin_gmem_kernel_3mm_64_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_3mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=46200 bundle=merlin_gmem_kernel_3mm_32_0
  
#pragma HLS INTERFACE m_axi port=E offset=slave depth=17100 bundle=merlin_gmem_kernel_3mm_64_E
  
#pragma HLS INTERFACE m_axi port=F offset=slave depth=39900 bundle=merlin_gmem_kernel_3mm_32_F
  
#pragma HLS INTERFACE m_axi port=G offset=slave depth=2363 bundle=merlin_gmem_kernel_3mm_512_G
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=D bundle=control
  
#pragma HLS INTERFACE s_axilite port=E bundle=control
  
#pragma HLS INTERFACE s_axilite port=F bundle=control
  
#pragma HLS INTERFACE s_axilite port=G bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=G
  
#pragma HLS DATA_PACK VARIABLE=C
  
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
    float B_11_0_buf[20][10][190];
    
#pragma HLS array_partition variable=B_11_0_buf cyclic factor=2 dim=3
    
#pragma HLS array_partition variable=B_11_0_buf complete dim=2
    float A_11_0_buf[180][20][10];
    
#pragma HLS array_partition variable=A_11_0_buf complete dim=3
    float D_12_0_buf[220][14][15];
    float C_12_0_buf[190][220];
    
#pragma HLS array_partition variable=C_12_0_buf cyclic factor=4 dim=2
    float F_13_0_buf[190][14][15];
    float E_buf[180][190];
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=E_buf cyclic factor=2 dim=2
    memcpy_wide_bus_read_float_2d_190_64(E_buf,0,0,(merlin_uint_64 *)E,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
{
      memcpy_wide_bus_read_float_3d_20_10_64(A_11_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      memcpy_wide_bus_read_float_3d_10_190_64(B_11_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )38000L),38000L);
    }
    merlinL15:
    for (i = 0; i < 180; i++) {
      merlinL14:
      for (j = 0; j < 190; j++) {
        E_buf[i][j] = ((float )0.0);
        merlinL13:
        for (k = 0; k < 20; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS pipeline
          merlinL12:
          for (int k_sub = 0; k_sub < 10; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            E_buf[i][j] += A_11_0_buf[i][k][k_sub] * B_11_0_buf[k][k_sub][j];
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_2d_220_128(C_12_0_buf,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      merlin_memcpy_0(D_12_0_buf,0,0,0,D,0,sizeof(float ) * ((unsigned long )46200L),184800UL);
    }
    merlinL11:
    for (i = 0; i < 190; i++) {
      merlinL10:
      for (j = 0; j < 14; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
{
        float F_buf[15][1];
{
          merlin_memcpy_1(F_buf,0,0,F,((long )i) * 210L + ((long )(j * 15)),sizeof(float ) * ((unsigned long )15L),60UL);
        }
        merlinL9:
        for (int j_sub_0 = 0; j_sub_0 < 15; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL */
{
          F_buf[((long )j_sub_0) - 0L][0] = ((float )0.0);
          merlinL8:
          for (k = 0; k < 220; ++k) 
/* Original: #pragma ACCEL PIPELINE AUTO */
{
            
#pragma HLS pipeline
            F_buf[((long )j_sub_0) - 0L][0] += C_12_0_buf[i][k] * D_12_0_buf[k][j][j_sub_0];
          }
        }
{
          merlin_memcpy_2(F,((long )i) * 210L + ((long )(j * 15)),F_buf,0,0,sizeof(float ) * ((unsigned long )15L),60UL);
        }
      }
    }
{
      merlin_memcpy_3(F_13_0_buf,0,0,0,F,0,sizeof(float ) * ((unsigned long )39900L),159600UL);
    }
    merlinL7:
    for (i = 0; i < 180; i++) {
      merlinL6:
      for (j = 0; j < 14; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
{
        float G_buf[15][1];
        
#pragma HLS array_partition variable=G_buf complete dim=2
        
#pragma HLS array_partition variable=G_buf complete dim=1
{
          memcpy_wide_bus_read_float_2d_1_512(G_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)G,(size_t )((((long )i) * 210L + ((long )(j * 15))) * ((long )4)),sizeof(float ) * ((unsigned long )15L),(size_t )15L);
        }
        merlinL5:
        for (int j_sub = 0; j_sub < 15; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL */
{
          G_buf[((long )j_sub) - 0L][0] = ((float )0.0);
          merlinL4:
          for (k = 0; k < 190; ++k) 
/* Original: #pragma ACCEL PIPELINE AUTO */
{
            
#pragma HLS pipeline
            G_buf[((long )j_sub) - 0L][0] += E_buf[i][k] * F_13_0_buf[k][j][j_sub];
          }
        }
{
          memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)G,G_buf,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 210L + ((long )(j * 15)))),sizeof(float ) * ((unsigned long )15L),(size_t )15L);
        }
      }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf complete dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf complete dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 1 dim=0 */
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 1 dim=0 */
    }
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_190_64((merlin_uint_64 *)E,E_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )34200L),34200L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_11_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_11_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_12_0_buf cyclic factor = 4 dim=2 */
}
