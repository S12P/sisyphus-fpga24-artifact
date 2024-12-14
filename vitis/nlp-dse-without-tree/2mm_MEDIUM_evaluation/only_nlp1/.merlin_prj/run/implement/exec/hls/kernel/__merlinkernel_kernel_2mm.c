#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 6
#define SIZE_2 190
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 3
#define SIZE_2 210
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 220
#include "memcpy_128_2d.h"
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
    float B_8_0_buf[210][190];
    
#pragma HLS array_partition variable=B_8_0_buf cyclic factor=2 dim=2
    
#pragma HLS array_partition variable=B_8_0_buf complete dim=1
    float A_8_0_buf[60][3][210];
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=3
    float C_9_0_buf[190][220];
    
#pragma HLS array_partition variable=C_9_0_buf cyclic factor=4 dim=2
    
#pragma HLS array_partition variable=C_9_0_buf complete dim=1
    float tmp_9_0_buf[30][6][190];
    
#pragma HLS array_partition variable=tmp_9_0_buf complete dim=3
{
      memcpy_wide_bus_read_float_3d_3_210_64(A_8_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    }
{
      memcpy_wide_bus_read_float_2d_190_64(B_8_0_buf,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL11:
    for (i = 0; i < 60; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
{
      float tmp_buf[3][190];
      
#pragma HLS array_partition variable=tmp_buf cyclic factor=2 dim=2
{
        merlinL10:
        for (int i_sub_0 = 0; i_sub_0 < 3; ++i_sub_0) {
          memcpy_wide_bus_read_float_64(tmp_buf[((long )i_sub_0) - 0L],(merlin_uint_64 *)tmp,(size_t )((((long )i) * 570L + ((long )i_sub_0) * 190L) * ((long )4)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=2 */
      }
      merlinL9:
      for (int i_sub_0 = 0; i_sub_0 < 3; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL8:
        for (j = 0; j < 190; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=tmp_buf array inter false
          
#pragma HLS pipeline
          tmp_buf[((long )i_sub_0) - 0L][j] = ((float )0.0);
          merlinL7:
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
        merlinL6:
        for (int i_sub_0 = 0; i_sub_0 < 3; ++i_sub_0) {
          memcpy_wide_bus_write_float_64((merlin_uint_64 *)tmp,tmp_buf[((long )i_sub_0) - 0L],(size_t )(((long )4) * (((long )i) * 570L + ((long )i_sub_0) * 190L)),sizeof(float ) * ((unsigned long )190L),(size_t )190L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=2 */
      }
    }
{
      memcpy_wide_bus_read_float_3d_6_190_64(tmp_9_0_buf,0,0,0,(merlin_uint_64 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
    }
{
      memcpy_wide_bus_read_float_2d_220_128(C_9_0_buf,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
    merlinL5:
    for (i = 0; i < 30; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
      float D_buf[6][220];
      
#pragma HLS array_partition variable=D_buf cyclic factor=16 dim=2
{
        merlinL4:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_read_float_512(D_buf[((long )i_sub) - 0L],(merlin_uint_512 *)D,(size_t )((((long )i) * 1320L + ((long )i_sub) * 220L) * ((long )4)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 16 dim=2 */
      }
      merlinL3:
      for (int i_sub = 0; i_sub < 6; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL2:
        for (j = 0; j < 220; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=D_buf array inter false
          
#pragma HLS pipeline
          D_buf[((long )i_sub) - 0L][j] *= beta;
          merlinL1:
          for (k = 0; k < 190; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=190 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            D_buf[((long )i_sub) - 0L][j] += tmp_9_0_buf[i][i_sub][k] * C_9_0_buf[k][j];
          }
        }
      }
{
        merlinL0:
        for (int i_sub = 0; i_sub < 6; ++i_sub) {
          memcpy_wide_bus_write_float_512((merlin_uint_512 *)D,D_buf[((long )i_sub) - 0L],(size_t )(((long )4) * (((long )i) * 1320L + ((long )i_sub) * 220L)),sizeof(float ) * ((unsigned long )220L),(size_t )220L);
        }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 16 dim=2 */
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_8_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_9_0_buf cyclic factor = 4 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_9_0_buf cyclic factor = 2 dim=3 */
}
