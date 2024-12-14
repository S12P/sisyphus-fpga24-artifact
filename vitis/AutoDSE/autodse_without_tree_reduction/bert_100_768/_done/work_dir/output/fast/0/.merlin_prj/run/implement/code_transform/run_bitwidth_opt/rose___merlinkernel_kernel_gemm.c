#include "memcpy_128_1d.h"
#include "memcpy_512_1d.h"
#define SIZE_1 96
#define SIZE_2 8
#include "memcpy_512_3d.h"
#undef SIZE_1
#undef SIZE_2
#define SIZE_1 100
#include "memcpy_128_2d.h"
#undef SIZE_1
#include <string.h> 
#include "cmost.h"
#include "merlin_type_define.h"
extern int __merlin_include__GB_memcpy_128_2d_h_3;
extern int __merlin_include__GB_memcpy_512_3d_h_2;
extern int __merlin_include__GB_memcpy_512_1d_h_1;
extern int __merlin_include__GB_memcpy_128_1d_h_0;
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_kernel_pragma();
/* Original: #pragma ACCEL kernel */

void kernel_gemm(merlin_uint_512 C[4800],merlin_uint_128 A[2500],merlin_uint_512 B[4800])
{
  
#pragma HLS DATA_PACK VARIABLE=B
  
#pragma HLS DATA_PACK VARIABLE=A
  
#pragma HLS DATA_PACK VARIABLE=C
  
#pragma ACCEL interface variable=B depth=100,768 max_depth=100,768
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,768 max_depth=100,768
  float B_5_0_buf[100][96][8];
  float A_5_0_buf[100][100];
  float C_buf[100][96][8];
  __merlin_access_range(B,0,76799);
  __merlin_access_range(A,0,9999);
  __merlin_access_range(C,0,76799);
  int i;
  int j;
  int k;
  
#pragma  HLS array_partition  variable=C_buf complete  dim=3
  
#pragma  HLS array_partition  variable=C_buf cyclic factor = 2 dim=2
  memcpy_wide_bus_read_float_3d_96_8_512(C_buf,0,0,0,(merlin_uint_512 *)C,0 * 4,sizeof(float ) * ((unsigned long )76800L),76800L);
{
    
#pragma  HLS array_partition  variable=A_5_0_buf cyclic factor = 4 dim=2
    memcpy_wide_bus_read_float_2d_100_128(A_5_0_buf,0,0,(merlin_uint_128 *)A,0 * 4,sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    
#pragma  HLS array_partition  variable=B_5_0_buf complete  dim=3
    
#pragma  HLS array_partition  variable=B_5_0_buf cyclic factor = 2 dim=2
    memcpy_wide_bus_read_float_3d_96_8_512(B_5_0_buf,0,0,0,(merlin_uint_512 *)B,0 * 4,sizeof(float ) * ((unsigned long )76800L),76800L);
  }
  for (i = 0; i < 100; i++) 
/* Original: #pragma ACCEL PIPELINE off */
/* Original: #pragma ACCEL TILE FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
/* Original: #pragma ACCEL PIPELINE OFF */
/* Original: #pragma ACCEL TILE FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
{
    
#pragma ACCEL TILE FACTOR=1
    for (j = 0; j < 96; j++) 
/* Original: #pragma ACCEL PIPELINE flatten */
/* Original: #pragma ACCEL TILE FACTOR=96 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL TILE FACTOR=96 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
{
      
#pragma ACCEL PIPELINE
      for (int j_sub = 0; j_sub < 8; ++j_sub) 
/* Original: #pragma ACCEL PIPELINE flatten */
/* Original: #pragma ACCEL TILE FACTOR=96 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL TILE FACTOR=96 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
{
        
#pragma ACCEL PARALLEL
        C_buf[i][j][j_sub] = ((float )0);
        for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma ACCEL PARALLEL COMPLETE
          C_buf[i][j][j_sub] += A_5_0_buf[i][k] * B_5_0_buf[k][j][j_sub];
        }
      }
    }
  }
  
#pragma  HLS array_partition  variable=C_buf complete  dim=3
  
#pragma  HLS array_partition  variable=C_buf cyclic factor = 2 dim=2
  memcpy_wide_bus_write_float_3d_96_8_512((merlin_uint_512 *)C,C_buf,0,0,0,4 * 0,sizeof(float ) * ((unsigned long )76800L),76800L);
}
