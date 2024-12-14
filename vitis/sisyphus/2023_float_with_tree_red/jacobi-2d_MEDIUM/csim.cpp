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

#pragma ACCEL kernel

void kernel_jacobi_2d(float A[250][250],float B[250][250])
{
  int t;
  int i;
  int j;
{
    
    
    
    // for (t = 0; t < 100; t++) {
      
      
      
      for (i = 1; i < 250 - 1; i++) {
        
        for (j = 1; j < 250 - 1; j++) {
          B[i][j] = 0.2 * (A[i][j] + A[i][j - 1] + A[i][1 + j] + A[1 + i][j] + A[i - 1][j]);
        }
      }
      
      
      
      for (i = 1; i < 250 - 1; i++) {
        
        for (j = 1; j < 250 - 1; j++) {
          A[i][j] = 0.2 * (B[i][j] + B[i][j - 1] + B[i][1 + j] + B[1 + i][j] + B[i - 1][j]);
        }
      }
    }
  // }
}

void kernel_nlp(float2 vA[31250], float2 vB[31250]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float A_ori[250][250];
    float A_new[250][250];
    float B_ori[250][250];
    float B_new[250][250];
    for(int i0 = 0; i0 < 250; i0++){
        for(int i1 = 0; i1 < 250; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 250; i0++){
        for(int i1 = 0; i1 < 250; i1++){
            val = ((float)rand() / RAND_MAX);
            B_ori[i0][i1] = val;
            B_new[i0][i1] = val;
        }
    }
    kernel_jacobi_2d(A_ori, B_ori);
    kernel_nlp((float2 *) A_new, (float2 *) B_new);
    for(int i0 = 0; i0 < 250; i0++){
        for(int i1 = 0; i1 < 250; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 250; i0++){
        for(int i1 = 0; i1 < 250; i1++){
            if(abs(B_ori[i0][i1] - B_new[i0][i1])/B_ori[i0][i1] > 0.0001){
                printf("Error in B[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
