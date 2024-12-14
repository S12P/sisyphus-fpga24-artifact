#pragma ACCEL kernel

void Cnn(float input[256][228][228],float weight[256][256][5][5],float bias[256],float output[256][224][224])
{
  int i;
  int j;
  int p;
  int q;
  int h;
  int w;
  
#pragma ACCEL PIPELINE auto{__PIPE__L0}
  
#pragma ACCEL TILE FACTOR=auto{__TILE__L0}
  
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L0}
  for (i = 0; i < 256; ++i) {
    
#pragma ACCEL PIPELINE auto{__PIPE__L1}
    
#pragma ACCEL TILE FACTOR=auto{__TILE__L1}
    
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L1}
    for (h = 0; h < 224; ++h) {
      
#pragma ACCEL PIPELINE auto{__PIPE__L2}
      
#pragma ACCEL TILE FACTOR=auto{__TILE__L2}
      
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L2}
      for (w = 0; w < 224; ++w) {
        
#pragma ACCEL PIPELINE auto{__PIPE__L3}
        
#pragma ACCEL TILE FACTOR=auto{__TILE__L3}
        
#pragma ACCEL PARALLEL FACTOR=auto{__PARA__L3}
        for (j = 0; j < 256; ++j) {
          
#pragma ACCEL PIPELINE auto{__PIPE__L4}
          
#pragma ACCEL TILE FACTOR=auto{__TILE__L4}
          for (p = 0; p < 5; ++p) {
            for (q = 0; q < 5; ++q) {
              output[i][h][w] += weight[i][j][p][q] * input[j][h + p][w + q];
            }
          }
        }
      }
    }
  }
}
