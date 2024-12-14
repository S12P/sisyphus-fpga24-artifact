#pragma ACCEL kernel

void kernel_jacobi_2d(float A[250][250],float B[250][250])
{
  int t;
  int i;
  int j;
{
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=1
    for (t = 0; t < 100; t++) {
      
#pragma ACCEL PIPELINE off
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=1
      for (i = 1; i < 250 - 1; i++) {
        
#pragma ACCEL PARALLEL FACTOR=8
        for (j = 1; j < 250 - 1; j++) {
          B[i][j] = ((float )(0.2 * ((double )(A[i][j] + A[i][j - 1] + A[i][1 + j] + A[1 + i][j] + A[i - 1][j]))));
        }
      }
      
#pragma ACCEL PIPELINE off
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=1
      for (i = 1; i < 250 - 1; i++) {
        
#pragma ACCEL PARALLEL FACTOR=2
        for (j = 1; j < 250 - 1; j++) {
          A[i][j] = ((float )(0.2 * ((double )(B[i][j] + B[i][j - 1] + B[i][1 + j] + B[1 + i][j] + B[i - 1][j]))));
        }
      }
    }
  }
}
