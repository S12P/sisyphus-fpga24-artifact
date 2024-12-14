#pragma ACCEL kernel

void kernel_gemm(float alpha,float beta,float C[200][220],float A[200][240],float B[240][220])
{
  int i;
  int j;
  int k;
//BLAS PARAMS
//TRANSA = 'N'
//TRANSB = 'N'
// => Form C := alpha*A*B + beta*C,
//A is NIxNK
//B is NKxNJ
//C is NIxNJ
{
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=8
    
#pragma ACCEL PARALLEL FACTOR=1
    for (i = 0; i < 200; i++) {
      
#pragma ACCEL PARALLEL FACTOR=4
      for (j = 0; j < 220; j++) {
        C[i][j] *= beta;
      }
      
#pragma ACCEL PIPELINE flatten
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=1
      for (k = 0; k < 240; k++) {
        
#pragma ACCEL PARALLEL FACTOR=1
        for (j = 0; j < 220; j++) {
          C[i][j] += alpha * A[i][k] * B[k][j];
        }
      }
    }
  }
}
