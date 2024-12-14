#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
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
#define SIZE_1 4
#define SIZE_2 105
#define SIZE_3 2
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#define SIZE_2 95
#define SIZE_3 2
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#define SIZE_2 110
#define SIZE_3 2
#include "memcpy_128_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"












/* Original: #pragma ACCEL kernel */

void kernel_2mm(float alpha,float beta,merlin_uint_64 tmp[17100],merlin_uint_64 A[18900],merlin_uint_64 B[19950],merlin_uint_128 C[10450],merlin_uint_512 D[2475])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=18900 bundle=merlin_gmem_kernel_2mm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19950 bundle=merlin_gmem_kernel_2mm_64_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_2mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=2475 bundle=merlin_gmem_kernel_2mm_512_D
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=17100 bundle=merlin_gmem_kernel_2mm_64_tmp
  
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
  
#pragma HLS DATA_PACK VARIABLE=tmp
  
#pragma ACCEL interface variable=D depth=180,220 max_depth=180,220
  
#pragma ACCEL interface variable=C depth=190,220 max_depth=190,220
  
#pragma ACCEL interface variable=B depth=210,190 max_depth=210,190
  
#pragma ACCEL interface variable=A depth=180,210 max_depth=180,210
  
#pragma ACCEL interface variable=tmp depth=180,190 max_depth=180,190
  int i;
  int j;
  int k;
{
    float B_12_0_buf[105][2][95][2];
    
#pragma HLS array_partition variable=B_12_0_buf complete dim=4
    
#pragma HLS array_partition variable=B_12_0_buf complete dim=2
    float A_12_0_buf[45][4][105][2];
    
#pragma HLS array_partition variable=A_12_0_buf complete dim=4
    float C_13_0_buf[95][2][110][2];
    
#pragma HLS array_partition variable=C_13_0_buf complete dim=4
    
#pragma HLS array_partition variable=C_13_0_buf cyclic factor=2 dim=3
    
#pragma HLS array_partition variable=C_13_0_buf complete dim=2
    float tmp_13_0_buf[45][4][95][2];
    
#pragma HLS array_partition variable=tmp_13_0_buf complete dim=4
{
      memcpy_wide_bus_read_float_4d_4_105_2_64(A_12_0_buf,0,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    }
{
      memcpy_wide_bus_read_float_4d_2_95_2_64(B_12_0_buf,0,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL15:
    for (i = 0; i < 45; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
{
      float tmp_buf[4][95][2];
      
#pragma HLS array_partition variable=tmp_buf complete dim=3
{
        merlinL14:
        for (int i_sub_0 = 0; i_sub_0 < 4; ++i_sub_0) {
          memcpy_wide_bus_read_float_2d_2_64(tmp_buf[i_sub_0],(size_t )0,(size_t )0,(merlin_uint_64 *)tmp,(size_t )((((long )i) * 760L + ((long )i_sub_0) * 190L) * ((long )4)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=3 */
      }
      merlinL13:
      for (int i_sub_0 = 0; i_sub_0 < 4; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL12:
        for (j = 0; j < 95; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
          merlinL11:
          for (int j_sub_0 = 0; j_sub_0 < 2; ++j_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            tmp_buf[i_sub_0][j][j_sub_0] = ((float )0.0);
            merlinL10:
            for (k = 0; k < 105; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL9:
              for (int k_sub_0 = 0; k_sub_0 < 2; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
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
        merlinL8:
        for (int i_sub_0 = 0; i_sub_0 < 4; ++i_sub_0) {
          memcpy_wide_bus_write_float_2d_2_64((merlin_uint_64 *)tmp,tmp_buf[i_sub_0],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 760L + ((long )i_sub_0) * 190L)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=3 */
      }
    }
{
      memcpy_wide_bus_read_float_4d_4_95_2_64(tmp_13_0_buf,0,0,0,0,(merlin_uint_64 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
    }
{
      memcpy_wide_bus_read_float_4d_2_110_2_128(C_13_0_buf,0,0,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
    merlinL7:
    for (i = 0; i < 45; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
{
      float D_buf[4][110][2];
      
#pragma HLS array_partition variable=D_buf complete dim=3
      
#pragma HLS array_partition variable=D_buf cyclic factor=8 dim=2
{
        merlinL6:
        for (int i_sub = 0; i_sub < 4; ++i_sub) {
          memcpy_wide_bus_read_float_2d_2_512(D_buf[i_sub],(size_t )0,(size_t )0,(merlin_uint_512 *)D,(size_t )((((long )i) * 880L + ((long )i_sub) * 220L) * ((long )4)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 8 dim=2 */
      }
      merlinL5:
      for (int i_sub = 0; i_sub < 4; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL4:
        for (j = 0; j < 110; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
          merlinL3:
          for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            D_buf[i_sub][j][j_sub] *= beta;
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
                D_buf[i_sub][j][j_sub] += tmp_13_0_buf[i][i_sub][k][k_sub] * C_13_0_buf[k][k_sub][j][j_sub];
              }
            }
          }
        }
      }
{
        merlinL0:
        for (int i_sub = 0; i_sub < 4; ++i_sub) {
          memcpy_wide_bus_write_float_2d_2_512((merlin_uint_512 *)D,D_buf[i_sub],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 880L + ((long )i_sub) * 220L)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 8 dim=2 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_12_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_12_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_13_0_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_13_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_13_0_buf cyclic factor = 2 dim=4 */
}
