#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_256_1d.h"
#define SIZE_1 3
#define SIZE_2 190
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 3
#define SIZE_2 200
#include "memcpy_256_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 95
#define SIZE_2 2
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 210
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 2
#define SIZE_2 220
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 3
#define SIZE_2 105
#define SIZE_3 2
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
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

void kernel_3mm(merlin_uint_64 E[17100],merlin_uint_256 A[4500],merlin_uint_64 B[19000],merlin_uint_64 F[19950],merlin_uint_128 C[10450],float D[46200],merlin_uint_64 G[18900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=4500 bundle=merlin_gmem_kernel_3mm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_3mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=46200 bundle=merlin_gmem_kernel_3mm_32_0
  
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
    float B_14_0_buf[200][95][2];
    
#pragma HLS array_partition variable=B_14_0_buf complete dim=3
    
#pragma HLS array_partition variable=B_14_0_buf complete dim=1
    float A_14_0_buf[60][3][200];
    
#pragma HLS array_partition variable=A_14_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_14_0_buf complete dim=2
    float D_15_0_buf[220][70][3];
    
#pragma HLS array_partition variable=D_15_0_buf complete dim=3
    
#pragma HLS array_partition variable=D_15_0_buf complete dim=1
    float C_15_0_buf[95][2][220];
    
#pragma HLS array_partition variable=C_15_0_buf complete dim=3
    
#pragma HLS array_partition variable=C_15_0_buf complete dim=2
    float G_buf[60][3][105][2];
    
#pragma HLS array_partition variable=G_buf complete dim=4
    
#pragma HLS array_partition variable=G_buf complete dim=2
    float F_buf[190][210];
    
#pragma HLS array_partition variable=F_buf cyclic factor=3 dim=2
    
#pragma HLS array_partition variable=F_buf complete dim=1
    float E_buf[60][3][190];
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=3 */
    
#pragma HLS array_partition variable=E_buf complete dim=3
    
#pragma HLS array_partition variable=E_buf complete dim=2
    memcpy_wide_bus_read_float_3d_3_190_64(E_buf,0,0,0,(merlin_uint_64 *)E,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_read_float_2d_210_64(F_buf,0,0,(merlin_uint_64 *)F,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
{
      memcpy_wide_bus_read_float_3d_3_200_256(A_14_0_buf,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      memcpy_wide_bus_read_float_3d_95_2_64(B_14_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )38000L),38000L);
    }
    merlinL15:
    for (i = 0; i < 60; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
{
      merlinL14:
      for (j = 0; j < 95; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=E_buf array inter false
        
#pragma HLS pipeline
        merlinL13:
        for (int i_sub_1 = 0; i_sub_1 < 3; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL12:
          for (int j_sub_1 = 0; j_sub_1 < 2; ++j_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            E_buf[i][i_sub_1][((long )j) * 2L + ((long )j_sub_1)] = ((float )0.0);
            merlinL11:
            for (k = 0; k < 200; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
              
#pragma HLS unroll
              E_buf[i][i_sub_1][((long )j) * 2L + ((long )j_sub_1)] += A_14_0_buf[i][i_sub_1][k] * B_14_0_buf[k][j][j_sub_1];
            }
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_3d_2_220_128(C_15_0_buf,0,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      merlin_memcpy_0(D_15_0_buf,0,0,0,D,0,sizeof(float ) * ((unsigned long )46200L),184800UL);
    }
    merlinL10:
    for (i = 0; i < 95; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      merlinL9:
      for (j = 0; j < 70; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=F_buf array inter false
        
#pragma HLS pipeline
        merlinL8:
        for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL7:
          for (int j_sub_0 = 0; j_sub_0 < 3; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            F_buf[((long )i) * 2L + ((long )i_sub_0)][((long )j) * 3L + ((long )j_sub_0)] = ((float )0.0);
            merlinL6:
            for (k = 0; k < 220; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=220 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
              
#pragma HLS unroll
              F_buf[((long )i) * 2L + ((long )i_sub_0)][((long )j) * 3L + ((long )j_sub_0)] += C_15_0_buf[i][i_sub_0][k] * D_15_0_buf[k][j][j_sub_0];
            }
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=4 */
    memcpy_wide_bus_read_float_4d_3_105_2_64(G_buf,0,0,0,0,(merlin_uint_64 *)G,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    merlinL5:
    for (i = 0; i < 60; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
{
      merlinL4:
      for (j = 0; j < 105; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=G_buf array inter false
        
#pragma HLS pipeline
        merlinL3:
        for (int i_sub = 0; i_sub < 3; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL2:
          for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            G_buf[i][i_sub][j][j_sub] = ((float )0.0);
            merlinL1:
            for (k = 0; k < 190; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=190 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
              
#pragma HLS unroll
              G_buf[i][i_sub][j][j_sub] += E_buf[i][i_sub][k] * F_buf[k][((long )j) * 2L + ((long )j_sub)];
            }
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=4 */
    memcpy_wide_bus_write_float_4d_3_105_2_64((merlin_uint_64 *)G,G_buf,0,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )37800L),37800L);
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_write_float_3d_3_190_64((merlin_uint_64 *)E,E_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )34200L),34200L);
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_210_64((merlin_uint_64 *)F,F_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )39900L),39900L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_14_0_buf cyclic factor = 8 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_14_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_15_0_buf cyclic factor = 4 dim=3 */
}
