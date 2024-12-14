#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 240
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 3
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

void kernel_syrk_L_0_para_sub(float alpha,float beta,int i,int j,int k,float A_7_1_buf[200],float C_buf[240],float A_7_0_buf_dup[80][3][200])
/* Original: #pragma ACCEL PARALLEL FACTOR=240 */
/* Original: #pragma ACCEL PARALLEL FACTOR=240 */
/* Original: #pragma ACCEL parallel */
{
  
#pragma HLS inline off
  merlinL5:
  for (j = 0; j < 30; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS dependence variable=C_buf array inter false
    
#pragma HLS pipeline
    merlinL4:
    for (int j_sub_0 = 0; j_sub_0 < 8; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
      
#pragma HLS unroll
      C_buf[j * 8 + j_sub_0] *= beta;
    }
  }
  merlinL3:
  for (k = 0; k < 200; k++) {
    merlinL2:
    for (j = 0; j < 80; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=C_buf array inter false
      
#pragma HLS pipeline
      merlinL1:
      for (int j_sub = 0; j_sub < 3; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=3 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        C_buf[j * 3 + j_sub] += alpha * A_7_1_buf[k] * A_7_0_buf_dup[j][j_sub][k];
      }
    }
  }
}

void kernel_syrk_L_0_para(float alpha,float beta,int j,int k,float A_7_1_buf[240][200],float C_buf[240][240],float A_7_0_buf_dup[240][80][3][200])
{
  
#pragma HLS inline off
  int i;
  merlinL0:
  for (i = 0; i < 240; ++i) {
    
#pragma HLS unroll complete
    kernel_syrk_L_0_para_sub(alpha,beta,i,j,k,A_7_1_buf[i],C_buf[i],A_7_0_buf_dup[i]);
  }
}

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
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_1_buf dim=1 complete */
    
#pragma HLS array_partition variable=A_7_1_buf cyclic factor=8 dim=2
    
#pragma HLS array_partition variable=A_7_1_buf complete dim=1
    float A_7_0_buf[80][3][200];
    
#pragma HLS array_partition variable=A_7_0_buf cyclic factor=8 dim=3
    float C_buf[240][240];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf dim=1 complete */
    
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=C_buf complete dim=1
{
      memcpy_wide_bus_read_float_2d_240_512(C_buf,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )57600L),57600L);
    }
{
      memcpy_wide_bus_read_float_3d_3_200_256(A_7_0_buf,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_1_buf cyclic factor = 8 dim=2 */
      memcpy_wide_bus_read_float_2d_200_256(A_7_1_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
    float A_7_0_buf_dup[240][80][3][200];
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=A_7_0_buf_dup complete dim=3
    
#pragma HLS array_partition variable=A_7_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      long _i2;
      long _i3;
      merlinL10:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 79UL; ++_i1) {
        merlinL9:
        for (_i2 = ((long )0); ((unsigned long )_i2) <= 2UL; ++_i2) {
          merlinL8:
          for (_i3 = ((long )0); ((unsigned long )_i3) <= 199UL; ++_i3) {
            
#pragma HLS pipeline
            
#pragma HLS loop_flatten
            merlinL7:
            for (_i0 = ((long )0); ((unsigned long )_i0) <= 239UL; ++_i0) {
              
#pragma HLS unroll
              A_7_0_buf_dup[_i0][_i1][_i2][_i3] = A_7_0_buf[_i1][_i2][_i3];
            }
          }
        }
      }
    }
    kernel_syrk_L_0_para(alpha,beta,j,k,A_7_1_buf,C_buf,A_7_0_buf_dup);
    merlinL6:
    for (i = 0; i < 240; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=240 */
/* Original: #pragma ACCEL PARALLEL FACTOR=240 */
/* Original: #pragma ACCEL parallel */
{
    }{
      memcpy_wide_bus_write_float_2d_240_512((merlin_uint_512 *)C,C_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )57600L),57600L);
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 8 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
}
