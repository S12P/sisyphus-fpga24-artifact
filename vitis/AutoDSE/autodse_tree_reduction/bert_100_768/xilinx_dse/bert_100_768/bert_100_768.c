#pragma ACCEL kernel

void kernel_gemm(float C[100][768],float A[100][100],float B[100][768])
{
  int i;
  int j;
  int k;
  
#pragma ACCEL PIPELINE auto{__PIPE__L0}
  
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
  
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
  for (i = 0; i < 100; i++) {
    
#pragma ACCEL PIPELINE auto{__PIPE__L1}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L1}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
    for (j = 0; j < 768; j++) {
      C[i][j] = ((float )0);
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (k = 0; k < 100; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
