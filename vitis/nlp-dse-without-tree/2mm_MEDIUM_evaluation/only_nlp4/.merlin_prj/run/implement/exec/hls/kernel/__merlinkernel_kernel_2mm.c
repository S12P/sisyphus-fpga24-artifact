#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#define SIZE_1 2
#define SIZE_2 210
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 5
#define SIZE_2 5
#define SIZE_3 44
#include "memcpy_128_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 44
#include "memcpy_128_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"









/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[190],int dst_idx_1,float src[34200],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = 0 * 190 + dst_idx_1;
  unsigned long total_offset2 = 0 * 34200 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[total_offset1 + i] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[34200],long dst_idx_0,float src[190],int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 34200 + dst_idx_0;
  unsigned long total_offset2 = 0 * 190 + src_idx_1;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=190
    dst[total_offset1 + i] = src[total_offset2 + i];
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

void kernel_2mm(float alpha,float beta,float tmp[34200],merlin_uint_64 A[18900],merlin_uint_64 B[19950],merlin_uint_128 C[10450],merlin_uint_128 D[9900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=18900 bundle=merlin_gmem_kernel_2mm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19950 bundle=merlin_gmem_kernel_2mm_64_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_2mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=9900 bundle=merlin_gmem_kernel_2mm_128_D
  
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
    float B_8_0_buf[210][190];
    
#pragma HLS array_partition variable=B_8_0_buf cyclic factor=2 dim=2
    
#pragma HLS array_partition variable=B_8_0_buf complete dim=1
    float A_8_0_buf[90][2][210];
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=3
    float C_11_0_buf[38][5][5][44];
    
#pragma HLS array_partition variable=C_11_0_buf cyclic factor=4 dim=4
    
#pragma HLS array_partition variable=C_11_0_buf complete dim=2
    float tmp_11_0_buf[30][6][38][5];
    
#pragma HLS array_partition variable=tmp_11_0_buf complete dim=4
{
      memcpy_wide_bus_read_float_3d_2_210_64(A_8_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    }
{
      memcpy_wide_bus_read_float_2d_190_64(B_8_0_buf,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL16:
    for (i = 0; i < 90; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      float tmp_buf[2][190];
{
        merlinL15:
        for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) {
          merlin_memcpy_0(tmp_buf[((long )i_sub_0) - 0L],0,tmp,((long )i) * 380L + ((long )i_sub_0) * 190L,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
      merlinL14:
      for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL13:
        for (j = 0; j < 190; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=tmp_buf array inter false
          
#pragma HLS pipeline
          tmp_buf[((long )i_sub_0) - 0L][j] = ((float )0.0);
          merlinL12:
          for (k = 0; k < 210; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=210 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            tmp_buf[((long )i_sub_0) - 0L][j] += alpha * A_8_0_buf[i][i_sub_0][k] * B_8_0_buf[k][j];
          }
        }
      }
{
        merlinL11:
        for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) {
          merlin_memcpy_1(tmp,((long )i) * 380L + ((long )i_sub_0) * 190L,tmp_buf[((long )i_sub_0) - 0L],0,sizeof(float ) * ((unsigned long )190L),760UL);
        }
      }
    }
{
      merlin_memcpy_2(tmp_11_0_buf,0,0,0,0,tmp,0,sizeof(float ) * ((unsigned long )34200L),136800UL);
    }
{
      memcpy_wide_bus_read_float_4d_5_5_44_128(C_11_0_buf,0,0,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
    merlinL10:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float D_buf[6][5][44];
      
#pragma HLS array_partition variable=D_buf cyclic factor=4 dim=3
{
        merlinL9:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_read_float_2d_44_128(D_buf[i_sub],(size_t )0,(size_t )0,(merlin_uint_128 *)D,(size_t )((((long )i) * 1320L + ((long )i_sub) * 220L) * ((long )4)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 4 dim=3 */
      }
      merlinL8:
      for (int i_sub = 0; i_sub < 6; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL7:
        for (j = 0; j < 5; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=44 */
/* Original: #pragma ACCEL PARALLEL FACTOR=44 */
{
          merlinL6:
          for (int j_sub = 0; j_sub < 44; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=44 */
/* Original: #pragma ACCEL PARALLEL FACTOR=44 */
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
                D_buf[i_sub][j][j_sub] += tmp_11_0_buf[i][i_sub][k][k_sub] * C_11_0_buf[k][k_sub][j][j_sub];
              }
            }
          }
        }
      }
{
        merlinL3:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_write_float_2d_44_128((merlin_uint_128 *)D,D_buf[i_sub],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 1320L + ((long )i_sub) * 220L)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 4 dim=3 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_8_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_11_0_buf cyclic factor = 4 dim=4 */
}
