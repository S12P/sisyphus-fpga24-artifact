#define __constant
#define __kernel
#define __global
#include "memcpy_256_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
#define SIZE_1 30
#define SIZE_2 8
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_trmm(float alpha,merlin_uint_256 A[5000],merlin_uint_512 B[3000])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=5000 bundle=merlin_gmem_kernel_trmm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=3000 bundle=merlin_gmem_kernel_trmm_512_B
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=B depth=200,240 max_depth=200,240
  
#pragma ACCEL interface variable=A depth=200,200 max_depth=200,200
  int i;
  int j;
  int k;
//BLAS parameters
//SIDE   = 'L'
//UPLO   = 'L'
//TRANSA = 'T'
//DIAG   = 'U'
// => Form  B := alpha*A**T*B.
// A is MxM
// B is MxN
{
    float B_buf[200][30][8];
/* Existing HLS partition: #pragma HLS array_partition variable=B_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=B_buf complete dim=3
    
#pragma HLS array_partition variable=B_buf cyclic factor=2 dim=2
    memcpy_wide_bus_read_float_3d_30_8_512(B_buf,0,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )48000L),48000L);
    merlinL4:
    for (i = 0; i < 25; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
{
      merlinL3:
      for (int i_sub = 0; i_sub < 8; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
        float A_6_0_buf[199][200];
        
#pragma HLS array_partition variable=A_6_0_buf cyclic factor=8 dim=2
{
          memcpy_wide_bus_read_float_2d_200_256(A_6_0_buf,(size_t )0,(size_t )0,(merlin_uint_256 *)A,(size_t )((200L + ((long )(i * 1608)) + ((long )(i_sub * 201))) * ((long )4)),sizeof(float ) * ((unsigned long )(39601L + ((long )(i * - 1600)) + ((long )(i_sub * - 200)))),(size_t )39800L);
        }
        merlinL2:
        for (j = 0; j < 30; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
{
          merlinL1:
          for (int j_sub = 0; j_sub < 8; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PARALLEL */
{
            merlinL0:
            for (k = i * 8 + i_sub + 1; k < 200; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              
#pragma HLS LOOP_TRIPCOUNT max=199
              B_buf[((long )i) * 8L + ((long )i_sub)][j][j_sub] += A_6_0_buf[((long )(- 1 + -i_sub)) + ((long )i) * - 8L + ((long )k)][0] * B_buf[k][j][j_sub];
            }
            B_buf[((long )i) * 8L + ((long )i_sub)][j][j_sub] = alpha * B_buf[((long )i) * 8L + ((long )i_sub)][j][j_sub];
          }
        }
      }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 8 dim=2 */
    }
/* Existing HLS partition: #pragma HLS array_partition variable=B_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_3d_30_8_512((merlin_uint_512 *)B,B_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )48000L),48000L);
  }
}
