
float compute1(float c, float beta, int i, int j){
  if (j<=i) {
    return c * beta;
  } 
  else {
    return c;
  }
}

float compute2(float c, float a, float alpha, float b, float b2, float a2, int i, int j){
  if (j<=i) {
    return c + a * alpha * b + b2 * alpha * a2;
  } 
  else {
    return c;
  }
}


#pragma ACCEL kernel

void kernel_syr2k(int n,int m,float alpha,float beta,float C[240][240],float A[240][200],float B[240][200])
{
  int i;
  int j;
  int k;
//BLAS PARAMS
//UPLO  = 'L'
//TRANS = 'N'
//A is NxM
//B is NxM
//C is NxN
{
    
    
    
#pragma ACCEL PARALLEL FACTOR=120
    for (i = 0; i < 240; i++) {
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=16
      for (j = 0; j < 240; j++) {
        C[i][j] = compute1(C[i][j], beta, i, j);
      }
      
      
      
      for (k = 0; k < 200; k++) {
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=3
        for (j = 0; j < 240; j++) {
          C[i][j] = compute2(C[i][j], A[j][k], alpha, B[i][k], B[j][k], A[i][k], i, j);
        }
      }
    }
  }
}
