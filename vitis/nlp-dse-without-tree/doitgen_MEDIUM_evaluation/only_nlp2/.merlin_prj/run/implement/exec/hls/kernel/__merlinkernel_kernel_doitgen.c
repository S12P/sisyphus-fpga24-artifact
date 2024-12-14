#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#define SIZE_1 40
#define SIZE_2 60
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 2
#define SIZE_2 30
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 30
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"








/* Original: #pragma ACCEL kernel */

void kernel_doitgen(merlin_uint_128 A[30000],merlin_uint_64 C4[1800],merlin_uint_64 sum[30])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=30000 bundle=merlin_gmem_kernel_doitgen_128_A
  
#pragma HLS INTERFACE m_axi port=C4 offset=slave depth=1800 bundle=merlin_gmem_kernel_doitgen_64_0
  
#pragma HLS INTERFACE m_axi port=sum offset=slave depth=30 bundle=merlin_gmem_kernel_doitgen_64_sum
  
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
    float C4_8_0_buf[60][2][30];
    
#pragma HLS array_partition variable=C4_8_0_buf complete dim=3
    
#pragma HLS array_partition variable=C4_8_0_buf complete dim=1
    float sum_buf[2][30];
    
#pragma HLS array_partition variable=sum_buf complete dim=2
    float A_buf[50][40][60];
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 4 dim=3 */
    
#pragma HLS array_partition variable=A_buf complete dim=3
    memcpy_wide_bus_read_float_3d_40_60_128(A_buf,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )120000L),120000L);
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_read_float_2d_30_64(sum_buf,0,0,(merlin_uint_64 *)sum,(0 * 4),sizeof(float ) * ((unsigned long )60),60L);
{
      memcpy_wide_bus_read_float_3d_2_30_64(C4_8_0_buf,0,0,0,(merlin_uint_64 *)C4,(0 * 4),sizeof(float ) * ((unsigned long )3600L),3600L);
    }
    merlinL6:
    for (r = 0; r < 50; r++) {
      merlinL5:
      for (q = 0; q < 40; q++) {
        merlinL4:
        for (p = 0; p < 2; p++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=30 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=30 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=sum_buf array inter false
          
#pragma HLS pipeline
          merlinL3:
          for (int p_sub_0 = 0; p_sub_0 < 30; ++p_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=30 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=30 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            sum_buf[p][p_sub_0] = ((float )0.0);
            merlinL2:
            for (s = 0; s < 60; s++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=60 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
              
#pragma HLS unroll
              sum_buf[p][p_sub_0] += A_buf[r][q][s] * C4_8_0_buf[s][p][p_sub_0];
            }
          }
        }
        merlinL1:
        for (p = 0; p < 2; p++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=30 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=30 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS dependence variable=A_buf array inter false
          
#pragma HLS pipeline
          merlinL0:
          for (int p_sub = 0; p_sub < 30; ++p_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=30 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=30 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            A_buf[r][q][((long )p) * 30L + ((long )p_sub)] = sum_buf[p][p_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_30_64((merlin_uint_64 *)sum,sum_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )60),60L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 4 dim=3 */
    memcpy_wide_bus_write_float_3d_40_60_128((merlin_uint_128 *)A,A_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )120000L),120000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C4_8_0_buf cyclic factor = 2 dim=3 */
}
