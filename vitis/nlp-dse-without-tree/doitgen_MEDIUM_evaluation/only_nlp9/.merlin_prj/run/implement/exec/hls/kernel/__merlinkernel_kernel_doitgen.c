#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#define SIZE_1 40
#define SIZE_2 60
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 4
#define SIZE_2 15
#define SIZE_3 4
#include "memcpy_128_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[4][1],int dst_idx_0,int dst_idx_1,float src[60],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 4 + dst_idx_0) * 1 + dst_idx_1;
  unsigned long total_offset2 = 0 * 60 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=4
    dst[(total_offset1 + i) / 1][(total_offset1 + i) % 1] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[60],int dst_idx_0,float src[4][1],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 60 + dst_idx_0;
  unsigned long total_offset2 = (0 * 4 + src_idx_0) * 1 + src_idx_1;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=4
    dst[total_offset1 + i] = src[(total_offset2 + i) / 1][(total_offset2 + i) % 1];
  }
}

static void merlin_memcpy_2(float dst[4][15],int dst_idx_0,int dst_idx_1,float src[60],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 4 + dst_idx_0) * 15 + dst_idx_1;
  unsigned long total_offset2 = 0 * 60 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=60
    dst[(total_offset1 + i) / 15][(total_offset1 + i) % 15] = src[total_offset2 + i];
  }
}

void kernel_doitgen(merlin_uint_128 A[30000],merlin_uint_128 C4[900],float sum[60])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=30000 bundle=merlin_gmem_kernel_doitgen_128_A
  
#pragma HLS INTERFACE m_axi port=C4 offset=slave depth=900 bundle=merlin_gmem_kernel_doitgen_128_0
  
#pragma HLS INTERFACE m_axi port=sum offset=slave depth=60 bundle=merlin_gmem_kernel_doitgen_32_sum
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=C4 bundle=control
  
#pragma HLS INTERFACE s_axilite port=sum bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=C4
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=sum depth=60 max_depth=60
  
#pragma ACCEL interface variable=C4 depth=60,60 max_depth=60,60
  
#pragma ACCEL interface variable=A depth=50,40,60 max_depth=50,40,60
  int r;
  int q;
  int p;
  int s;
{
    float C4_9_0_buf[15][4][15][4];
    
#pragma HLS array_partition variable=C4_9_0_buf complete dim=4
    
#pragma HLS array_partition variable=C4_9_0_buf complete dim=2
    float A_buf[50][40][60];
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 4 dim=3 */
    
#pragma HLS array_partition variable=A_buf cyclic factor=8 dim=3
    memcpy_wide_bus_read_float_3d_40_60_128(A_buf,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )120000L),120000L);
{
      memcpy_wide_bus_read_float_4d_4_15_4_128(C4_9_0_buf,0,0,0,0,(merlin_uint_128 *)C4,(0 * 4),sizeof(float ) * ((unsigned long )3600L),3600L);
    }
    merlinL10:
    for (r = 0; r < 50; r++) {
      merlinL9:
      for (q = 0; q < 40; q++) {
        float sum_7_0_buf[4][15];
        
#pragma HLS array_partition variable=sum_7_0_buf complete dim=2
        merlinL8:
        for (p = 0; p < 15; p++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
{
          float sum_buf[4][1];
{
            merlin_memcpy_0(sum_buf,0,0,sum,p * 4,sizeof(float ) * ((unsigned long )4),16UL);
          }
          merlinL7:
          for (int p_sub_0 = 0; p_sub_0 < 4; ++p_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL */
{
            sum_buf[((long )p_sub_0) - 0L][0] = ((float )0.0);
            merlinL6:
            for (s = 0; s < 15; s++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL5:
              for (int s_sub = 0; s_sub < 4; ++s_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL */
{
                
#pragma HLS unroll
                sum_buf[((long )p_sub_0) - 0L][0] += A_buf[r][q][((long )s) * 4L + ((long )s_sub)] * C4_9_0_buf[s][s_sub][p][p_sub_0];
              }
            }
          }
{
            merlin_memcpy_1(sum,p * 4,sum_buf,0,0,sizeof(float ) * ((unsigned long )4),16UL);
          }
        }
{
          merlin_memcpy_2(sum_7_0_buf,0,0,sum,0,sizeof(float ) * ((unsigned long )60),240UL);
        }
        merlinL4:
        for (p = 0; p < 4; p++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=A_buf array inter false
          
#pragma HLS pipeline
          merlinL3:
          for (int p_sub = 0; p_sub < 15; ++p_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            A_buf[r][q][((long )p) * 15L + ((long )p_sub)] = sum_7_0_buf[p][p_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 4 dim=3 */
    memcpy_wide_bus_write_float_3d_40_60_128((merlin_uint_128 *)A,A_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )120000L),120000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C4_9_0_buf cyclic factor = 4 dim=4 */
}
