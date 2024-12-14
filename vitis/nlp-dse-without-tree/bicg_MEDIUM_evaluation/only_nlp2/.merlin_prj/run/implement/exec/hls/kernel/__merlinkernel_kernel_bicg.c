#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 5
#define SIZE_2 390
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
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

static void merlin_memcpy_1(float dst[82][5],int dst_idx_0,int dst_idx_1,float src[410],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 82 + dst_idx_0) * 5 + dst_idx_1;
  unsigned long total_offset2 = 0 * 410 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=410
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[410],int dst_idx_0,float src[82][5],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 410 + dst_idx_0;
  unsigned long total_offset2 = (0 * 82 + src_idx_0) * 5 + src_idx_1;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=410
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5][(total_offset2 + i) % 5];
  }
}

void kernel_bicg(merlin_uint_64 A[79950],merlin_uint_512 s[25],float q[410],merlin_uint_512 p[25],float r[410])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=79950 bundle=merlin_gmem_kernel_bicg_64_0
  
#pragma HLS INTERFACE m_axi port=p offset=slave depth=25 bundle=merlin_gmem_kernel_bicg_512_0
  
#pragma HLS INTERFACE m_axi port=q offset=slave depth=410 bundle=merlin_gmem_kernel_bicg_32_q
  
#pragma HLS INTERFACE m_axi port=r offset=slave depth=410 bundle=merlin_gmem_kernel_bicg_32_0
  
#pragma HLS INTERFACE m_axi port=s offset=slave depth=25 bundle=merlin_gmem_kernel_bicg_512_s
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=p bundle=control
  
#pragma HLS INTERFACE s_axilite port=q bundle=control
  
#pragma HLS INTERFACE s_axilite port=r bundle=control
  
#pragma HLS INTERFACE s_axilite port=s bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=p
  
#pragma HLS DATA_PACK VARIABLE=s
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=r depth=410 max_depth=410
  
#pragma ACCEL interface variable=p depth=390 max_depth=390
  
#pragma ACCEL interface variable=q depth=410 max_depth=410
  
#pragma ACCEL interface variable=s depth=390 max_depth=390
  
#pragma ACCEL interface variable=A depth=410,390 max_depth=410,390
  int i;
  int j;
{
    float p_5_0_buf[390];
    
#pragma HLS array_partition variable=p_5_0_buf complete dim=1
    float A_5_1_buf[82][5][390];
    
#pragma HLS array_partition variable=A_5_1_buf complete dim=3
    
#pragma HLS array_partition variable=A_5_1_buf complete dim=2
    float A_5_0_buf[82][5][390];
    
#pragma HLS array_partition variable=A_5_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_5_0_buf complete dim=2
    float r_5_0_buf[82][5];
    
#pragma HLS array_partition variable=r_5_0_buf complete dim=2
    float q_buf[82][5];
    
#pragma HLS array_partition variable=q_buf complete dim=2
    float s_buf[390];
/* Existing HLS partition: #pragma HLS array_partition variable=s_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=s_buf complete dim=1
    memcpy_wide_bus_read_float_512(&s_buf[0],(merlin_uint_512 *)s,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
    merlinL6:
    for (i = 0; i < 390; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=390 */
/* Original: #pragma ACCEL PARALLEL FACTOR=390 */
/* Original: #pragma ACCEL parallel */
{
      
#pragma HLS unroll
      s_buf[i] = ((float )0);
    }
    merlin_memcpy_0(q_buf,0,0,q,0,sizeof(float ) * ((unsigned long )410),1640UL);
{
      merlin_memcpy_1(r_5_0_buf,0,0,r,0,sizeof(float ) * ((unsigned long )410),1640UL);
    }
{
      memcpy_wide_bus_read_float_3d_5_390_64(A_5_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_1_buf cyclic factor = 2 dim=3 */
      memcpy_wide_bus_read_float_3d_5_390_64(A_5_1_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
    }
{
      memcpy_wide_bus_read_float_512(&p_5_0_buf[0],(merlin_uint_512 *)p,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
    }
    merlinL5:
    for (i = 0; i < 82; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=q_buf array inter false
      
#pragma HLS pipeline
      merlinL4:
      for (int i_sub = 0; i_sub < 5; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        q_buf[i][i_sub] = ((float )0.0);
        merlinL3:
        for (j = 0; j < 390; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=390 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          s_buf[j] = s_buf[j] + r_5_0_buf[i][i_sub] * A_5_1_buf[i][i_sub][j];
          q_buf[i][i_sub] = q_buf[i][i_sub] + A_5_0_buf[i][i_sub][j] * p_5_0_buf[j];
        }
      }
    }
    merlin_memcpy_2(q,0,q_buf,0,0,sizeof(float ) * ((unsigned long )410),1640UL);
/* Existing HLS partition: #pragma HLS array_partition variable=s_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)s,&s_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )390),390L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=p_5_0_buf cyclic factor = 16 dim=1 */
}
