#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 1
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 200
#define SIZE_2 2
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_mvt_L_0_para_sub(int i,int j,float A_6_0_buf[200][2],float x1_buf[1],float y_1_6_0_buf_dup[200][2])
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
  
#pragma HLS inline off
  merlinL2:
  for (j = 0; j < 200; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS pipeline
    merlinL1:
    for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
      
#pragma HLS unroll
      x1_buf[0] = x1_buf[0] + A_6_0_buf[j][j_sub] * y_1_6_0_buf_dup[j][j_sub];
    }
  }
}

void kernel_mvt_L_0_para(int j,float A_6_0_buf[400][200][2],float x1_buf[400][1],float y_1_6_0_buf_dup[400][200][2])
{
  
#pragma HLS inline off
  int i;
  merlinL0:
  for (i = 0; i < 400; ++i) {
    
#pragma HLS unroll complete
    kernel_mvt_L_0_para_sub(i,j,A_6_0_buf[i],x1_buf[i],y_1_6_0_buf_dup[i]);
  }
}

void kernel_mvt(merlin_uint_512 x1[25],merlin_uint_512 x2[25],merlin_uint_512 y_1[25],merlin_uint_512 y_2[25],merlin_uint_512 A[10000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=10000 bundle=merlin_gmem_kernel_mvt_512_0
  
#pragma HLS INTERFACE m_axi port=x1 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_x1
  
#pragma HLS INTERFACE m_axi port=x2 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_x2
  
#pragma HLS INTERFACE m_axi port=y_1 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_1
  
#pragma HLS INTERFACE m_axi port=y_2 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_2
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=x1 bundle=control
  
#pragma HLS INTERFACE s_axilite port=x2 bundle=control
  
#pragma HLS INTERFACE s_axilite port=y_1 bundle=control
  
#pragma HLS INTERFACE s_axilite port=y_2 bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=y_2
  
#pragma HLS DATA_PACK VARIABLE=y_1
  
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
    float y_1_6_0_buf[200][2];
    
#pragma HLS array_partition variable=y_1_6_0_buf complete dim=2
    
#pragma HLS array_partition variable=y_1_6_0_buf cyclic factor=8 dim=1
    float A_6_0_buf[400][200][2];
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf dim=1 complete */
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=8 dim=2
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=1
    float y_2_7_0_buf[400];
    
#pragma HLS array_partition variable=y_2_7_0_buf complete dim=1
    float A_7_0_buf[400][200][2];
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=8 dim=2
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=1
    float x2_buf[200][2];
    
#pragma HLS array_partition variable=x2_buf complete dim=2
    
#pragma HLS array_partition variable=x2_buf cyclic factor=8 dim=1
    float x1_buf[400][1];
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf dim=1 complete */
    
#pragma HLS array_partition variable=x1_buf complete dim=2
    
#pragma HLS array_partition variable=x1_buf complete dim=1
{
      memcpy_wide_bus_read_float_2d_1_512(x1_buf,0,0,(merlin_uint_512 *)x1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_3d_200_2_512(A_6_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_2d_2_512(y_1_6_0_buf,0,0,(merlin_uint_512 *)y_1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    float y_1_6_0_buf_dup[400][200][2];
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_6_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=y_1_6_0_buf_dup complete dim=3
    
#pragma HLS array_partition variable=y_1_6_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      long _i2;
      merlinL9:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 199UL; ++_i1) {
        merlinL8:
        for (_i2 = ((long )0); ((unsigned long )_i2) <= 1UL; ++_i2) {
          
#pragma HLS pipeline
          
#pragma HLS loop_flatten
          merlinL7:
          for (_i0 = ((long )0); ((unsigned long )_i0) <= 399UL; ++_i0) {
            
#pragma HLS unroll
            y_1_6_0_buf_dup[_i0][_i1][_i2] = y_1_6_0_buf[_i1][_i2];
          }
        }
      }
    }
    kernel_mvt_L_0_para(j,A_6_0_buf,x1_buf,y_1_6_0_buf_dup);
    merlinL6:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
    }{
      memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)x1,x1_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_read_float_2d_2_512(x2_buf,0,0,(merlin_uint_512 *)x2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_3d_200_2_512(A_7_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
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
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 8 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 8 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_6_0_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_6_0_buf cyclic factor = 8 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_2_7_0_buf cyclic factor = 16 dim=1 */
}
