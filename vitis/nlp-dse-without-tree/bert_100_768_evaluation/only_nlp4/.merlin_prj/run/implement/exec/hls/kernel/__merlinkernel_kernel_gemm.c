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

static void merlin_memcpy_0(float dst[25][4][256][3],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[76800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 25 + dst_idx_0) * 4 + dst_idx_1) * 256 + dst_idx_2) * 3 + dst_idx_3;
  unsigned long total_offset2 = 0 * 76800 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=76800
    dst[(total_offset1 + i) / 3 / 256 / 4][(total_offset1 + i) / 3 / 256 % 4][(total_offset1 + i) / 3 % 256][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[100][256][3],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[76800],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 100 + dst_idx_0) * 256 + dst_idx_1) * 3 + dst_idx_2;
  unsigned long total_offset2 = 0 * 76800 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=76800
    dst[(total_offset1 + i) / 3 / 256][(total_offset1 + i) / 3 % 256][(total_offset1 + i) % 3] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[76800],int dst_idx_0,float src[25][4][256][3],int src_idx_0,int src_idx_1,int src_idx_2,int src_idx_3,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1,src_idx_2,src_idx_3
  unsigned long i;
  unsigned long total_offset1 = 0 * 76800 + dst_idx_0;
  unsigned long total_offset2 = (((0 * 25 + src_idx_0) * 4 + src_idx_1) * 256 + src_idx_2) * 3 + src_idx_3;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=76800
    dst[total_offset1 + i] = src[(total_offset2 + i) / 3 / 256 / 4][(total_offset2 + i) / 3 / 256 % 4][(total_offset2 + i) / 3 % 256][(total_offset2 + i) % 3];
  }
}

void kernel_gemm(float C[76800],merlin_uint_128 A[2500],float B[76800])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=2500 bundle=merlin_gmem_kernel_gemm_128_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=76800 bundle=merlin_gmem_kernel_gemm_32_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=76800 bundle=merlin_gmem_kernel_gemm_32_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=B depth=100,768 max_depth=100,768
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,768 max_depth=100,768
  float B_6_0_buf[100][256][3];
  
#pragma HLS array_partition variable=B_6_0_buf complete dim=3
  
#pragma HLS array_partition variable=B_6_0_buf complete dim=1
  float A_6_0_buf[25][4][100];
  
#pragma HLS array_partition variable=A_6_0_buf complete dim=3
  
#pragma HLS array_partition variable=A_6_0_buf complete dim=2
  float C_buf[25][4][256][3];
  
#pragma HLS array_partition variable=C_buf complete dim=4
  
#pragma HLS array_partition variable=C_buf complete dim=2
  int i;
  int j;
  int k;
  merlin_memcpy_0(C_buf,0,0,0,0,C,0,sizeof(float ) * ((unsigned long )76800L),307200UL);
{
    memcpy_wide_bus_read_float_3d_4_100_128(A_6_0_buf,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    merlin_memcpy_1(B_6_0_buf,0,0,0,B,0,sizeof(float ) * ((unsigned long )76800L),307200UL);
  }
  merlinL7:
  for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
{
    merlinL6:
    for (j = 0; j < 256; j++) 
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
  merlin_memcpy_2(C,0,C_buf,0,0,0,0,sizeof(float ) * ((unsigned long )76800L),307200UL);
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 4 dim=3 */
