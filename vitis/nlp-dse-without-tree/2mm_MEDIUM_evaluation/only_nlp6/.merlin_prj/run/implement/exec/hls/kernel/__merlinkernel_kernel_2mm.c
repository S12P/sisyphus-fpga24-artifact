#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 210
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 10
#define SIZE_2 10
#define SIZE_3 22
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 22
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_2mm(float alpha,float beta,merlin_uint_64 tmp[17100],merlin_uint_64 A[18900],merlin_uint_64 B[19950],merlin_uint_64 C[20900],merlin_uint_64 D[19800])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=18900 bundle=merlin_gmem_kernel_2mm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19950 bundle=merlin_gmem_kernel_2mm_64_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=20900 bundle=merlin_gmem_kernel_2mm_64_2
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=19800 bundle=merlin_gmem_kernel_2mm_64_D
  
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
    float B_6_0_buf[210][190];
    
#pragma HLS array_partition variable=B_6_0_buf cyclic factor=2 dim=2
    
#pragma HLS array_partition variable=B_6_0_buf complete dim=1
    float A_6_0_buf[180][210];
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=2
    float C_10_0_buf[19][10][10][22];
    
#pragma HLS array_partition variable=C_10_0_buf cyclic factor=2 dim=4
    
#pragma HLS array_partition variable=C_10_0_buf complete dim=2
    float tmp_buf[180][190];
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=tmp_buf cyclic factor=8 dim=2
    memcpy_wide_bus_read_float_2d_190_64(tmp_buf,0,0,(merlin_uint_64 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
{
      memcpy_wide_bus_read_float_2d_210_64(A_6_0_buf,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    }
{
      memcpy_wide_bus_read_float_2d_190_64(B_6_0_buf,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL10:
    for (i = 0; i < 180; i++) {
      merlinL9:
      for (j = 0; j < 190; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=tmp_buf array inter false
        
#pragma HLS pipeline
        tmp_buf[i][j] = ((float )0.0);
        merlinL8:
        for (k = 0; k < 210; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=210 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          tmp_buf[i][j] += alpha * A_6_0_buf[i][k] * B_6_0_buf[k][j];
        }
      }
    }
{
      memcpy_wide_bus_read_float_4d_10_10_22_64(C_10_0_buf,0,0,0,0,(merlin_uint_64 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
    merlinL7:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float D_buf[6][10][22];
      
#pragma HLS array_partition variable=D_buf cyclic factor=2 dim=3
{
        merlinL6:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_read_float_2d_22_64(D_buf[i_sub],(size_t )0,(size_t )0,(merlin_uint_64 *)D,(size_t )((((long )i) * 1320L + ((long )i_sub) * 220L) * ((long )4)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 2 dim=3 */
      }
      merlinL5:
      for (int i_sub = 0; i_sub < 6; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL4:
        for (j = 0; j < 10; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
{
          merlinL3:
          for (int j_sub = 0; j_sub < 22; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PARALLEL FACTOR=22 */
/* Original: #pragma ACCEL PARALLEL */
{
            D_buf[i_sub][j][j_sub] *= beta;
            merlinL2:
            for (k = 0; k < 19; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL1:
              for (int k_sub = 0; k_sub < 10; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
                
#pragma HLS unroll
                D_buf[i_sub][j][j_sub] += tmp_buf[((long )i) * 6L + ((long )i_sub)][((long )k) * 10L + ((long )k_sub)] * C_10_0_buf[k][k_sub][j][j_sub];
              }
            }
          }
        }
      }
{
        merlinL0:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_write_float_2d_22_64((merlin_uint_64 *)D,D_buf[i_sub],(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 1320L + ((long )i_sub) * 220L)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 2 dim=3 */
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_190_64((merlin_uint_64 *)tmp,tmp_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )34200L),34200L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_6_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_10_0_buf cyclic factor = 2 dim=4 */
}
