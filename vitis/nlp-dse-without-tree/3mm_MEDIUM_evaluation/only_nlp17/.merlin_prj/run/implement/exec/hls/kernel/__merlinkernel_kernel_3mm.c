#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 2
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 4
#define SIZE_2 95
#define SIZE_3 2
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#define SIZE_2 50
#define SIZE_3 4
#include "memcpy_256_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#define SIZE_2 105
#define SIZE_3 2
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#define SIZE_2 55
#define SIZE_3 4
#include "memcpy_128_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 4
#define SIZE_2 105
#define SIZE_3 2
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"














/* Original: #pragma ACCEL kernel */

void kernel_3mm(merlin_uint_64 E[17100],merlin_uint_256 A[4500],merlin_uint_64 B[19000],merlin_uint_64 F[19950],merlin_uint_128 C[10450],merlin_uint_64 D[23100],merlin_uint_512 G[2363])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=4500 bundle=merlin_gmem_kernel_3mm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_3mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=23100 bundle=merlin_gmem_kernel_3mm_64_1
  
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
  
#pragma HLS DATA_PACK VARIABLE=D
  
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
    float B_17_0_buf[50][4][95][2];
    
#pragma HLS array_partition variable=B_17_0_buf complete dim=4
    
#pragma HLS array_partition variable=B_17_0_buf complete dim=2
    float A_17_0_buf[90][2][50][4];
    
#pragma HLS array_partition variable=A_17_0_buf complete dim=4
    
#pragma HLS array_partition variable=A_17_0_buf cyclic factor=2 dim=3
    float D_18_0_buf[55][4][105][2];
    
#pragma HLS array_partition variable=D_18_0_buf complete dim=4
    
#pragma HLS array_partition variable=D_18_0_buf complete dim=2
    float C_18_0_buf[95][2][55][4];
    
#pragma HLS array_partition variable=C_18_0_buf complete dim=4
    float F_19_0_buf[95][2][105][2];
    
#pragma HLS array_partition variable=F_19_0_buf complete dim=4
    
#pragma HLS array_partition variable=F_19_0_buf complete dim=2
    float E_19_0_buf[45][4][95][2];
    
#pragma HLS array_partition variable=E_19_0_buf complete dim=4
{
      memcpy_wide_bus_read_float_4d_2_50_4_256(A_17_0_buf,0,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      memcpy_wide_bus_read_float_4d_4_95_2_64(B_17_0_buf,0,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )38000L),38000L);
    }
    merlinL23:
    for (i = 0; i < 90; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      float E_buf[2][95][2];
      
#pragma HLS array_partition variable=E_buf complete dim=3
{
        merlinL22:
        for (int i_sub_1 = 0; i_sub_1 < 2; ++i_sub_1) {
          memcpy_wide_bus_read_float_2d_2_64(E_buf[i_sub_1],(size_t )0,(size_t )0,(merlin_uint_64 *)E,(size_t )((((long )i) * 380L + ((long )i_sub_1) * 190L) * ((long )4)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=3 */
      }
      merlinL21:
      for (int i_sub_1 = 0; i_sub_1 < 2; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL20:
        for (j = 0; j < 95; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
          merlinL19:
          for (int j_sub_1 = 0; j_sub_1 < 2; ++j_sub_1) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            E_buf[i_sub_1][j][j_sub_1] = ((float )0.0);
            merlinL18:
            for (k = 0; k < 50; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL17:
              for (int k_sub_1 = 0; k_sub_1 < 4; ++k_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
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
        merlinL16:
        for (int i_sub_1 = 0; i_sub_1 < 2; ++i_sub_1) {
          memcpy_wide_bus_write_float_2d_2_64((merlin_uint_64 *)E,E_buf[i_sub_1],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 380L + ((long )i_sub_1) * 190L)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=3 */
      }
    }
{
      memcpy_wide_bus_read_float_4d_2_55_4_128(C_18_0_buf,0,0,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      memcpy_wide_bus_read_float_4d_4_105_2_64(D_18_0_buf,0,0,0,0,(merlin_uint_64 *)D,(0 * 4),sizeof(float ) * ((unsigned long )46200L),46200L);
    }
    merlinL15:
    for (i = 0; i < 95; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      float F_buf[2][105][2];
      
#pragma HLS array_partition variable=F_buf complete dim=3
{
        merlinL14:
        for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) {
          memcpy_wide_bus_read_float_2d_2_64(F_buf[i_sub_0],(size_t )0,(size_t )0,(merlin_uint_64 *)F,(size_t )((((long )i) * 420L + ((long )i_sub_0) * 210L) * ((long )4)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
      }
      merlinL13:
      for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL12:
        for (j = 0; j < 105; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
          merlinL11:
          for (int j_sub_0 = 0; j_sub_0 < 2; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            F_buf[i_sub_0][j][j_sub_0] = ((float )0.0);
            merlinL10:
            for (k = 0; k < 55; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL9:
              for (int k_sub_0 = 0; k_sub_0 < 4; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
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
        merlinL8:
        for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) {
          memcpy_wide_bus_write_float_2d_2_64((merlin_uint_64 *)F,F_buf[i_sub_0],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 420L + ((long )i_sub_0) * 210L)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
      }
    }
{
      memcpy_wide_bus_read_float_4d_4_95_2_64(E_19_0_buf,0,0,0,0,(merlin_uint_64 *)E,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
    }
{
      memcpy_wide_bus_read_float_4d_2_105_2_64(F_19_0_buf,0,0,0,0,(merlin_uint_64 *)F,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL7:
    for (i = 0; i < 45; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
{
      float G_buf[4][105][2];
      
#pragma HLS array_partition variable=G_buf complete dim=3
      
#pragma HLS array_partition variable=G_buf cyclic factor=8 dim=2
{
        merlinL6:
        for (int i_sub = 0; i_sub < 4; ++i_sub) {
          memcpy_wide_bus_read_float_2d_2_512(G_buf[i_sub],(size_t )0,(size_t )0,(merlin_uint_512 *)G,(size_t )((((long )i) * 840L + ((long )i_sub) * 210L) * ((long )4)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 8 dim=2 */
      }
      merlinL5:
      for (int i_sub = 0; i_sub < 4; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL4:
        for (j = 0; j < 105; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
          merlinL3:
          for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            G_buf[i_sub][j][j_sub] = ((float )0.0);
            merlinL2:
            for (k = 0; k < 95; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL1:
              for (int k_sub = 0; k_sub < 2; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
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
        merlinL0:
        for (int i_sub = 0; i_sub < 4; ++i_sub) {
          memcpy_wide_bus_write_float_2d_2_512((merlin_uint_512 *)G,G_buf[i_sub],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 840L + ((long )i_sub) * 210L)),sizeof(float ) * ((unsigned long )210L),(size_t )210L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 8 dim=2 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_17_0_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_17_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_17_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_18_0_buf cyclic factor = 4 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_18_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=E_19_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=F_19_0_buf cyclic factor = 2 dim=4 */
}
