#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 30
#define SIZE_2 8
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
#define SIZE_1 8
#define SIZE_2 200
#include "memcpy_256_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"








static float compute1_1(float c,float beta,int i,int j)
{
  
#pragma HLS INLINE
  if (j <= i) {
    return c * beta;
  }
   else {
    return c;
  }
}

static float compute2_1(float c,float a,float alpha,float b,float b2,float a2,int i,int j)
{
  
#pragma HLS INLINE
  if (j <= i) {
    return c + a * alpha * b + b2 * alpha * a2;
  }
   else {
    return c;
  }
}

/* Original: #pragma ACCEL kernel */

void kernel_syr2k(float alpha,float beta,merlin_uint_512 C[3600],merlin_uint_256 A[6000],merlin_uint_256 B[6000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=6000 bundle=merlin_gmem_kernel_syr2k_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=6000 bundle=merlin_gmem_kernel_syr2k_256_1
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=3600 bundle=merlin_gmem_kernel_syr2k_512_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=B depth=240,200 max_depth=240,200
  
#pragma ACCEL interface variable=A depth=240,200 max_depth=240,200
  
#pragma ACCEL interface variable=C depth=240,240 max_depth=240,240
  int i;
  int j;
  int k;
//BLAS PARAMS
//UPLO  = 'L'
//TRANS = 'N'
//A is NxM
//B is NxM
//C is NxN
{
    float B_8_1_buf[240][200];
    
#pragma HLS array_partition variable=B_8_1_buf cyclic factor=8 dim=2
    float B_8_0_buf[30][8][200];
    
#pragma HLS array_partition variable=B_8_0_buf cyclic factor=8 dim=3
    
#pragma HLS array_partition variable=B_8_0_buf complete dim=2
    float A_8_1_buf[30][8][200];
    
#pragma HLS array_partition variable=A_8_1_buf cyclic factor=8 dim=3
    
#pragma HLS array_partition variable=A_8_1_buf complete dim=2
    float A_8_0_buf[240][200];
    
#pragma HLS array_partition variable=A_8_0_buf cyclic factor=8 dim=2
    float C_buf[240][30][8];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=C_buf complete dim=3
    
#pragma HLS array_partition variable=C_buf cyclic factor=2 dim=2
    memcpy_wide_bus_read_float_3d_30_8_512(C_buf,0,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )57600L),57600L);
{
      memcpy_wide_bus_read_float_2d_200_256(A_8_0_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_1_buf cyclic factor = 8 dim=3 */
      memcpy_wide_bus_read_float_3d_8_200_256(A_8_1_buf,0,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      memcpy_wide_bus_read_float_3d_8_200_256(B_8_0_buf,0,0,0,(merlin_uint_256 *)B,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
/* Existing HLS partition: #pragma HLS array_partition variable=B_8_1_buf cyclic factor = 8 dim=2 */
      memcpy_wide_bus_read_float_2d_200_256(B_8_1_buf,0,0,(merlin_uint_256 *)B,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
    merlinL5:
    for (i = 0; i < 240; i++) {
      merlinL4:
      for (j = 0; j < 30; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=C_buf array inter false
        
#pragma HLS pipeline
        merlinL3:
        for (int j_sub_0 = 0; j_sub_0 < 8; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          C_buf[i][j][j_sub_0] = compute1_1(C_buf[i][j][j_sub_0],beta,i,j * 8 + j_sub_0);
        }
      }
      merlinL2:
      for (k = 0; k < 200; k++) {
        merlinL1:
        for (j = 0; j < 30; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=C_buf array inter false
          
#pragma HLS pipeline
          merlinL0:
          for (int j_sub = 0; j_sub < 8; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            C_buf[i][j][j_sub] = compute2_1(C_buf[i][j][j_sub],A_8_1_buf[j][j_sub][k],alpha,B_8_1_buf[i][k],B_8_0_buf[j][j_sub][k],A_8_0_buf[i][k],i,j * 8 + j_sub);
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_3d_30_8_512((merlin_uint_512 *)C,C_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )57600L),57600L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_8_0_buf cyclic factor = 8 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_8_0_buf cyclic factor = 8 dim=3 */
}
