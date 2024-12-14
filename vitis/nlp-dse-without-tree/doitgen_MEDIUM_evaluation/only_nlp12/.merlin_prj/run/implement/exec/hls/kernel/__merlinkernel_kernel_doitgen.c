#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 40
#define SIZE_2 10
#define SIZE_3 6
#include "memcpy_64_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 6
#define SIZE_2 60
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_doitgen(merlin_uint_64 A[60000],merlin_uint_128 C4[900],merlin_uint_512 sum[4])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=60000 bundle=merlin_gmem_kernel_doitgen_64_A
  
#pragma HLS INTERFACE m_axi port=C4 offset=slave depth=900 bundle=merlin_gmem_kernel_doitgen_128_0
  
#pragma HLS INTERFACE m_axi port=sum offset=slave depth=4 bundle=merlin_gmem_kernel_doitgen_512_sum
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=C4 bundle=control
  
#pragma HLS INTERFACE s_axilite port=sum bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=sum
  
#pragma HLS DATA_PACK VARIABLE=C4
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=sum depth=60 max_depth=60
  
#pragma ACCEL interface variable=C4 depth=60,60 max_depth=60,60
  
#pragma ACCEL interface variable=A depth=50,40,60 max_depth=50,40,60
  int r;
  int q;
  int p;
  int s;
{
    float C4_8_0_buf[10][6][60];
    
#pragma HLS array_partition variable=C4_8_0_buf cyclic factor=4 dim=3
    
#pragma HLS array_partition variable=C4_8_0_buf complete dim=2
    float sum_buf[60];
    
#pragma HLS array_partition variable=sum_buf cyclic factor=16 dim=1
    float A_buf[50][40][10][6];
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 2 dim=4 */
    
#pragma HLS array_partition variable=A_buf complete dim=4
    memcpy_wide_bus_read_float_4d_40_10_6_64(A_buf,0,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )120000L),120000L);
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&sum_buf[0],(merlin_uint_512 *)sum,(0 * 4),sizeof(float ) * ((unsigned long )60),60L);
{
      memcpy_wide_bus_read_float_3d_6_60_128(C4_8_0_buf,0,0,0,(merlin_uint_128 *)C4,(0 * 4),sizeof(float ) * ((unsigned long )3600L),3600L);
    }
    merlinL6:
    for (r = 0; r < 50; r++) {
      merlinL5:
      for (q = 0; q < 40; q++) {
        merlinL4:
        for (p = 0; p < 60; p++) {
          sum_buf[p] = ((float )0.0);
          merlinL3:
          for (s = 0; s < 10; s++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
{
            
#pragma HLS pipeline
            merlinL2:
            for (int s_sub = 0; s_sub < 6; ++s_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
              
#pragma HLS unroll
              sum_buf[p] += A_buf[r][q][s][s_sub] * C4_8_0_buf[s][s_sub][p];
            }
          }
        }
        merlinL1:
        for (p = 0; p < 10; p++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=A_buf array inter false
          
#pragma HLS pipeline
          merlinL0:
          for (int p_sub = 0; p_sub < 6; ++p_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=6 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            A_buf[r][q][p][p_sub] = sum_buf[p * 6 + p_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)sum,&sum_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )60),60L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 2 dim=4 */
    memcpy_wide_bus_write_float_4d_40_10_6_64((merlin_uint_64 *)A,A_buf,0,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )120000L),120000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C4_8_0_buf cyclic factor = 4 dim=3 */
}
