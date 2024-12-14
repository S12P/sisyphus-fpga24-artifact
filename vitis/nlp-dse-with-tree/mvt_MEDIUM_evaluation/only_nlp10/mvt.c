#pragma ACCEL kernel

void kernel_mvt(int n,float x1[400],float x2[400],float y_1[400],float y_2[400],float A[400][400])
{
  int i;
  int j;
{
    
    
    
#pragma ACCEL PARALLEL FACTOR=4
    for (i = 0; i < 400; i++) {
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=16
      for (j = 0; j < 400; j++) {
        x1[i] = x1[i] + A[i][j] * y_1[j];
      }
    }
    
    
    
#pragma ACCEL PARALLEL FACTOR=16
    for (i = 0; i < 400; i++) {
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=4
      for (j = 0; j < 400; j++) {
        x2[i] = x2[i] + A[j][i] * y_2[j];
      }
    }
  }
}
