#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"





/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[200][48][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[48000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 200 + dst_idx_0) * 48 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 48000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=48000
    dst[(total_offset1 + i) / 5 / 48][(total_offset1 + i) / 5 % 48][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[48000],int dst_idx_0,float src[200][48][5],int src_idx_0,int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 48000 + dst_idx_0;
  unsigned long total_offset2 = ((0 * 200 + src_idx_0) * 48 + src_idx_1) * 5 + src_idx_2;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=48000
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5 / 48][(total_offset2 + i) / 5 % 48][(total_offset2 + i) % 5];
  }
}

void kernel_trmm(float alpha,merlin_uint_256 A[5000],float B[48000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=5000 bundle=merlin_gmem_kernel_trmm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=48000 bundle=merlin_gmem_kernel_trmm_32_B
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=B depth=200,240 max_depth=200,240
  
#pragma ACCEL interface variable=A depth=200,200 max_depth=200,200
  int i;
  int j;
  int k;
//BLAS parameters
//SIDE   = 'L'
//UPLO   = 'L'
//TRANSA = 'T'
//DIAG   = 'U'
// => Form  B := alpha*A**T*B.
// A is MxM
// B is MxN
{
    float B_buf[200][48][5];
    merlin_memcpy_0(B_buf,0,0,0,B,0,sizeof(float ) * ((unsigned long )48000L),192000UL);
    merlinL6:
    for (i = 0; i < 2; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
{
      merlinL5:
      for (int i_sub = 0; i_sub < 100; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PARALLEL */
{
        float A_6_0_buf[199][200];
        
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=8 dim=2
{
          memcpy_wide_bus_read_float_2d_200_256(A_6_0_buf,(size_t )0,(size_t )0,(merlin_uint_256 *)A,(size_t )((200L + ((long )(i * 20100)) + ((long )(i_sub * 201))) * ((long )4)),sizeof(float ) * ((unsigned long )(39601L + ((long )(i * - 20000)) + ((long )(i_sub * - 200)))),(size_t )39800L);
        }
        merlinL4:
        for (j = 0; j < 48; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
{
          merlinL3:
          for (int j_sub = 0; j_sub < 5; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            merlinL2:
            for (k = i * 100 + i_sub + 1; k < 200; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              
#pragma HLS LOOP_TRIPCOUNT max=199
              B_buf[((long )i) * 100L + ((long )i_sub)][j][j_sub] += A_6_0_buf[((long )(- 1 + -i_sub)) + ((long )i) * - 100L + ((long )k)][0] * B_buf[k][j][j_sub];
            }
            B_buf[((long )i) * 100L + ((long )i_sub)][j][j_sub] = alpha * B_buf[((long )i) * 100L + ((long )i_sub)][j][j_sub];
          }
        }
      }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 8 dim=2 */
    }
    merlin_memcpy_1(B,0,B_buf,0,0,0,sizeof(float ) * ((unsigned long )48000L),192000UL);
  }
}
