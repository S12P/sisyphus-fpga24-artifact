#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#define SIZE_1 128
#define SIZE_2 6
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 5
#define SIZE_2 128
#define SIZE_3 6
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[10][10][20][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,int dst_idx_3,float src[10000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,dst_idx_3,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (((0 * 10 + dst_idx_0) * 10 + dst_idx_1) * 20 + dst_idx_2) * 5 + dst_idx_3;
  unsigned long total_offset2 = 0 * 10000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=10000
    dst[(total_offset1 + i) / 5 / 20 / 10][(total_offset1 + i) / 5 / 20 % 10][(total_offset1 + i) / 5 % 20][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

void kernel_gemm(merlin_uint_64 C[38400],float A[10000],merlin_uint_64 B[38400])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=10000 bundle=merlin_gmem_kernel_gemm_32_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=38400 bundle=merlin_gmem_kernel_gemm_64_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=38400 bundle=merlin_gmem_kernel_gemm_64_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=B depth=100,768 max_depth=100,768
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,768 max_depth=100,768
  float B_7_0_buf[20][5][128][6];
  
#pragma HLS array_partition variable=B_7_0_buf cyclic factor=2 dim=4
  
#pragma HLS array_partition variable=B_7_0_buf complete dim=2
  float A_7_0_buf[10][10][20][5];
  
#pragma HLS array_partition variable=A_7_0_buf complete dim=4
  int i;
  int j;
  int k;
{
    merlin_memcpy_0(A_7_0_buf,0,0,0,0,A,0,sizeof(float ) * ((unsigned long )10000L),40000UL);
  }
{
    memcpy_wide_bus_read_float_4d_5_128_6_64(B_7_0_buf,0,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )76800L),76800L);
  }
  merlinL6:
  for (i = 0; i < 10; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
    float C_buf[10][128][6];
    
#pragma HLS array_partition variable=C_buf cyclic factor=2 dim=3
{
      memcpy_wide_bus_read_float_3d_128_6_64(C_buf,(size_t )0,(size_t )0,(size_t )0,(merlin_uint_64 *)C,(size_t )(((long )i) * 7680L * ((long )4)),sizeof(float ) * ((unsigned long )7680L),(size_t )7680L);
    }
    merlinL5:
    for (int i_sub = 0; i_sub < 10; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
      merlinL4:
      for (j = 0; j < 128; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
{
        merlinL3:
        for (int j_sub = 0; j_sub < 6; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
          C_buf[i_sub][j][j_sub] = ((float )0);
          merlinL2:
          for (k = 0; k < 20; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS pipeline
            merlinL1:
            for (int k_sub = 0; k_sub < 5; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
              
#pragma HLS unroll
              C_buf[i_sub][j][j_sub] += A_7_0_buf[i][i_sub][k][k_sub] * B_7_0_buf[k][k_sub][j][j_sub];
            }
          }
        }
      }
    }
{
      memcpy_wide_bus_write_float_3d_128_6_64((merlin_uint_64 *)C,C_buf,(size_t )0,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 7680L)),sizeof(float ) * ((unsigned long )7680L),(size_t )7680L);
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 2 dim=3 */
}
/* Existing HLS partition: #pragma HLS array_partition variable=B_7_0_buf cyclic factor = 2 dim=4 */
