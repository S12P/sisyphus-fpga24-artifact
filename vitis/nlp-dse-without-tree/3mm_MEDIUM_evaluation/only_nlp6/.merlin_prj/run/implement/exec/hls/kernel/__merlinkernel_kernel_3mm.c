#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#include "memcpy_256_1d.h"
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 200
#include "memcpy_256_2d.h"
#undef SIZE_1
#define SIZE_1 95
#define SIZE_2 2
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 105
#define SIZE_2 2
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 220
#include "memcpy_128_2d.h"
#undef SIZE_1
#include <string.h> 

#include "merlin_type_define.h"











/* Original: #pragma ACCEL kernel */

void kernel_3mm(merlin_uint_64 E[17100],merlin_uint_256 A[4500],merlin_uint_64 B[19000],merlin_uint_64 F[19950],merlin_uint_128 C[10450],merlin_uint_64 D[23100],merlin_uint_64 G[18900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=4500 bundle=merlin_gmem_kernel_3mm_256_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=10450 bundle=merlin_gmem_kernel_3mm_128_0
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=23100 bundle=merlin_gmem_kernel_3mm_64_1
  
#pragma HLS INTERFACE m_axi port=E offset=slave depth=17100 bundle=merlin_gmem_kernel_3mm_64_E
  
#pragma HLS INTERFACE m_axi port=F offset=slave depth=19950 bundle=merlin_gmem_kernel_3mm_64_F
  
#pragma HLS INTERFACE m_axi port=G offset=slave depth=18900 bundle=merlin_gmem_kernel_3mm_64_G
  
#pragma HLS INTERFACE s_axilite port=A bundle=control
  
#pragma HLS INTERFACE s_axilite port=B bundle=control
  
#pragma HLS INTERFACE s_axilite port=C bundle=control
  
#pragma HLS INTERFACE s_axilite port=D bundle=control
  
#pragma HLS INTERFACE s_axilite port=E bundle=control
  
#pragma HLS INTERFACE s_axilite port=F bundle=control
  
#pragma HLS INTERFACE s_axilite port=G bundle=control
  
#pragma HLS INTERFACE s_axilite port=return bundle=control
  
#pragma HLS DATA_PACK VARIABLE=G
  
#pragma HLS DATA_PACK VARIABLE=D
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma HLS DATA_PACK VARIABLE=F
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=E
  
#pragma ACCEL interface variable=G depth=180,210 max_depth=180,210
  
#pragma ACCEL interface variable=D depth=220,210 max_depth=220,210
  
#pragma ACCEL interface variable=C depth=190,220 max_depth=190,220
  
#pragma ACCEL interface variable=F depth=190,210 max_depth=190,210
  
#pragma ACCEL interface variable=B depth=200,190 max_depth=200,190
  
#pragma ACCEL interface variable=A depth=180,200 max_depth=180,200
  
#pragma ACCEL interface variable=E depth=180,190 max_depth=180,190
  int i;
  int j;
  int k;
{
    float B_11_0_buf[200][95][2];
    
#pragma HLS array_partition variable=B_11_0_buf complete dim=3
    
#pragma HLS array_partition variable=B_11_0_buf complete dim=1
    float A_11_0_buf[180][200];
    
#pragma HLS array_partition variable=A_11_0_buf complete dim=2
    float D_12_0_buf[220][105][2];
    
#pragma HLS array_partition variable=D_12_0_buf complete dim=3
    
#pragma HLS array_partition variable=D_12_0_buf complete dim=1
    float C_12_0_buf[190][220];
    
#pragma HLS array_partition variable=C_12_0_buf complete dim=2
    float G_buf[180][105][2];
    
#pragma HLS array_partition variable=G_buf complete dim=3
    float F_buf[190][105][2];
    
#pragma HLS array_partition variable=F_buf complete dim=3
    
#pragma HLS array_partition variable=F_buf complete dim=1
    float E_buf[180][190];
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=E_buf complete dim=2
    memcpy_wide_bus_read_float_2d_190_64(E_buf,0,0,(merlin_uint_64 *)E,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_read_float_3d_105_2_64(F_buf,0,0,0,(merlin_uint_64 *)F,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
{
      memcpy_wide_bus_read_float_2d_200_256(A_11_0_buf,0,0,(merlin_uint_256 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      memcpy_wide_bus_read_float_3d_95_2_64(B_11_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )38000L),38000L);
    }
    merlinL11:
    for (i = 0; i < 180; i++) {
      merlinL10:
      for (j = 0; j < 95; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=E_buf array inter false
        
#pragma HLS pipeline
        merlinL9:
        for (int j_sub_1 = 0; j_sub_1 < 2; ++j_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          E_buf[i][((long )j) * 2L + ((long )j_sub_1)] = ((float )0.0);
          merlinL8:
          for (k = 0; k < 200; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=200 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            E_buf[i][((long )j) * 2L + ((long )j_sub_1)] += A_11_0_buf[i][k] * B_11_0_buf[k][j][j_sub_1];
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_2d_220_128(C_12_0_buf,0,0,(merlin_uint_128 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      memcpy_wide_bus_read_float_3d_105_2_64(D_12_0_buf,0,0,0,(merlin_uint_64 *)D,(0 * 4),sizeof(float ) * ((unsigned long )46200L),46200L);
    }
    merlinL7:
    for (i = 0; i < 190; i++) {
      merlinL6:
      for (j = 0; j < 105; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=F_buf array inter false
        
#pragma HLS pipeline
        merlinL5:
        for (int j_sub_0 = 0; j_sub_0 < 2; ++j_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          F_buf[i][j][j_sub_0] = ((float )0.0);
          merlinL4:
          for (k = 0; k < 220; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=220 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            F_buf[i][j][j_sub_0] += C_12_0_buf[i][k] * D_12_0_buf[k][j][j_sub_0];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_read_float_3d_105_2_64(G_buf,0,0,0,(merlin_uint_64 *)G,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    merlinL3:
    for (i = 0; i < 180; i++) {
      merlinL2:
      for (j = 0; j < 105; j++) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
{
        
#pragma HLS dependence variable=G_buf array inter false
        
#pragma HLS pipeline
        merlinL1:
        for (int j_sub = 0; j_sub < 2; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=2 */
/* Original: #pragma ACCEL PARALLEL */
{
          
#pragma HLS unroll
          G_buf[i][j][j_sub] = ((float )0.0);
          merlinL0:
          for (k = 0; k < 190; ++k) 
/* Original: #pragma ACCEL PARALLEL FACTOR=190 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
            
#pragma HLS unroll
            G_buf[i][j][j_sub] += E_buf[i][k] * F_buf[k][j][j_sub];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_write_float_3d_105_2_64((merlin_uint_64 *)G,G_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )37800L),37800L);
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_190_64((merlin_uint_64 *)E,E_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )34200L),34200L);
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=3 */
    memcpy_wide_bus_write_float_3d_105_2_64((merlin_uint_64 *)F,F_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )39900L),39900L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_11_0_buf cyclic factor = 8 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_11_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_12_0_buf cyclic factor = 4 dim=2 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_12_0_buf cyclic factor = 2 dim=3 */
}
