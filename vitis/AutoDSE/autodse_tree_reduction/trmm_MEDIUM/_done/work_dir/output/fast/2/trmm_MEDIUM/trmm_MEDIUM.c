
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
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=1
    for (i = 0; i < 200; i++) {
      
#pragma ACCEL PIPELINE off
      
#pragma ACCEL TILE FACTOR=240
      
#pragma ACCEL PARALLEL FACTOR=1
      for (j = 0; j < 240; j++) {
        
#pragma ACCEL PARALLEL FACTOR=50
        for (k = 0; k < 200; k++) {
// B[i][j] += A[k][i] * B[k][j];
          B[i][j] = compute1_1(B[i][j],A[k][i],B[k][j],i,k);
        }
        B[i][j] = alpha * B[i][j];
      }
    }
  }
}
