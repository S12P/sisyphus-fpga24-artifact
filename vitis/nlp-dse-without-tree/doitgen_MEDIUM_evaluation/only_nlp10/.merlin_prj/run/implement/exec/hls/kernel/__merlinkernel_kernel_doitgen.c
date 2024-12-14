#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 15
#define SIZE_2 60
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[50][40][4][15],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[120000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 50 + dst_idx_0) * 40 + dst_idx_1) * 4 + dst_idx_2) * 15 + dst_idx_3;
  unsigned long total_offset2 = 0 * 120000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=120000
    dst[(total_offset1 + i) / 15 / 4 / 40][(total_offset1 + i) / 15 / 4 % 40][(total_offset1 + i) / 15 % 4][(total_offset1 + i) % 15] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[120000],int dst_idx_0,float src[50][40][4][15],int src_idx_0,int src_idx_1,int src_idx_2,int src_idx_3,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1,src_idx_2,src_idx_3
  unsigned long i;
  unsigned long total_offset1 = 0 * 120000 + dst_idx_0;
  unsigned long total_offset2 = (((0 * 50 + src_idx_0) * 40 + src_idx_1) * 4 + src_idx_2) * 15 + src_idx_3;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=120000
    dst[total_offset1 + i] = src[(total_offset2 + i) / 15 / 4 / 40][(total_offset2 + i) / 15 / 4 % 40][(total_offset2 + i) / 15 % 4][(total_offset2 + i) % 15];
  }
}

void kernel_doitgen(float A[120000],merlin_uint_128 C4[900],merlin_uint_512 sum[4])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=120000 bundle=merlin_gmem_kernel_doitgen_32_A
  
#pragma HLS INTERFACE m_axi port=C4 offset=slave depth=900 bundle=merlin_gmem_kernel_doitgen_128_0
  
#pragma HLS INTERFACE m_axi port=sum offset=slave depth=4 bundle=merlin_gmem_kernel_doitgen_512_sum
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=C4 bundle=control
  
#pragma HLS INTERFACE s_axilite port=sum bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=sum
  
#pragma HLS DATA_PACK VARIABLE=C4
  
#pragma ACCEL interface variable=sum depth=60 max_depth=60
  
#pragma ACCEL interface variable=C4 depth=60,60 max_depth=60,60
  
#pragma ACCEL interface variable=A depth=50,40,60 max_depth=50,40,60
  int r;
  int q;
  int p;
  int s;
{
    float C4_8_0_buf[4][15][60];
    
#pragma HLS array_partition variable=C4_8_0_buf cyclic factor=4 dim=3
    
#pragma HLS array_partition variable=C4_8_0_buf complete dim=2
    float sum_buf[60];
    
#pragma HLS array_partition variable=sum_buf cyclic factor=16 dim=1
    float A_buf[50][40][4][15];
    
#pragma HLS array_partition variable=A_buf complete dim=4
    merlin_memcpy_0(A_buf,0,0,0,0,A,0,sizeof(float ) * ((unsigned long )120000L),480000UL);
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&sum_buf[0],(merlin_uint_512 *)sum,(0 * 4),sizeof(float ) * ((unsigned long )60),60L);
{
      memcpy_wide_bus_read_float_3d_15_60_128(C4_8_0_buf,0,0,0,(merlin_uint_128 *)C4,(0 * 4),sizeof(float ) * ((unsigned long )3600L),3600L);
    }
    merlinL8:
    for (r = 0; r < 50; r++) {
      merlinL7:
      for (q = 0; q < 40; q++) {
        merlinL6:
        for (p = 0; p < 60; p++) {
          sum_buf[p] = ((float )0.0);
          merlinL5:
          for (s = 0; s < 4; s++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS pipeline
            merlinL4:
            for (int s_sub = 0; s_sub < 15; ++s_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL */
{
              
#pragma HLS unroll
              sum_buf[p] += A_buf[r][q][s][s_sub] * C4_8_0_buf[s][s_sub][p];
            }
          }
        }
        merlinL3:
        for (p = 0; p < 4; p++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=A_buf array inter false
          
#pragma HLS pipeline
          merlinL2:
          for (int p_sub = 0; p_sub < 15; ++p_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=15 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            A_buf[r][q][p][p_sub] = sum_buf[p * 15 + p_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)sum,&sum_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )60),60L);
    merlin_memcpy_1(A,0,A_buf,0,0,0,0,sizeof(float ) * ((unsigned long )120000L),480000UL);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C4_8_0_buf cyclic factor = 4 dim=3 */
}
