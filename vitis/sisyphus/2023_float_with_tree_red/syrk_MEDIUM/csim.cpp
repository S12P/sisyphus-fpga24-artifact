#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>
#include <ap_int.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_syrk(float alpha,float beta,float C[240][240],float A[240][200])
{
  int i;
  int j;
  int k;
//BLAS PARAMS
//TRANS = 'N'
//UPLO  = 'L'
// =>  Form  C := alpha*A*A**T + beta*C.
//A is NxM
//C is NxN
{
    
    
    
    for (i = 0; i < 240; i++) {
      for (j = 0; j <= i; j++) {
        C[i][j] *= beta;
      }
      
      
      for (j = 0; j <= i; j++) {
      for (k = 0; k < 200; k++) {
        // for (j = 0; j <= i; j++) {
          C[i][j] += alpha * A[i][k] * A[j][k];
        }
      }
    }
  }
}

void kernel_nlp(float alpha, float beta, float16 vC[3600], float8 vA[6000]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float alpha_ori;
    float alpha_new;
    float beta_ori;
    float beta_new;
    float C_ori[240][240];
    float C_new[240][240];
    float A_ori[240][200];
    float A_new[240][200];
    val = ((float)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    val = ((float)rand() / RAND_MAX);
    beta_ori = val;
    beta_new = val;
    for(int i0 = 0; i0 < 240; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            val = ((float)rand() / RAND_MAX);
            C_ori[i0][i1] = val;
            C_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 240; i0++){
        for(int i1 = 0; i1 < 200; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    kernel_syrk(alpha_ori, beta_ori, C_ori, A_ori);
    kernel_nlp(alpha_new, beta_new, (float16 *) C_new, (float8 *) A_new);
    if(abs(alpha_ori - alpha_new) > 0.0001){
        printf("Error in alpha...\n");
        return 1;
    }
    if(abs(beta_ori - beta_new) > 0.0001){
        printf("Error in beta...\n");
        return 1;
    }
    for(int i0 = 0; i0 < 240; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            if(abs(C_ori[i0][i1] - C_new[i0][i1])/C_ori[i0][i1] > 0.0001){
                printf("Error in C[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 240; i0++){
        for(int i1 = 0; i1 < 200; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
