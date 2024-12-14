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







static float compute1_1(float c,float alpha,float b,float a,int i,int k)
{
  
#pragma HLS INLINE
  if (k < i) {
    return c + alpha * a * b;
  }
   else {
    return c;
  }
}

static float compute2_1(float temp2,float b,float a,int i,int k)
{
  
#pragma HLS INLINE
  if (k < i) {
    return temp2 + a * b;
  }
   else {
    return temp2;
  }
}

/* Original: #pragma ACCEL kernel */

void kernel_symm(float alpha,float beta,merlin_uint_512 C[3000],merlin_uint_256 A[5000],merlin_uint_512 B[3000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=5000 bundle=merlin_gmem_kernel_symm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=3000 bundle=merlin_gmem_kernel_symm_512_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=3000 bundle=merlin_gmem_kernel_symm_512_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=beta bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=B depth=200,240 max_depth=200,240
  
#pragma ACCEL interface variable=A depth=200,200 max_depth=200,200
  
#pragma ACCEL interface variable=C depth=200,240 max_depth=200,240
  int i;
  int j;
  int k;
  float temp2;
//BLAS PARAMS
//SIDE = 'L'
//UPLO = 'L'
// =>  Form  C := alpha*A*B + beta*C
// A is MxM
// B is MxN
// C is MxN
//note that due to Fortran array layout, the code below more closely resembles upper triangular case in BLAS
{
    float B_3_0_buf[200][240];
    
#pragma HLS array_partition variable=B_3_0_buf cyclic factor=16 dim=2
    float A_4_1_buf[200][200];
    
#pragma HLS array_partition variable=A_4_1_buf complete dim=2
    float A_4_0_buf[200][200];
    
#pragma HLS array_partition variable=A_4_0_buf complete dim=2
    float B_4_1_buf[200][240];
    
#pragma HLS array_partition variable=B_4_1_buf cyclic factor=16 dim=2
    float B_4_0_buf[199][240];
    
#pragma HLS array_partition variable=B_4_0_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=B_4_0_buf complete dim=1
    float C_buf[200][240];
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
    
#pragma HLS array_partition variable=C_buf cyclic factor=16 dim=2
    
#pragma HLS array_partition variable=C_buf complete dim=1
    memcpy_wide_bus_read_float_2d_240_512(C_buf,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
{
      memcpy_wide_bus_read_float_2d_240_512(B_4_0_buf,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )47760L),47760L);
/* Existing HLS partition: #pragma HLS array_partition variable=B_4_1_buf cyclic factor = 16 dim=2 */
      memcpy_wide_bus_read_float_2d_240_512(B_4_1_buf,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
/* Existing HLS partition: #pragma HLS array_partition variable=B_3_0_buf cyclic factor = 16 dim=2 */
      memcpy_wide_bus_read_float_2d_240_512(B_3_0_buf,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    }
{
      memcpy_wide_bus_read_float_2d_200_256(A_4_0_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )39999L),39999L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_1_buf cyclic factor = 8 dim=2 */
      memcpy_wide_bus_read_float_2d_200_256(A_4_1_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )39999L),39999L);
    }
    merlinL2:
    for (i = 0; i < 200; i++) {
      float A_3_0_buf[1];
{
        memcpy((void *)(&A_3_0_buf[0]),(const void *)(&A[((long )i) * 201L]),sizeof(float ) * ((unsigned long )1L));
      }
      merlinL1:
      for (j = 0; j < 240; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=C_buf array inter false
        
#pragma HLS pipeline
        temp2 = ((float )0);
        merlinL0:
        for (k = 0; k < 199; k++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=199 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
// C[k][j] += alpha * B[i][j] * A[i][k];
          C_buf[k][j] = compute1_1(C_buf[k][j],alpha,B_4_1_buf[i][j],A_4_1_buf[i][k],i,k);
// temp2 += B[k][j] * A[i][k];
          temp2 = compute2_1(temp2,B_4_0_buf[k][j],A_4_0_buf[i][k],i,k);
        }
        C_buf[i][j] = beta * C_buf[i][j] + alpha * B_3_0_buf[i][j] * A_3_0_buf[0] + alpha * temp2;
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 16 dim=2 */
    memcpy_wide_bus_write_float_2d_240_512((merlin_uint_512 *)C,C_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )48000L),48000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_4_0_buf cyclic factor = 8 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_4_0_buf cyclic factor = 16 dim=2 */
}
