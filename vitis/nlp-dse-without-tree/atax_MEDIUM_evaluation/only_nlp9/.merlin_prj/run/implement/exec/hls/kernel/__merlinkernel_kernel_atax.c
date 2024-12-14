#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#include <string.h> 

#include "merlin_type_define.h"




/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[82][5],int dst_idx_0,int dst_idx_1,float src[410],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 82 + dst_idx_0) * 5 + dst_idx_1;
  unsigned long total_offset2 = 0 * 410 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=410
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[390][82][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[159900],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 390 + dst_idx_0) * 82 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 159900 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=159900
    dst[(total_offset1 + i) / 5 / 82][(total_offset1 + i) / 5 % 82][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[390][82][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[159900],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 390 + dst_idx_0) * 82 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 159900 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=159900
    dst[(total_offset1 + i) / 5 / 82][(total_offset1 + i) / 5 % 82][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_3(float dst[82][5],int dst_idx_0,int dst_idx_1,float src[410],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 82 + dst_idx_0) * 5 + dst_idx_1;
  unsigned long total_offset2 = 0 * 410 + src_idx_0;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=410
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_4(float dst[410],int dst_idx_0,float src[82][5],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 410 + dst_idx_0;
  unsigned long total_offset2 = (0 * 82 + src_idx_0) * 5 + src_idx_1;
  merlinL4:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=410
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5][(total_offset2 + i) % 5];
  }
}

void kernel_atax(float A[159900],float x[410],float y[410],merlin_uint_512 tmp[25])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=159900 bundle=merlin_gmem_kernel_atax_32_0
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=25 bundle=merlin_gmem_kernel_atax_512_tmp
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=410 bundle=merlin_gmem_kernel_atax_32_1
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=410 bundle=merlin_gmem_kernel_atax_32_y
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=tmp bundle=control
  
#pragma HLS INTERFACE s_axilite port=x bundle=control
  
#pragma HLS INTERFACE s_axilite port=y bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=tmp
  
#pragma ACCEL interface variable=tmp depth=390 max_depth=390
  
#pragma ACCEL interface variable=y depth=410 max_depth=410
  
#pragma ACCEL interface variable=x depth=410 max_depth=410
  
#pragma ACCEL interface variable=A depth=390,410 max_depth=390,410
  int i;
  int j;
{
    float x_7_0_buf[82][5];
    
#pragma HLS array_partition variable=x_7_0_buf complete dim=2
    float A_7_0_buf[390][82][5];
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=3
    float A_8_0_buf[390][82][5];
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=3
    float tmp_buf[390];
    
#pragma HLS array_partition variable=tmp_buf cyclic factor=16 dim=1
    float y_buf[82][5];
    
#pragma HLS array_partition variable=y_buf complete dim=2
    merlin_memcpy_0(y_buf,0,0,y,0,sizeof(float ) * ((unsigned long )410),1640UL);
    merlinL11:
    for (i = 0; i < 82; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=y_buf array inter false
      
#pragma HLS pipeline
      merlinL10:
      for (int i_sub = 0; i_sub < 5; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        y_buf[i][i_sub] = ((float )0);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&tmp_buf[0],(merlin_uint_512 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
{
      merlin_memcpy_1(A_8_0_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )159900L),639600UL);
      merlin_memcpy_2(A_7_0_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )159900L),639600UL);
    }
{
      merlin_memcpy_3(x_7_0_buf,0,0,x,0,sizeof(float ) * ((unsigned long )410),1640UL);
    }
    merlinL9:
    for (i = 0; i < 390; i++) {
      tmp_buf[i] = ((float )0.0);
      merlinL8:
      for (j = 0; j < 82; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL7:
        for (int j_sub_0 = 0; j_sub_0 < 5; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          tmp_buf[i] = tmp_buf[i] + A_7_0_buf[i][j][j_sub_0] * x_7_0_buf[j][j_sub_0];
        }
      }
      merlinL6:
      for (j = 0; j < 82; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=y_buf array inter false
        
#pragma HLS pipeline
        merlinL5:
        for (int j_sub = 0; j_sub < 5; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          y_buf[j][j_sub] = y_buf[j][j_sub] + A_8_0_buf[i][j][j_sub] * tmp_buf[i];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)tmp,&tmp_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )390),390L);
    merlin_memcpy_4(y,0,y_buf,0,0,sizeof(float ) * ((unsigned long )410),1640UL);
  }
}
