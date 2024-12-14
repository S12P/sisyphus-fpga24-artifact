#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#include <string.h> 

#include "merlin_type_define.h"




/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[2][195],int dst_idx_0,int dst_idx_1,float src[390],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 2 + dst_idx_0) * 195 + dst_idx_1;
  unsigned long total_offset2 = 0 * 390 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=390
    dst[(total_offset1 + i) / 195][(total_offset1 + i) % 195] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[410][2][195],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[159900],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 410 + dst_idx_0) * 2 + dst_idx_1) * 195 + dst_idx_2;
  unsigned long total_offset2 = 0 * 159900 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=159900
    dst[(total_offset1 + i) / 195 / 2][(total_offset1 + i) / 195 % 2][(total_offset1 + i) % 195] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[410][2][195],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[159900],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 410 + dst_idx_0) * 2 + dst_idx_1) * 195 + dst_idx_2;
  unsigned long total_offset2 = 0 * 159900 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=159900
    dst[(total_offset1 + i) / 195 / 2][(total_offset1 + i) / 195 % 2][(total_offset1 + i) % 195] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_3(float dst[2][195],int dst_idx_0,int dst_idx_1,float src[390],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 2 + dst_idx_0) * 195 + dst_idx_1;
  unsigned long total_offset2 = 0 * 390 + src_idx_0;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=390
    dst[(total_offset1 + i) / 195][(total_offset1 + i) % 195] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_4(float dst[390],int dst_idx_0,float src[2][195],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 390 + dst_idx_0;
  unsigned long total_offset2 = (0 * 2 + src_idx_0) * 195 + src_idx_1;
  merlinL4:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=390
    dst[total_offset1 + i] = src[(total_offset2 + i) / 195][(total_offset2 + i) % 195];
  }
}

void kernel_bicg(float A[159900],float s[390],merlin_uint_512 q[26],float p[390],merlin_uint_512 r[26])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=159900 bundle=merlin_gmem_kernel_bicg_32_0
  
#pragma HLS INTERFACE m_axi port=p offset=slave depth=390 bundle=merlin_gmem_kernel_bicg_32_1
  
#pragma HLS INTERFACE m_axi port=q offset=slave depth=26 bundle=merlin_gmem_kernel_bicg_512_q
  
#pragma HLS INTERFACE m_axi port=r offset=slave depth=26 bundle=merlin_gmem_kernel_bicg_512_0
  
#pragma HLS INTERFACE m_axi port=s offset=slave depth=390 bundle=merlin_gmem_kernel_bicg_32_s
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=p bundle=control
  
#pragma HLS INTERFACE s_axilite port=q bundle=control
  
#pragma HLS INTERFACE s_axilite port=r bundle=control
  
#pragma HLS INTERFACE s_axilite port=s bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=r
  
#pragma HLS DATA_PACK VARIABLE=q
  
#pragma ACCEL interface variable=r depth=410 max_depth=410
  
#pragma ACCEL interface variable=p depth=390 max_depth=390
  
#pragma ACCEL interface variable=q depth=410 max_depth=410
  
#pragma ACCEL interface variable=s depth=390 max_depth=390
  
#pragma ACCEL interface variable=A depth=410,390 max_depth=410,390
  int i;
  int j;
{
    float p_6_0_buf[2][195];
    
#pragma HLS array_partition variable=p_6_0_buf complete dim=2
    float A_6_1_buf[410][2][195];
    
#pragma HLS array_partition variable=A_6_1_buf complete dim=3
    float A_6_0_buf[410][2][195];
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=3
    float r_6_0_buf[410];
    
#pragma HLS array_partition variable=r_6_0_buf cyclic factor=16 dim=1
    float q_buf[410];
    
#pragma HLS array_partition variable=q_buf cyclic factor=16 dim=1
    float s_buf[2][195];
    
#pragma HLS array_partition variable=s_buf complete dim=2
    merlin_memcpy_0(s_buf,0,0,s,0,sizeof(float ) * ((unsigned long )390),1560UL);
    merlinL9:
    for (i = 0; i < 2; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=195 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=195 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=s_buf array inter false
      
#pragma HLS pipeline
      merlinL8:
      for (int i_sub = 0; i_sub < 195; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=195 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=195 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        s_buf[i][i_sub] = ((float )0);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=q_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&q_buf[0],(merlin_uint_512 *)q,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
{
      memcpy_wide_bus_read_float_512(&r_6_0_buf[0],(merlin_uint_512 *)r,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    }
{
      merlin_memcpy_1(A_6_0_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )159900L),639600UL);
      merlin_memcpy_2(A_6_1_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )159900L),639600UL);
    }
{
      merlin_memcpy_3(p_6_0_buf,0,0,p,0,sizeof(float ) * ((unsigned long )390),1560UL);
    }
    merlinL7:
    for (i = 0; i < 410; i++) {
      q_buf[i] = ((float )0.0);
      merlinL6:
      for (j = 0; j < 2; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=195 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=195 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=s_buf array inter false
        
#pragma HLS pipeline
        merlinL5:
        for (int j_sub = 0; j_sub < 195; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=195 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=195 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          s_buf[j][j_sub] = s_buf[j][j_sub] + r_6_0_buf[i] * A_6_1_buf[i][j][j_sub];
          q_buf[i] = q_buf[i] + A_6_0_buf[i][j][j_sub] * p_6_0_buf[j][j_sub];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=q_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)q,&q_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )410),410L);
    merlin_memcpy_4(s,0,s_buf,0,0,sizeof(float ) * ((unsigned long )390),1560UL);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=r_6_0_buf cyclic factor = 16 dim=1 */
}
