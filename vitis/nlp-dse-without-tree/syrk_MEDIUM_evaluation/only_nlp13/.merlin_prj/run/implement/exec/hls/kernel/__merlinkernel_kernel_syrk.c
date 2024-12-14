#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 15
#define SIZE_2 16
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 16
#define SIZE_2 200
#include "memcpy_256_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
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
    float A_7_1_buf[240][200];
    
#pragma HLS array_partition variable=A_7_1_buf cyclic factor=8 dim=2
    float A_7_0_buf[15][16][200];
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=8 dim=3
    
#pragma HLS array_partition variable=A_7_0_buf complete dim=2
    float C_buf[240][15][16];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=3 */
    
#pragma HLS array_partition variable=C_buf complete dim=3
    memcpy_wide_bus_read_float_3d_15_16_512(C_buf,0,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )57600L),57600L);
{
      memcpy_wide_bus_read_float_3d_16_200_256(A_7_0_buf,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_1_buf cyclic factor = 8 dim=2 */
      memcpy_wide_bus_read_float_2d_200_256(A_7_1_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
    merlinL5:
    for (i = 0; i < 240; i++) {
      merlinL4:
      for (j = 0; j < 15; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=C_buf array inter false
        
#pragma HLS pipeline
        merlinL3:
        for (int j_sub_0 = 0; j_sub_0 < 16; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          C_buf[i][j][j_sub_0] *= beta;
        }
      }
      merlinL2:
      for (k = 0; k < 200; k++) {
        merlinL1:
        for (j = 0; j < 15; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=C_buf array inter false
          
#pragma HLS pipeline
          merlinL0:
          for (int j_sub = 0; j_sub < 16; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=16 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            C_buf[i][j][j_sub] += alpha * A_7_1_buf[i][k] * A_7_0_buf[j][j_sub][k];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=3 */
    memcpy_wide_bus_write_float_3d_15_16_512((merlin_uint_512 *)C,C_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )57600L),57600L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 8 dim=3 */
}
