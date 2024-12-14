
float compute_dd1(float c, float alpha, float b, float a, int i, int k){
  if (k<i){
    return c+alpha * b * a;
  }
  else{
    return c;
  }
}

float compute_dd2(float temp2, float b, float a, int i, int k){
  if (k<i){
    return temp2 + b * a;
  }
  else{
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

{

    for (i = 0; i < 200; i++) {
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=4
      for (j = 0; j < 240; j++) {
        temp2 = ((float )0);
#pragma ACCEL PARALLEL FACTOR=199
        // for (k = 0; k < i; k++) {
          for (k = 0; k < 199; k++) {
          // C[k][j] += alpha * B[i][j] * A[i][k];
          C[k][j] = compute_dd1(C[k][j], alpha, B[i][j], A[i][k], i, k);
          // temp2 += B[k][j] * A[i][k];
          temp2 = compute_dd2(temp2, B[k][j], A[i][k]);
        }
        C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2;
      }
    }
  }
}
