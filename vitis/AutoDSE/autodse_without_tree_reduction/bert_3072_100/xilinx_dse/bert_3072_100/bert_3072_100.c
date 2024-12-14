#pragma ACCEL kernel

void kernel_gemm(float C[3072][100],float A[3072][3072],float B[3072][100])
{
  int i;
  int j;
  int k;
  
#pragma ACCEL PIPELINE auto{__PIPE__L0}
  
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
  
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
  for (i = 0; i < 3072; i++) {
    
#pragma ACCEL PIPELINE auto{__PIPE__L1}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L1}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
    for (j = 0; j < 100; j++) {
      C[i][j] = ((float )0);
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (k = 0; k < 3072; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
