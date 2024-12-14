#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 2
#define SIZE_2 390
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 2
#include "memcpy_512_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"







/* Original: #pragma ACCEL kernel */

void kernel_bicg(merlin_uint_64 A[79950],merlin_uint_512 s[25],merlin_uint_512 q[26],merlin_uint_512 p[25],merlin_uint_512 r[26])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=79950 bundle=merlin_gmem_kernel_bicg_64_0
  
#pragma HLS INTERFACE m_axi port=p offset=slave depth=25 bundle=merlin_gmem_kernel_bicg_512_0
  
#pragma HLS INTERFACE m_axi port=q offset=slave depth=26 bundle=merlin_gmem_kernel_bicg_512_q
  
#pragma HLS INTERFACE m_axi port=r offset=slave depth=26 bundle=merlin_gmem_kernel_bicg_512_1
  
#pragma HLS INTERFACE m_axi port=s offset=slave depth=25 bundle=merlin_gmem_kernel_bicg_512_s
  
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
    float p_5_0_buf[390];
    
#pragma HLS array_partition variable=p_5_0_buf complete dim=1
    float A_5_1_buf[205][2][390];
    
#pragma HLS array_partition variable=A_5_1_buf complete dim=3
    
#pragma HLS array_partition variable=A_5_1_buf complete dim=2
    float A_5_0_buf[205][2][390];
    
#pragma HLS array_partition variable=A_5_0_buf complete dim=3
    
#pragma HLS array_partition variable=A_5_0_buf complete dim=2
    float r_5_0_buf[205][2];
    
#pragma HLS array_partition variable=r_5_0_buf complete dim=2
    
#pragma HLS array_partition variable=r_5_0_buf cyclic factor=8 dim=1
    float q_buf[205][2];
    
#pragma HLS array_partition variable=q_buf complete dim=2
    
#pragma HLS array_partition variable=q_buf cyclic factor=8 dim=1
    float s_buf[390];
/* Existing HLS partition: #pragma HLS array_partition variable=s_buf cyclic factor = 16 dim=1 */
    
#pragma HLS array_partition variable=s_buf complete dim=1
    memcpy_wide_bus_read_float_512(&s_buf[0],(merlin_uint_512 *)s,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
    merlinL3:
    for (i = 0; i < 390; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=390 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=390 */
/* Original: #pragma ACCEL parallel */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS unroll
      s_buf[i] = ((float )0);
    }
/* Existing HLS partition: #pragma HLS array_partition variable=q_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=q_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_read_float_2d_2_512(q_buf,0,0,(merlin_uint_512 *)q,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
{
      memcpy_wide_bus_read_float_2d_2_512(r_5_0_buf,0,0,(merlin_uint_512 *)r,(0 * 4),sizeof(float ) * ((unsigned long )410),410L);
    }
{
      memcpy_wide_bus_read_float_3d_2_390_64(A_5_0_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_1_buf cyclic factor = 2 dim=3 */
      memcpy_wide_bus_read_float_3d_2_390_64(A_5_1_buf,0,0,0,(merlin_uint_64 *)A,(0 * 4),sizeof(float ) * ((unsigned long )159900L),159900L);
    }
{
      memcpy_wide_bus_read_float_512(&p_5_0_buf[0],(merlin_uint_512 *)p,(0 * 4),sizeof(float ) * ((unsigned long )390),390L);
    }
    merlinL2:
    for (i = 0; i < 205; i++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
      
#pragma HLS dependence variable=q_buf array inter false
      
#pragma HLS pipeline
      merlinL1:
      for (int i_sub = 0; i_sub < 2; ++i_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
        
#pragma HLS unroll
        q_buf[i][i_sub] = ((float )0.0);
        merlinL0:
        for (j = 0; j < 390; j++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=390 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma HLS unroll
          s_buf[j] = s_buf[j] + r_5_0_buf[i][i_sub] * A_5_1_buf[i][i_sub][j];
          q_buf[i][i_sub] = q_buf[i][i_sub] + A_5_0_buf[i][i_sub][j] * p_5_0_buf[j];
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=q_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=q_buf cyclic factor = 8 dim=1 */
    memcpy_wide_bus_write_float_2d_2_512((merlin_uint_512 *)q,q_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )410),410L);
/* Existing HLS partition: #pragma HLS array_partition variable=s_buf cyclic factor = 16 dim=1 */
    memcpy_wide_bus_write_float_512((merlin_uint_512 *)s,&s_buf[0],(4 * 0),sizeof(float ) * ((unsigned long )390),390L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_5_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=p_5_0_buf cyclic factor = 16 dim=1 */
/* Existing HLS partition: #pragma HLS array_partition variable=r_5_0_buf complete dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=r_5_0_buf cyclic factor = 8 dim=1 */
}
