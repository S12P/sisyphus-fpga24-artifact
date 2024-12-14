#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#include <string.h> 

#include "merlin_type_define.h"




/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[400][16][25],int dst_idx_0,int dst_idx_1,int dst_idx_2,float src[160000],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,dst_idx_2,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = ((0 * 400 + dst_idx_0) * 16 + dst_idx_1) * 25 + dst_idx_2;
  unsigned long total_offset2 = 0 * 160000 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=160000
    dst[(total_offset1 + i) / 25 / 16][(total_offset1 + i) / 25 % 16][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_1(float dst[16][25],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 16 + dst_idx_0) * 25 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL1:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[(total_offset1 + i) / 25][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_2(float dst[16][25],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 16 + dst_idx_0) * 25 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL2:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[(total_offset1 + i) / 25][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_3(float dst[25][1],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 25 + dst_idx_0) * 1 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL3:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=25
    dst[(total_offset1 + i) / 1][(total_offset1 + i) % 1] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_4(float dst[400],int dst_idx_0,float src[25][1],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 400 + dst_idx_0;
  unsigned long total_offset2 = (0 * 25 + src_idx_0) * 1 + src_idx_1;
  merlinL4:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=25
    dst[total_offset1 + i] = src[(total_offset2 + i) / 1][(total_offset2 + i) % 1];
  }
}

static void merlin_memcpy_5(float dst[16][25],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 16 + dst_idx_0) * 25 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL5:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[(total_offset1 + i) / 25][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_6(float dst[16][25],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 16 + dst_idx_0) * 25 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL6:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[(total_offset1 + i) / 25][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_7(float dst[400],int dst_idx_0,float src[16][25],int src_idx_0,int src_idx_1,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1
  unsigned long i;
  unsigned long total_offset1 = 0 * 400 + dst_idx_0;
  unsigned long total_offset2 = (0 * 16 + src_idx_0) * 25 + src_idx_1;
  merlinL7:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[total_offset1 + i] = src[(total_offset2 + i) / 25][(total_offset2 + i) % 25];
  }
}

static void merlin_memcpy_8(float dst[16][25],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 16 + dst_idx_0) * 25 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL8:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[(total_offset1 + i) / 25][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

static void merlin_memcpy_9(float dst[160000],int dst_idx_0,float src[400][16][25],int src_idx_0,int src_idx_1,int src_idx_2,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,src_idx_0,src_idx_1,src_idx_2
  unsigned long i;
  unsigned long total_offset1 = 0 * 160000 + dst_idx_0;
  unsigned long total_offset2 = ((0 * 400 + src_idx_0) * 16 + src_idx_1) * 25 + src_idx_2;
  merlinL9:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=160000
    dst[total_offset1 + i] = src[(total_offset2 + i) / 25 / 16][(total_offset2 + i) / 25 % 16][(total_offset2 + i) % 25];
  }
}

void kernel_gemver(float alpha,float beta,float A[160000],merlin_uint_512 u1[25],float v1[400],merlin_uint_512 u2[25],float v2[400],merlin_uint_512 w[25],float x[400],merlin_uint_512 y[25],float z[400])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=160000 bundle=merlin_gmem_kernel_gemver_32_A
  
#pragma HLS INTERFACE m_axi port=u1 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_0
  
#pragma HLS INTERFACE m_axi port=u2 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_1
  
#pragma HLS INTERFACE m_axi port=v1 offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_0
  
#pragma HLS INTERFACE m_axi port=v2 offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_1
  
#pragma HLS INTERFACE m_axi port=w offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_w
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_x
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_2
  
#pragma HLS INTERFACE m_axi port=z offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_2
  
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
  
#pragma HLS DATA_PACK VARIABLE=y
  
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
    float z_8_0_buf[16][25];
    
#pragma HLS array_partition variable=z_8_0_buf complete dim=2
    float v2_10_0_buf[16][25];
    
#pragma HLS array_partition variable=v2_10_0_buf complete dim=2
    float u2_10_0_buf[400];
    
#pragma HLS array_partition variable=u2_10_0_buf cyclic factor=16 dim=1
    float v1_10_0_buf[16][25];
    
#pragma HLS array_partition variable=v1_10_0_buf complete dim=2
    float u1_10_0_buf[400];
    
#pragma HLS array_partition variable=u1_10_0_buf cyclic factor=16 dim=1
    float y_11_0_buf[400];
    
#pragma HLS array_partition variable=y_11_0_buf cyclic factor=16 dim=1
    float x_12_0_buf[16][25];
    
#pragma HLS array_partition variable=x_12_0_buf complete dim=2
    float w_buf[400];
    
#pragma HLS array_partition variable=w_buf cyclic factor=16 dim=1
    float x_buf_0[16][25];
    
#pragma HLS array_partition variable=x_buf_0 complete dim=2
    float A_buf[400][16][25];
    
#pragma HLS array_partition variable=A_buf complete dim=3
    merlin_memcpy_0(A_buf,0,0,0,A,0,sizeof(float ) * ((unsigned long )160000L),640000UL);
{
      memcpy_wide_bus_read_float_512(&u1_10_0_buf[0],(merlin_uint_512 *)u1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      merlin_memcpy_1(v1_10_0_buf,0,0,v1,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
{
      memcpy_wide_bus_read_float_512(&u2_10_0_buf[0],(merlin_uint_512 *)u2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      merlin_memcpy_2(v2_10_0_buf,0,0,v2,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
    merlinL20:
    for (i = 0; i < 400; i++) {
      merlinL19:
      for (j = 0; j < 16; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=A_buf array inter false
        
#pragma HLS pipeline
        merlinL18:
        for (int j_sub_0 = 0; j_sub_0 < 25; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          A_buf[i][j][j_sub_0] = A_buf[i][j][j_sub_0] + u1_10_0_buf[i] * v1_10_0_buf[j][j_sub_0] + u2_10_0_buf[i] * v2_10_0_buf[j][j_sub_0];
        }
      }
    }
{
      memcpy_wide_bus_read_float_512(&y_11_0_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL17:
    for (i = 0; i < 16; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
{
      float x_buf[25][1];
{
        merlin_memcpy_3(x_buf,0,0,x,i * 25,sizeof(float ) * ((unsigned long )25),100UL);
      }
      merlinL16:
      for (int i_sub_0 = 0; i_sub_0 < 25; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL15:
        for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PIPELINE AUTO */
{
          
#pragma HLS pipeline
          x_buf[((long )i_sub_0) - 0L][0] = x_buf[((long )i_sub_0) - 0L][0] + beta * A_buf[j][i][i_sub_0] * y_11_0_buf[j];
        }
      }
{
        merlin_memcpy_4(x,i * 25,x_buf,0,0,sizeof(float ) * ((unsigned long )25),100UL);
      }
    }
    merlin_memcpy_5(x_buf_0,0,0,x,0,sizeof(float ) * ((unsigned long )400),1600UL);
{
      merlin_memcpy_6(z_8_0_buf,0,0,z,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
    merlinL14:
    for (i = 0; i < 16; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=x_buf_0 array inter false
      
#pragma HLS pipeline
      merlinL13:
      for (int i_sub = 0; i_sub < 25; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        x_buf_0[i][i_sub] = x_buf_0[i][i_sub] + z_8_0_buf[i][i_sub];
      }
    }
    merlin_memcpy_7(x,0,x_buf_0,0,0,sizeof(float ) * ((unsigned long )400),1600UL);
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&w_buf[0],(merlin_uint_512 *)w,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      merlin_memcpy_8(x_12_0_buf,0,0,x,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
    merlinL12:
    for (i = 0; i < 400; i++) {
      merlinL11:
      for (j = 0; j < 16; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL10:
        for (int j_sub = 0; j_sub < 25; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          w_buf[i] = w_buf[i] + alpha * A_buf[i][j][j_sub] * x_12_0_buf[j][j_sub];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)w,&w_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
    merlin_memcpy_9(A,0,A_buf,0,0,0,sizeof(float ) * ((unsigned long )160000L),640000UL);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=u1_10_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=u2_10_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_11_0_buf cyclic factor = 16 dim=1 */
}
