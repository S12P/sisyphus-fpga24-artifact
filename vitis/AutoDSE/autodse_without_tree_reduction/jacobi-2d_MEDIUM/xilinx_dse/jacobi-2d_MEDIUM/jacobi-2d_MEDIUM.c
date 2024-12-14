#pragma ACCEL kernel

void kernel_jacobi_2d(float A[250][250],float B[250][250])
{
  int t;
  int i;
  int j;
{
    
#pragma ACCEL PIPELINE auto{__PIPE__L0}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
    for (t = 0; t < 100; t++) {
      
#pragma ACCEL PIPELINE auto{__PIPE__L1}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L1}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
      for (i = 1; i < 250 - 1; i++) {
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L3}
        for (j = 1; j < 250 - 1; j++) {
          B[i][j] = ((float )(0.2 * ((double )(A[i][j] + A[i][j - 1] + A[i][1 + j] + A[1 + i][j] + A[i - 1][j]))));
        }
      }
      
#pragma ACCEL PIPELINE auto{__PIPE__L2}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L2}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (i = 1; i < 250 - 1; i++) {
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L4}
        for (j = 1; j < 250 - 1; j++) {
          A[i][j] = ((float )(0.2 * ((double )(B[i][j] + B[i][j - 1] + B[i][1 + j] + B[1 + i][j] + B[i - 1][j]))));
        }
      }
    }
  }
}
