#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 15
#define SIZE_2 190
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 10
#define SIZE_2 220
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 220
#include "memcpy_128_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"









/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[180][14][15],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[37800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 180 + dst_idx_0) * 14 + dst_idx_1) * 15 + dst_idx_2;
  unsigned long total_offset2 = 0 * 37800 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=37800
    dst[(total_offset1 + i) / 15 / 14][(total_offset1 + i) / 15 % 14][(total_offset1 + i) % 15] = src[total_offset2 + i];
  }
}

void kernel_2mm(float alpha,float beta,merlin_uint_64 tmp[17100],float A[37800],merlin_uint_64 B[19950],merlin_uint_128 C[10450],merlin_uint_128 D[9900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=37800 bundle=merlin_gmem_kernel_2mm_32_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19950 bundle=merlin_gmem_kernel_2mm_64_0
  
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
    float B_8_0_buf[14][15][190];
    
#pragma HLS array_partition variable=B_8_0_buf cyclic factor=2 dim=3
    
#pragma HLS array_partition variable=B_8_0_buf complete dim=2
    float A_8_0_buf[180][14][15];
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=3
    float C_9_0_buf[19][10][220];
    
#pragma HLS array_partition variable=C_9_0_buf cyclic factor=4 dim=3
    
#pragma HLS array_partition variable=C_9_0_buf complete dim=2
    float D_buf[180][220];
    
#pragma HLS array_partition variable=D_buf cyclic factor=4 dim=2
    float tmp_buf[180][190];
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=tmp_buf cyclic factor=8 dim=2
    memcpy_wide_bus_read_float_2d_190_64(tmp_buf,0,0,(merlin_uint_64 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
{
      merlin_memcpy_0(A_8_0_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )37800L),151200UL);
    }
{
      memcpy_wide_bus_read_float_3d_15_190_64(B_8_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
    }
    merlinL8:
    for (i = 0; i < 180; i++) {
      merlinL7:
      for (j = 0; j < 190; j++) {
        tmp_buf[i][j] = ((float )0.0);
        merlinL6:
        for (k = 0; k < 14; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS pipeline
          merlinL5:
          for (int k_sub_0 = 0; k_sub_0 < 15; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            tmp_buf[i][j] += alpha * A_8_0_buf[i][k][k_sub_0] * B_8_0_buf[k][k_sub_0][j];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 4 dim=2 */
    memcpy_wide_bus_read_float_2d_220_128(D_buf,0,0,(merlin_uint_128 *)D,(0 * 4),sizeof(float ) * ((unsigned long )39600L),39600L);
{
      memcpy_wide_bus_read_float_3d_10_220_128(C_9_0_buf,0,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
    merlinL4:
    for (i = 0; i < 180; i++) {
      merlinL3:
      for (j = 0; j < 220; j++) {
        D_buf[i][j] *= beta;
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
            D_buf[i][j] += tmp_buf[i][((long )k) * 10L + ((long )k_sub)] * C_9_0_buf[k][k_sub][j];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=D_buf cyclic factor = 4 dim=2 */
    memcpy_wide_bus_write_float_2d_220_128((merlin_uint_128 *)D,D_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )39600L),39600L);
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_190_64((merlin_uint_64 *)tmp,tmp_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )34200L),34200L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=B_8_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_9_0_buf cyclic factor = 4 dim=3 */
}
