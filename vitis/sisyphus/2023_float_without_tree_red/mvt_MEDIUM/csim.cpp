#include <hls_vector.h>
#include <ap_int.h>
#include <hls_stream.h>
#include <cstring>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_mvt(float x1[400],float x2[400],float y_1[400],float y_2[400],float A[400][400])
{
  int i;
  int j;
{
    
    
    
    for (i = 0; i < 400; i++) {
      
      for (j = 0; j < 400; j++) {
        x1[i] = x1[i] + A[i][j] * y_1[j];
      }
    }
    
    
    
    for (i = 0; i < 400; i++) {
      
      for (j = 0; j < 400; j++) {
        x2[i] = x2[i] + A[j][i] * y_2[j];
      }
    }
  }
}

void kernel_nlp(float16 vx1[25], float16 vx2[25], float16 vy_1[25], float16 vy_2[25], float16 vA[10000]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float x1_ori[400];
    float x1_new[400];
    float x2_ori[400];
    float x2_new[400];
    float y_1_ori[400];
    float y_1_new[400];
    float y_2_ori[400];
    float y_2_new[400];
    float A_ori[400][400];
    float A_new[400][400];
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        x1_ori[i0] = val;
        x1_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        x2_ori[i0] = val;
        x2_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        y_1_ori[i0] = val;
        y_1_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        y_2_ori[i0] = val;
        y_2_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        for(int i1 = 0; i1 < 400; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    kernel_mvt(x1_ori, x2_ori, y_1_ori, y_2_ori, A_ori);
    kernel_nlp((float16 *) x1_new, (float16 *) x2_new, (float16 *) y_1_new, (float16 *) y_2_new, (float16 *) A_new);
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(x1_ori[i0] - x1_new[i0])/x1_ori[i0] > 0.0001){
            printf("Error in x1[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(x2_ori[i0] - x2_new[i0])/x2_ori[i0] > 0.0001){
            printf("Error in x2[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(y_1_ori[i0] - y_1_new[i0])/y_1_ori[i0] > 0.0001){
            printf("Error in y_1[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(y_2_ori[i0] - y_2_new[i0])/y_2_ori[i0] > 0.0001){
            printf("Error in y_2[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        for(int i1 = 0; i1 < 400; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}