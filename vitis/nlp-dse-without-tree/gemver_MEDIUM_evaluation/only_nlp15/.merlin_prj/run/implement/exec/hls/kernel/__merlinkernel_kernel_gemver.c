#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 16
#define SIZE_2 200
#define SIZE_3 2
#include "memcpy_512_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 16
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

static void merlin_memcpy_0(float dst[16][25],int dst_idx_0,int dst_idx_1,float src[400],int src_idx_0,unsigned int len,unsigned int max_len)
{
  
#pragma HLS inline off
  
#pragma HLS function_instantiate variable=dst_idx_0,dst_idx_1,src_idx_0
  unsigned long i;
  unsigned long total_offset1 = (0 * 16 + dst_idx_0) * 25 + dst_idx_1;
  unsigned long total_offset2 = 0 * 400 + src_idx_0;
  merlinL0:
  for (i = 0; i < len / 4; ++i) {
    
#pragma HLS PIPELINE II=1
    
#pragma HLS LOOP_TRIPCOUNT max=400
    dst[(total_offset1 + i) / 25][(total_offset1 + i) % 25] = src[total_offset2 + i];
  }
}

void kernel_gemver(float alpha,float beta,merlin_uint_512 A[10000],merlin_uint_512 u1[25],merlin_uint_512 v1[25],merlin_uint_512 u2[25],merlin_uint_512 v2[25],merlin_uint_512 w[25],merlin_uint_512 x[25],merlin_uint_512 y[25],float z[400])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=10000 bundle=merlin_gmem_kernel_gemver_512_A
  
#pragma HLS INTERFACE m_axi port=u1 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_0
  
#pragma HLS INTERFACE m_axi port=u2 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_1
  
#pragma HLS INTERFACE m_axi port=v1 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_2
  
#pragma HLS INTERFACE m_axi port=v2 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_3
  
#pragma HLS INTERFACE m_axi port=w offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_w
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_x
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_4
  
#pragma HLS INTERFACE m_axi port=z offset=slave depth=400 bundle=merlin_gmem_kernel_gemver_32_0
  
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
  
#pragma HLS DATA_PACK VARIABLE=x
  
#pragma HLS DATA_PACK VARIABLE=w
  
#pragma HLS DATA_PACK VARIABLE=v2
  
#pragma HLS DATA_PACK VARIABLE=u2
  
#pragma HLS DATA_PACK VARIABLE=v1
  
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
    float z_8_0_buf[16][25];
    
#pragma HLS array_partition variable=z_8_0_buf complete dim=2
    float v2_13_0_buf[200][2];
    
#pragma HLS array_partition variable=v2_13_0_buf complete dim=2
    
#pragma HLS array_partition variable=v2_13_0_buf cyclic factor=8 dim=1
    float u2_13_0_buf[25][16];
    
#pragma HLS array_partition variable=u2_13_0_buf complete dim=2
    float v1_13_0_buf[200][2];
    
#pragma HLS array_partition variable=v1_13_0_buf complete dim=2
    
#pragma HLS array_partition variable=v1_13_0_buf cyclic factor=8 dim=1
    float u1_13_0_buf[25][16];
    
#pragma HLS array_partition variable=u1_13_0_buf complete dim=2
    float y_14_0_buf[25][16];
    
#pragma HLS array_partition variable=y_14_0_buf complete dim=2
    float w_buf[25][16];
    
#pragma HLS array_partition variable=w_buf complete dim=2
    float A_buf[25][16][200][2];
    
#pragma HLS array_partition variable=A_buf complete dim=4
    
#pragma HLS array_partition variable=A_buf cyclic factor=8 dim=3
    
#pragma HLS array_partition variable=A_buf complete dim=2
    float x_buf[400];
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=x_buf cyclic factor=25 dim=1
    memcpy_wide_bus_read_float_512(&x_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 8 dim=3 */
    memcpy_wide_bus_read_float_4d_16_200_2_512(A_buf,0,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
{
      memcpy_wide_bus_read_float_2d_16_512(u1_13_0_buf,0,0,(merlin_uint_512 *)u1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_2d_2_512(v1_13_0_buf,0,0,(merlin_uint_512 *)v1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_2d_16_512(u2_13_0_buf,0,0,(merlin_uint_512 *)u2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_2d_2_512(v2_13_0_buf,0,0,(merlin_uint_512 *)v2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL14:
    for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
{
      merlinL13:
      for (j = 0; j < 200; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=A_buf array inter false
        
#pragma HLS pipeline
        merlinL12:
        for (int i_sub_2 = 0; i_sub_2 < 16; ++i_sub_2) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL11:
          for (int j_sub_1 = 0; j_sub_1 < 2; ++j_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            A_buf[i][i_sub_2][j][j_sub_1] = A_buf[i][i_sub_2][j][j_sub_1] + u1_13_0_buf[i][i_sub_2] * v1_13_0_buf[j][j_sub_1] + u2_13_0_buf[i][i_sub_2] * v2_13_0_buf[j][j_sub_1];
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_2d_16_512(y_14_0_buf,0,0,(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL10:
    for (i = 0; i < 200; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      merlinL9:
      for (j = 0; j < 25; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL8:
        for (int i_sub_1 = 0; i_sub_1 < 2; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL7:
          for (int j_sub_0 = 0; j_sub_0 < 16; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            x_buf[i * 2 + i_sub_1] = x_buf[i * 2 + i_sub_1] + beta * A_buf[j][j_sub_0][i][i_sub_1] * y_14_0_buf[j][j_sub_0];
          }
        }
      }
    }
{
      merlin_memcpy_0(z_8_0_buf,0,0,z,0,sizeof(float ) * ((unsigned long )400),1600UL);
    }
    merlinL6:
    for (i = 0; i < 16; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=x_buf array inter false
      
#pragma HLS pipeline
      merlinL5:
      for (int i_sub_0 = 0; i_sub_0 < 25; ++i_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        x_buf[i * 25 + i_sub_0] = x_buf[i * 25 + i_sub_0] + z_8_0_buf[i][i_sub_0];
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_read_float_2d_16_512(w_buf,0,0,(merlin_uint_512 *)w,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    merlinL4:
    for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
{
      merlinL3:
      for (j = 0; j < 200; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL2:
        for (int i_sub = 0; i_sub < 16; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL1:
          for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            w_buf[i][i_sub] = w_buf[i][i_sub] + alpha * A_buf[i][i_sub][j][j_sub] * x_buf[j * 2 + j_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_write_float_2d_16_512((merlin_uint_512 *)w,w_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)x,&x_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 8 dim=3 */
    memcpy_wide_bus_write_float_4d_16_200_2_512((merlin_uint_512 *)A,A_buf,0,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )160000L),160000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=u1_13_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=u2_13_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=v1_13_0_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=v1_13_0_buf cyclic factor = 8 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=v2_13_0_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=v2_13_0_buf cyclic factor = 8 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_14_0_buf cyclic factor = 16 dim=2 */
}