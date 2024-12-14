#pragma ACCEL kernel

void kernel_gemm(float C[3072][100],float A[3072][3072],float B[3072][100])
{
  int i;
  int j;
  int k;
  
#pragma ACCEL PIPELINE off
  
#pragma ACCEL TILE FACTOR=3072
  
#pragma ACCEL PARALLEL FACTOR=1
  for (i = 0; i < 3072; i++) {
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=1
    for (j = 0; j < 100; j++) {
      C[i][j] = ((float )0);
      
#pragma ACCEL PARALLEL FACTOR=8
      for (k = 0; k < 3072; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}
