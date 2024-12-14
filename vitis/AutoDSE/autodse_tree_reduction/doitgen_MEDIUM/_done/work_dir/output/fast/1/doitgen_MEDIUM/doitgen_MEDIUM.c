#pragma ACCEL kernel

void kernel_doitgen(float A[50][40][60],float C4[60][60],float sum[50][40][60])
{
  int r;
  int q;
  int p;
  int s;
{
    
#pragma ACCEL PIPELINE off
    
#pragma ACCEL TILE FACTOR=1
    
#pragma ACCEL PARALLEL FACTOR=1
    for (r = 0; r < 50; r++) {
      
#pragma ACCEL PIPELINE off
      
#pragma ACCEL TILE FACTOR=40
      
#pragma ACCEL PARALLEL FACTOR=1
      for (q = 0; q < 40; q++) {
        
#pragma ACCEL PIPELINE flatten
        
#pragma ACCEL TILE FACTOR=1
        
#pragma ACCEL PARALLEL FACTOR=4
        for (p = 0; p < 60; p++) {
          sum[r][q][p] = ((float )0.0);
          
#pragma ACCEL PARALLEL FACTOR=1
          for (s = 0; s < 60; s++) {
            sum[r][q][p] += A[r][q][s] * C4[s][p];
          }
        }
        
#pragma ACCEL PARALLEL FACTOR=60
        for (p = 0; p < 60; p++) {
          A[r][q][p] = sum[r][q][p];
        }
      }
    }
  }
}
