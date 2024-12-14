#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 50
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 200
#include "memcpy_256_2d.h"
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

static void merlin_memcpy_2(float dst[50][80][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[160000],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 50 + dst_idx_0) * 80 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 160000 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=20000
    dst[(total_offset1 + i) / 5 / 80][(total_offset1 + i) / 5 % 80][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_3(float dst[160000],long dst_idx_0,float src[50][80][5],int src_idx_0,int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 160000 + dst_idx_0;
  unsigned long total_offset2 = ((0 * 50 + src_idx_0) * 80 + src_idx_1) * 5 + src_idx_2;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=20000
    dst[total_offset1 + i] = src[(total_offset2 + i) / 5 / 80][(total_offset2 + i) / 5 % 80][(total_offset2 + i) % 5];
  }
}

static void merlin_memcpy_4(float dst[50][80][5],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[160000],long src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 50 + dst_idx_0) * 80 + dst_idx_1) * 5 + dst_idx_2;
  unsigned long total_offset2 = 0 * 160000 + src_idx_0;
  merlinL4:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=20000
    dst[(total_offset1 + i) / 5 / 80][(total_offset1 + i) / 5 % 80][(total_offset1 + i) % 5] = src[total_offset2 + i];
  }
}

void kernel_gemver(float alpha,float beta,float A[160000],merlin_uint_64 u1[200],float v1[400],merlin_uint_64 u2[200],float v2[400],merlin_uint_64 w[200],merlin_uint_512 x[25],merlin_uint_64 y[200],merlin_uint_256 z[50])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=160000 bundle=merlin_gmem_kernel_gemver_32_A
  
#pragma HLS INTERFACE m_axi port=u1 offset=slave depth=200 bundle=merlin_gmem_kernel_gemver_64_0
  
#pragma HLS INTERFACE m_axi port=u2 offset=slave depth=200 bundle=merlin_gmem_kernel_gemver_64_1
  
#pragma HLS INTERFACE m_axi port=v1 offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_0
  
#pragma HLS INTERFACE m_axi port=v2 offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_1
  
#pragma HLS INTERFACE m_axi port=w offset=slave depth=200 bundle=merlin_gmem_kernel_gemver_64_w
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_x
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=200 bundle=merlin_gmem_kernel_gemver_64_2
  
#pragma HLS INTERFACE m_axi port=z offset=slave depth=50 bundle=merlin_gmem_kernel_gemver_256_0
  
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
    float z_8_0_buf[2][200];
    
#pragma HLS array_partition variable=z_8_0_buf complete dim=2
    float v2_13_0_buf[80][5];
    
#pragma HLS array_partition variable=v2_13_0_buf complete dim=2
    float u2_13_0_buf[8][50];
    
#pragma HLS array_partition variable=u2_13_0_buf complete dim=2
    float v1_13_0_buf[80][5];
    
#pragma HLS array_partition variable=v1_13_0_buf complete dim=2
    float u1_13_0_buf[8][50];
    
#pragma HLS array_partition variable=u1_13_0_buf complete dim=2
    float y_14_0_buf[8][50];
    
#pragma HLS array_partition variable=y_14_0_buf complete dim=2
    float w_buf[8][50];
    
#pragma HLS array_partition variable=w_buf complete dim=2
    float x_buf[400];
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=x_buf complete dim=1
    memcpy_wide_bus_read_float_512(&x_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_2d_50_64(u1_13_0_buf,0,0,(merlin_uint_64 *)u1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      merlin_memcpy_0(v1_13_0_buf,0,0,v1,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
{
      memcpy_wide_bus_read_float_2d_50_64(u2_13_0_buf,0,0,(merlin_uint_64 *)u2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      merlin_memcpy_1(v2_13_0_buf,0,0,v2,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
    merlinL18:
    for (i = 0; i < 8; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
{
      float A_buf[50][80][5];
      
#pragma HLS array_partition variable=A_buf complete dim=3
      
#pragma HLS array_partition variable=A_buf complete dim=1
      merlin_memcpy_2(A_buf,0,0,0,A,((long )i) * 20000L,sizeof(float ) * ((unsigned long )20000L),80000UL);
      merlinL17:
      for (j = 0; j < 80; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=A_buf array inter false
        
#pragma HLS pipeline
        merlinL16:
        for (int i_sub_2 = 0; i_sub_2 < 50; ++i_sub_2) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL15:
          for (int j_sub_1 = 0; j_sub_1 < 5; ++j_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            A_buf[i_sub_2][j][j_sub_1] = A_buf[i_sub_2][j][j_sub_1] + u1_13_0_buf[i][i_sub_2] * v1_13_0_buf[j][j_sub_1] + u2_13_0_buf[i][i_sub_2] * v2_13_0_buf[j][j_sub_1];
          }
        }
      }
      merlin_memcpy_3(A,((long )i) * 20000L,A_buf,0,0,0,sizeof(float ) * ((unsigned long )20000L),80000UL);
    }
{
      memcpy_wide_bus_read_float_2d_50_64(y_14_0_buf,0,0,(merlin_uint_64 *)y,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL14:
    for (i = 0; i < 80; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
{
      float A_buf[8][50][400];
      
#pragma HLS array_partition variable=A_buf cyclic factor=5 dim=3
      
#pragma HLS array_partition variable=A_buf complete dim=2
      merlinL13:
      for (j = 0; j < 8; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL12:
        for (int i_sub_1 = 0; i_sub_1 < 5; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL11:
          for (int j_sub_0 = 0; j_sub_0 < 50; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            x_buf[i * 5 + i_sub_1] = x_buf[i * 5 + i_sub_1] + beta * A_buf[j][j_sub_0][i_sub_1] * y_14_0_buf[j][j_sub_0];
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_2d_200_256(z_8_0_buf,0,0,(merlin_uint_256 *)z,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL10:
    for (i = 0; i < 2; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=x_buf array inter false
      
#pragma HLS pipeline
      merlinL9:
      for (int i_sub_0 = 0; i_sub_0 < 200; ++i_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        x_buf[i * 200 + i_sub_0] = x_buf[i * 200 + i_sub_0] + z_8_0_buf[i][i_sub_0];
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_read_float_2d_50_64(w_buf,0,0,(merlin_uint_64 *)w,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    merlinL8:
    for (i = 0; i < 8; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
/* Original: #pragma ACCEL PARALLEL FACTOR=50 */
{
      float A_15_0_buf[50][80][5];
      
#pragma HLS array_partition variable=A_15_0_buf complete dim=3
      
#pragma HLS array_partition variable=A_15_0_buf complete dim=1
{
        merlin_memcpy_4(A_15_0_buf,0,0,0,A,((long )i) * 20000L,sizeof(float ) * ((unsigned long )20000L),80000UL);
      }
      merlinL7:
      for (j = 0; j < 80; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL6:
        for (int i_sub = 0; i_sub < 50; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL5:
          for (int j_sub = 0; j_sub < 5; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=5 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            w_buf[i][i_sub] = w_buf[i][i_sub] + alpha * A_15_0_buf[i_sub][j][j_sub] * x_buf[j * 5 + j_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_50_64((merlin_uint_64 *)w,w_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)x,&x_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=u1_13_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=u2_13_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_14_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=z_8_0_buf cyclic factor = 8 dim=2 */
}
