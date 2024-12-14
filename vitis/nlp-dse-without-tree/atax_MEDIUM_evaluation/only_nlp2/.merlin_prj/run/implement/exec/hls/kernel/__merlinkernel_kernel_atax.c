#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 3
#define SIZE_2 410
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[130][3],int dst_idx_0,int dst_idx_1,float src[390],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 130 + dst_idx_0) * 3 + dst_idx_1;
  unsigned long total_offset2 = 0 * 390 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=390
    dst[(total_offset1 + i) / 3][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[390],int dst_idx_0,float src[130][3],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 390 + dst_idx_0;
  unsigned long total_offset2 = (0 * 130 + src_idx_0) * 3 + src_idx_1;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=390
    dst[total_offset1 + i] = src[(total_offset2 + i) / 3][(total_offset2 + i) % 3];
  }
}

void kernel_atax(merlin_uint_64 A[79950],merlin_uint_512 x[26],merlin_uint_512 y[26],float tmp[390])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=79950 bundle=merlin_gmem_kernel_atax_64_0
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=390 bundle=merlin_gmem_kernel_atax_32_tmp
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=26 bundle=merlin_gmem_kernel_atax_512_0
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=26 bundle=merlin_gmem_kernel_atax_512_y
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=tmp bundle=control
  
#pragma HLS INTERFACE s_axilite port=x bundle=control
  
#pragma HLS INTERFACE s_axilite port=y bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=y
  
#pragma HLS DATA_PACK VARIABLE=x
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=tmp depth=390 max_depth=390
  
#pragma ACCEL interface variable=y depth=410 max_depth=410
  
#pragma ACCEL interface variable=x depth=410 max_depth=410
  
#pragma ACCEL interface variable=A depth=390,410 max_depth=390,410
  int i;
  int j;
{
    float x_5_0_buf[410];
    
#pragma HLS array_partition variable=x_5_0_buf complete dim=1
    float A_5_0_buf[130][3][410];
    
#pragma HLS array_partition variable=A_5_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_5_0_buf complete dim=2
    float A_buf[3][130][410];
    
#pragma HLS array_partition variable=A_buf complete dim=3
    
#pragma HLS array_partition variable=A_buf complete dim=1
    float tmp_buf[130][3];
    
#pragma HLS array_partition variable=tmp_buf complete dim=2
    float y_buf[410];
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=y_buf complete dim=1
    memcpy_wide_bus_read_float_512(&y_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    merlinL6:
    for (i = 0; i < 410; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=410 */
/* Original: #pragma ACCEL PARALLEL FACTOR=410 */
/* Original: #pragma ACCEL parallel */
{
      
#pragma HLS unroll
      y_buf[i] = ((float )0);
    }
    merlin_memcpy_0(tmp_buf,0,0,tmp,0,sizeof(float ) * ((unsigned long )390),1560UL);
{
      memcpy_wide_bus_read_float_3d_3_410_64(A_5_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
    }
{
      memcpy_wide_bus_read_float_512(&x_5_0_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    }
    merlinL5:
    for (i = 0; i < 130; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=tmp_buf array inter false
      
#pragma HLS pipeline
      merlinL4:
      for (int i_sub = 0; i_sub < 3; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        tmp_buf[i][i_sub] = ((float )0.0);
        merlinL3:
        for (j = 0; j < 410; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=410 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          tmp_buf[i][i_sub] = tmp_buf[i][i_sub] + A_5_0_buf[i][i_sub][j] * x_5_0_buf[j];
        }
        merlinL2:
        for (j = 0; j < 410; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=410 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          y_buf[j] = y_buf[j] + A_buf[i_sub][i][j] * tmp_buf[i][i_sub];
        }
      }
    }
    merlin_memcpy_1(tmp,0,tmp_buf,0,0,sizeof(float ) * ((unsigned long )390),1560UL);
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)y,&y_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )410),410L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_5_0_buf cyclic factor = 16 dim=1 */
}
