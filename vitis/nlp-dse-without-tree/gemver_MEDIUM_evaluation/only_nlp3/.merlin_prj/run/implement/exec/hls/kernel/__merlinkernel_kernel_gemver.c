#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 400
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 100
#include "memcpy_128_2d.h"
#undef SIZE_1
#define SIZE_1 1
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_gemver_L_3_para_sub(float alpha,int i,int j,float A_buf[400],float w_buf[1],float x_buf_dup[400])
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
  
#pragma HLS inline off
  merlinL4:
  for (j = 0; j < 200; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS pipeline
    merlinL3:
    for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
      
#pragma HLS unroll
      w_buf[0] = w_buf[0] + alpha * A_buf[((long )j) * 2L + ((long )j_sub)] * x_buf_dup[j * 2 + j_sub];
    }
  }
}

void kernel_gemver_L_3_para(float alpha,int j,float A_buf[400][400],float w_buf[400][1],float x_buf_dup[400][400])
{
  
#pragma HLS inline off
  int i;
  merlinL2:
  for (i = 0; i < 400; ++i) {
    
#pragma HLS unroll complete
    kernel_gemver_L_3_para_sub(alpha,i,j,A_buf[i],w_buf[i],x_buf_dup[i]);
  }
}

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

static void merlin_memcpy_1(float dst[80][5],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 80 + dst_idx_0) * 5 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[(total_offset1 + i) / 5][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

void kernel_gemver(float alpha,float beta,merlin_uint_512 A[10000],merlin_uint_128 u1[100],float v1[400],merlin_uint_128 u2[100],float v2[400],merlin_uint_512 w[25],merlin_uint_512 x[25],merlin_uint_512 y[25],merlin_uint_512 z[25])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=10000 bundle=merlin_gmem_kernel_gemver_512_A
  
#pragma HLS INTERFACE m_axi port=u1 offset=slave depth=100 bundle=merlin_gmem_kernel_gemver_128_0
  
#pragma HLS INTERFACE m_axi port=u2 offset=slave depth=100 bundle=merlin_gmem_kernel_gemver_128_1
  
#pragma HLS INTERFACE m_axi port=v1 offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_0
  
#pragma HLS INTERFACE m_axi port=v2 offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_1
  
#pragma HLS INTERFACE m_axi port=w offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_w
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_x
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_0
  
#pragma HLS INTERFACE m_axi port=z offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_1
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=u1 bundle=control
  
#pragma HLS INTERFACE s_axilite port=u2 bundle=control
  
#pragma HLS INTERFACE s_axilite port=v1 bundle=control
  
#pragma HLS INTERFACE s_axilite port=v2 bundle=control
  
#pragma HLS INTERFACE s_axilite port=w bundle=control
  
#pragma HLS INTERFACE s_axilite port=x bundle=control
  
#pragma HLS INTERFACE s_axilite port=y bundle=control
  
#pragma HLS INTERFACE s_axilite port=z bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=z
  
#pragma HLS DATA_PACK VARIABLE=y
  
#pragma HLS DATA_PACK VARIABLE=x
  
#pragma HLS DATA_PACK VARIABLE=w
  
#pragma HLS DATA_PACK VARIABLE=u2
  
#pragma HLS DATA_PACK VARIABLE=u1
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=z depth=400 max_depth=400
  
#pragma ACCEL interface variable=y depth=400 max_depth=400
  
#pragma ACCEL interface variable=x depth=400 max_depth=400
  
#pragma ACCEL interface variable=w depth=400 max_depth=400
  
#pragma ACCEL interface variable=v2 depth=400 max_depth=400
  
#pragma ACCEL interface variable=u2 depth=400 max_depth=400
  
#pragma ACCEL interface variable=v1 depth=400 max_depth=400
  
#pragma ACCEL interface variable=u1 depth=400 max_depth=400
  
#pragma ACCEL interface variable=A depth=400,400 max_depth=400,400
  int i;
  int j;
{
    float z_4_0_buf[400];
    
#pragma HLS array_partition variable=z_4_0_buf complete dim=1
    float y_10_0_buf[400];
    
#pragma HLS array_partition variable=y_10_0_buf complete dim=1
    float v2_12_0_buf[80][5];
    
#pragma HLS array_partition variable=v2_12_0_buf complete dim=2
    float u2_12_0_buf[4][100];
    
#pragma HLS array_partition variable=u2_12_0_buf complete dim=2
    float v1_12_0_buf[80][5];
    
#pragma HLS array_partition variable=v1_12_0_buf complete dim=2
    float u1_12_0_buf[4][100];
    
#pragma HLS array_partition variable=u1_12_0_buf complete dim=2
    float A_buf[400][400];
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf dim=1 complete */
    
#pragma HLS array_partition variable=A_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=A_buf complete dim=1
    float x_buf[400];
    
#pragma HLS array_partition variable=x_buf complete dim=1
    float w_buf[400][1];
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf dim=1 complete */
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=w_buf complete dim=2
    
#pragma HLS array_partition variable=w_buf complete dim=1
    memcpy_wide_bus_read_float_512(&x_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_read_float_2d_400_512(A_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
{
      memcpy_wide_bus_read_float_2d_100_128(u1_12_0_buf,0,0,(merlin_uint_128 *)u1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      merlin_memcpy_0(v1_12_0_buf,0,0,v1,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
{
      memcpy_wide_bus_read_float_2d_100_128(u2_12_0_buf,0,0,(merlin_uint_128 *)u2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      merlin_memcpy_1(v2_12_0_buf,0,0,v2,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
    merlinL15:
    for (i = 0; i < 4; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
{
      merlinL14:
      for (j = 0; j < 80; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=A_buf array inter false
        
#pragma HLS pipeline
        merlinL13:
        for (int i_sub_0 = 0; i_sub_0 < 100; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL12:
          for (int j_sub_0 = 0; j_sub_0 < 5; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            A_buf[((long )i) * 100L + ((long )i_sub_0)][((long )j) * 5L + ((long )j_sub_0)] = A_buf[((long )i) * 100L + ((long )i_sub_0)][((long )j) * 5L + ((long )j_sub_0)] + u1_12_0_buf[i][i_sub_0] * v1_12_0_buf[j][j_sub_0] + u2_12_0_buf[i][i_sub_0] * v2_12_0_buf[j][j_sub_0];
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_512(&y_10_0_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL11:
    for (i = 0; i < 200; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=x_buf array inter false
      
#pragma HLS pipeline
      merlinL10:
      for (int i_sub = 0; i_sub < 2; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        merlinL9:
        for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          x_buf[i * 2 + i_sub] = x_buf[i * 2 + i_sub] + beta * A_buf[j][((long )i) * 2L + ((long )i_sub)] * y_10_0_buf[j];
        }
      }
    }
{
      memcpy_wide_bus_read_float_512(&z_4_0_buf[0],(merlin_uint_512 *)z,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL8:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS unroll
      x_buf[i] = x_buf[i] + z_4_0_buf[i];
    }
{
      memcpy_wide_bus_read_float_2d_1_512(w_buf,0,0,(merlin_uint_512 *)w,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    float x_buf_dup[400][400];
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=x_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      merlinL7:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 399UL; ++_i1) {
        
#pragma HLS pipeline
        merlinL6:
        for (_i0 = ((long )0); ((unsigned long )_i0) <= 399UL; ++_i0) {
          
#pragma HLS unroll
          x_buf_dup[_i0][_i1] = x_buf[_i1];
        }
      }
    }
    kernel_gemver_L_3_para(alpha,j,A_buf,w_buf,x_buf_dup);
    merlinL5:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
    }{
      memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)w,w_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)x,&x_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_write_float_2d_400_512((merlin_uint_512 *)A,A_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )160000L),160000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=u1_12_0_buf cyclic factor = 4 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=u2_12_0_buf cyclic factor = 4 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_10_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=z_4_0_buf cyclic factor = 16 dim=1 */
}
