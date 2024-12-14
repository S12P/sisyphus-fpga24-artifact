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
#define SIZE_1 4
#define SIZE_2 30
#define SIZE_3 2
#include "memcpy_128_4d.h"
#undef SIZE_1
#undef SIZE_2
#undef SIZE_3
#define SIZE_1 1
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 6
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"









/* Original: #pragma ACCEL kernel */

void kernel_doitgen(merlin_uint_128 A[30000],merlin_uint_128 C4[900],merlin_uint_64 sum[30])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=30000 bundle=merlin_gmem_kernel_doitgen_128_A
  
#pragma HLS INTERFACE m_axi port=C4 offset=slave depth=900 bundle=merlin_gmem_kernel_doitgen_128_0
  
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
    float C4_9_0_buf[15][4][30][2];
    
#pragma HLS array_partition variable=C4_9_0_buf complete dim=4
    
#pragma HLS array_partition variable=C4_9_0_buf cyclic factor=2 dim=3
    
#pragma HLS array_partition variable=C4_9_0_buf complete dim=2
    float A_buf[50][40][60];
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 4 dim=3 */
    
#pragma HLS array_partition variable=A_buf cyclic factor=4 dim=3
    memcpy_wide_bus_read_float_3d_40_60_128(A_buf,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )120000L),120000L);
{
      memcpy_wide_bus_read_float_4d_4_30_2_128(C4_9_0_buf,0,0,0,0,(merlin_uint_128 *)C4,(0 * 4),sizeof(float ) * ((unsigned long )3600L),3600L);
    }
    merlinL7:
    for (r = 0; r < 50; r++) {
      merlinL6:
      for (q = 0; q < 40; q++) {
        float sum_7_0_buf[10][6];
        
#pragma HLS array_partition variable=sum_7_0_buf complete dim=2
        merlinL5:
        for (p = 0; p < 30; p++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
{
          float sum_buf[2][1];
          
#pragma HLS array_partition variable=sum_buf complete dim=2
          
#pragma HLS array_partition variable=sum_buf complete dim=1
{
            memcpy_wide_bus_read_float_2d_1_64(sum_buf,(size_t )0,(size_t )0,(merlin_uint_64 *)sum,(size_t )(p * 2 * 4),sizeof(float ) * ((unsigned long )2),(size_t )2L);
          }
          merlinL4:
          for (int p_sub_0 = 0; p_sub_0 < 2; ++p_sub_0) 
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
            sum_buf[((long )p_sub_0) - 0L][0] = ((float )0.0);
            merlinL3:
            for (s = 0; s < 15; s++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
{
              
#pragma HLS pipeline
              merlinL2:
              for (int s_sub = 0; s_sub < 4; ++s_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=4 */
/* Original: #pragma ACCEL PARALLEL */
{
                
#pragma HLS unroll
                sum_buf[((long )p_sub_0) - 0L][0] += A_buf[r][q][((long )s) * 4L + ((long )s_sub)] * C4_9_0_buf[s][s_sub][p][p_sub_0];
              }
            }
          }
{
            memcpy_wide_bus_write_float_2d_1_64((merlin_uint_64 *)sum,sum_buf,(size_t )0,(size_t )0,(size_t )(4 * (p * 2)),sizeof(float ) * ((unsigned long )2),(size_t )2L);
          }
        }
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf cyclic factor = 2 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=sum_buf cyclic factor = 2 dim=1 */
{
          memcpy_wide_bus_read_float_2d_6_64(sum_7_0_buf,(size_t )0,(size_t )0,(merlin_uint_64 *)sum,(size_t )(0 * 4),sizeof(float ) * ((unsigned long )60),(size_t )60L);
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
            A_buf[r][q][((long )p) * 6L + ((long )p_sub)] = sum_7_0_buf[p][p_sub];
          }
        }
      }
/* Existing HLS partition: #pragma HLS array_partition variable=sum_7_0_buf cyclic factor = 2 dim=2 */
    }
/* Existing HLS partition: #pragma HLS array_partition variable=A_buf cyclic factor = 4 dim=3 */
    memcpy_wide_bus_write_float_3d_40_60_128((merlin_uint_128 *)A,A_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )120000L),120000L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=C4_9_0_buf complete dim=4 */
/* Existing HLS partition: #pragma HLS array_partition variable=C4_9_0_buf cyclic factor = 2 dim=3 */
}
