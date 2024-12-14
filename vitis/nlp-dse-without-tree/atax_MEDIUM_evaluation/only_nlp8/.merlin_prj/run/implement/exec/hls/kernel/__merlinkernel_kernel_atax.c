#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 41
#define SIZE_2 10
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 10
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_atax(merlin_uint_64 A[79950],merlin_uint_64 x[205],merlin_uint_64 y[205],merlin_uint_512 tmp[25])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=79950 bundle=merlin_gmem_kernel_atax_64_0
  
#pragma HLS INTERFACE m_axi port=tmp offset=slave depth=25 bundle=merlin_gmem_kernel_atax_512_tmp
  
#pragma HLS INTERFACE m_axi port=x offset=slave depth=205 bundle=merlin_gmem_kernel_atax_64_1
  
#pragma HLS INTERFACE m_axi port=y offset=slave depth=205 bundle=merlin_gmem_kernel_atax_64_y
  
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
    float x_7_0_buf[41][10];
    
#pragma HLS array_partition variable=x_7_0_buf complete dim=2
    float A_7_0_buf[390][41][10];
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=3
    float A_8_0_buf[390][41][10];
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=3
    float tmp_buf[390];
    
#pragma HLS array_partition variable=tmp_buf cyclic factor=16 dim=1
    float y_buf[41][10];
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=y_buf complete dim=2
    memcpy_wide_bus_read_float_2d_10_64(y_buf,0,0,(merlin_uint_64 *)y,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    merlinL6:
    for (i = 0; i < 41; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=y_buf array inter false
      
#pragma HLS pipeline
      merlinL5:
      for (int i_sub = 0; i_sub < 10; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        y_buf[i][i_sub] = ((float )0);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&tmp_buf[0],(merlin_uint_512 *)tmp,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
{
      memcpy_wide_bus_read_float_3d_41_10_64(A_8_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 2 dim=3 */
      memcpy_wide_bus_read_float_3d_41_10_64(A_7_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
    }
{
      memcpy_wide_bus_read_float_2d_10_64(x_7_0_buf,0,0,(merlin_uint_64 *)x,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    }
    merlinL4:
    for (i = 0; i < 390; i++) {
      tmp_buf[i] = ((float )0.0);
      merlinL3:
      for (j = 0; j < 41; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL2:
        for (int j_sub_0 = 0; j_sub_0 < 10; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          tmp_buf[i] = tmp_buf[i] + A_7_0_buf[i][j][j_sub_0] * x_7_0_buf[j][j_sub_0];
        }
      }
      merlinL1:
      for (j = 0; j < 41; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=y_buf array inter false
        
#pragma HLS pipeline
        merlinL0:
        for (int j_sub = 0; j_sub < 10; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          y_buf[j][j_sub] = y_buf[j][j_sub] + A_8_0_buf[i][j][j_sub] * tmp_buf[i];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)tmp,&tmp_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )390),390L);
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_10_64((merlin_uint_64 *)y,y_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )410),410L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_7_0_buf cyclic factor = 2 dim=2 */
}
