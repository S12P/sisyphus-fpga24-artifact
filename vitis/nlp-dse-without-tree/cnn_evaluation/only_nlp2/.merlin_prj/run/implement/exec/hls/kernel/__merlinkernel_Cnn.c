#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 228
#include "memcpy_128_2d.h"
#undef SIZE_1
#define SIZE_1 7
#define SIZE_2 32
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void mars_kernel_0_1_node_0_stage_0(int i,int exec,merlin_uint_512 merlin_output[802816],float merlin_output_buf_0[224][7][32])
{
  
#pragma HLS INLINE OFF
  if (exec == 1) {
    memcpy_wide_bus_read_float_3d_7_32_512(merlin_output_buf_0,(size_t )0,(size_t )0,(size_t )0,(merlin_uint_512 *)merlin_output,(size_t )(((long )i) * 50176L * ((long )4)),sizeof(float ) * ((unsigned long )50176L),(size_t )50176L);
  }
}

void mars_kernel_0_1_node_1_stage_1(int i,int exec,merlin_uint_128 merlin_input[3326976],float merlin_output_buf_0[224][7][32],float weight_8_0_buf[256][256][5][5])
{
  
#pragma HLS INLINE OFF
  if (exec == 1) {
    merlinL6:
    for (int j = 0; j < 256; ++j) {
      float merlin_input_8_0_buf[228][228];
      
#pragma HLS array_partition variable=merlin_input_8_0_buf cyclic factor=36 dim=2
      
#pragma HLS array_partition variable=merlin_input_8_0_buf cyclic factor=5 dim=1
{
        memcpy_wide_bus_read_float_2d_228_128(merlin_input_8_0_buf,(size_t )0,(size_t )0,(merlin_uint_128 *)merlin_input,(size_t )(((long )j) * 51984L * ((long )4)),sizeof(float ) * ((unsigned long )51984L),(size_t )51984L);
      }
      merlinL5:
      for (int h = 0; h < 224; ++h) {
        merlinL4:
        for (int w = 0; w < 7; ++w) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=32 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=32 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=merlin_output_buf_0 array inter false
          
#pragma HLS pipeline
          merlinL3:
          for (int w_sub = 0; w_sub < 32; ++w_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=32 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=32 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            merlinL2:
            for (int p = 0; p < 5; ++p) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
              
#pragma HLS unroll
              merlinL1:
              for (int q = 0; q < 5; ++q) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
                
#pragma HLS unroll
                merlin_output_buf_0[h][w][w_sub] += weight_8_0_buf[i][j][p][q] * merlin_input_8_0_buf[h + p][((long )w) * 32L + ((long )q) + ((long )w_sub)];
              }
            }
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=merlin_input_8_0_buf cyclic factor = 4 dim=2 */
  }
}

void mars_kernel_0_1_node_2_stage_2(int i,int exec,merlin_uint_512 merlin_output[802816],float merlin_output_buf_0[224][7][32])
{
  
#pragma HLS INLINE OFF
  if (exec == 1) {
    memcpy_wide_bus_write_float_3d_7_32_512((merlin_uint_512 *)merlin_output,merlin_output_buf_0,(size_t )0,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 50176L)),sizeof(float ) * ((unsigned long )50176L),(size_t )50176L);
  }
}

void mars_kernel_0_1_bus(int mars_i,int mars_init,int mars_cond,merlin_uint_128 merlin_input[3326976],merlin_uint_512 merlin_output[802816],float mars_merlin_output_buf_0_0[224][7][32],float mars_merlin_output_buf_0_1[224][7][32],float mars_merlin_output_buf_0_2[224][7][32],float mars_weight_8_0_buf_1[256][256][5][5])
{
  
#pragma HLS INLINE OFF
  mars_kernel_0_1_node_0_stage_0(mars_i - 0,(int )(mars_i >= mars_init + 0 & mars_i <= mars_cond + 0),merlin_output,mars_merlin_output_buf_0_0);
  mars_kernel_0_1_node_1_stage_1(mars_i - 1,(int )(mars_i >= mars_init + 1 & mars_i <= mars_cond + 1),merlin_input,mars_merlin_output_buf_0_1,mars_weight_8_0_buf_1);
  mars_kernel_0_1_node_2_stage_2(mars_i - 2,(int )(mars_i >= mars_init + 2 & mars_i <= mars_cond + 2),merlin_output,mars_merlin_output_buf_0_2);
}

void mars_kernel_0_1_comp(int mars_i,int mars_init,int mars_cond,merlin_uint_128 merlin_input[3326976],merlin_uint_512 merlin_output[802816],float mars_merlin_output_buf_0_0[224][7][32],float mars_merlin_output_buf_0_1[224][7][32],float mars_merlin_output_buf_0_2[224][7][32],float mars_weight_8_0_buf_1[256][256][5][5])
{
  
#pragma HLS INLINE OFF
}

void mars_kernel_0_1(int mars_i,int mars_init,int mars_cond,merlin_uint_128 merlin_input[3326976],merlin_uint_512 merlin_output[802816],float mars_merlin_output_buf_0_0[224][7][32],float mars_merlin_output_buf_0_1[224][7][32],float mars_merlin_output_buf_0_2[224][7][32],float mars_weight_8_0_buf_1[256][256][5][5])
{
  
#pragma HLS INLINE OFF
  mars_kernel_0_1_bus(mars_i,mars_init,mars_cond,merlin_input,merlin_output,mars_merlin_output_buf_0_0,mars_merlin_output_buf_0_1,mars_merlin_output_buf_0_2,mars_weight_8_0_buf_1);
  mars_kernel_0_1_comp(mars_i,mars_init,mars_cond,merlin_input,merlin_output,mars_merlin_output_buf_0_0,mars_merlin_output_buf_0_1,mars_merlin_output_buf_0_2,mars_weight_8_0_buf_1);
}

static void merlin_memcpy_0(float dst[256][256][5][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[1638400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 256 + dst_idx_0) * 256 + dst_idx_1) * 5 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 1638400 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=1638400
    dst[(total_offset1 + i) / 5 / 5 / 256][(total_offset1 + i) / 5 / 5 % 256][(total_offset1 + i) / 5 % 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

void Cnn(merlin_uint_128 merlin_input[3326976],float weight[1638400],merlin_uint_512 merlin_output[802816])
{
  
#pragma HLS INTERFACE m_axi port=merlin_input offset=slave depth=3326976 bundle=merlin_gmem_Cnn_128_0
  
#pragma HLS INTERFACE m_axi port=merlin_output offset=slave depth=802816 bundle=merlin_gmem_Cnn_512_merlin_output
  
#pragma HLS INTERFACE m_axi port=weight offset=slave depth=1638400 bundle=merlin_gmem_Cnn_32_0
  
#pragma HLS INTERFACE s_axilite port=merlin_input bundle=control
  
#pragma HLS INTERFACE s_axilite port=merlin_output bundle=control
  
#pragma HLS INTERFACE s_axilite port=weight bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=merlin_output
  
#pragma HLS DATA_PACK VARIABLE=merlin_input
  
#pragma ACCEL interface variable=merlin_output depth=256,224,224 max_depth=256,224,224
  
#pragma ACCEL interface variable=weight depth=256,256,5,5 max_depth=256,256,5,5
  
#pragma ACCEL interface variable=merlin_input depth=256,228,228 max_depth=256,228,228
  float weight_8_0_buf[256][256][5][5];
  
#pragma HLS array_partition variable=weight_8_0_buf complete dim=4
  
#pragma HLS array_partition variable=weight_8_0_buf complete dim=3
{
    merlin_memcpy_0(weight_8_0_buf,0,0,0,0,weight,0,sizeof(float ) * ((unsigned long )1638400L),6553600UL);
  }
  float merlin_output_buf_0[224][7][32];
  int mars_count_0_1 = 0;
  float mars_kernel_0_1_merlin_output_buf_0_0[224][7][32];
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_0 cyclic factor=16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_0 cyclic factor=16 dim=3 */
  
#pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_0 complete dim=3
  float mars_kernel_0_1_merlin_output_buf_0_1[224][7][32];
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_1 cyclic factor=16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_1 cyclic factor=16 dim=3 */
  
#pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_1 complete dim=3
  float mars_kernel_0_1_merlin_output_buf_0_2[224][7][32];
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_2 cyclic factor=16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_2 cyclic factor=16 dim=3 */
  
#pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_2 complete dim=3
  merlinL7:
  for (int i = 0; i < 256 + 2; ++i) 
/* Original: #pragma ACCEL pipeline */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
    if (mars_count_0_1 == 0) 
      mars_kernel_0_1(i,0,255,merlin_input,merlin_output,mars_kernel_0_1_merlin_output_buf_0_0,mars_kernel_0_1_merlin_output_buf_0_1,mars_kernel_0_1_merlin_output_buf_0_2,weight_8_0_buf);
     else if (mars_count_0_1 == 1) 
      mars_kernel_0_1(i,0,255,merlin_input,merlin_output,mars_kernel_0_1_merlin_output_buf_0_2,mars_kernel_0_1_merlin_output_buf_0_0,mars_kernel_0_1_merlin_output_buf_0_1,weight_8_0_buf);
     else 
      mars_kernel_0_1(i,0,255,merlin_input,merlin_output,mars_kernel_0_1_merlin_output_buf_0_1,mars_kernel_0_1_merlin_output_buf_0_2,mars_kernel_0_1_merlin_output_buf_0_0,weight_8_0_buf);
    mars_count_0_1++;
    if (mars_count_0_1 == 3) 
      mars_count_0_1 = 0;
  }
}
