#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 6
#define SIZE_2 190
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 6
#define SIZE_2 200
#include "memcpy_256_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 210
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 2
#define SIZE_2 220
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"












/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[220][70][3],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[46200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 220 + dst_idx_0) * 70 + dst_idx_1) * 3 + dst_idx_2;
  unsigned long total_offset2 = 0 * 46200 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=46200
    dst[(total_offset1 + i) / 3 / 70][(total_offset1 + i) / 3 % 70][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

void kernel_3mm(merlin_uint_64 E[17100],merlin_uint_256 A[4500],merlin_uint_64 B[19000],merlin_uint_64 F[19950],merlin_uint_128 C[10450],float D[46200],merlin_uint_512 G[2363])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=4500 bundle=merlin_gmem_kernel_3mm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_3mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=46200 bundle=merlin_gmem_kernel_3mm_32_0
  
#pragma HLS INTERFACE m_axi port=E offset=slave depth=17100 bundle=merlin_gmem_kernel_3mm_64_E
  
#pragma HLS INTERFACE m_axi port=F offset=slave depth=19950 bundle=merlin_gmem_kernel_3mm_64_F
  
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
    float B_11_0_buf[200][190];
    
#pragma HLS array_partition variable=B_11_0_buf cyclic factor=2 dim=2
    
#pragma HLS array_partition variable=B_11_0_buf complete dim=1
    float A_11_0_buf[30][6][200];
    
#pragma HLS array_partition variable=A_11_0_buf complete dim=3
    float E_13_0_buf[30][6][190];
    
#pragma HLS array_partition variable=E_13_0_buf complete dim=3
    float D_14_0_buf[220][70][3];
    
#pragma HLS array_partition variable=D_14_0_buf complete dim=3
    
#pragma HLS array_partition variable=D_14_0_buf complete dim=1
    float C_14_0_buf[95][2][220];
    
#pragma HLS array_partition variable=C_14_0_buf complete dim=3
    
#pragma HLS array_partition variable=C_14_0_buf complete dim=2
    float F_buf[190][210];
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=F_buf cyclic factor=3 dim=2
    
#pragma HLS array_partition variable=F_buf complete dim=1
    memcpy_wide_bus_read_float_2d_210_64(F_buf,0,0,(merlin_uint_64 *)F,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
{
      memcpy_wide_bus_read_float_3d_6_200_256(A_11_0_buf,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      memcpy_wide_bus_read_float_2d_190_64(B_11_0_buf,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )38000L),38000L);
    }
    merlinL17:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float E_buf[6][190];
      
#pragma HLS array_partition variable=E_buf cyclic factor=2 dim=2
{
        merlinL16:
        for (int i_sub_1 = 0; i_sub_1 < 6; ++i_sub_1) {
          memcpy_wide_bus_read_float_64(E_buf[((long )i_sub_1) - 0L],(merlin_uint_64 *)E,(size_t )((((long )i) * 1140L + ((long )i_sub_1) * 190L) * ((long )4)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
      }
      merlinL15:
      for (int i_sub_1 = 0; i_sub_1 < 6; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL14:
        for (j = 0; j < 190; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=E_buf array inter false
          
#pragma HLS pipeline
          E_buf[((long )i_sub_1) - 0L][j] = ((float )0.0);
          merlinL13:
          for (k = 0; k < 200; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            E_buf[((long )i_sub_1) - 0L][j] += A_11_0_buf[i][i_sub_1][k] * B_11_0_buf[k][j];
          }
        }
      }
{
        merlinL12:
        for (int i_sub_1 = 0; i_sub_1 < 6; ++i_sub_1) {
          memcpy_wide_bus_write_float_64((merlin_uint_64 *)E,E_buf[((long )i_sub_1) - 0L],(size_t )(((long )4) * (((long )i) * 1140L + ((long )i_sub_1) * 190L)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
      }
    }
{
      memcpy_wide_bus_read_float_3d_2_220_128(C_14_0_buf,0,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      merlin_memcpy_0(D_14_0_buf,0,0,0,D,0,sizeof(float ) * ((unsigned long )46200L),184800UL);
    }
    merlinL11:
    for (i = 0; i < 95; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      merlinL10:
      for (j = 0; j < 70; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=F_buf array inter false
        
#pragma HLS pipeline
        merlinL9:
        for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL8:
          for (int j_sub = 0; j_sub < 3; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            F_buf[((long )i) * 2L + ((long )i_sub_0)][((long )j) * 3L + ((long )j_sub)] = ((float )0.0);
            merlinL7:
            for (k = 0; k < 220; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=220 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
              
#pragma HLS unroll
              F_buf[((long )i) * 2L + ((long )i_sub_0)][((long )j) * 3L + ((long )j_sub)] += C_14_0_buf[i][i_sub_0][k] * D_14_0_buf[k][j][j_sub];
            }
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_3d_6_190_64(E_13_0_buf,0,0,0,(merlin_uint_64 *)E,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
    }
    merlinL6:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float G_buf[6][210];
      
#pragma HLS array_partition variable=G_buf cyclic factor=16 dim=2
{
        merlinL5:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_read_float_512(G_buf[((long )i_sub) - 0L],(merlin_uint_512 *)G,(size_t )((((long )i) * 1260L + ((long )i_sub) * 210L) * ((long )4)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 16 dim=2 */
      }
      merlinL4:
      for (int i_sub = 0; i_sub < 6; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL3:
        for (j = 0; j < 210; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=G_buf array inter false
          
#pragma HLS pipeline
          G_buf[((long )i_sub) - 0L][j] = ((float )0.0);
          merlinL2:
          for (k = 0; k < 190; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=190 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            G_buf[((long )i_sub) - 0L][j] += E_13_0_buf[i][i_sub][k] * F_buf[k][j];
          }
        }
      }
{
        merlinL1:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_write_float_512((merlin_uint_512 *)G,G_buf[((long )i_sub) - 0L],(size_t )(((long )4) * (((long )i) * 1260L + ((long )i_sub) * 210L)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 16 dim=2 */
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_210_64((merlin_uint_64 *)F,F_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )39900L),39900L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_11_0_buf cyclic factor = 8 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_11_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_14_0_buf cyclic factor = 4 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=E_13_0_buf cyclic factor = 2 dim=3 */
}
