#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 410
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

void kernel_atax(merlin_uint_64 A[79950],merlin_uint_512 x[26],merlin_uint_512 y[26],merlin_uint_512 tmp[25])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=79950 bundle=merlin_gmem_kernel_atax_64_0
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=25 bundle=merlin_gmem_kernel_atax_512_tmp
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=26 bundle=merlin_gmem_kernel_atax_512_0
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=26 bundle=merlin_gmem_kernel_atax_512_y
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=tmp bundle=control
  
#pragma HLS INTERFACE s_axilite port=x bundle=control
  
#pragma HLS INTERFACE s_axilite port=y bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=tmp
  
#pragma HLS DATA_PACK VARIABLE=y
  
#pragma HLS DATA_PACK VARIABLE=x
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=tmp depth=390 max_depth=390
  
#pragma ACCEL interface variable=y depth=410 max_depth=410
  
#pragma ACCEL interface variable=x depth=410 max_depth=410
  
#pragma ACCEL interface variable=A depth=390,410 max_depth=390,410
  int i;
  int j;
{
    float x_4_0_buf[410];
    
#pragma HLS array_partition variable=x_4_0_buf complete dim=1
    float A_4_0_buf[390][410];
    
#pragma HLS array_partition variable=A_4_0_buf complete dim=2
    float A_buf[390][410];
    
#pragma HLS array_partition variable=A_buf complete dim=2
    float tmp_buf[390];
    
#pragma HLS array_partition variable=tmp_buf cyclic factor=16 dim=1
    float y_buf[410];
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=y_buf complete dim=1
    memcpy_wide_bus_read_float_512(&y_buf[0],(merlin_uint_512 *)y,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    merlinL3:
    for (i = 0; i < 410; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=410 */
/* Original: #pragma ACCEL PARALLEL FACTOR=410 */
/* Original: #pragma ACCEL parallel */
{
      
#pragma HLS unroll
      y_buf[i] = ((float )0);
    }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&tmp_buf[0],(merlin_uint_512 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
{
      memcpy_wide_bus_read_float_2d_410_64(A_4_0_buf,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
    }
{
      memcpy_wide_bus_read_float_512(&x_4_0_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    }
    merlinL2:
    for (i = 0; i < 390; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=tmp_buf array inter false
      
#pragma HLS pipeline
      tmp_buf[i] = ((float )0.0);
      merlinL1:
      for (j = 0; j < 410; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=410 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
        
#pragma HLS unroll
        tmp_buf[i] = tmp_buf[i] + A_4_0_buf[i][j] * x_4_0_buf[j];
      }
      merlinL0:
      for (j = 0; j < 410; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=410 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
        
#pragma HLS unroll
        y_buf[j] = y_buf[j] + A_buf[i][j] * tmp_buf[i];
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)tmp,&tmp_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )390),390L);
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)y,&y_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )410),410L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_0_buf cyclic factor = 16 dim=1 */
}
