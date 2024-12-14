#pragma ACCEL kernel

void kernel_2mm(float alpha,float beta,float tmp[180][190],float A[180][210],float B[210][190],float C[190][220],float D[180][220])
{
  int i;
  int j;
  int k;
{
    
#pragma ACCEL PIPELINE auto{__PIPE__L0}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
    for (i = 0; i < 180; i++) {
      
#pragma ACCEL PIPELINE auto{__PIPE__L2}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L2}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (j = 0; j < 190; j++) {
        tmp[i][j] = ((float )0.0);
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L4}
        for (k = 0; k < 210; ++k) {
          tmp[i][j] += alpha * A[i][k] * B[k][j];
        }
      }
    }
    
#pragma ACCEL PIPELINE auto{__PIPE__L1}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L1}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
    for (i = 0; i < 180; i++) {
      
#pragma ACCEL PIPELINE auto{__PIPE__L3}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L3}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L3}
      for (j = 0; j < 220; j++) {
        D[i][j] *= beta;
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L5}
        for (k = 0; k < 190; ++k) {
          D[i][j] += tmp[i][k] * C[k][j];
        }
      }
    }
  }
}
