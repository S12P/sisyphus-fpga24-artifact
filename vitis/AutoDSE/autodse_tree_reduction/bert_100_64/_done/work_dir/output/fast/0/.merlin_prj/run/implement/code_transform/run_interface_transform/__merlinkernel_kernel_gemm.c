#include "merlin_type_define.h"
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_kernel_pragma();
/* Original: #pragma ACCEL kernel */

void kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
  int i;
  int j;
  int k;
  for (i = 0; i < 100; i++) 
/* Original: #pragma ACCEL PIPELINE off */
/* Original: #pragma ACCEL TILE FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
{
    
#pragma ACCEL PIPELINE OFF
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=1
    for (j = 0; j < 64; j++) 
/* Original: #pragma ACCEL PIPELINE flatten */
/* Original: #pragma ACCEL TILE FACTOR=1 */
/* Original: #pragma ACCEL PARALLEL FACTOR=8 */
{
      
#pragma ACCEL PIPELINE
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=8
      C[i][j] = ((float )0);
      for (k = 0; k < 100; k++) 
/* Original: #pragma ACCEL PARALLEL FACTOR=1 */
{
        
#pragma ACCEL PARALLEL COMPLETE
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
