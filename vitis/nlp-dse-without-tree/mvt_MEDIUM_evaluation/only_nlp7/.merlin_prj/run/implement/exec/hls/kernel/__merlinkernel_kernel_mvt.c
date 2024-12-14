#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 1
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
#define SIZE_1 400
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 200
#define SIZE_2 400
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"









/* Original: #pragma ACCEL kernel */

void kernel_mvt_L_0_0_para_sub(int j,float A_6_0_buf[400],float x1_buf[1],int i_sub,float y_1_6_0_buf_dup[400])
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL */
{
  
#pragma HLS inline off
  merlinL1:
  for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PIPELINE AUTO */
{
    
#pragma HLS pipeline
    x1_buf[0] = x1_buf[0] + A_6_0_buf[j] * y_1_6_0_buf_dup[j];
  }
}

void kernel_mvt_L_0_0_para(int j,float A_6_0_buf[200][400],float x1_buf[200][1],float y_1_6_0_buf_dup[200][400])
{
  
#pragma HLS inline off
  int i_sub;
  merlinL0:
  for (i_sub = 0; i_sub < 200; ++i_sub) {
    
#pragma HLS unroll complete
    kernel_mvt_L_0_0_para_sub(j,A_6_0_buf[i_sub],x1_buf[i_sub],i_sub,y_1_6_0_buf_dup[i_sub]);
  }
}

void kernel_mvt(merlin_uint_512 x1[25],merlin_uint_512 x2[25],merlin_uint_512 y_1[25],merlin_uint_256 y_2[50],merlin_uint_512 A[10000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=10000 bundle=merlin_gmem_kernel_mvt_512_0
  
#pragma HLS INTERFACE m_axi port=x1 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_x1
  
#pragma HLS INTERFACE m_axi port=x2 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_x2
  
#pragma HLS INTERFACE m_axi port=y_1 offset=slave depth=25 bundle=merlin_gmem_kernel_mvt_512_1
  
#pragma HLS INTERFACE m_axi port=y_2 offset=slave depth=50 bundle=merlin_gmem_kernel_mvt_256_0
  
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
    float y_1_6_0_buf[400];
    
#pragma HLS array_partition variable=y_1_6_0_buf cyclic factor=16 dim=1
    float y_2_7_0_buf[2][200];
    
#pragma HLS array_partition variable=y_2_7_0_buf complete dim=2
    float A_7_0_buf[2][200][400];
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=16 dim=3
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=2
    float x2_buf[400];
    
#pragma HLS array_partition variable=x2_buf cyclic factor=16 dim=1
{
      memcpy_wide_bus_read_float_512(&y_1_6_0_buf[0],(merlin_uint_512 *)y_1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    float y_1_6_0_buf_dup[200][400];
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_6_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=y_1_6_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      merlinL8:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 399UL; ++_i1) {
        
#pragma HLS pipeline
        merlinL7:
        for (_i0 = ((long )0); ((unsigned long )_i0) <= 199UL; ++_i0) {
          
#pragma HLS unroll
          y_1_6_0_buf_dup[_i0][_i1] = y_1_6_0_buf[_i1];
        }
      }
    }
    merlinL6:
    for (i = 0; i < 2; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
{
      float A_6_0_buf[200][400];
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf dim=1 complete */
      
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=16 dim=2
      
#pragma HLS array_partition variable=A_6_0_buf complete dim=1
      float x1_buf[200][1];
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf dim=1 complete */
      
#pragma HLS array_partition variable=x1_buf complete dim=2
      
#pragma HLS array_partition variable=x1_buf complete dim=1
{
        memcpy_wide_bus_read_float_2d_1_512(x1_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)x1,(size_t )(i * 200 * 4),sizeof(float ) * ((unsigned long )200),(size_t )200L);
      }
{
        memcpy_wide_bus_read_float_2d_400_512(A_6_0_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)A,(size_t )(((long )i) * 80000L * ((long )4)),sizeof(float ) * ((unsigned long )80000L),(size_t )80000L);
      }
      kernel_mvt_L_0_0_para(j,A_6_0_buf,x1_buf,y_1_6_0_buf_dup);
      merlinL5:
      for (int i_sub = 0; i_sub < 200; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL */
{
      }{
        memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)x1,x1_buf,(size_t )0,(size_t )0,(size_t )(4 * (i * 200)),sizeof(float ) * ((unsigned long )200),(size_t )200L);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&x2_buf[0],(merlin_uint_512 *)x2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_3d_200_400_512(A_7_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_2d_200_256(y_2_7_0_buf,0,0,(merlin_uint_256 *)y_2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL4:
    for (i = 0; i < 400; i++) {
      merlinL3:
      for (j = 0; j < 2; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL2:
        for (int j_sub = 0; j_sub < 200; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          x2_buf[i] = x2_buf[i] + A_7_0_buf[j][j_sub][i] * y_2_7_0_buf[j][j_sub];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)x2,&x2_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_6_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_2_7_0_buf cyclic factor = 8 dim=2 */
}
