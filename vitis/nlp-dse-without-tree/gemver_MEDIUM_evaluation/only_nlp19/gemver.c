#pragma ACCEL kernel

void kernel_gemver(int n,float alpha,float beta,float A[400][400],float u1[400],float v1[400],float u2[400],float v2[400],float w[400],float x[400],float y[400],float z[400])
{
  int i;
  int j;
{
    
    
    
#pragma ACCEL PARALLEL FACTOR=8
    for (i = 0; i < 400; i++) {
      
#pragma ACCEL PIPELINE FLATTEN
      for (j = 0; j < 400; j++) {
        A[i][j] = A[i][j] + u1[i] * v1[j] + u2[i] * v2[j];
      }
    }
    
    
    
    for (i = 0; i < 400; i++) {
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=8
      for (j = 0; j < 400; j++) {
        x[i] = x[i] + beta * A[j][i] * y[j];
      }
    }
    
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=8
    for (i = 0; i < 400; i++) {
      x[i] = x[i] + z[i];
    }
    
    
    
#pragma ACCEL PARALLEL FACTOR=8
    for (i = 0; i < 400; i++) {
      
#pragma ACCEL PIPELINE FLATTEN
      for (j = 0; j < 400; j++) {
        w[i] = w[i] + alpha * A[i][j] * x[j];
      }
    }
  }
}