#pragma ACCEL kernel

void kernel_doitgen(int nr,int nq,int np,float A[50][40][60],float C4[60][60],float sum[60])
{
  int r;
  int q;
  int p;
  int s;
{
    
    
    
    for (r = 0; r < 50; r++) {
      
      
      
      for (q = 0; q < 40; q++) {
        
        
        
#pragma ACCEL PARALLEL FACTOR=4
        for (p = 0; p < 60; p++) {
          sum[p] = 0.0;
          
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=4
          for (s = 0; s < 60; s++) {
            sum[p] += A[r][q][s] * C4[s][p];
          }
        }
        
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=15
        for (p = 0; p < 60; p++) {
          A[r][q][p] = sum[p];
        }
      }
    }
  }
}
