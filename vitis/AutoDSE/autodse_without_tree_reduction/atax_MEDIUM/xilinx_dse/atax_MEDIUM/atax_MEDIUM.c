
#pragma ACCEL kernel

void kernel_atax(int m,int n,float A[390][410],float x[410],float y[410],float tmp[390])
{
  int i;
  int j;
{
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
    for (i = 0; i < 410; i++) {
      y[i] = ((float )0);
    }
    
#pragma ACCEL PIPELINE auto{__PIPE__L1}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L1}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
    for (i = 0; i < 390; i++) {
      tmp[i] = 0.0;
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (j = 0; j < 410; j++) {
        tmp[i] = tmp[i] + A[i][j] * x[j];
      }
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L3}
      for (j = 0; j < 410; j++) {
        y[j] = y[j] + A[i][j] * tmp[i];
      }
    }
  }
}
