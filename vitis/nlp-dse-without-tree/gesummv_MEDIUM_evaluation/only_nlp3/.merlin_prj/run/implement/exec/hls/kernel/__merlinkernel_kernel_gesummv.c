#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 250
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

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
    float B_3_0_buf[250][250];
    
#pragma HLS array_partition variable=B_3_0_buf complete dim=2
    float x_3_1_buf[250];
    
#pragma HLS array_partition variable=x_3_1_buf complete dim=1
    float x_3_0_buf[250];
    
#pragma HLS array_partition variable=x_3_0_buf complete dim=1
    float A_3_0_buf[250][250];
    
#pragma HLS array_partition variable=A_3_0_buf complete dim=2
    float y_buf[250];
    
#pragma HLS array_partition variable=y_buf cyclic factor=16 dim=1
    float tmp_buf[250];
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=tmp_buf cyclic factor=16 dim=1
    memcpy_wide_bus_read_float_512(&tmp_buf[0],(merlin_uint_512 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&y_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
{
      memcpy_wide_bus_read_float_2d_250_64(A_3_0_buf,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )62500L),62500L);
    }
{
      memcpy_wide_bus_read_float_512(&x_3_0_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
/* Existing HLS partition: #pragma HLS array_partition variable=x_3_1_buf cyclic factor = 16 dim=1 */
      memcpy_wide_bus_read_float_512(&x_3_1_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
    }
{
      memcpy_wide_bus_read_float_2d_250_64(B_3_0_buf,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )62500L),62500L);
    }
    merlinL1:
    for (i = 0; i < 250; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=tmp_buf array inter false
      
#pragma HLS dependence variable=y_buf array inter false
      
#pragma HLS pipeline
      tmp_buf[i] = ((float )0.0);
      y_buf[i] = ((float )0.0);
      merlinL0:
      for (j = 0; j < 250; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=250 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
        
#pragma HLS unroll
        tmp_buf[i] = A_3_0_buf[i][j] * x_3_1_buf[j] + tmp_buf[i];
        y_buf[i] = B_3_0_buf[i][j] * x_3_0_buf[j] + y_buf[i];
      }
      y_buf[i] = alpha * tmp_buf[i] + beta * y_buf[i];
    }
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)y,&y_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )250),250L);
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)tmp,&tmp_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )250),250L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_3_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_3_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_3_0_buf cyclic factor = 16 dim=1 */
}
