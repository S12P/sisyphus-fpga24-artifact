#pragma ACCEL kernel

void kernel_bicg(int m,int n,float A[410][390],float s[390],float q[410],float p[390],float r[410])
{
  int i;
  int j;
{
    
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=15
    for (i = 0; i < 390; i++) {
      s[i] = ((float )0);
    }
    
    
    
    for (i = 0; i < 410; i++) {
      q[i] = 0.0;
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=15
      for (j = 0; j < 390; j++) {
        s[j] = s[j] + r[i] * A[i][j];
        q[i] = q[i] + A[i][j] * p[j];
      }
    }
  }
}
