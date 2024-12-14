#include "merlin_type_define.h"
extern int __merlin_include__GB_merlin_type_define_h_0;
#pragma ACCEL kernel

void kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
  int i;
  int j;
  int k;
  
#pragma ACCEL PIPELINE off
  
#pragma ACCEL TILE FACTOR=1
  
#pragma ACCEL PARALLEL FACTOR=1
  for (i = 0; i < 100; i++) {
    
#pragma ACCEL PIPELINE flatten
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=8
    for (j = 0; j < 64; j++) {
      C[i][j] = ((float )0);
      
#pragma ACCEL PARALLEL FACTOR=1
      for (k = 0; k < 100; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
