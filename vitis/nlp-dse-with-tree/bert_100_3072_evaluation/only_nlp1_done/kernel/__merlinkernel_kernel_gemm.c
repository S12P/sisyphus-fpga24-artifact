#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#define SIZE_1 4
#define SIZE_2 100
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"





/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[25][4][1024][3],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[307200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 25 + dst_idx_0) * 4 + dst_idx_1) * 1024 + dst_idx_2) * 3 + dst_idx_3;
  unsigned long total_offset2 = 0 * 307200 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=307200
    dst[(total_offset1 + i) / 3 / 1024 / 4][(total_offset1 + i) / 3 / 1024 % 4][(total_offset1 + i) / 3 % 1024][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[100][1024][3],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[307200],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 100 + dst_idx_0) * 1024 + dst_idx_1) * 3 + dst_idx_2;
  unsigned long total_offset2 = 0 * 307200 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=307200
    dst[(total_offset1 + i) / 3 / 1024][(total_offset1 + i) / 3 % 1024][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[307200],int dst_idx_0,float src[25][4][1024][3],int src_idx_0,int src_idx_1,int src_idx_2,int src_idx_3,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1,src_idx_2,src_idx_3
  unsigned long i;
  unsigned long total_offset1 = 0 * 307200 + dst_idx_0;
  unsigned long total_offset2 = (((0 * 25 + src_idx_0) * 4 + src_idx_1) * 1024 + src_idx_2) * 3 + src_idx_3;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=307200
    dst[total_offset1 + i] = src[(total_offset2 + i) / 3 / 1024 / 4][(total_offset2 + i) / 3 / 1024 % 4][(total_offset2 + i) / 3 % 1024][(total_offset2 + i) % 3];
  }
}

void kernel_gemm(float C[307200],merlin_uint_128 A[2500],float B[307200])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=2500 bundle=merlin_gmem_kernel_gemm_128_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=307200 bundle=merlin_gmem_kernel_gemm_32_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=307200 bundle=merlin_gmem_kernel_gemm_32_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=B depth=100,3072 max_depth=100,3072
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,3072 max_depth=100,3072
  float B_6_0_buf[100][1024][3];
  
#pragma HLS array_partition variable=B_6_0_buf complete dim=3
  
#pragma HLS array_partition variable=B_6_0_buf complete dim=1
  float A_6_0_buf[25][4][100];
  
#pragma HLS array_partition variable=A_6_0_buf complete dim=3
  
#pragma HLS array_partition variable=A_6_0_buf complete dim=2
  float C_buf[25][4][1024][3];
  
#pragma HLS array_partition variable=C_buf complete dim=4
  
#pragma HLS array_partition variable=C_buf complete dim=2
  int i;
  int j;
  int k;
  merlin_memcpy_0(C_buf,0,0,0,0,C,0,sizeof(float ) * ((unsigned long )307200L),1228800UL);
{
    memcpy_wide_bus_read_float_3d_4_100_128(A_6_0_buf,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    merlin_memcpy_1(B_6_0_buf,0,0,0,B,0,sizeof(float ) * ((unsigned long )307200L),1228800UL);
  }
  merlinL7:
  for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
{
    merlinL6:
    for (j = 0; j < 1024; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=C_buf array inter false
      
#pragma HLS pipeline
      merlinL5:
      for (int i_sub = 0; i_sub < 4; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        merlinL4:
        for (int j_sub = 0; j_sub < 3; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          C_buf[i][i_sub][j][j_sub] = ((float )0);
          merlinL3:
          for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            C_buf[i][i_sub][j][j_sub] += A_6_0_buf[i][i_sub][k] * B_6_0_buf[k][j][j_sub];
          }
        }
      }
    }
  }
  merlin_memcpy_2(C,0,C_buf,0,0,0,0,sizeof(float ) * ((unsigned long )307200L),1228800UL);
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 4 dim=3 */
