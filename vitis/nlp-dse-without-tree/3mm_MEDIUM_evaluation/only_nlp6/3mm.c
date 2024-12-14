#pragma ACCEL kernel

void kernel_3mm(int ni,int nj,int nk,int nl,int nm,float E[180][190],float A[180][200],float B[200][190],float F[190][210],float C[190][220],float D[220][210],float G[180][210])
{
  int i;
  int j;
  int k;
{
    
    
    
    for (i = 0; i < 180; i++) {
      
      
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=2
      for (j = 0; j < 190; j++) {
        E[i][j] = 0.0;
        
#pragma ACCEL PARALLEL FACTOR=200
        for (k = 0; k < 200; ++k) {
          E[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    
    
    
    for (i = 0; i < 190; i++) {
      
      
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=2
      for (j = 0; j < 210; j++) {
        F[i][j] = 0.0;
        
#pragma ACCEL PARALLEL FACTOR=220
        for (k = 0; k < 220; ++k) {
          F[i][j] += C[i][k] * D[k][j];
        }
      }
    }
    
    
    
    for (i = 0; i < 180; i++) {
      
      
      
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=2
      for (j = 0; j < 210; j++) {
        G[i][j] = 0.0;
        
#pragma ACCEL PARALLEL FACTOR=190
        for (k = 0; k < 190; ++k) {
          G[i][j] += E[i][k] * F[k][j];
        }
      }
    }
  }
}
