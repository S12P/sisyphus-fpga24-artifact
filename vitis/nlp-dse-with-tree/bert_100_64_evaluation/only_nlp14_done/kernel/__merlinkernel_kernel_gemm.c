#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 64
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 25
#define SIZE_2 64
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[100][4][25],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[10000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 100 + dst_idx_0) * 4 + dst_idx_1) * 25 + dst_idx_2;
  unsigned long total_offset2 = 0 * 10000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=10000
    dst[(total_offset1 + i) / 25 / 4][(total_offset1 + i) / 25 % 4][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

void kernel_gemm(merlin_uint_512 C[400],float A[10000],merlin_uint_512 B[400])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=10000 bundle=merlin_gmem_kernel_gemm_32_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=400 bundle=merlin_gmem_kernel_gemm_512_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=400 bundle=merlin_gmem_kernel_gemm_512_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=B depth=100,64 max_depth=100,64
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,64 max_depth=100,64
  float B_5_0_buf[4][25][64];
  
#pragma HLS array_partition variable=B_5_0_buf cyclic factor=16 dim=3
  
#pragma HLS array_partition variable=B_5_0_buf complete dim=2
  float A_5_0_buf[100][4][25];
  
#pragma HLS array_partition variable=A_5_0_buf complete dim=3
  float C_buf[100][64];
  
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
  int i;
  int j;
  int k;
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
  memcpy_wide_bus_read_float_2d_64_512(C_buf,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
{
    merlin_memcpy_0(A_5_0_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )10000L),40000UL);
  }
{
    memcpy_wide_bus_read_float_3d_25_64_512(B_5_0_buf,0,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
  }
  merlinL4:
  for (i = 0; i < 100; i++) {
    merlinL3:
    for (j = 0; j < 64; j++) {
      C_buf[i][j] = ((float )0);
      merlinL2:
      for (k = 0; k < 4; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL1:
        for (int k_sub = 0; k_sub < 25; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          C_buf[i][j] += A_5_0_buf[i][k][k_sub] * B_5_0_buf[k][k_sub][j];
        }
      }
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
  memcpy_wide_bus_write_float_2d_64_512((merlin_uint_512 *)C,C_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )6400L),6400L);
}
/* Existing HLS partition: #pragma HLS array_partition variable=B_5_0_buf cyclic factor = 16 dim=3 */
