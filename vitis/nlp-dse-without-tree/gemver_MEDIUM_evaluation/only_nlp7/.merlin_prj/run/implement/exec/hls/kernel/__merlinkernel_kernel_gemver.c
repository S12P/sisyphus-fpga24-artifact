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

void kernel_gemver_L_0_para_sub(int i,int j,float u2_6_0_buf,float u1_6_0_buf,float A_buf[400],float v2_6_0_buf_dup[400],float v1_6_0_buf_dup[400])
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
  
#pragma HLS inline off
  merlinL1:
  for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS dependence variable=A_buf array inter false
    
#pragma HLS pipeline
    A_buf[j] = A_buf[j] + u1_6_0_buf * v1_6_0_buf_dup[j] + u2_6_0_buf * v2_6_0_buf_dup[j];
  }
}

void kernel_gemver_L_0_para(int j,float u2_6_0_buf[400],float u1_6_0_buf[400],float A_buf[400][400],float v2_6_0_buf_dup[400][400],float v1_6_0_buf_dup[400][400])
{
  
#pragma HLS inline off
  int i;
  merlinL0:
  for (i = 0; i < 400; ++i) {
    
#pragma HLS unroll complete
    kernel_gemver_L_0_para_sub(i,j,u2_6_0_buf[i],u1_6_0_buf[i],A_buf[i],v2_6_0_buf_dup[i],v1_6_0_buf_dup[i]);
  }
}

void kernel_gemver_L_5_para_sub(float alpha,int i,int j,float A_8_0_buf[400],float w_buf[1],float x_buf_dup[400])
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
  
#pragma HLS inline off
  merlinL3:
  for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS pipeline
    w_buf[0] = w_buf[0] + alpha * A_8_0_buf[j] * x_buf_dup[j];
  }
}

void kernel_gemver_L_5_para(float alpha,int j,float A_8_0_buf[400][400],float w_buf[400][1],float x_buf_dup[400][400])
{
  
#pragma HLS inline off
  int i;
  merlinL2:
  for (i = 0; i < 400; ++i) {
    
#pragma HLS unroll complete
    kernel_gemver_L_5_para_sub(alpha,i,j,A_8_0_buf[i],w_buf[i],x_buf_dup[i]);
  }
}

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
    
#pragma HLS array_partition variable=v2_6_0_buf cyclic factor=16 dim=1
    float u2_6_0_buf[400];
/* Existing HLS partition: #pragma HLS array_partition variable=u2_6_0_buf dim=1 complete */
    
#pragma HLS array_partition variable=u2_6_0_buf complete dim=1
    float v1_6_0_buf[400];
    
#pragma HLS array_partition variable=v1_6_0_buf cyclic factor=16 dim=1
    float u1_6_0_buf[400];
/* Existing HLS partition: #pragma HLS array_partition variable=u1_6_0_buf dim=1 complete */
    
#pragma HLS array_partition variable=u1_6_0_buf complete dim=1
    float y_7_0_buf[400];
    
#pragma HLS array_partition variable=y_7_0_buf complete dim=1
    float A_7_0_buf[400][400];
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=1
    float A_8_0_buf[400][400];
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf dim=1 complete */
    
#pragma HLS array_partition variable=A_8_0_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=1
    float x_buf[400];
    
#pragma HLS array_partition variable=x_buf complete dim=1
    float w_buf[400][1];
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf dim=1 complete */
    
#pragma HLS array_partition variable=w_buf complete dim=2
    
#pragma HLS array_partition variable=w_buf complete dim=1
    float A_buf[400][400];
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf dim=1 complete */
    
#pragma HLS array_partition variable=A_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=A_buf complete dim=1
{
      memcpy_wide_bus_read_float_2d_400_512(A_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&x_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
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
    float v2_6_0_buf_dup[400][400];
/* Existing HLS partition: #pragma HLS array_partition variable=v2_6_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=v2_6_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      merlinL14:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 399UL; ++_i1) {
        
#pragma HLS pipeline
        merlinL13:
        for (_i0 = ((long )0); ((unsigned long )_i0) <= 399UL; ++_i0) {
          
#pragma HLS unroll
          v2_6_0_buf_dup[_i0][_i1] = v2_6_0_buf[_i1];
        }
      }
    }
    float v1_6_0_buf_dup[400][400];
/* Existing HLS partition: #pragma HLS array_partition variable=v1_6_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=v1_6_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      merlinL12:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 399UL; ++_i1) {
        
#pragma HLS pipeline
        merlinL11:
        for (_i0 = ((long )0); ((unsigned long )_i0) <= 399UL; ++_i0) {
          
#pragma HLS unroll
          v1_6_0_buf_dup[_i0][_i1] = v1_6_0_buf[_i1];
        }
      }
    }
    kernel_gemver_L_0_para(j,u2_6_0_buf,u1_6_0_buf,A_buf,v2_6_0_buf_dup,v1_6_0_buf_dup);
    merlinL10:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
    }{
      memcpy_wide_bus_write_float_2d_400_512((merlin_uint_512 *)A,A_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_2d_400_512(A_7_0_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_512(&y_7_0_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL9:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=x_buf array inter false
      
#pragma HLS pipeline
      merlinL8:
      for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
        
#pragma HLS unroll
        x_buf[i] = x_buf[i] + beta * A_7_0_buf[j][i] * y_7_0_buf[j];
      }
    }
{
      memcpy_wide_bus_read_float_512(&z_4_0_buf[0],(merlin_uint_512 *)z,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL7:
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
{
      memcpy_wide_bus_read_float_2d_400_512(A_8_0_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
    float x_buf_dup[400][400];
/* Existing HLS partition: #pragma HLS array_partition variable=x_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=x_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      merlinL6:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 399UL; ++_i1) {
        
#pragma HLS pipeline
        merlinL5:
        for (_i0 = ((long )0); ((unsigned long )_i0) <= 399UL; ++_i0) {
          
#pragma HLS unroll
          x_buf_dup[_i0][_i1] = x_buf[_i1];
        }
      }
    }
    kernel_gemver_L_5_para(alpha,j,A_8_0_buf,w_buf,x_buf_dup);
    merlinL4:
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
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=u1_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=u2_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=v1_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=v2_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=w_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_7_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=z_4_0_buf cyclic factor = 16 dim=1 */
}
