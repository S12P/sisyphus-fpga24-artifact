#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 5
#define SIZE_2 78
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 78
#include "memcpy_64_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_bicg(merlin_uint_64 A[79950],merlin_uint_64 s[195],merlin_uint_512 q[26],merlin_uint_64 p[195],merlin_uint_512 r[26])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=79950 bundle=merlin_gmem_kernel_bicg_64_0
  
#pragma HLS INTERFACE m_axi port=p offset=slave depth=195 bundle=merlin_gmem_kernel_bicg_64_1
  
#pragma HLS INTERFACE m_axi port=q offset=slave depth=26 bundle=merlin_gmem_kernel_bicg_512_q
  
#pragma HLS INTERFACE m_axi port=r offset=slave depth=26 bundle=merlin_gmem_kernel_bicg_512_0
  
#pragma HLS INTERFACE m_axi port=s offset=slave depth=195 bundle=merlin_gmem_kernel_bicg_64_s
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=p bundle=control
  
#pragma HLS INTERFACE s_axilite port=q bundle=control
  
#pragma HLS INTERFACE s_axilite port=r bundle=control
  
#pragma HLS INTERFACE s_axilite port=s bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=r
  
#pragma HLS DATA_PACK VARIABLE=p
  
#pragma HLS DATA_PACK VARIABLE=q
  
#pragma HLS DATA_PACK VARIABLE=s
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma ACCEL interface variable=r depth=410 max_depth=410
  
#pragma ACCEL interface variable=p depth=390 max_depth=390
  
#pragma ACCEL interface variable=q depth=410 max_depth=410
  
#pragma ACCEL interface variable=s depth=390 max_depth=390
  
#pragma ACCEL interface variable=A depth=410,390 max_depth=410,390
  int i;
  int j;
{
    float p_6_0_buf[5][78];
    
#pragma HLS array_partition variable=p_6_0_buf complete dim=2
    float A_6_1_buf[410][5][78];
    
#pragma HLS array_partition variable=A_6_1_buf complete dim=3
    float A_6_0_buf[410][5][78];
    
#pragma HLS array_partition variable=A_6_0_buf complete dim=3
    float r_6_0_buf[410];
    
#pragma HLS array_partition variable=r_6_0_buf cyclic factor=16 dim=1
    float q_buf[410];
    
#pragma HLS array_partition variable=q_buf cyclic factor=16 dim=1
    float s_buf[5][78];
/* Existing HLS partition: #pragma HLS array_partition variable=s_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=s_buf complete dim=2
    memcpy_wide_bus_read_float_2d_78_64(s_buf,0,0,(merlin_uint_64 *)s,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
    merlinL4:
    for (i = 0; i < 5; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=78 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=78 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=s_buf array inter false
      
#pragma HLS pipeline
      merlinL3:
      for (int i_sub = 0; i_sub < 78; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=78 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=78 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        s_buf[i][i_sub] = ((float )0);
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=q_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_read_float_512(&q_buf[0],(merlin_uint_512 *)q,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
{
      memcpy_wide_bus_read_float_512(&r_6_0_buf[0],(merlin_uint_512 *)r,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    }
{
      memcpy_wide_bus_read_float_3d_5_78_64(A_6_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_1_buf cyclic factor = 2 dim=3 */
      memcpy_wide_bus_read_float_3d_5_78_64(A_6_1_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
    }
{
      memcpy_wide_bus_read_float_2d_78_64(p_6_0_buf,0,0,(merlin_uint_64 *)p,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
    }
    merlinL2:
    for (i = 0; i < 410; i++) {
      q_buf[i] = ((float )0.0);
      merlinL1:
      for (j = 0; j < 5; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=78 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=78 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=s_buf array inter false
        
#pragma HLS pipeline
        merlinL0:
        for (int j_sub = 0; j_sub < 78; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=78 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=78 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          s_buf[j][j_sub] = s_buf[j][j_sub] + r_6_0_buf[i] * A_6_1_buf[i][j][j_sub];
          q_buf[i] = q_buf[i] + A_6_0_buf[i][j][j_sub] * p_6_0_buf[j][j_sub];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=q_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)q,&q_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )410),410L);
/* Existing HLS partition: #pragma HLS array_partition variable=s_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_78_64((merlin_uint_64 *)s,s_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )390),390L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_6_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=p_6_0_buf cyclic factor = 2 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=r_6_0_buf cyclic factor = 16 dim=1 */
}
