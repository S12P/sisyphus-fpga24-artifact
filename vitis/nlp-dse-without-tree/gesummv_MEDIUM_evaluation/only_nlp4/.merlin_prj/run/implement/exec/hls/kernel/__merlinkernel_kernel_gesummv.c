#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 250
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 1
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_gesummv_L_0_0_para_sub(float alpha,float beta,int j,float B_4_0_buf[250],float A_4_0_buf[250],float y_buf[1],float tmp_buf[1],int i_sub,float x_4_1_buf_dup[250],float x_4_0_buf_dup[250])
/* Original: #pragma ACCEL PARALLEL FACTOR=125 */
/* Original: #pragma ACCEL PARALLEL FACTOR=125 */
/* Original: #pragma ACCEL PARALLEL */
{
  
#pragma HLS inline off
  tmp_buf[0] = ((float )0.0);
  y_buf[0] = ((float )0.0);
  merlinL1:
  for (j = 0; j < 250; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS pipeline
    tmp_buf[0] = A_4_0_buf[j] * x_4_1_buf_dup[j] + tmp_buf[0];
    y_buf[0] = B_4_0_buf[j] * x_4_0_buf_dup[j] + y_buf[0];
  }
  y_buf[0] = alpha * tmp_buf[0] + beta * y_buf[0];
}

void kernel_gesummv_L_0_0_para(float alpha,float beta,int j,float B_4_0_buf[125][250],float A_4_0_buf[125][250],float y_buf[125][1],float tmp_buf[125][1],float x_4_1_buf_dup[125][250],float x_4_0_buf_dup[125][250])
{
  
#pragma HLS inline off
  int i_sub;
  merlinL0:
  for (i_sub = 0; i_sub < 125; ++i_sub) {
    
#pragma HLS unroll complete
    kernel_gesummv_L_0_0_para_sub(alpha,beta,j,B_4_0_buf[i_sub],A_4_0_buf[i_sub],y_buf[i_sub],tmp_buf[i_sub],i_sub,x_4_1_buf_dup[i_sub],x_4_0_buf_dup[i_sub]);
  }
}

void kernel_gesummv(float alpha,float beta,merlin_uint_64 A[31250],merlin_uint_64 B[31250],merlin_uint_512 tmp[16],merlin_uint_512 x[16],merlin_uint_512 y[16])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=31250 bundle=merlin_gmem_kernel_gesummv_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=31250 bundle=merlin_gmem_kernel_gesummv_64_1
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=16 bundle=merlin_gmem_kernel_gesummv_512_tmp
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=16 bundle=merlin_gmem_kernel_gesummv_512_0
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=16 bundle=merlin_gmem_kernel_gesummv_512_y
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=tmp bundle=control
  
#pragma HLS INTERFACE s_axilite port=x bundle=control
  
#pragma HLS INTERFACE s_axilite port=y bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=y
  
#pragma HLS DATA_PACK VARIABLE=x
  
#pragma HLS DATA_PACK VARIABLE=tmp
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=y depth=250 max_depth=250
  
#pragma ACCEL interface variable=x depth=250 max_depth=250
  
#pragma ACCEL interface variable=tmp depth=250 max_depth=250
  
#pragma ACCEL interface variable=B depth=250,250 max_depth=250,250
  
#pragma ACCEL interface variable=A depth=250,250 max_depth=250,250
  int i;
  int j;
{
    float x_4_1_buf[250];
    
#pragma HLS array_partition variable=x_4_1_buf cyclic factor=16 dim=1
    float x_4_0_buf[250];
    
#pragma HLS array_partition variable=x_4_0_buf cyclic factor=16 dim=1
{
      memcpy_wide_bus_read_float_512(&x_4_0_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_1_buf cyclic factor = 16 dim=1 */
      memcpy_wide_bus_read_float_512(&x_4_1_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
    }
    float x_4_1_buf_dup[125][250];
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_1_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=x_4_1_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      merlinL7:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 249UL; ++_i1) {
        
#pragma HLS pipeline
        merlinL6:
        for (_i0 = ((long )0); ((unsigned long )_i0) <= 124UL; ++_i0) {
          
#pragma HLS unroll
          x_4_1_buf_dup[_i0][_i1] = x_4_1_buf[_i1];
        }
      }
    }
    float x_4_0_buf_dup[125][250];
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=x_4_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      merlinL5:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 249UL; ++_i1) {
        
#pragma HLS pipeline
        merlinL4:
        for (_i0 = ((long )0); ((unsigned long )_i0) <= 124UL; ++_i0) {
          
#pragma HLS unroll
          x_4_0_buf_dup[_i0][_i1] = x_4_0_buf[_i1];
        }
      }
    }
    merlinL3:
    for (i = 0; i < 2; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=125 */
/* Original: #pragma ACCEL PARALLEL FACTOR=125 */
{
      float B_4_0_buf[125][250];
/* Existing HLS partition: #pragma HLS array_partition variable=B_4_0_buf dim=1 complete */
      
#pragma HLS array_partition variable=B_4_0_buf cyclic factor=2 dim=2
      
#pragma HLS array_partition variable=B_4_0_buf complete dim=1
      float A_4_0_buf[125][250];
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_0_buf dim=1 complete */
      
#pragma HLS array_partition variable=A_4_0_buf cyclic factor=2 dim=2
      
#pragma HLS array_partition variable=A_4_0_buf complete dim=1
      float y_buf[125][1];
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf dim=1 complete */
      
#pragma HLS array_partition variable=y_buf complete dim=2
      
#pragma HLS array_partition variable=y_buf complete dim=1
      float tmp_buf[125][1];
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf dim=1 complete */
      
#pragma HLS array_partition variable=tmp_buf complete dim=2
      
#pragma HLS array_partition variable=tmp_buf complete dim=1
{
        memcpy_wide_bus_read_float_2d_1_512(tmp_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)tmp,(size_t )(i * 125 * 4),sizeof(float ) * ((unsigned long )125),(size_t )125L);
      }
{
        memcpy_wide_bus_read_float_2d_1_512(y_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)y,(size_t )(i * 125 * 4),sizeof(float ) * ((unsigned long )125),(size_t )125L);
      }
{
        memcpy_wide_bus_read_float_2d_250_64(A_4_0_buf,(size_t )0,(size_t )0,(merlin_uint_64 *)A,(size_t )(((long )i) * 31250L * ((long )4)),sizeof(float ) * ((unsigned long )31250L),(size_t )31250L);
      }
{
        memcpy_wide_bus_read_float_2d_250_64(B_4_0_buf,(size_t )0,(size_t )0,(merlin_uint_64 *)B,(size_t )(((long )i) * 31250L * ((long )4)),sizeof(float ) * ((unsigned long )31250L),(size_t )31250L);
      }
      kernel_gesummv_L_0_0_para(alpha,beta,j,B_4_0_buf,A_4_0_buf,y_buf,tmp_buf,x_4_1_buf_dup,x_4_0_buf_dup);
      merlinL2:
      for (int i_sub = 0; i_sub < 125; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=125 */
/* Original: #pragma ACCEL PARALLEL FACTOR=125 */
/* Original: #pragma ACCEL PARALLEL */
{
      }{
        memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)y,y_buf,(size_t )0,(size_t )0,(size_t )(4 * (i * 125)),sizeof(float ) * ((unsigned long )125),(size_t )125L);
      }
{
        memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)tmp,tmp_buf,(size_t )0,(size_t )0,(size_t )(4 * (i * 125)),sizeof(float ) * ((unsigned long )125),(size_t )125L);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_4_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
  }
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_0_buf cyclic factor = 16 dim=1 */
}
