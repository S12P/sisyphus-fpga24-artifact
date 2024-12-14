#pragma ACCEL kernel

void kernel_gemm(int ni,int nj,int nk,float alpha,float beta,float C[200][220],float A[200][240],float B[240][220])
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
    
    
    
    for (i = 0; i < 200; i++) {
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=110
      for (j = 0; j < 220; j++) {
        C[i][j] *= beta;
      }
      
      
      
      for (k = 0; k < 240; k++) {
        
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=110
        for (j = 0; j < 220; j++) {
          C[i][j] += alpha * A[i][k] * B[k][j];
        }
      }
    }
  }
}
