#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 400
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 80
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 8
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_gemver(float alpha,float beta,merlin_uint_512 A[10000],merlin_uint_512 u1[25],merlin_uint_512 v1[25],merlin_uint_512 u2[25],merlin_uint_512 v2[25],merlin_uint_512 w[25],merlin_uint_512 x[25],merlin_uint_512 y[25],merlin_uint_512 z[25])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=10000 bundle=merlin_gmem_kernel_gemver_512_A
  
#pragma HLS INTERFACE m_axi port=u1 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_0
  
#pragma HLS INTERFACE m_axi port=u2 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_1
  
#pragma HLS INTERFACE m_axi port=v1 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_2
  
#pragma HLS INTERFACE m_axi port=v2 offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_3
  
#pragma HLS INTERFACE m_axi port=w offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_w
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_x
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_4
  
#pragma HLS INTERFACE m_axi port=z offset=slave depth=25 bundle=merlin_gmem_kernel_gemver_512_5
  
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
    float z_4_0_buf[400];
    
#pragma HLS array_partition variable=z_4_0_buf complete dim=1
    float y_10_0_buf[400];
    
#pragma HLS array_partition variable=y_10_0_buf complete dim=1
    float v2_12_0_buf[50][8];
    
#pragma HLS array_partition variable=v2_12_0_buf complete dim=2
    
#pragma HLS array_partition variable=v2_12_0_buf cyclic factor=2 dim=1
    float u2_12_0_buf[5][80];
    
#pragma HLS array_partition variable=u2_12_0_buf complete dim=2
    float v1_12_0_buf[50][8];
    
#pragma HLS array_partition variable=v1_12_0_buf complete dim=2
    
#pragma HLS array_partition variable=v1_12_0_buf cyclic factor=2 dim=1
    float u1_12_0_buf[5][80];
    
#pragma HLS array_partition variable=u1_12_0_buf complete dim=2
    float w_buf[200][2];
    
#pragma HLS array_partition variable=w_buf complete dim=2
    
#pragma HLS array_partition variable=w_buf cyclic factor=8 dim=1
    float A_buf[400][400];
    
#pragma HLS array_partition variable=A_buf complete dim=2
    
#pragma HLS array_partition variable=A_buf complete dim=1
    float x_buf[400];
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=x_buf complete dim=1
    memcpy_wide_bus_read_float_512(&x_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_read_float_2d_400_512(A_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
{
      memcpy_wide_bus_read_float_2d_80_512(u1_12_0_buf,0,0,(merlin_uint_512 *)u1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_2d_8_512(v1_12_0_buf,0,0,(merlin_uint_512 *)v1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_2d_80_512(u2_12_0_buf,0,0,(merlin_uint_512 *)u2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_2d_8_512(v2_12_0_buf,0,0,(merlin_uint_512 *)v2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL10:
    for (i = 0; i < 5; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=80 */
/* Original: #pragma ACCEL PARALLEL FACTOR=80 */
{
      merlinL9:
      for (j = 0; j < 50; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=A_buf array inter false
        
#pragma HLS pipeline
        merlinL8:
        for (int i_sub_1 = 0; i_sub_1 < 80; ++i_sub_1) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL7:
          for (int j_sub = 0; j_sub < 8; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            A_buf[((long )i) * 80L + ((long )i_sub_1)][((long )j) * 8L + ((long )j_sub)] = A_buf[((long )i) * 80L + ((long )i_sub_1)][((long )j) * 8L + ((long )j_sub)] + u1_12_0_buf[i][i_sub_1] * v1_12_0_buf[j][j_sub] + u2_12_0_buf[i][i_sub_1] * v2_12_0_buf[j][j_sub];
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_512(&y_10_0_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL6:
    for (i = 0; i < 200; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=x_buf array inter false
      
#pragma HLS pipeline
      merlinL5:
      for (int i_sub_0 = 0; i_sub_0 < 2; ++i_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        merlinL4:
        for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          x_buf[i * 2 + i_sub_0] = x_buf[i * 2 + i_sub_0] + beta * A_buf[j][((long )i) * 2L + ((long )i_sub_0)] * y_10_0_buf[j];
        }
      }
    }
{
      memcpy_wide_bus_read_float_512(&z_4_0_buf[0],(merlin_uint_512 *)z,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL3:
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
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_read_float_2d_2_512(w_buf,0,0,(merlin_uint_512 *)w,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    merlinL2:
    for (i = 0; i < 200; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=w_buf array inter false
      
#pragma HLS pipeline
      merlinL1:
      for (int i_sub = 0; i_sub < 2; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        merlinL0:
        for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          w_buf[i][i_sub] = w_buf[i][i_sub] + alpha * A_buf[((long )i) * 2L + ((long )i_sub)][j] * x_buf[j];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_write_float_2d_2_512((merlin_uint_512 *)w,w_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)x,&x_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_write_float_2d_400_512((merlin_uint_512 *)A,A_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )160000L),160000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=u1_12_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=u2_12_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=v1_12_0_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=v1_12_0_buf cyclic factor = 2 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=v2_12_0_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=v2_12_0_buf cyclic factor = 2 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_10_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=z_4_0_buf cyclic factor = 16 dim=1 */
}