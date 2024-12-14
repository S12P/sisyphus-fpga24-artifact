#pragma ACCEL kernel

void kernel_gesummv(int n,float alpha,float beta,float A[250][250],float B[250][250],float tmp[250],float x[250],float y[250])
{
  int i;
  int j;
{
    
    
    
#pragma ACCEL PARALLEL FACTOR=5
    for (i = 0; i < 250; i++) {
      tmp[i] = 0.0;
      y[i] = 0.0;
      
#pragma ACCEL PIPELINE FLATTEN
      for (j = 0; j < 250; j++) {
        tmp[i] = A[i][j] * x[j] + tmp[i];
        y[i] = B[i][j] * x[j] + y[i];
      }
      y[i] = alpha * tmp[i] + beta * y[i];
    }
  }
}
