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
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_syrk_L_0_0_para_sub(float alpha,float beta,int j,int k,float A_6_1_buf[200],float C_buf[240],int i_sub,float A_6_0_buf_dup[240][200])
/* Original: #pragma ACCEL PARALLEL FACTOR=120 */
/* Original: #pragma ACCEL PARALLEL FACTOR=120 */
/* Original: #pragma ACCEL PARALLEL */
{
  
#pragma HLS inline off
  merlinL3:
  for (j = 0; j < 240; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
    
#pragma HLS dependence variable=C_buf array inter false
    
#pragma HLS pipeline
    C_buf[j] *= beta;
  }
  merlinL2:
  for (k = 0; k < 200; k++) {
    merlinL1:
    for (j = 0; j < 240; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=C_buf array inter false
      
#pragma HLS pipeline
      C_buf[j] += alpha * A_6_1_buf[k] * A_6_0_buf_dup[j][k];
    }
  }
}

void kernel_syrk_L_0_0_para(float alpha,float beta,int j,int k,float A_6_1_buf[120][200],float C_buf[120][240],float A_6_0_buf_dup[120][240][200])
{
  
#pragma HLS inline off
  int i_sub;
  merlinL0:
  for (i_sub = 0; i_sub < 120; ++i_sub) {
    
#pragma HLS unroll complete
    kernel_syrk_L_0_0_para_sub(alpha,beta,j,k,A_6_1_buf[i_sub],C_buf[i_sub],i_sub,A_6_0_buf_dup[i_sub]);
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
    float A_6_0_buf[240][200];
    
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=8 dim=2
{
      memcpy_wide_bus_read_float_2d_200_256(A_6_0_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
    float A_6_0_buf_dup[120][240][200];
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf_dup dim=1 complete */
    
#pragma HLS array_partition variable=A_6_0_buf_dup complete dim=1
{
      long _i0;
      long _i1;
      long _i2;
      merlinL8:
      for (_i1 = ((long )0); ((unsigned long )_i1) <= 239UL; ++_i1) {
        merlinL7:
        for (_i2 = ((long )0); ((unsigned long )_i2) <= 199UL; ++_i2) {
          
#pragma HLS pipeline
          
#pragma HLS loop_flatten
          merlinL6:
          for (_i0 = ((long )0); ((unsigned long )_i0) <= 119UL; ++_i0) {
            
#pragma HLS unroll
            A_6_0_buf_dup[_i0][_i1][_i2] = A_6_0_buf[_i1][_i2];
          }
        }
      }
    }
    merlinL5:
    for (i = 0; i < 2; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=120 */
/* Original: #pragma ACCEL PARALLEL FACTOR=120 */
{
      float A_6_1_buf[120][200];
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_1_buf dim=1 complete */
      
#pragma HLS array_partition variable=A_6_1_buf cyclic factor=8 dim=2
      
#pragma HLS array_partition variable=A_6_1_buf complete dim=1
      float C_buf[120][240];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf dim=1 complete */
      
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
      
#pragma HLS array_partition variable=C_buf complete dim=1
{
        memcpy_wide_bus_read_float_2d_240_512(C_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)C,(size_t )(((long )i) * 28800L * ((long )4)),sizeof(float ) * ((unsigned long )28800L),(size_t )28800L);
      }
{
        memcpy_wide_bus_read_float_2d_200_256(A_6_1_buf,(size_t )0,(size_t )0,(merlin_uint_256 *)A,(size_t )(((long )i) * 24000L * ((long )4)),sizeof(float ) * ((unsigned long )24000L),(size_t )24000L);
      }
      kernel_syrk_L_0_0_para(alpha,beta,j,k,A_6_1_buf,C_buf,A_6_0_buf_dup);
      merlinL4:
      for (int i_sub = 0; i_sub < 120; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=120 */
/* Original: #pragma ACCEL PARALLEL FACTOR=120 */
/* Original: #pragma ACCEL PARALLEL */
{
      }{
        memcpy_wide_bus_write_float_2d_240_512((merlin_uint_512 *)C,C_buf,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 28800L)),sizeof(float ) * ((unsigned long )28800L),(size_t )28800L);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_1_buf cyclic factor = 8 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 8 dim=2 */
}