#pragma ACCEL kernel

void kernel_heat_3d(float A[40][40][40],float B[40][40][40])
{
  int t;
  int i;
  int j;
  int k;
{
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=1
    for (t = 1; t <= 100; t++) {
      
#pragma ACCEL PIPELINE off
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=1
      for (i = 1; i < 40 - 1; i++) {
        
#pragma ACCEL PIPELINE flatten
        
#pragma ACCEL TILE FACTOR=1
        
#pragma ACCEL PARALLEL FACTOR=2
        for (j = 1; j < 40 - 1; j++) {
          
#pragma ACCEL PARALLEL FACTOR=1
          for (k = 1; k < 40 - 1; k++) {
            B[i][j][k] = ((float )(0.125 * (((double )A[i + 1][j][k]) - 2.0 * ((double )A[i][j][k]) + ((double )A[i - 1][j][k])) + 0.125 * (((double )A[i][j + 1][k]) - 2.0 * ((double )A[i][j][k]) + ((double )A[i][j - 1][k])) + 0.125 * (((double )A[i][j][k + 1]) - 2.0 * ((double )A[i][j][k]) + ((double )A[i][j][k - 1])) + ((double )A[i][j][k])));
          }
        }
      }
      
#pragma ACCEL PIPELINE off
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=1
      for (i = 1; i < 40 - 1; i++) {
        
#pragma ACCEL PIPELINE off
        
#pragma ACCEL TILE FACTOR=1
        
#pragma ACCEL PARALLEL FACTOR=1
        for (j = 1; j < 40 - 1; j++) {
          
#pragma ACCEL PARALLEL FACTOR=1
          for (k = 1; k < 40 - 1; k++) {
            A[i][j][k] = ((float )(0.125 * (((double )B[i + 1][j][k]) - 2.0 * ((double )B[i][j][k]) + ((double )B[i - 1][j][k])) + 0.125 * (((double )B[i][j + 1][k]) - 2.0 * ((double )B[i][j][k]) + ((double )B[i][j - 1][k])) + 0.125 * (((double )B[i][j][k + 1]) - 2.0 * ((double )B[i][j][k]) + ((double )B[i][j][k - 1])) + ((double )B[i][j][k])));
          }
        }
      }
    }
  }
}
