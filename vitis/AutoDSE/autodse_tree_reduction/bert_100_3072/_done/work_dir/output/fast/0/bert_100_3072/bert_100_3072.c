#pragma ACCEL kernel

void kernel_gemm(float C[100][3072],float A[100][100],float B[100][3072])
{
  int i;
  int j;
  int k;
  
#pragma ACCEL PIPELINE 
  
#pragma ACCEL TILE FACTOR=1
  
#pragma ACCEL PARALLEL FACTOR=4
  for (i = 0; i < 100; i++) {
    
#pragma ACCEL PIPELINE flatten
    
#pragma ACCEL TILE FACTOR=384
    
#pragma ACCEL PARALLEL FACTOR=8
    for (j = 0; j < 3072; j++) {
      C[i][j] = ((float )0);
      
#pragma ACCEL PARALLEL FACTOR=1
      for (k = 0; k < 100; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}