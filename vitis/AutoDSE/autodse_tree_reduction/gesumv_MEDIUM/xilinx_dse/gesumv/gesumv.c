#pragma ACCEL kernel

void kernel_gesummv(float alpha,float beta,float A[250][250],float B[250][250],float tmp[250],float x[250],float y[250])
{
  int i;
  int j;
{
    
#pragma ACCEL PIPELINE auto{__PIPE__L0}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
    for (i = 0; i < 250; i++) {
      tmp[i] = ((float )0.0);
      y[i] = ((float )0.0);
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
      for (j = 0; j < 250; j++) {
        tmp[i] = A[i][j] * x[j] + tmp[i];
        y[i] = B[i][j] * x[j] + y[i];
      }
      y[i] = alpha * tmp[i] + beta * y[i];
    }
// for ( i = 0; i < 250; i++) {
//     tmp[i] = 0.0;
// }
// for ( i = 0; i < 250; i++) {
//     for ( j = 0; j < 250; j++) {
//         tmp[i] = A[i][j] * x[j] + tmp[i];
//     }
// }
// for ( i = 0; i < 250; i++) {
//     y[i] = 0.0;
// }
// for ( i = 0; i < 250; i++) {
//     for ( j = 0; j < 250; j++) {
//         y[i] = B[i][j] * x[j] + y[i];
//     }
// }
// for ( i = 0; i < 250; i++) {
//     y[i] = alpha * tmp[i] + beta * y[i];
// }
  }
}