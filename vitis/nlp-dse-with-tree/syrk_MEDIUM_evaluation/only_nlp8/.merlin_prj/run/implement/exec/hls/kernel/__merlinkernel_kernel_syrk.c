#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 240
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
#define SIZE_1 60
#define SIZE_2 200
#include "memcpy_256_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_syrk(float alpha,float beta,merlin_uint_512 C[3600],merlin_uint_256 A[6000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=6000 bundle=merlin_gmem_kernel_syrk_256_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=3600 bundle=merlin_gmem_kernel_syrk_512_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=A depth=240,200 max_depth=240,200
  
#pragma ACCEL interface variable=C depth=240,240 max_depth=240,240
  int i;
  int j;
  int k;
//BLAS PARAMS
//TRANS = 'N'
//UPLO  = 'L'
// =>  Form  C := alpha*A*A**T + beta*C.
//A is NxM
//C is NxN
{
    float A_6_1_buf[4][60][200];
    
#pragma HLS array_partition variable=A_6_1_buf cyclic factor=8 dim=3
    float A_6_0_buf[240][200];
    
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=8 dim=2
{
      memcpy_wide_bus_read_float_2d_200_256(A_6_0_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_1_buf cyclic factor = 8 dim=3 */
      memcpy_wide_bus_read_float_3d_60_200_256(A_6_1_buf,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
    merlinL4:
    for (i = 0; i < 4; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=60 */
/* Original: #pragma ACCEL PARALLEL FACTOR=60 */
{
      float C_buf[60][240];
      
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
{
        memcpy_wide_bus_read_float_2d_240_512(C_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)C,(size_t )(((long )i) * 14400L * ((long )4)),sizeof(float ) * ((unsigned long )14400L),(size_t )14400L);
      }
      merlinL3:
      for (int i_sub = 0; i_sub < 60; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=60 */
/* Original: #pragma ACCEL PARALLEL FACTOR=60 */
/* Original: #pragma ACCEL PARALLEL */
{
        merlinL2:
        for (j = 0; j < 240; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=C_buf array inter false
          
#pragma HLS pipeline
          C_buf[((long )i_sub) - 0L][j] *= beta;
        }
        merlinL1:
        for (k = 0; k < 200; k++) {
          merlinL0:
          for (j = 0; j < 240; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS dependence variable=C_buf array inter false
            
#pragma HLS pipeline
            C_buf[((long )i_sub) - 0L][j] += alpha * A_6_1_buf[i][i_sub][k] * A_6_0_buf[j][k];
          }
        }
      }
{
        memcpy_wide_bus_write_float_2d_240_512((merlin_uint_512 *)C,C_buf,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 14400L)),sizeof(float ) * ((unsigned long )14400L),(size_t )14400L);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 8 dim=2 */
}
