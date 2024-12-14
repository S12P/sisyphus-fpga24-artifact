#include <ap_int.h>
#include <cstring>
#include <hls_vector.h>
#include <hls_stream.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_gemm(float alpha,float beta,float C[200][220],float A[200][240],float B[240][220])
{
  int i;
  int j;
  int k;

{
    
    
    
    for (i = 0; i < 200; i++) {
      
      for (j = 0; j < 220; j++) {
        C[i][j] *= beta;
      }
      
      
      for (j = 0; j < 220; j++) {
        for (k = 0; k < 240; k++) {
        
        
          C[i][j] += alpha * A[i][k] * B[k][j];
        }
      }
    }
  }
}

void kernel_nlp(float alpha, float beta, float4 vC[11000], float16 vA[3000], float4 vB[13200]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float alpha_ori;
    float alpha_new;
    float beta_ori;
    float beta_new;
    float C_ori[200][220];
    float C_new[200][220];
    float A_ori[200][240];
    float A_new[200][240];
    float B_ori[240][220];
    float B_new[240][220];
    val = ((float)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    val = ((float)rand() / RAND_MAX);
    beta_ori = val;
    beta_new = val;
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            val = ((float)rand() / RAND_MAX);
            C_ori[i0][i1] = val;
            C_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 240; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            val = ((float)rand() / RAND_MAX);
            B_ori[i0][i1] = val;
            B_new[i0][i1] = val;
        }
    }
    kernel_gemm(alpha_ori, beta_ori, C_ori, A_ori, B_ori);
    kernel_nlp(alpha_new, beta_new, (float4 *) C_new, (float16 *) A_new, (float4 *) B_new);
    if(abs(alpha_ori - alpha_new) > 0.0001){
        printf("Error in alpha...\n");
        return 1;
    }
    if(abs(beta_ori - beta_new) > 0.0001){
        printf("Error in beta...\n");
        return 1;
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            if(abs(C_ori[i0][i1] - C_new[i0][i1])/C_ori[i0][i1] > 0.0001){
                printf("Error in C[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 240; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            if(abs(B_ori[i0][i1] - B_new[i0][i1])/B_ori[i0][i1] > 0.0001){
                printf("Error in B[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
