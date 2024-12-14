#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 228
#include "memcpy_128_2d.h"
#undef SIZE_1
#define SIZE_1 224
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

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
  merlinL7:
  for (int i = 0; i < 256; ++i) 
/* Original: #pragma ACCEL pipeline */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
    merlinL6:
    for (int j = 0; j < 256; ++j) {
      float merlin_input_8_0_buf[228][228];
      
#pragma HLS array_partition variable=merlin_input_8_0_buf cyclic factor=5 dim=2
      
#pragma HLS array_partition variable=merlin_input_8_0_buf cyclic factor=5 dim=1
{
        memcpy_wide_bus_read_float_2d_228_128(merlin_input_8_0_buf,(size_t )0,(size_t )0,(merlin_uint_128 *)merlin_input,(size_t )(((long )j) * 51984L * ((long )4)),sizeof(float ) * ((unsigned long )51984L),(size_t )51984L);
      }
      merlinL5:
      for (int h = 0; h < 7; ++h) 
/* Original: #pragma ACCEL PARALLEL FACTOR=32 */
/* Original: #pragma ACCEL PARALLEL FACTOR=32 */
{
        float merlin_output_buf[32][224];
        
#pragma HLS array_partition variable=merlin_output_buf cyclic factor=16 dim=2
{
          memcpy_wide_bus_read_float_2d_224_512(merlin_output_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)merlin_output,(size_t )((((long )h) * 7168L + ((long )i) * 50176L) * ((long )4)),sizeof(float ) * ((unsigned long )7168L),(size_t )7168L);
        }
        merlinL4:
        for (int h_sub = 0; h_sub < 32; ++h_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=32 */
/* Original: #pragma ACCEL PARALLEL FACTOR=32 */
/* Original: #pragma ACCEL PARALLEL */
{
          merlinL3:
          for (int w = 0; w < 224; ++w) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS dependence variable=merlin_output_buf array inter false
            
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
                merlin_output_buf[((long )h_sub) - 0L][w] += weight_8_0_buf[i][j][p][q] * merlin_input_8_0_buf[((long )h) * 32L + ((long )h_sub) + ((long )p)][q + w];
              }
            }
          }
        }
{
          memcpy_wide_bus_write_float_2d_224_512((merlin_uint_512 *)merlin_output,merlin_output_buf,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )h) * 7168L + ((long )i) * 50176L)),sizeof(float ) * ((unsigned long )7168L),(size_t )7168L);
        }
      }
/* Existing HLS partition: #pragma HLS array_partition variable=merlin_output_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=merlin_output_buf cyclic factor = 16 dim=2 */
    }
/* Existing HLS partition: #pragma HLS array_partition variable=merlin_input_8_0_buf cyclic factor = 4 dim=2 */
  }
}
