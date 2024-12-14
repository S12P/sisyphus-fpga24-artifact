#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 5
#define SIZE_2 250
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[50][5],int dst_idx_0,int dst_idx_1,float src[250],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 50 + dst_idx_0) * 5 + dst_idx_1;
  unsigned long total_offset2 = 0 * 250 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=250
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[50][5],int dst_idx_0,int dst_idx_1,float src[250],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 50 + dst_idx_0) * 5 + dst_idx_1;
  unsigned long total_offset2 = 0 * 250 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=250
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[250],int dst_idx_0,float src[50][5],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 250 + dst_idx_0;
  unsigned long total_offset2 = (0 * 50 + src_idx_0) * 5 + src_idx_1;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=250
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5][(total_offset2 + i) % 5];
  }
}

static void merlin_memcpy_3(float dst[250],int dst_idx_0,float src[50][5],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 250 + dst_idx_0;
  unsigned long total_offset2 = (0 * 50 + src_idx_0) * 5 + src_idx_1;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=250
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5][(total_offset2 + i) % 5];
  }
}

void kernel_gesummv(float alpha,float beta,merlin_uint_64 A[31250],merlin_uint_64 B[31250],float tmp[250],merlin_uint_512 x[16],float y[250])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=31250 bundle=merlin_gmem_kernel_gesummv_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=31250 bundle=merlin_gmem_kernel_gesummv_64_1
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=250 bundle=merlin_gmem_kernel_gesummv_32_tmp
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=16 bundle=merlin_gmem_kernel_gesummv_512_0
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=250 bundle=merlin_gmem_kernel_gesummv_32_y
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=tmp bundle=control
  
#pragma HLS INTERFACE s_axilite port=x bundle=control
  
#pragma HLS INTERFACE s_axilite port=y bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=x
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=y depth=250 max_depth=250
  
#pragma ACCEL interface variable=x depth=250 max_depth=250
  
#pragma ACCEL interface variable=tmp depth=250 max_depth=250
  
#pragma ACCEL interface variable=B depth=250,250 max_depth=250,250
  
#pragma ACCEL interface variable=A depth=250,250 max_depth=250,250
  int i;
  int j;
{
    float B_4_0_buf[50][5][250];
    
#pragma HLS array_partition variable=B_4_0_buf complete dim=3
    
#pragma HLS array_partition variable=B_4_0_buf complete dim=2
    float x_4_1_buf[250];
    
#pragma HLS array_partition variable=x_4_1_buf complete dim=1
    float x_4_0_buf[250];
    
#pragma HLS array_partition variable=x_4_0_buf complete dim=1
    float A_4_0_buf[50][5][250];
    
#pragma HLS array_partition variable=A_4_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_4_0_buf complete dim=2
    float y_buf[50][5];
    
#pragma HLS array_partition variable=y_buf complete dim=2
    float tmp_buf[50][5];
    
#pragma HLS array_partition variable=tmp_buf complete dim=2
    merlin_memcpy_0(tmp_buf,0,0,tmp,0,sizeof(float ) * ((unsigned long )250),1000UL);
    merlin_memcpy_1(y_buf,0,0,y,0,sizeof(float ) * ((unsigned long )250),1000UL);
{
      memcpy_wide_bus_read_float_3d_5_250_64(A_4_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )62500L),62500L);
    }
{
      memcpy_wide_bus_read_float_512(&x_4_0_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_1_buf cyclic factor = 16 dim=1 */
      memcpy_wide_bus_read_float_512(&x_4_1_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
    }
{
      memcpy_wide_bus_read_float_3d_5_250_64(B_4_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )62500L),62500L);
    }
    merlinL6:
    for (i = 0; i < 50; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=tmp_buf array inter false
      
#pragma HLS dependence variable=y_buf array inter false
      
#pragma HLS pipeline
      merlinL5:
      for (int i_sub = 0; i_sub < 5; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        tmp_buf[i][i_sub] = ((float )0.0);
        y_buf[i][i_sub] = ((float )0.0);
        merlinL4:
        for (j = 0; j < 250; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=250 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          tmp_buf[i][i_sub] = A_4_0_buf[i][i_sub][j] * x_4_1_buf[j] + tmp_buf[i][i_sub];
          y_buf[i][i_sub] = B_4_0_buf[i][i_sub][j] * x_4_0_buf[j] + y_buf[i][i_sub];
        }
        y_buf[i][i_sub] = alpha * tmp_buf[i][i_sub] + beta * y_buf[i][i_sub];
      }
    }
    merlin_memcpy_2(y,0,y_buf,0,0,sizeof(float ) * ((unsigned long )250),1000UL);
    merlin_memcpy_3(tmp,0,tmp_buf,0,0,sizeof(float ) * ((unsigned long )250),1000UL);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_4_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_0_buf cyclic factor = 16 dim=1 */
}
