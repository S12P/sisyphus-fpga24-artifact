#pragma ACCEL kernel

void kernel_3mm(float E[180][190],float A[180][200],float B[200][190],float F[190][210],float C[190][220],float D[220][210],float G[180][210])
{
  int i;
  int j;
  int k;
{
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=1
    for (i = 0; i < 180; i++) {
      
#pragma ACCEL PIPELINE 
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=2
      for (j = 0; j < 190; j++) {
        E[i][j] = ((float )0.0);
        
#pragma ACCEL PARALLEL FACTOR=8
        for (k = 0; k < 200; ++k) {
          E[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=2
    for (i = 0; i < 190; i++) {
      
#pragma ACCEL PIPELINE flatten
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=2
      for (j = 0; j < 210; j++) {
        F[i][j] = ((float )0.0);
        
#pragma ACCEL PARALLEL FACTOR=1
        for (k = 0; k < 220; ++k) {
          F[i][j] += C[i][k] * D[k][j];
        }
      }
    }
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=2
    for (i = 0; i < 180; i++) {
      
#pragma ACCEL PIPELINE flatten
      
#pragma ACCEL TILE FACTOR=1
      
#pragma ACCEL PARALLEL FACTOR=2
      for (j = 0; j < 210; j++) {
        G[i][j] = ((float )0.0);
        
#pragma ACCEL PARALLEL FACTOR=1
        for (k = 0; k < 190; ++k) {
          G[i][j] += E[i][k] * F[k][j];
        }
      }
    }
  }
}
