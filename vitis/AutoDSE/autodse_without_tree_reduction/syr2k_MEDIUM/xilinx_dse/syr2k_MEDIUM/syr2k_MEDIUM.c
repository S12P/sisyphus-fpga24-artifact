
static float compute1_1(float c,float beta,int i,int j)
{
  if (j <= i) {
    return c * beta;
  }
   else {
    return c;
  }
}

static float compute2_1(float c,float a,float alpha,float b,float b2,float a2,int i,int j)
{
  if (j <= i) {
    return c + a * alpha * b + b2 * alpha * a2;
  }
   else {
    return c;
  }
}
#pragma ACCEL kernel

void kernel_syr2k(float alpha,float beta,float C[240][240],float A[240][200],float B[240][200])
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
      
#pragma ACCEL PIPELINE auto{__PIPE__L2}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L2}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (k = 0; k < 200; k++) {
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L3}
        for (j = 0; j < 240; j++) {
// C[i][j] += A[j][k] * alpha * B[i][k] + B[j][k] * alpha * A[i][k];
          C[i][j] = compute2_1(C[i][j],A[j][k],alpha,B[i][k],B[j][k],A[i][k],i,j);
        }
      }
    }
  }
}
