#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void Cnn( float input[256][228][228], float weight[256][256][5][5], float output[256][224][224]) {

int i;
int j;
int p;
int q;
int h;
int w;


  for ( i = 0; i < 256; ++i) {
    for ( j = 0; j < 256; ++j) {
      for ( p = 0; p < 5; ++p) {
            for ( q = 0; q < 5; ++q){
    for ( h = 0; h < 224; ++h) {
      for ( w = 0; w < 224; ++w) {
              output[i][h][w] += weight[i][j][p][q] * input[j][h + p][w + q];
            }
          }
        }
      }
    }
  }
}
void kernel_nlp(float4 vinput[3326976], float1 vweight[1638400], float16 voutput[802816]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float input_ori[256][228][228];
    float input_new[256][228][228];
    float weight_ori[256][256][5][5];
    float weight_new[256][256][5][5];
    float output_ori[256][224][224];
    float output_new[256][224][224];
    for(int i0 = 0; i0 < 256; i0++){
        for(int i1 = 0; i1 < 228; i1++){
            for(int i2 = 0; i2 < 228; i2++){
                val = ((float)rand() / RAND_MAX);
                input_ori[i0][i1][i2] = val;
                input_new[i0][i1][i2] = val;
            }
        }
    }
    for(int i0 = 0; i0 < 256; i0++){
        for(int i1 = 0; i1 < 256; i1++){
            for(int i2 = 0; i2 < 5; i2++){
                for(int i3 = 0; i3 < 5; i3++){
                    val = ((float)rand() / RAND_MAX);
                    weight_ori[i0][i1][i2][i3] = val;
                    weight_new[i0][i1][i2][i3] = val;
                }
            }
        }
    }
    for(int i0 = 0; i0 < 256; i0++){
        for(int i1 = 0; i1 < 224; i1++){
            for(int i2 = 0; i2 < 224; i2++){
                val = ((float)rand() / RAND_MAX);
                output_ori[i0][i1][i2] = val;
                output_new[i0][i1][i2] = val;
            }
        }
    }
    Cnn(input_ori, weight_ori, output_ori);
    kernel_nlp((float4 *) input_new, (float1 *) weight_new, (float16 *) output_new);
    for(int i0 = 0; i0 < 256; i0++){
        for(int i1 = 0; i1 < 228; i1++){
            for(int i2 = 0; i2 < 228; i2++){
                if(abs(input_ori[i0][i1][i2] - input_new[i0][i1][i2])/input_ori[i0][i1][i2] > 0.0001){
                    printf("Error in input[%d][%d][%d]...\n", i0, i1, i2);
                    return 1;
                }
            }
        }
    }
    for(int i0 = 0; i0 < 256; i0++){
        for(int i1 = 0; i1 < 256; i1++){
            for(int i2 = 0; i2 < 5; i2++){
                for(int i3 = 0; i3 < 5; i3++){
                    if(abs(weight_ori[i0][i1][i2][i3] - weight_new[i0][i1][i2][i3])/weight_ori[i0][i1][i2][i3] > 0.0001){
                        printf("Error in weight[%d][%d][%d][%d]...\n", i0, i1, i2, i3);
                        return 1;
                    }
                }
            }
        }
    }
    for(int i0 = 0; i0 < 256; i0++){
        for(int i1 = 0; i1 < 224; i1++){
            for(int i2 = 0; i2 < 224; i2++){
                if(abs(output_ori[i0][i1][i2] - output_new[i0][i1][i2])/output_ori[i0][i1][i2] > 0.0001){
                    printf("Error in output[%d][%d][%d]...\n", i0, i1, i2);
                    return 1;
                }
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
