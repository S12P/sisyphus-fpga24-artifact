#include "cmost.h"
#include "merlin_type_define.h"
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_kernel_pragma();
/* Original: #pragma ACCEL kernel */

void kernel_gemm(float C[76800],float A[10000],float B[76800])
{
  
#pragma ACCEL interface variable=B depth=100,768 max_depth=100,768
  
#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100
  
#pragma ACCEL interface variable=C depth=100,768 max_depth=100,768
  __merlin_access_range(B,0,76799);
  __merlin_access_range(A,0,9999);
  __merlin_access_range(C,0,76799);
  int i;
  int j;
  int k;
  for (i = 0; i < 100; i++) 
/* Original: #pragma ACCEL PIPELINE off */
/* Original: #pragma ACCEL TILE FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
/* Original: #pragma ACCEL PIPELINE OFF */
/* Original: #pragma ACCEL TILE FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
{
    
#pragma ACCEL PIPELINE OFF 
    
#pragma ACCEL TILE FACTOR=1 
    
#pragma ACCEL PARALLEL FACTOR=1 
    for (j = 0; j < 768; j++) 
/* Original: #pragma ACCEL PIPELINE flatten */
/* Original: #pragma ACCEL TILE FACTOR=96 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
/* Original: #pragma ACCEL PIPELINE */
/* Original: #pragma ACCEL TILE FACTOR=96 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
{
      
#pragma ACCEL PIPELINE 
      
#pragma ACCEL TILE FACTOR=96 
      
#pragma ACCEL PARALLEL FACTOR=8 
      C[i * 768L + j] = ((float )0);
      for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL COMPLETE */
{
        
#pragma ACCEL PARALLEL COMPLETE 
        C[i * 768L + j] += A[i * 100L + k] * B[k * 768L + j];
      }
    }
  }
}
