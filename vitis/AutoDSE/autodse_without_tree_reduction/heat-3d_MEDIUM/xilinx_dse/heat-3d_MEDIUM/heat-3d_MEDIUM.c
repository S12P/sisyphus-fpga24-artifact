#pragma ACCEL kernel

void kernel_heat_3d(float A[40][40][40],float B[40][40][40])
{
  int t;
  int i;
  int j;
  int k;
{
    
#pragma ACCEL PIPELINE auto{__PIPE__L0}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
    for (t = 1; t <= 100; t++) {
      
#pragma ACCEL PIPELINE auto{__PIPE__L1}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L1}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
      for (i = 1; i < 40 - 1; i++) {
        
#pragma ACCEL PIPELINE auto{__PIPE__L3}
        
#pragma ACCEL TILE FACTOR=auto{__TILE__L3}
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L3}
        for (j = 1; j < 40 - 1; j++) {
          
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L5}
          for (k = 1; k < 40 - 1; k++) {
            B[i][j][k] = ((float )(0.125 * (((double )A[i + 1][j][k]) - 2.0 * ((double )A[i][j][k]) + ((double )A[i - 1][j][k])) + 0.125 * (((double )A[i][j + 1][k]) - 2.0 * ((double )A[i][j][k]) + ((double )A[i][j - 1][k])) + 0.125 * (((double )A[i][j][k + 1]) - 2.0 * ((double )A[i][j][k]) + ((double )A[i][j][k - 1])) + ((double )A[i][j][k])));
          }
        }
      }
      
#pragma ACCEL PIPELINE auto{__PIPE__L2}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L2}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (i = 1; i < 40 - 1; i++) {
        
#pragma ACCEL PIPELINE auto{__PIPE__L4}
        
#pragma ACCEL TILE FACTOR=auto{__TILE__L4}
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L4}
        for (j = 1; j < 40 - 1; j++) {
          
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L6}
          for (k = 1; k < 40 - 1; k++) {
            A[i][j][k] = ((float )(0.125 * (((double )B[i + 1][j][k]) - 2.0 * ((double )B[i][j][k]) + ((double )B[i - 1][j][k])) + 0.125 * (((double )B[i][j + 1][k]) - 2.0 * ((double )B[i][j][k]) + ((double )B[i][j - 1][k])) + 0.125 * (((double )B[i][j][k + 1]) - 2.0 * ((double )B[i][j][k]) + ((double )B[i][j][k - 1])) + ((double )B[i][j][k])));
          }
        }
      }
    }
  }
}
