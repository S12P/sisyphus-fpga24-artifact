
static float compute1_1(float b,float a,float b2,int i,int k)
{
  if (k >= i + 1) {
    return b + a * b2;
  }
   else {
    return b;
  }
}
#pragma ACCEL kernel

void kernel_trmm(float alpha,float A[200][200],float B[200][240])
{
  int i;
  int j;
  int k;
{
    
#pragma ACCEL PIPELINE auto{__PIPE__L0}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
    for (i = 0; i < 200; i++) {
      
#pragma ACCEL PIPELINE auto{__PIPE__L1}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L1}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
      for (j = 0; j < 240; j++) {
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
        for (k = 0; k < 200; k++) {
// B[i][j] += A[k][i] * B[k][j];
          B[i][j] = compute1_1(B[i][j],A[k][i],B[k][j],i,k);
        }
        B[i][j] = alpha * B[i][j];
      }
    }
  }
}
