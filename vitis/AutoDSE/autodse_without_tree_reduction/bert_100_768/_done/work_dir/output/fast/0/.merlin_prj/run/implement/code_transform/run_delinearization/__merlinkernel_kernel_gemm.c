#include <string.h> 
#include "cmost.h"
#include "merlin_type_define.h"
extern int __merlin_include__GB_string_h_0;
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_kernel_pragma();
/* Original: #pragma ACCEL kernel */

void kernel_gemm(float C[76800],float A[10000],float B[76800])
{
  
#pragma ACCEL interface variable=B depth=100,768 max_depth=100,768
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,768 max_depth=100,768
  float B_5_0_buf[76800];
  float A_5_0_buf[10000];
  float C_buf[76800];
  __merlin_access_range(B,0,76799);
  __merlin_access_range(A,0,9999);
  __merlin_access_range(C,0,76799);
  int i;
  int j;
  int k;
  memcpy((void *)(&C_buf[0]),(const void *)(&C[0]),sizeof(float ) * 76800L);
{
    memcpy((void *)(&A_5_0_buf[0]),(const void *)(&A[0]),sizeof(float ) * 10000L);
  }
{
    memcpy((void *)(&B_5_0_buf[0]),(const void *)(&B[0]),sizeof(float ) * 76800L);
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
        C_buf[i * 768L + j * 8 + j_sub] = ((float )0);
        for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
          
#pragma ACCEL PARALLEL COMPLETE
          C_buf[i * 768L + j * 8 + j_sub] += A_5_0_buf[i * 100L + k] * B_5_0_buf[j * 8 + k * 768L + j_sub];
        }
      }
    }
  }
  memcpy((void *)(&C[0]),(const void *)(&C_buf[0]),sizeof(float ) * 76800L);
}