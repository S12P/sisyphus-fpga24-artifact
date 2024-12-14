#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 25
#define SIZE_2 250
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 1
#include "memcpy_512_2d.h"
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
    float B_4_0_buf[10][25][250];
    
#pragma HLS array_partition variable=B_4_0_buf cyclic factor=2 dim=3
    float x_4_1_buf[250];
    
#pragma HLS array_partition variable=x_4_1_buf cyclic factor=16 dim=1
    float x_4_0_buf[250];
    
#pragma HLS array_partition variable=x_4_0_buf cyclic factor=16 dim=1
    float A_4_0_buf[10][25][250];
    
#pragma HLS array_partition variable=A_4_0_buf cyclic factor=2 dim=3
{
      memcpy_wide_bus_read_float_3d_25_250_64(A_4_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )62500L),62500L);
    }
{
      memcpy_wide_bus_read_float_512(&x_4_0_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_1_buf cyclic factor = 16 dim=1 */
      memcpy_wide_bus_read_float_512(&x_4_1_buf[0],(merlin_uint_512 *)x,(0 * 4),sizeof(float ) * ((unsigned long )250),250L);
    }
{
      memcpy_wide_bus_read_float_3d_25_250_64(B_4_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )62500L),62500L);
    }
    merlinL2:
    for (i = 0; i < 10; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
{
      float y_buf[25][1];
      
#pragma HLS array_partition variable=y_buf complete dim=2
      
#pragma HLS array_partition variable=y_buf complete dim=1
      float tmp_buf[25][1];
      
#pragma HLS array_partition variable=tmp_buf complete dim=2
      
#pragma HLS array_partition variable=tmp_buf complete dim=1
{
        memcpy_wide_bus_read_float_2d_1_512(tmp_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)tmp,(size_t )(i * 25 * 4),sizeof(float ) * ((unsigned long )25),(size_t )25L);
      }
{
        memcpy_wide_bus_read_float_2d_1_512(y_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)y,(size_t )(i * 25 * 4),sizeof(float ) * ((unsigned long )25),(size_t )25L);
      }
      merlinL1:
      for (int i_sub = 0; i_sub < 25; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL FACTOR=25 */
/* Original: #pragma ACCEL PARALLEL */
{
        tmp_buf[((long )i_sub) - 0L][0] = ((float )0.0);
        y_buf[((long )i_sub) - 0L][0] = ((float )0.0);
        merlinL0:
        for (j = 0; j < 250; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS pipeline
          tmp_buf[((long )i_sub) - 0L][0] = A_4_0_buf[i][i_sub][j] * x_4_1_buf[j] + tmp_buf[((long )i_sub) - 0L][0];
          y_buf[((long )i_sub) - 0L][0] = B_4_0_buf[i][i_sub][j] * x_4_0_buf[j] + y_buf[((long )i_sub) - 0L][0];
        }
        y_buf[((long )i_sub) - 0L][0] = alpha * tmp_buf[((long )i_sub) - 0L][0] + beta * y_buf[((long )i_sub) - 0L][0];
      }
{
        memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)y,y_buf,(size_t )0,(size_t )0,(size_t )(4 * (i * 25)),sizeof(float ) * ((unsigned long )25),(size_t )25L);
      }
{
        memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)tmp,tmp_buf,(size_t )0,(size_t )0,(size_t )(4 * (i * 25)),sizeof(float ) * ((unsigned long )25),(size_t )25L);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=tmp_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=y_buf cyclic factor = 16 dim=1 */
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_4_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=x_4_0_buf cyclic factor = 16 dim=1 */
}
