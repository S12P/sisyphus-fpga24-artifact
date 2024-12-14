#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#include <string.h> 

#include "merlin_type_define.h"




/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[250][10][25],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[62500],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 250 + dst_idx_0) * 10 + dst_idx_1) * 25 + dst_idx_2;
  unsigned long total_offset2 = 0 * 62500 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=62500
    dst[(total_offset1 + i) / 25 / 10][(total_offset1 + i) / 25 % 10][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[10][25],int dst_idx_0,int dst_idx_1,float src[250],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 10 + dst_idx_0) * 25 + dst_idx_1;
  unsigned long total_offset2 = 0 * 250 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=250
    dst[(total_offset1 + i) / 25][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[10][25],int dst_idx_0,int dst_idx_1,float src[250],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 10 + dst_idx_0) * 25 + dst_idx_1;
  unsigned long total_offset2 = 0 * 250 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=250
    dst[(total_offset1 + i) / 25][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_3(float dst[250][10][25],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[62500],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 250 + dst_idx_0) * 10 + dst_idx_1) * 25 + dst_idx_2;
  unsigned long total_offset2 = 0 * 62500 + src_idx_0;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=62500
    dst[(total_offset1 + i) / 25 / 10][(total_offset1 + i) / 25 % 10][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

void kernel_gesummv(float alpha,float beta,float A[62500],float B[62500],merlin_uint_512 tmp[16],float x[250],merlin_uint_512 y[16])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=62500 bundle=merlin_gmem_kernel_gesummv_32_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=62500 bundle=merlin_gmem_kernel_gesummv_32_1
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=16 bundle=merlin_gmem_kernel_gesummv_512_tmp
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=250 bundle=merlin_gmem_kernel_gesummv_32_2
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=16 bundle=merlin_gmem_kernel_gesummv_512_y
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=tmp bundle=control
  
#pragma HLS INTERFACE s_axilite port=x bundle=control
  
#pragma HLS INTERFACE s_axilite port=y bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=y
  
#pragma HLS DATA_PACK VARIABLE=tmp
  
#pragma ACCEL interface variable=y depth=250 max_depth=250
  
#pragma ACCEL interface variable=x depth=250 max_depth=250
  
#pragma ACCEL interface variable=tmp depth=250 max_depth=250
  
#pragma ACCEL interface variable=B depth=250,250 max_depth=250,250
  
#pragma ACCEL interface variable=A depth=250,250 max_depth=250,250
  int i;
  int j;
{
    float B_4_0_buf[250][10][25];
    
#pragma HLS array_partition variable=B_4_0_buf complete dim=3
    float x_4_1_buf[10][25];
    
#pragma HLS array_partition variable=x_4_1_buf complete dim=2
    float x_4_0_buf[10][25];
    
#pragma HLS array_partition variable=x_4_0_buf complete dim=2
    float A_4_0_buf[250][10][25];
    
#pragma HLS array_partition variable=A_4_0_buf complete dim=3
    float y_buf[250];
    
#pragma HLS array_partition variable=y_buf cyclic factor=16 dim=1
    float tmp_buf[250];
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=tmp_buf cyclic factor=16 dim=1
    memcpy_wide_bus_read_float_512(&tmp_buf[0],(merlin_uint_512 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&y_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
{
      merlin_memcpy_0(A_4_0_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )62500L),250000UL);
    }
{
      merlin_memcpy_1(x_4_0_buf,0,0,x,0,sizeof(float ) * ((unsigned long )250),1000UL);
      merlin_memcpy_2(x_4_1_buf,0,0,x,0,sizeof(float ) * ((unsigned long )250),1000UL);
    }
{
      merlin_memcpy_3(B_4_0_buf,0,0,0,B,0,sizeof(float ) * ((unsigned long )62500L),250000UL);
    }
    merlinL6:
    for (i = 0; i < 250; i++) {
      tmp_buf[i] = ((float )0.0);
      y_buf[i] = ((float )0.0);
      merlinL5:
      for (j = 0; j < 10; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL4:
        for (int j_sub = 0; j_sub < 25; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          tmp_buf[i] = A_4_0_buf[i][j][j_sub] * x_4_1_buf[j][j_sub] + tmp_buf[i];
          y_buf[i] = B_4_0_buf[i][j][j_sub] * x_4_0_buf[j][j_sub] + y_buf[i];
        }
      }
      y_buf[i] = alpha * tmp_buf[i] + beta * y_buf[i];
    }
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)y,&y_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )250),250L);
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)tmp,&tmp_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )250),250L);
  }
}
