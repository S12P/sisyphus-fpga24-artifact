
static float compute1_1(float c,float beta,int i,int j)
{
  if (j <= i) {
    return c * beta;
  }
   else {
    return c;
  }
}

static float compute2_1(float c,float alpha,float a1,float a2,int i,int j)
{
  if (j <= i) {
    return c + alpha * a1 * a2;
  }
   else {
    return c;
  }
}
#pragma ACCEL kernel

void kernel_syrk(float alpha,float beta,float C[240][240],float A[240][200])
{
  int i;
  int j;
  int k;
{
    
#pragma ACCEL PIPELINE auto{__PIPE__L0}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
    for (i = 0; i < 240; i++) {
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
      for (j = 0; j < 240; j++) {
// C[i][j] *= beta;
        C[i][j] = compute1_1(C[i][j],beta,i,j);
      }
// for (j = 0; j <= i; j++) {
      
#pragma ACCEL PIPELINE auto{__PIPE__L2}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L2}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (k = 0; k < 200; k++) {
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L3}
        for (j = 0; j < 240; j++) {
// C[i][j] += alpha * A[i][k] * A[j][k];
          C[i][j] = compute2_1(C[i][j],alpha,A[i][k],A[j][k],i,j);
        }
      }
    }
  }
}