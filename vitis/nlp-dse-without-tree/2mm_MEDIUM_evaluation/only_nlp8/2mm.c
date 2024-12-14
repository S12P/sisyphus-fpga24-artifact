#pragma ACCEL kernel

void kernel_2mm(int ni,int nj,int nk,int nl,float alpha,float beta,float tmp[180][190],float A[180][210],float B[210][190],float C[190][220],float D[180][220])
{
  int i;
  int j;
  int k;
{
    
    
    
#pragma ACCEL PARALLEL FACTOR=12
    for (i = 0; i < 180; i++) {
      
      
      
#pragma ACCEL PARALLEL FACTOR=10
      for (j = 0; j < 190; j++) {
        tmp[i][j] = 0.0;
        
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=6
        for (k = 0; k < 210; ++k) {
          tmp[i][j] += alpha * A[i][k] * B[k][j];
        }
      }
    }
    
    
    
#pragma ACCEL PARALLEL FACTOR=12
    for (i = 0; i < 180; i++) {
      
      
      
#pragma ACCEL PARALLEL FACTOR=10
      for (j = 0; j < 220; j++) {
        D[i][j] *= beta;
        
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=10
        for (k = 0; k < 190; ++k) {
          D[i][j] += tmp[i][k] * C[k][j];
        }
      }
    }
  }
}
