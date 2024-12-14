
float compute1(float c, float alpha, float b, float a, int i, int k){
  if (k<i) {
     return c + alpha * a * b;
  } 
  else {
    return c;
  }
}

float compute2(float temp2, float b, float a, int i, int k){
  if (k<i) {
     return temp2 + a * b;
  } 
  else {
    return temp2;
  }
}

#pragma ACCEL kernel

void kernel_symm(int m,int n,float alpha,float beta,float C[200][240],float A[200][200],float B[200][240])
{
  int i;
  int j;
  int k;
  float temp2;
//BLAS PARAMS
//SIDE = 'L'
//UPLO = 'L'
// =>  Form  C := alpha*A*B + beta*C
// A is MxM
// B is MxN
// C is MxN
//note that due to Fortran array layout, the code below more closely resembles upper triangular case in BLAS
{
    
    
    
    for (i = 0; i < 200; i++) {
      
      
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=4
      for (j = 0; j < 240; j++) {
        temp2 = ((float )0);
#pragma ACCEL PARALLEL FACTOR=199
        for (k = 0; k < 199; k++) {
          // C[k][j] += alpha * B[i][j] * A[i][k];
          C[k][j] = compute1(C[k][j], alpha, B[i][j], A[i][k], i, k);
          // temp2 += B[k][j] * A[i][k];
          temp2 = compute2(temp2, B[k][j], A[i][k], i, k);
        }
        C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2;
      }
    }
  }
}
