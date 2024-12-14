#define __constant
#define __kernel
#define __global
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 1
#include "memcpy_512_2d.h"
#undef SIZE_1
#define SIZE_1 100
#include "memcpy_128_2d.h"
#undef SIZE_1
#define SIZE_1 1536
#define SIZE_2 2
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_gemm(merlin_uint_512 C[19200],merlin_uint_128 A[2500],merlin_uint_512 B[19200])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=2500 bundle=merlin_gmem_kernel_gemm_128_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19200 bundle=merlin_gmem_kernel_gemm_512_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=19200 bundle=merlin_gmem_kernel_gemm_512_C
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=B depth=100,3072 max_depth=100,3072
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,3072 max_depth=100,3072
  float B_5_0_buf[100][1536][2];
  
#pragma HLS array_partition variable=B_5_0_buf complete dim=3
  
#pragma HLS array_partition variable=B_5_0_buf cyclic factor=8 dim=2
  float A_5_0_buf[100][100];
  
#pragma HLS array_partition variable=A_5_0_buf cyclic factor=4 dim=2
  int i;
  int j;
  int k;
{
    memcpy_wide_bus_read_float_2d_100_128(A_5_0_buf,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_3d_1536_2_512(B_5_0_buf,0,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )307200L),307200L);
  }
  merlinL3:
  for (i = 0; i < 100; i++) {
    merlinL2:
    for (j = 0; j < 1536; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
      float C_buf[2][1];
      
#pragma HLS array_partition variable=C_buf complete dim=2
      
#pragma HLS array_partition variable=C_buf complete dim=1
{
        memcpy_wide_bus_read_float_2d_1_512(C_buf,(size_t )0,(size_t )0,(merlin_uint_512 *)C,(size_t )((((long )i) * 3072L + ((long )(j * 2))) * ((long )4)),sizeof(float ) * ((unsigned long )2L),(size_t )2L);
      }
      merlinL1:
      for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        C_buf[((long )j_sub) - 0L][0] = ((float )0);
        merlinL0:
        for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS pipeline
          C_buf[((long )j_sub) - 0L][0] += A_5_0_buf[i][k] * B_5_0_buf[k][j][j_sub];
        }
      }
{
        memcpy_wide_bus_write_float_2d_1_512((merlin_uint_512 *)C,C_buf,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 3072L + ((long )(j * 2)))),sizeof(float ) * ((unsigned long )2L),(size_t )2L);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 8 dim=0 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 8 dim=0 */
  }
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_0_buf cyclic factor = 4 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_5_0_buf complete dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_5_0_buf cyclic factor = 8 dim=2 */
