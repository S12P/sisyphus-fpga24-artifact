#define __constant
#define __kernel
#define __global
#include "memcpy_64_1d.h"
#include "memcpy_128_1d.h"
#define SIZE_1 190
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 2
#define SIZE_2 100
#include "memcpy_128_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 100
#define SIZE_2 190
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 210
#include "memcpy_64_2d.h"
#undef SIZE_1
#define SIZE_1 2
#define SIZE_2 110
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 110
#define SIZE_2 210
#include "memcpy_64_3d.h"
#undef SIZE_1
#undef SIZE_2
#include <string.h> 

#include "merlin_type_define.h"











/* Original: #pragma ACCEL kernel */

void kernel_3mm(merlin_uint_64 E[17100],merlin_uint_128 A[9000],merlin_uint_64 B[19000],merlin_uint_64 F[19950],merlin_uint_64 C[20900],merlin_uint_64 D[23100],merlin_uint_64 G[18900])
{
  
#pragma HLS INTERFACE m_axi port=A offset=slave depth=9000 bundle=merlin_gmem_kernel_3mm_128_0
  
#pragma HLS INTERFACE m_axi port=B offset=slave depth=19000 bundle=merlin_gmem_kernel_3mm_64_0
  
#pragma HLS INTERFACE m_axi port=C offset=slave depth=20900 bundle=merlin_gmem_kernel_3mm_64_1
  
#pragma HLS INTERFACE m_axi port=D offset=slave depth=23100 bundle=merlin_gmem_kernel_3mm_64_2
  
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
    float B_11_0_buf[2][100][190];
    
#pragma HLS array_partition variable=B_11_0_buf cyclic factor=2 dim=3
    
#pragma HLS array_partition variable=B_11_0_buf complete dim=2
    float A_11_0_buf[180][2][100];
    
#pragma HLS array_partition variable=A_11_0_buf complete dim=3
    float D_12_0_buf[2][110][210];
    
#pragma HLS array_partition variable=D_12_0_buf cyclic factor=2 dim=3
    
#pragma HLS array_partition variable=D_12_0_buf complete dim=2
    float C_12_0_buf[190][2][110];
    
#pragma HLS array_partition variable=C_12_0_buf complete dim=3
    float G_buf[180][210];
    
#pragma HLS array_partition variable=G_buf cyclic factor=2 dim=2
    float F_buf[190][210];
    
#pragma HLS array_partition variable=F_buf cyclic factor=2 dim=2
    
#pragma HLS array_partition variable=F_buf complete dim=1
    float E_buf[180][190];
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
    
#pragma HLS array_partition variable=E_buf complete dim=2
    memcpy_wide_bus_read_float_2d_190_64(E_buf,0,0,(merlin_uint_64 *)E,(0 * 4),sizeof(float ) * ((unsigned long )34200L),34200L);
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_read_float_2d_210_64(F_buf,0,0,(merlin_uint_64 *)F,(0 * 4),sizeof(float ) * ((unsigned long )39900L),39900L);
{
      memcpy_wide_bus_read_float_3d_2_100_128(A_11_0_buf,0,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )36000L),36000L);
    }
{
      memcpy_wide_bus_read_float_3d_100_190_64(B_11_0_buf,0,0,0,(merlin_uint_64 *)B,(0 * 4),sizeof(float ) * ((unsigned long )38000L),38000L);
    }
    merlinL11:
    for (i = 0; i < 180; i++) {
      merlinL10:
      for (j = 0; j < 190; j++) {
        E_buf[i][j] = ((float )0.0);
        merlinL9:
        for (k = 0; k < 2; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS pipeline
          merlinL8:
          for (int k_sub_1 = 0; k_sub_1 < 100; ++k_sub_1) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=100 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            E_buf[i][j] += A_11_0_buf[i][k][k_sub_1] * B_11_0_buf[k][k_sub_1][j];
          }
        }
      }
    }
{
      memcpy_wide_bus_read_float_3d_2_110_64(C_12_0_buf,0,0,0,(merlin_uint_64 *)C,(0 * 4),sizeof(float ) * ((unsigned long )41800L),41800L);
    }
{
      memcpy_wide_bus_read_float_3d_110_210_64(D_12_0_buf,0,0,0,(merlin_uint_64 *)D,(0 * 4),sizeof(float ) * ((unsigned long )46200L),46200L);
    }
    merlinL7:
    for (i = 0; i < 190; i++) {
      merlinL6:
      for (j = 0; j < 210; j++) {
        F_buf[i][j] = ((float )0.0);
        merlinL5:
        for (k = 0; k < 2; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=110 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=110 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS pipeline
          merlinL4:
          for (int k_sub_0 = 0; k_sub_0 < 110; ++k_sub_0) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=110 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=110 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            F_buf[i][j] += C_12_0_buf[i][k][k_sub_0] * D_12_0_buf[k][k_sub_0][j];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_read_float_2d_210_64(G_buf,0,0,(merlin_uint_64 *)G,(0 * 4),sizeof(float ) * ((unsigned long )37800L),37800L);
    merlinL3:
    for (i = 0; i < 180; i++) {
      merlinL2:
      for (j = 0; j < 210; j++) {
        G_buf[i][j] = ((float )0.0);
        merlinL1:
        for (k = 0; k < 2; ++k) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=95 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=95 */
/* Original: #pragma ACCEL PIPELINE */
{
          
#pragma HLS pipeline
          merlinL0:
          for (int k_sub = 0; k_sub < 95; ++k_sub) 
/* Original: #pragma ACCEL PIPELINE FLATTEN */
/* Original: #pragma ACCEL PARALLEL FACTOR=95 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL PARALLEL FACTOR=95 */
/* Original: #pragma ACCEL PARALLEL */
{
            
#pragma HLS unroll
            G_buf[i][j] += E_buf[i][((long )k) * 95L + ((long )k_sub)] * F_buf[((long )k) * 95L + ((long )k_sub)][j];
          }
        }
      }
    }
/* Existing HLS partition: #pragma HLS array_partition variable=G_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_210_64((merlin_uint_64 *)G,G_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )37800L),37800L);
/* Existing HLS partition: #pragma HLS array_partition variable=E_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_190_64((merlin_uint_64 *)E,E_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )34200L),34200L);
/* Existing HLS partition: #pragma HLS array_partition variable=F_buf cyclic factor = 2 dim=2 */
    memcpy_wide_bus_write_float_2d_210_64((merlin_uint_64 *)F,F_buf,0,0,(4 * 0),sizeof(float ) * ((unsigned long )39900L),39900L);
  }
/* Existing HLS partition: #pragma HLS array_partition variable=A_11_0_buf cyclic factor = 4 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=B_11_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=C_12_0_buf cyclic factor = 2 dim=3 */
/* Existing HLS partition: #pragma HLS array_partition variable=D_12_0_buf cyclic factor = 2 dim=3 */
}
