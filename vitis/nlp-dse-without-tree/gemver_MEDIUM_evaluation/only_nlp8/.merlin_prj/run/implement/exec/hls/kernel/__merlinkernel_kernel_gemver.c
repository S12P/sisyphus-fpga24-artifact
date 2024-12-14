#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 400
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 1
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
    float v2_6_0_buf[400];
    
#pragma HLS array_partition variable=v2_6_0_buf complete dim=1
    float u2_6_0_buf[400];
    
#pragma HLS array_partition variable=u2_6_0_buf cyclic factor=16 dim=1
    float v1_6_0_buf[400];
    
#pragma HLS array_partition variable=v1_6_0_buf complete dim=1
    float u1_6_0_buf[400];
    
#pragma HLS array_partition variable=u1_6_0_buf cyclic factor=16 dim=1
    float y_7_0_buf[400];
    
#pragma HLS array_partition variable=y_7_0_buf cyclic factor=16 dim=1
    float x_8_0_buf[400];
    
#pragma HLS array_partition variable=x_8_0_buf complete dim=1
    float w_buf[400];
    
#pragma HLS array_partition variable=w_buf cyclic factor=16 dim=1
    float x_buf_0[400];
    
#pragma HLS array_partition variable=x_buf_0 complete dim=1
    float A_buf[400][400];
    
#pragma HLS array_partition variable=A_buf complete dim=2
    float x_buf[400][1];
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 16 dim=2 */
    
#pragma HLS array_partition variable=x_buf complete dim=2
    
#pragma HLS array_partition variable=x_buf cyclic factor=16 dim=1
    memcpy_wide_bus_read_float_2d_400_512(A_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
{
      memcpy_wide_bus_read_float_512(&u1_6_0_buf[0],(merlin_uint_512 *)u1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_512(&v1_6_0_buf[0],(merlin_uint_512 *)v1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_512(&u2_6_0_buf[0],(merlin_uint_512 *)u2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_512(&v2_6_0_buf[0],(merlin_uint_512 *)v2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL6:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=A_buf array inter false
      
#pragma HLS pipeline
      merlinL5:
      for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
        
#pragma HLS unroll
        A_buf[i][j] = A_buf[i][j] + u1_6_0_buf[i] * v1_6_0_buf[j] + u2_6_0_buf[i] * v2_6_0_buf[j];
      }
    }
{
      memcpy_wide_bus_read_float_2d_1_512(x_buf,0,0,(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_512(&y_7_0_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL4:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
      merlinL3:
      for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PIPELINE AUTO */
{
        
#pragma HLS pipeline
        x_buf[((long )i) - 0L][0] = x_buf[((long )i) - 0L][0] + beta * A_buf[j][i] * y_7_0_buf[j];
      }
    }
{
      memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)x,x_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf_0 cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&x_buf_0[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_512(&z_4_0_buf[0],(merlin_uint_512 *)z,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL2:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS unroll
      x_buf_0[i] = x_buf_0[i] + z_4_0_buf[i];
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf_0 cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)x,&x_buf_0[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&w_buf[0],(merlin_uint_512 *)w,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_512(&x_8_0_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL1:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=w_buf array inter false
      
#pragma HLS pipeline
      merlinL0:
      for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
        
#pragma HLS unroll
        w_buf[i] = w_buf[i] + alpha * A_buf[i][j] * x_8_0_buf[j];
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)w,&w_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_write_float_2d_400_512((merlin_uint_512 *)A,A_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )160000L),160000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=u1_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=u2_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=v1_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=v2_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_8_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_7_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=z_4_0_buf cyclic factor = 16 dim=1 */
}
