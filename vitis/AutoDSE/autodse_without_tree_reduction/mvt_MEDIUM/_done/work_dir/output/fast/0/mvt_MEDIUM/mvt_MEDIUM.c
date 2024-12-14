#pragma ACCEL kernel

void kernel_mvt(float x1[400],float x2[400],float y_1[400],float y_2[400],float A[400][400])
{
  int i;
  int j;
{
    
#pragma ACCEL PIPELINE flatten
    
#pragma ACCEL TILE FACTOR=400
    
#pragma ACCEL PARALLEL FACTOR=1
    for (i = 0; i < 400; i++) {
      
#pragma ACCEL PARALLEL FACTOR=1
      for (j = 0; j < 400; j++) {
        x1[i] = x1[i] + A[i][j] * y_1[j];
      }
    }
    
#pragma ACCEL PIPELINE flatten
    
#pragma ACCEL TILE FACTOR=200
    
#pragma ACCEL PARALLEL FACTOR=2
    for (i = 0; i < 400; i++) {
      
#pragma ACCEL PARALLEL FACTOR=1
      for (j = 0; j < 400; j++) {
        x2[i] = x2[i] + A[j][i] * y_2[j];
      }
    }
  }
}
