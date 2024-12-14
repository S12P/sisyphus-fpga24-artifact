#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#define SIZE_1 256
#define SIZE_2 12
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 10
#define SIZE_2 10
#define SIZE_3 10
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 10
#define SIZE_2 256
#define SIZE_3 12
#include "memcpy_128_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_gemm(merlin_uint_128 C[76800],merlin_uint_64 A[5000],merlin_uint_128 B[76800])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=5000 bundle=merlin_gmem_kernel_gemm_64_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=76800 bundle=merlin_gmem_kernel_gemm_128_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=76800 bundle=merlin_gmem_kernel_gemm_128_C
  
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
  float B_7_0_buf[10][10][256][12];
  
#pragma HLS array_partition variable=B_7_0_buf cyclic factor=4 dim=4
  
#pragma HLS array_partition variable=B_7_0_buf complete dim=2
  float A_7_0_buf[10][10][10][10];
  
#pragma HLS array_partition variable=A_7_0_buf complete dim=4
  int i;
  int j;
  int k;
{
    memcpy_wide_bus_read_float_4d_10_10_10_64(A_7_0_buf,0,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_4d_10_256_12_128(B_7_0_buf,0,0,0,0,(merlin_uint_128 *)B,(0 * 4),sizeof(float ) * ((unsigned long )307200L),307200L);
  }
  merlinL5:
  for (i = 0; i < 10; i++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
{
    float C_buf[10][256][12];
    
#pragma HLS array_partition variable=C_buf cyclic factor=4 dim=3
{
      memcpy_wide_bus_read_float_3d_256_12_128(C_buf,(size_t )0,(size_t )0,(size_t )0,(merlin_uint_128 *)C,(size_t )(((long )i) * 30720L * ((long )4)),sizeof(float ) * ((unsigned long )30720L),(size_t )30720L);
    }
    merlinL4:
    for (int i_sub = 0; i_sub < 10; ++i_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
      merlinL3:
      for (j = 0; j < 256; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
{
        merlinL2:
        for (int j_sub = 0; j_sub < 12; ++j_sub) 
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL FACTOR=12 */
/* Original: #pragma ACCEL PARALLEL */
{
          C_buf[i_sub][j][j_sub] = ((float )0);
          merlinL1:
          for (k = 0; k < 10; k++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS pipeline
            merlinL0:
            for (int k_sub = 0; k_sub < 10; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=10 */
/* Original: #pragma ACCEL PARALLEL */
{
              
#pragma HLS unroll
              C_buf[i_sub][j][j_sub] += A_7_0_buf[i][i_sub][k][k_sub] * B_7_0_buf[k][k_sub][j][j_sub];
            }
          }
        }
      }
    }
{
      memcpy_wide_bus_write_float_3d_256_12_128((merlin_uint_128 *)C,C_buf,(size_t )0,(size_t )0,(size_t )0,(size_t )(((long )4) * (((long )i) * 30720L)),sizeof(float ) * ((unsigned long )30720L),(size_t )30720L);
    }
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 4 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_buf cyclic factor = 4 dim=3 */
}
/* Existing HLS partition: #pragma HLS array_partition variable=A_7_0_buf cyclic factor = 2 dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_7_0_buf cyclic factor = 4 dim=4 */
