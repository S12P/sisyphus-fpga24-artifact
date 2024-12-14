#pragma ACCEL kernel
void Cnn(
    const float input[256][228][228],
    const float weight[256][256][5][5], const float bias[256],
    float output[256][224][224]) {



#pragma ACCEL pipeline 
#pragma ACCEL PARALLEL FACTOR=16
for (int i = 0; i < 256; ++i) {
  for (int j = 0; j < 256; ++j) {
#pragma ACCEL PARALLEL FACTOR=2
    for (int h = 0; h < 224; ++h) {
#pragma ACCEL PIPELINE FLATTEN
      for (int w = 0; w < 224; ++w) {
#pragma ACCEL PARALLEL FACTOR=5
        for (int p = 0; p < 5; ++p) {
#pragma ACCEL PARALLEL FACTOR=5
          for (int q = 0; q < 5; ++q){
              output[i][h][w] += weight[i][j][p][q] * input[j][h + p][w + q];
            }
          }
        }
      }
    }
  }
}