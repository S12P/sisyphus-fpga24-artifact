#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 240
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 100
#define SIZE_2 2
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
    float A_6_1_buf[240][100][2];
    
#pragma HLS array_partition variable=A_6_1_buf complete dim=3
    
#pragma HLS array_partition variable=A_6_1_buf cyclic factor=4 dim=2
    float A_6_0_buf[240][100][2];
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=4 dim=2
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=1
    float C_buf[240][240];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
    
#pragma HLS array_partition variable=C_buf complete dim=2
    memcpy_wide_bus_read_float_2d_240_512(C_buf,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )57600L),57600L);
{
      memcpy_wide_bus_read_float_3d_100_2_256(A_6_0_buf,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_1_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_1_buf cyclic factor = 4 dim=2 */
      memcpy_wide_bus_read_float_3d_100_2_256(A_6_1_buf,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
    merlinL4:
    for (i = 0; i < 240; i++) {
      merlinL3:
      for (j = 0; j < 240; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=240 */
/* Original: #pragma ACCEL PARALLEL FACTOR=240 */
/* Original: #pragma ACCEL parallel */
{
        
#pragma HLS unroll
        C_buf[i][j] *= beta;
      }
      merlinL2:
      for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS pipeline
        merlinL1:
        for (int k_sub = 0; k_sub < 2; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          merlinL0:
          for (j = 0; j < 240; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=240 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            C_buf[i][j] += alpha * A_6_1_buf[i][k][k_sub] * A_6_0_buf[j][k][k_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_write_float_2d_240_512((merlin_uint_512 *)C,C_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )57600L),57600L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 4 dim=2 */
}
