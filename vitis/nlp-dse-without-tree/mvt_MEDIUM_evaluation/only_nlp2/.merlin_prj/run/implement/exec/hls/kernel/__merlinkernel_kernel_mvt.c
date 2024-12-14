#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[80][5],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 80 + dst_idx_0) * 5 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[200][80][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[160000],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 200 + dst_idx_0) * 80 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 160000 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=80000
    dst[(total_offset1 + i) / 5 / 80][(total_offset1 + i) / 5 % 80][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[400][200][2],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[160000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 400 + dst_idx_0) * 200 + dst_idx_1) * 2 + dst_idx_2;
  unsigned long total_offset2 = 0 * 160000 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=160000
    dst[(total_offset1 + i) / 2 / 200][(total_offset1 + i) / 2 % 200][(total_offset1 + i) % 2] = src[total_offset2 + i];
  }
}

void kernel_mvt(merlin_uint_256 x1[50],merlin_uint_512 x2[25],float y_1[400],merlin_uint_512 y_2[25],float A[160000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=160000 bundle=merlin_gmem_kernel_mvt_32_0
  
#pragma HLS INTERFACE m_axi port=x1 offset=slave depth=50 bundle=merlin_gmem_kernel_mvt_256_x1
  
#pragma HLS INTERFACE m_axi port=x2 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_x2
  
#pragma HLS INTERFACE m_axi port=y_1 offset=slave depth=400 bundle=merlin_gmem_kernel_mvt_32_1
  
#pragma HLS INTERFACE m_axi port=y_2 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_0
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=x1 bundle=control
  
#pragma HLS INTERFACE s_axilite port=x2 bundle=control
  
#pragma HLS INTERFACE s_axilite port=y_1 bundle=control
  
#pragma HLS INTERFACE s_axilite port=y_2 bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=y_2
  
#pragma HLS DATA_PACK VARIABLE=x2
  
#pragma HLS DATA_PACK VARIABLE=x1
  
#pragma ACCEL interface variable=A depth=400,400 max_depth=400,400
  
#pragma ACCEL interface variable=y_2 depth=400 max_depth=400
  
#pragma ACCEL interface variable=y_1 depth=400 max_depth=400
  
#pragma ACCEL interface variable=x2 depth=400 max_depth=400
  
#pragma ACCEL interface variable=x1 depth=400 max_depth=400
  int i;
  int j;
{
    float y_2_7_0_buf[400];
    
#pragma HLS array_partition variable=y_2_7_0_buf complete dim=1
    float A_7_0_buf[400][200][2];
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=1
    float y_1_8_0_buf[80][5];
    
#pragma HLS array_partition variable=y_1_8_0_buf complete dim=2
    float x1_buf[2][200];
    
#pragma HLS array_partition variable=x1_buf complete dim=2
    float x2_buf[200][2];
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 8 dim=2 */
    
#pragma HLS array_partition variable=x2_buf complete dim=2
    
#pragma HLS array_partition variable=x2_buf cyclic factor=8 dim=1
    memcpy_wide_bus_read_float_2d_200_256(x1_buf,0,0,(merlin_uint_256 *)x1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      merlin_memcpy_0(y_1_8_0_buf,0,0,y_1,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
    merlinL9:
    for (i = 0; i < 2; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
{
      float A_8_0_buf[200][80][5];
      
#pragma HLS array_partition variable=A_8_0_buf complete dim=3
      
#pragma HLS array_partition variable=A_8_0_buf complete dim=1
{
        merlin_memcpy_1(A_8_0_buf,0,0,0,A,((long )i) * 80000L,sizeof(float ) * ((unsigned long )80000L),320000UL);
      }
      merlinL8:
      for (j = 0; j < 80; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL7:
        for (int i_sub_0 = 0; i_sub_0 < 200; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL6:
          for (int j_sub = 0; j_sub < 5; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            x1_buf[i][i_sub_0] = x1_buf[i][i_sub_0] + A_8_0_buf[i_sub_0][j][j_sub] * y_1_8_0_buf[j][j_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 8 dim=2 */
    memcpy_wide_bus_write_float_2d_200_256((merlin_uint_256 *)x1,x1_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_read_float_2d_2_512(x2_buf,0,0,(merlin_uint_512 *)x2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      merlin_memcpy_2(A_7_0_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )160000L),640000UL);
    }
{
      memcpy_wide_bus_read_float_512(&y_2_7_0_buf[0],(merlin_uint_512 *)y_2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL5:
    for (i = 0; i < 200; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=x2_buf array inter false
      
#pragma HLS pipeline
      merlinL4:
      for (int i_sub = 0; i_sub < 2; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        merlinL3:
        for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          x2_buf[i][i_sub] = x2_buf[i][i_sub] + A_7_0_buf[j][i][i_sub] * y_2_7_0_buf[j];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_write_float_2d_2_512((merlin_uint_512 *)x2,x2_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=y_2_7_0_buf cyclic factor = 16 dim=1 */
}
