#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 1
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 400
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"






/* Original: #pragma ACCEL kernel */

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
    float y_1_4_0_buf[400];
    
#pragma HLS array_partition variable=y_1_4_0_buf complete dim=1
    float A_4_0_buf[400][400];
    
#pragma HLS array_partition variable=A_4_0_buf complete dim=2
    float y_2_5_0_buf[400];
    
#pragma HLS array_partition variable=y_2_5_0_buf cyclic factor=16 dim=1
    float A_5_0_buf[400][400];
    
#pragma HLS array_partition variable=A_5_0_buf cyclic factor=16 dim=2
    float x1_buf[400];
    
#pragma HLS array_partition variable=x1_buf cyclic factor=16 dim=1
    float x2_buf[400][1];
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=x2_buf complete dim=2
    
#pragma HLS array_partition variable=x2_buf cyclic factor=16 dim=1
    memcpy_wide_bus_read_float_512(&x1_buf[0],(merlin_uint_512 *)x1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_2d_400_512(A_4_0_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_512(&y_1_4_0_buf[0],(merlin_uint_512 *)y_1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL3:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=x1_buf array inter false
      
#pragma HLS pipeline
      merlinL2:
      for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
        
#pragma HLS unroll
        x1_buf[i] = x1_buf[i] + A_4_0_buf[i][j] * y_1_4_0_buf[j];
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)x1,&x1_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_2d_1_512(x2_buf,0,0,(merlin_uint_512 *)x2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
{
      memcpy_wide_bus_read_float_2d_400_512(A_5_0_buf,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_512(&y_2_5_0_buf[0],(merlin_uint_512 *)y_2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL1:
    for (i = 0; i < 400; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL PARALLEL FACTOR=400 */
/* Original: #pragma ACCEL parallel */
{
      merlinL0:
      for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        x2_buf[((long )i) - 0L][0] = x2_buf[((long )i) - 0L][0] + A_5_0_buf[j][i] * y_2_5_0_buf[j];
      }
    }
{
      memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)x2,x2_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_4_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_2_5_0_buf cyclic factor = 16 dim=1 */
}
