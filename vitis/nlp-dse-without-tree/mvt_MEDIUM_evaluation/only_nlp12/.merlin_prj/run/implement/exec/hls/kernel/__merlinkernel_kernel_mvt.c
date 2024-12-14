#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 16
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 16
#define SIZE_2 200
#define SIZE_3 2
#include "memcpy_512_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
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
    float y_1_8_0_buf[200][2];
    
#pragma HLS array_partition variable=y_1_8_0_buf complete dim=2
    
#pragma HLS array_partition variable=y_1_8_0_buf cyclic factor=8 dim=1
    float A_8_0_buf[25][16][200][2];
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=4
    
#pragma HLS array_partition variable=A_8_0_buf cyclic factor=8 dim=3
    
#pragma HLS array_partition variable=A_8_0_buf complete dim=2
    float y_2_9_0_buf[25][16];
    
#pragma HLS array_partition variable=y_2_9_0_buf complete dim=2
    float A_9_0_buf[25][16][200][2];
    
#pragma HLS array_partition variable=A_9_0_buf complete dim=4
    
#pragma HLS array_partition variable=A_9_0_buf cyclic factor=8 dim=3
    
#pragma HLS array_partition variable=A_9_0_buf complete dim=2
    float x2_buf[200][2];
    
#pragma HLS array_partition variable=x2_buf complete dim=2
    
#pragma HLS array_partition variable=x2_buf cyclic factor=8 dim=1
    float x1_buf[25][16];
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=2 */
    
#pragma HLS array_partition variable=x1_buf complete dim=2
    memcpy_wide_bus_read_float_2d_16_512(x1_buf,0,0,(merlin_uint_512 *)x1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_4d_16_200_2_512(A_8_0_buf,0,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_2d_2_512(y_1_8_0_buf,0,0,(merlin_uint_512 *)y_1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL7:
    for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
{
      merlinL6:
      for (j = 0; j < 200; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL5:
        for (int i_sub_0 = 0; i_sub_0 < 16; ++i_sub_0) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL4:
          for (int j_sub_0 = 0; j_sub_0 < 2; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            x1_buf[i][i_sub_0] = x1_buf[i][i_sub_0] + A_8_0_buf[i][i_sub_0][j][j_sub_0] * y_1_8_0_buf[j][j_sub_0];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_write_float_2d_16_512((merlin_uint_512 *)x1,x1_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_read_float_2d_2_512(x2_buf,0,0,(merlin_uint_512 *)x2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_4d_16_200_2_512(A_9_0_buf,0,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_2d_16_512(y_2_9_0_buf,0,0,(merlin_uint_512 *)y_2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL3:
    for (i = 0; i < 200; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      merlinL2:
      for (j = 0; j < 25; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL1:
        for (int i_sub = 0; i_sub < 2; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL0:
          for (int j_sub = 0; j_sub < 16; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            x2_buf[i][i_sub] = x2_buf[i][i_sub] + A_9_0_buf[j][j_sub][i][i_sub] * y_2_9_0_buf[j][j_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_write_float_2d_2_512((merlin_uint_512 *)x2,x2_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 8 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_9_0_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_9_0_buf cyclic factor = 8 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_8_0_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_8_0_buf cyclic factor = 8 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_2_9_0_buf cyclic factor = 16 dim=2 */
}
