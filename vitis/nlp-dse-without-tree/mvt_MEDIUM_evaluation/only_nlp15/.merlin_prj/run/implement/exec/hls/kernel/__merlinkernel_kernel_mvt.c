#define __constant
#define __kernel
#define __global
#include "memcpy_512_1d.h"
#define SIZE_1 1
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 16
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 25
#define SIZE_2 16
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
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
    float y_1_6_0_buf[25][16];
    
#pragma HLS array_partition variable=y_1_6_0_buf complete dim=2
    float A_6_0_buf[400][25][16];
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=3
    float y_2_7_0_buf[400];
    
#pragma HLS array_partition variable=y_2_7_0_buf cyclic factor=16 dim=1
    float A_7_0_buf[400][25][16];
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=16 dim=3
    float x1_buf[400];
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=x1_buf cyclic factor=16 dim=1
    memcpy_wide_bus_read_float_512(&x1_buf[0],(merlin_uint_512 *)x1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_3d_25_16_512(A_6_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_2d_16_512(y_1_6_0_buf,0,0,(merlin_uint_512 *)y_1,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL5:
    for (i = 0; i < 400; i++) {
      merlinL4:
      for (j = 0; j < 25; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL3:
        for (int j_sub = 0; j_sub < 16; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          x1_buf[i] = x1_buf[i] + A_6_0_buf[i][j][j_sub] * y_1_6_0_buf[j][j_sub];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x1_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)x1,&x1_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )400),400L);
{
      memcpy_wide_bus_read_float_3d_25_16_512(A_7_0_buf,0,0,0,(merlin_uint_512 *)A,(0 * 4),sizeof(float ) * ((unsigned long )160000L),160000L);
    }
{
      memcpy_wide_bus_read_float_512(&y_2_7_0_buf[0],(merlin_uint_512 *)y_2,(0 * 4),sizeof(float ) * ((unsigned long )400),400L);
    }
    merlinL2:
    for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
{
      float x2_buf[16][1];
      
#pragma HLS array_partition variable=x2_buf complete dim=2
      
#pragma HLS array_partition variable=x2_buf complete dim=1
{
        memcpy_wide_bus_read_float_2d_1_512(x2_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)x2,(size_t )(i * 16 * 4),sizeof(float ) * ((unsigned long )16),(size_t )16L);
      }
      merlinL1:
      for (int i_sub = 0; i_sub < 16; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL0:
        for (j = 0; j < 400; j++) 
/* Original: #pragma ACCEL PIPELINE AUTO */
{
          
#pragma HLS pipeline
          x2_buf[((long )i_sub) - 0L][0] = x2_buf[((long )i_sub) - 0L][0] + A_7_0_buf[j][i][i_sub] * y_2_7_0_buf[j];
        }
      }
{
        memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)x2,x2_buf,(size_t )0,(size_t )0,(size_t )(4 * (i * 16)),sizeof(float ) * ((unsigned long )16),(size_t )16L);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=x2_buf cyclic factor = 16 dim=1 */
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 16 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_1_6_0_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_2_7_0_buf cyclic factor = 16 dim=1 */
}
