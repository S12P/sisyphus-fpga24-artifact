#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 210
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 95
#define SIZE_2 2
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 110
#define SIZE_2 2
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"









/* Original: #pragma ACCEL kernel */

void kernel_2mm(float alpha,float beta,merlin_uint_64 tmp[17100],merlin_uint_64 A[18900],merlin_uint_64 B[19950],merlin_uint_128 C[10450],merlin_uint_128 D[9900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=18900 bundle=merlin_gmem_kernel_2mm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19950 bundle=merlin_gmem_kernel_2mm_64_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_2mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=9900 bundle=merlin_gmem_kernel_2mm_128_D
  
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
    float B_8_0_buf[210][95][2];
    
#pragma HLS array_partition variable=B_8_0_buf complete dim=3
    
#pragma HLS array_partition variable=B_8_0_buf complete dim=1
    float A_8_0_buf[180][210];
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=2
    float C_9_0_buf[190][110][2];
    
#pragma HLS array_partition variable=C_9_0_buf complete dim=3
    
#pragma HLS array_partition variable=C_9_0_buf cyclic factor=2 dim=2
    
#pragma HLS array_partition variable=C_9_0_buf complete dim=1
    float D_buf[180][110][2];
    
#pragma HLS array_partition variable=D_buf complete dim=3
    
#pragma HLS array_partition variable=D_buf cyclic factor=2 dim=2
    float tmp_buf[180][190];
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=tmp_buf complete dim=2
    memcpy_wide_bus_read_float_2d_190_64(tmp_buf,0,0,(merlin_uint_64 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
{
      memcpy_wide_bus_read_float_2d_210_64(A_8_0_buf,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    }
{
      memcpy_wide_bus_read_float_3d_95_2_64(B_8_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL7:
    for (i = 0; i < 180; i++) {
      merlinL6:
      for (j = 0; j < 95; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=tmp_buf array inter false
        
#pragma HLS pipeline
        merlinL5:
        for (int j_sub_0 = 0; j_sub_0 < 2; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          tmp_buf[i][((long )j) * 2L + ((long )j_sub_0)] = ((float )0.0);
          merlinL4:
          for (k = 0; k < 210; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=210 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            tmp_buf[i][((long )j) * 2L + ((long )j_sub_0)] += alpha * A_8_0_buf[i][k] * B_8_0_buf[k][j][j_sub_0];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_read_float_3d_110_2_128(D_buf,0,0,0,(merlin_uint_128 *)D,(0 * 4),sizeof(float ) * ((unsigned long )39600L),39600L);
{
      memcpy_wide_bus_read_float_3d_110_2_128(C_9_0_buf,0,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
    merlinL3:
    for (i = 0; i < 180; i++) {
      merlinL2:
      for (j = 0; j < 110; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=D_buf array inter false
        
#pragma HLS pipeline
        merlinL1:
        for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          D_buf[i][j][j_sub] *= beta;
          merlinL0:
          for (k = 0; k < 190; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=190 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            D_buf[i][j][j_sub] += tmp_buf[i][k] * C_9_0_buf[k][j][j_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_3d_110_2_128((merlin_uint_128 *)D,D_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )39600L),39600L);
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_190_64((merlin_uint_64 *)tmp,tmp_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )34200L),34200L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_8_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_9_0_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_9_0_buf cyclic factor = 2 dim=2 */
}
