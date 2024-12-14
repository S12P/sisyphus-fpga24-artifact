#include <hls_vector.h>
#include <hls_stream.h>
#include <cstring>
#include <ap_int.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_trmm(float alpha,float A[200][200],float B[200][240], float B2[200][240])
{
  int i;
  int j;
  int k;
//BLAS parameters
//SIDE   = 'L'
//UPLO   = 'L'
//TRANSA = 'T'
//DIAG   = 'U'
// => Form  B := alpha*A**T*B.
// A is MxM
// B is MxN
{
    
    
    
    for (i = 0; i < 200; i++) {
      
      
      
      for (j = 0; j < 240; j++) {
        for (k = i + 1; k < 200; k++) {
          B[i][j] += A[k][i] * B2[k][j];
        }
        B[i][j] = alpha * B[i][j];
      }
    }
  }
}

void kernel_nlp(float alpha, float8 vA[5000], float16 vB[3000], float16 vB2[3000]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float alpha_ori;
    float alpha_new;
    float A_ori[200][200];
    float A_new[200][200];
    float B_ori[200][240];
    float B_new[200][240];
    float B2_ori[200][240];
    float B2_new[200][240];
    val = ((float)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 200; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            val = ((float)rand() / RAND_MAX);
            B_ori[i0][i1] = val;
            B_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            val = ((float)rand() / RAND_MAX);
            B2_ori[i0][i1] = val;
            B2_new[i0][i1] = val;
        }
    }
    kernel_trmm(alpha_ori, A_ori, B_ori, B2_ori);
    kernel_nlp(alpha_new, (float8 *) A_new, (float16 *) B_new, (float16 *) B2_new);
    if(abs(alpha_ori - alpha_new) > 0.0001){
        printf("Error in alpha...\n");
        return 1;
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 200; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            if(abs(B_ori[i0][i1] - B_new[i0][i1])/B_ori[i0][i1] > 0.0001){
                printf("Error in B[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            if(abs(B2_ori[i0][i1] - B2_new[i0][i1])/B2_ori[i0][i1] > 0.0001){
                printf("Error in B2[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
