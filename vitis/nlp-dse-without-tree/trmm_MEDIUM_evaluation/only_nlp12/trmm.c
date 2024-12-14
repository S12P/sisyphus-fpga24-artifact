#pragma ACCEL kernel

void kernel_trmm(int m,int n,float alpha,float A[200][200],float B[200][240])
{
  int i;
  int j;
  int k;
//BLAS parameters
//SIDE   = 'L'
//UPLO   = 'L'
//TRANSA = 'T'
//DIAG   = 'U'
// => Form  B := alpha*A**T*B.
// A is MxM
// B is MxN
{
    
    
    
#pragma ACCEL PARALLEL FACTOR=4
    for (i = 0; i < 200; i++) {
      
      
      
#pragma ACCEL PARALLEL FACTOR=8
      for (j = 0; j < 240; j++) {
        for (k = i + 1; k < 200; k++) {
          B[i][j] += A[k][i] * B[k][j];
        }
        B[i][j] = alpha * B[i][j];
      }
    }
  }
}
