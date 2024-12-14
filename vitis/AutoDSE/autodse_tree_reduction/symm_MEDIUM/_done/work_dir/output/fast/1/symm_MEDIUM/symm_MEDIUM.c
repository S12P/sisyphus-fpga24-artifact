
static float compute1_1(float c,float alpha,float b,float a,int i,int k)
{
  if (k < i) {
    return c + alpha * a * b;
  }
   else {
    return c;
  }
}

static float compute2_1(float temp2,float b,float a,int i,int k)
{
  if (k < i) {
    return temp2 + a * b;
  }
   else {
    return temp2;
  }
}
#pragma ACCEL kernel

void kernel_symm(float alpha,float beta,float temp2[200][240],float C[200][240],float A[200][200],float B[200][240])
{
  int i;
  int j;
  int k;
{
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=1
    for (i = 0; i < 200; i++) {
      
#pragma ACCEL PIPELINE flatten
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=1
      for (j = 0; j < 240; j++) {
        temp2[i][j] = ((float )0);
        
#pragma ACCEL PARALLEL FACTOR=1
        for (k = 0; k < 199; k++) {
// C[k][j] += alpha * B[i][j] * A[i][k];
          C[k][j] = compute1_1(C[k][j],alpha,B[i][j],A[i][k],i,k);
// temp2[i][j] += B[k][j] * A[i][k];
          temp2[i][j] = compute2_1(temp2[i][j],B[k][j],A[i][k],i,k);
        }
        C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2[i][j];
      }
    }
  }
}
