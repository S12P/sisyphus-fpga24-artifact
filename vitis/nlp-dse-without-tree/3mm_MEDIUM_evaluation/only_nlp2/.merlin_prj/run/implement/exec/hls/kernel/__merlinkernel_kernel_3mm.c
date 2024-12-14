#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_256_1d.h"
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
#define SIZE_1 35
#define SIZE_2 6
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 220
#include "memcpy_128_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"










/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[200][38][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[38000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 200 + dst_idx_0) * 38 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 38000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=38000
    dst[(total_offset1 + i) / 5 / 38][(total_offset1 + i) / 5 % 38][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

void kernel_3mm(merlin_uint_64 E[17100],merlin_uint_256 A[4500],float B[38000],merlin_uint_64 F[19950],merlin_uint_128 C[10450],merlin_uint_64 D[23100],merlin_uint_64 G[18900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=4500 bundle=merlin_gmem_kernel_3mm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=38000 bundle=merlin_gmem_kernel_3mm_32_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_3mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=23100 bundle=merlin_gmem_kernel_3mm_64_0
  
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
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma HLS DATA_PACK VARIABLE=F
  
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
    float B_11_0_buf[200][38][5];
    
#pragma HLS array_partition variable=B_11_0_buf complete dim=3
    
#pragma HLS array_partition variable=B_11_0_buf complete dim=1
    float A_11_0_buf[180][200];
    
#pragma HLS array_partition variable=A_11_0_buf complete dim=2
    float D_12_0_buf[220][35][6];
    
#pragma HLS array_partition variable=D_12_0_buf complete dim=3
    
#pragma HLS array_partition variable=D_12_0_buf complete dim=1
    float C_12_0_buf[190][220];
    
#pragma HLS array_partition variable=C_12_0_buf complete dim=2
    float G_buf[180][35][6];
    
#pragma HLS array_partition variable=G_buf complete dim=3
    float F_buf[190][35][6];
    
#pragma HLS array_partition variable=F_buf complete dim=3
    
#pragma HLS array_partition variable=F_buf complete dim=1
    float E_buf[180][190];
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=E_buf complete dim=2
    memcpy_wide_bus_read_float_2d_190_64(E_buf,0,0,(merlin_uint_64 *)E,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_read_float_3d_35_6_64(F_buf,0,0,0,(merlin_uint_64 *)F,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
{
      memcpy_wide_bus_read_float_2d_200_256(A_11_0_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      merlin_memcpy_0(B_11_0_buf,0,0,0,B,0,sizeof(float ) * ((unsigned long )38000L),152000UL);
    }
    merlinL12:
    for (i = 0; i < 180; i++) {
      merlinL11:
      for (j = 0; j < 38; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=E_buf array inter false
        
#pragma HLS pipeline
        merlinL10:
        for (int j_sub_1 = 0; j_sub_1 < 5; ++j_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          E_buf[i][((long )j) * 5L + ((long )j_sub_1)] = ((float )0.0);
          merlinL9:
          for (k = 0; k < 200; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            E_buf[i][((long )j) * 5L + ((long )j_sub_1)] += A_11_0_buf[i][k] * B_11_0_buf[k][j][j_sub_1];
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_2d_220_128(C_12_0_buf,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      memcpy_wide_bus_read_float_3d_35_6_64(D_12_0_buf,0,0,0,(merlin_uint_64 *)D,(0 * 4),sizeof(float ) * ((unsigned long )46200L),46200L);
    }
    merlinL8:
    for (i = 0; i < 190; i++) {
      merlinL7:
      for (j = 0; j < 35; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=F_buf array inter false
        
#pragma HLS pipeline
        merlinL6:
        for (int j_sub_0 = 0; j_sub_0 < 6; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          F_buf[i][j][j_sub_0] = ((float )0.0);
          merlinL5:
          for (k = 0; k < 220; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=220 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            F_buf[i][j][j_sub_0] += C_12_0_buf[i][k] * D_12_0_buf[k][j][j_sub_0];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_read_float_3d_35_6_64(G_buf,0,0,0,(merlin_uint_64 *)G,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    merlinL4:
    for (i = 0; i < 180; i++) {
      merlinL3:
      for (j = 0; j < 35; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=G_buf array inter false
        
#pragma HLS pipeline
        merlinL2:
        for (int j_sub = 0; j_sub < 6; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          G_buf[i][j][j_sub] = ((float )0.0);
          merlinL1:
          for (k = 0; k < 190; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=190 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            G_buf[i][j][j_sub] += E_buf[i][k] * F_buf[k][j][j_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_write_float_3d_35_6_64((merlin_uint_64 *)G,G_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )37800L),37800L);
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_190_64((merlin_uint_64 *)E,E_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )34200L),34200L);
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_write_float_3d_35_6_64((merlin_uint_64 *)F,F_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )39900L),39900L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_11_0_buf cyclic factor = 8 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_12_0_buf cyclic factor = 4 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_12_0_buf cyclic factor = 2 dim=3 */
}
