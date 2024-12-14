#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 228
#include "memcpy_128_2d.h"
#undef SIZE_1
#define SIZE_1 56
#define SIZE_2 4
#define SIZE_3 224
#include "memcpy_512_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void mars_kernel_0_1_node_0_stage_0(int i,int exec,merlin_uint_512 merlin_output[802816],float merlin_output_buf_0[8][56][4][224])
{
  
#pragma HLS INLINE OFF
  if (exec == 1) {
    memcpy_wide_bus_read_float_4d_56_4_224_512(merlin_output_buf_0,(size_t )0,(size_t )0,(size_t )0,(size_t )0,(merlin_uint_512 *)merlin_output,(size_t )(((long )i) * 401408L * ((long )4)),sizeof(float ) * ((unsigned long )401408L),(size_t )401408L);
  }
}

static void merlin_memcpy_0(float dst[8][256][5][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[1638400],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 8 + dst_idx_0) * 256 + dst_idx_1) * 5 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 1638400 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=51200
    dst[(total_offset1 + i) / 5 / 5 / 256][(total_offset1 + i) / 5 / 5 % 256][(total_offset1 + i) / 5 % 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

void mars_kernel_0_1_node_1_stage_0(int i,int exec,float weight[1638400],float weight_9_0_buf_0[8][256][5][5])
{
  
#pragma HLS INLINE OFF
  if (exec == 1) {
    merlin_memcpy_0(weight_9_0_buf_0,0,0,0,0,weight,((long )i) * 51200L,sizeof(float ) * ((unsigned long )51200L),204800UL);
  }
}

void mars_kernel_0_1_node_2_stage_1(int i,int exec,merlin_uint_128 merlin_input[3326976],float merlin_output_buf_0[8][56][4][224],float weight_9_0_buf_0[8][256][5][5])
{
  
#pragma HLS INLINE OFF
  if (exec == 1) {
    merlinL7:
    for (int i_sub = 0; i_sub < 8; ++i_sub) 
/* Original: #pragma ACCEL pipeline */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
      merlinL6:
      for (int j = 0; j < 256; ++j) {
        float merlin_input_9_0_buf[228][228];
        
#pragma HLS array_partition variable=merlin_input_9_0_buf cyclic factor=5 dim=2
        
#pragma HLS array_partition variable=merlin_input_9_0_buf cyclic factor=5 dim=1
{
          memcpy_wide_bus_read_float_2d_228_128(merlin_input_9_0_buf,(size_t )0,(size_t )0,(merlin_uint_128 *)merlin_input,(size_t )(((long )j) * 51984L * ((long )4)),sizeof(float ) * ((unsigned long )51984L),(size_t )51984L);
        }
        merlinL5:
        for (int h = 0; h < 56; ++h) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
{
          merlinL4:
          for (int h_sub = 0; h_sub < 4; ++h_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL */
{
            merlinL3:
            for (int w = 0; w < 224; ++w) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS dependence variable=merlin_output_buf_0 array inter false
              
#pragma HLS pipeline
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
                  merlin_output_buf_0[i_sub][h][h_sub][w] += weight_9_0_buf_0[i_sub][j][p][q] * merlin_input_9_0_buf[((long )h) * 4L + ((long )h_sub) + ((long )p)][q + w];
                }
              }
            }
          }
        }
      }
/* Existing HLS partition: #pragma HLS array_partition variable=merlin_input_9_0_buf cyclic factor = 4 dim=2 */
    }
  }
}

void mars_kernel_0_1_node_3_stage_2(int i,int exec,merlin_uint_512 merlin_output[802816],float merlin_output_buf_0[8][56][4][224])
{
  
#pragma HLS INLINE OFF
  if (exec == 1) {
    memcpy_wide_bus_write_float_4d_56_4_224_512((merlin_uint_512 *)merlin_output,merlin_output_buf_0,(size_t )0,(size_t )0,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 401408L)),sizeof(float ) * ((unsigned long )401408L),(size_t )401408L);
  }
}

void mars_kernel_0_1_bus(int mars_i,int mars_init,int mars_cond,merlin_uint_128 merlin_input[3326976],merlin_uint_512 merlin_output[802816],float mars_merlin_output_buf_0_0[8][56][4][224],float mars_merlin_output_buf_0_1[8][56][4][224],float mars_merlin_output_buf_0_2[8][56][4][224],float weight[1638400],float mars_weight_9_0_buf_0_0[8][256][5][5],float mars_weight_9_0_buf_0_1[8][256][5][5])
{
  
#pragma HLS INLINE OFF
  mars_kernel_0_1_node_0_stage_0(mars_i - 0,(int )(mars_i >= mars_init + 0 & mars_i <= mars_cond + 0),merlin_output,mars_merlin_output_buf_0_0);
  mars_kernel_0_1_node_1_stage_0(mars_i - 0,(int )(mars_i >= mars_init + 0 & mars_i <= mars_cond + 0),weight,mars_weight_9_0_buf_0_0);
  mars_kernel_0_1_node_2_stage_1(mars_i - 1,(int )(mars_i >= mars_init + 1 & mars_i <= mars_cond + 1),merlin_input,mars_merlin_output_buf_0_1,mars_weight_9_0_buf_0_1);
  mars_kernel_0_1_node_3_stage_2(mars_i - 2,(int )(mars_i >= mars_init + 2 & mars_i <= mars_cond + 2),merlin_output,mars_merlin_output_buf_0_2);
}

void mars_kernel_0_1_comp(int mars_i,int mars_init,int mars_cond,merlin_uint_128 merlin_input[3326976],merlin_uint_512 merlin_output[802816],float mars_merlin_output_buf_0_0[8][56][4][224],float mars_merlin_output_buf_0_1[8][56][4][224],float mars_merlin_output_buf_0_2[8][56][4][224],float weight[1638400],float mars_weight_9_0_buf_0_0[8][256][5][5],float mars_weight_9_0_buf_0_1[8][256][5][5])
{
  
#pragma HLS INLINE OFF
}

void mars_kernel_0_1(int mars_i,int mars_init,int mars_cond,merlin_uint_128 merlin_input[3326976],merlin_uint_512 merlin_output[802816],float mars_merlin_output_buf_0_0[8][56][4][224],float mars_merlin_output_buf_0_1[8][56][4][224],float mars_merlin_output_buf_0_2[8][56][4][224],float weight[1638400],float mars_weight_9_0_buf_0_0[8][256][5][5],float mars_weight_9_0_buf_0_1[8][256][5][5])
{
  
#pragma HLS INLINE OFF
  mars_kernel_0_1_bus(mars_i,mars_init,mars_cond,merlin_input,merlin_output,mars_merlin_output_buf_0_0,mars_merlin_output_buf_0_1,mars_merlin_output_buf_0_2,weight,mars_weight_9_0_buf_0_0,mars_weight_9_0_buf_0_1);
  mars_kernel_0_1_comp(mars_i,mars_init,mars_cond,merlin_input,merlin_output,mars_merlin_output_buf_0_0,mars_merlin_output_buf_0_1,mars_merlin_output_buf_0_2,weight,mars_weight_9_0_buf_0_0,mars_weight_9_0_buf_0_1);
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
  float weight_9_0_buf_0[8][256][5][5];
  float merlin_output_buf_0[8][56][4][224];
  int mars_count_0_1 = 0;
  float mars_kernel_0_1_merlin_output_buf_0_0[8][56][4][224];
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_0 cyclic factor=16 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_0 cyclic factor=16 dim=4 */
  
#pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_0 cyclic factor=16 dim=4
  float mars_kernel_0_1_merlin_output_buf_0_1[8][56][4][224];
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_1 cyclic factor=16 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_1 cyclic factor=16 dim=4 */
  
#pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_1 cyclic factor=16 dim=4
  float mars_kernel_0_1_merlin_output_buf_0_2[8][56][4][224];
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_2 cyclic factor=16 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_2 cyclic factor=16 dim=4 */
  
#pragma HLS array_partition variable=mars_kernel_0_1_merlin_output_buf_0_2 cyclic factor=16 dim=4
  float mars_kernel_0_1_weight_9_0_buf_0_0[8][256][5][5];
  
#pragma HLS array_partition variable=mars_kernel_0_1_weight_9_0_buf_0_0 complete dim=4
  
#pragma HLS array_partition variable=mars_kernel_0_1_weight_9_0_buf_0_0 complete dim=3
  float mars_kernel_0_1_weight_9_0_buf_0_1[8][256][5][5];
  
#pragma HLS array_partition variable=mars_kernel_0_1_weight_9_0_buf_0_1 complete dim=4
  
#pragma HLS array_partition variable=mars_kernel_0_1_weight_9_0_buf_0_1 complete dim=3
  float mars_kernel_0_1_weight_9_0_buf_0_2[8][256][5][5];
  
#pragma HLS array_partition variable=mars_kernel_0_1_weight_9_0_buf_0_2 complete dim=4
  
#pragma HLS array_partition variable=mars_kernel_0_1_weight_9_0_buf_0_2 complete dim=3
  merlinL8:
  for (int i = 0; i < 32 + 2; ++i) 
/* Original: #pragma ACCEL pipeline */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
{
    if (mars_count_0_1 == 0) 
      mars_kernel_0_1(i,0,31,merlin_input,merlin_output,mars_kernel_0_1_merlin_output_buf_0_0,mars_kernel_0_1_merlin_output_buf_0_1,mars_kernel_0_1_merlin_output_buf_0_2,weight,mars_kernel_0_1_weight_9_0_buf_0_0,mars_kernel_0_1_weight_9_0_buf_0_1);
     else if (mars_count_0_1 == 1) 
      mars_kernel_0_1(i,0,31,merlin_input,merlin_output,mars_kernel_0_1_merlin_output_buf_0_2,mars_kernel_0_1_merlin_output_buf_0_0,mars_kernel_0_1_merlin_output_buf_0_1,weight,mars_kernel_0_1_weight_9_0_buf_0_2,mars_kernel_0_1_weight_9_0_buf_0_0);
     else 
      mars_kernel_0_1(i,0,31,merlin_input,merlin_output,mars_kernel_0_1_merlin_output_buf_0_1,mars_kernel_0_1_merlin_output_buf_0_2,mars_kernel_0_1_merlin_output_buf_0_0,weight,mars_kernel_0_1_weight_9_0_buf_0_1,mars_kernel_0_1_weight_9_0_buf_0_2);
    mars_count_0_1++;
    if (mars_count_0_1 == 3) 
      mars_count_0_1 = 0;
  }
}
