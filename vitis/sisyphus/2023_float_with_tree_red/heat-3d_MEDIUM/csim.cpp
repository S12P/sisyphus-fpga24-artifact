#include <cstring>
#include <hls_vector.h>
#include <hls_stream.h>
#include <ap_int.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_heat_3d(float A[40][40][40],float B[40][40][40])
{
  int t;
  int i;
  int j;
  int k;
{
    
    
    
    // for (t = 1; t <= 100; t++) {
      
      
      
      for (i = 1; i < 40 - 1; i++) {
        
        
        
        for (j = 1; j < 40 - 1; j++) {
          
          for (k = 1; k < 40 - 1; k++) {
            B[i][j][k] = 0.125 * (A[i + 1][j][k] - 2.0 * A[i][j][k] + A[i - 1][j][k]) + 0.125 * (A[i][j + 1][k] - 2.0 * A[i][j][k] + A[i][j - 1][k]) + 0.125 * (A[i][j][k + 1] - 2.0 * A[i][j][k] + A[i][j][k - 1]) + A[i][j][k];
          }
        }
      }
      
      
      
      for (i = 1; i < 40 - 1; i++) {
        
        
        
        for (j = 1; j < 40 - 1; j++) {
          
          for (k = 1; k < 40 - 1; k++) {
            A[i][j][k] = 0.125 * (B[i + 1][j][k] - 2.0 * B[i][j][k] + B[i - 1][j][k]) + 0.125 * (B[i][j + 1][k] - 2.0 * B[i][j][k] + B[i][j - 1][k]) + 0.125 * (B[i][j][k + 1] - 2.0 * B[i][j][k] + B[i][j][k - 1]) + B[i][j][k];
          }
        }
      }
    }
  // }
}

void kernel_nlp(float8 vA[8000], float8 vB[8000]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float A_ori[40][40][40];
    float A_new[40][40][40];
    float B_ori[40][40][40];
    float B_new[40][40][40];
    for(int i0 = 0; i0 < 40; i0++){
        for(int i1 = 0; i1 < 40; i1++){
            for(int i2 = 0; i2 < 40; i2++){
                val = ((float)rand() / RAND_MAX);
                A_ori[i0][i1][i2] = val;
                A_new[i0][i1][i2] = val;
            }
        }
    }
    for(int i0 = 0; i0 < 40; i0++){
        for(int i1 = 0; i1 < 40; i1++){
            for(int i2 = 0; i2 < 40; i2++){
                val = ((float)rand() / RAND_MAX);
                B_ori[i0][i1][i2] = val;
                B_new[i0][i1][i2] = val;
            }
        }
    }
    kernel_heat_3d(A_ori, B_ori);
    kernel_nlp((float8 *) A_new, (float8 *) B_new);
    for(int i0 = 0; i0 < 40; i0++){
        for(int i1 = 0; i1 < 40; i1++){
            for(int i2 = 0; i2 < 40; i2++){
                if(abs(A_ori[i0][i1][i2] - A_new[i0][i1][i2])/A_ori[i0][i1][i2] > 0.0001){
                    printf("Error in A[%d][%d][%d]...\n", i0, i1, i2);
                    return 1;
                }
            }
        }
    }
    for(int i0 = 0; i0 < 40; i0++){
        for(int i1 = 0; i1 < 40; i1++){
            for(int i2 = 0; i2 < 40; i2++){
                if(abs(B_ori[i0][i1][i2] - B_new[i0][i1][i2])/B_ori[i0][i1][i2] > 0.0001){
                    printf("Error in B[%d][%d][%d]...\n", i0, i1, i2);
                    return 1;
                }
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
