
float compute1(float c, float beta, int i, int j){
  if (j<=i) {
    return c * beta;
  } 
  else {
    return c;
  }

}

float compute2(float c, float alpha, float a1, float a2, int i, int j){
  if (j<=i) {
    return c + alpha * a1 * a2;
  } 
  else {
    return c;
  }

}

#pragma ACCEL kernel

void kernel_syrk(int n,int m,float alpha,float beta,float C[240][240],float A[240][200])
{
  int i;
  int j;
  int k;
//BLAS PARAMS
//TRANS = 'N'
//UPLO  = 'L'
// =>  Form  C := alpha*A*A**T + beta*C.
//A is NxM
//C is NxN
{
    
    
    
    for (i = 0; i < 240; i++) {
#pragma ACCEL PARALLEL FACTOR=240
      for (j = 0; j < 240; j++) {
        C[i][j] *= beta;
      }
      
      
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=2
      for (k = 0; k < 200; k++) {
#pragma ACCEL PARALLEL FACTOR=240
        for (j = 0; j < 240; j++) {
          C[i][j] += alpha * A[i][k] * A[j][k];
        }
      }
    }
  }
}
