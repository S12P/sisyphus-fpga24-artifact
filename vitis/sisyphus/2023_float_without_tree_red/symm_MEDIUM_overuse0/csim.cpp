#include <hls_vector.h>
#include <cstring>
#include <hls_stream.h>
#include <ap_int.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_symm(float alpha,float beta,float temp2[200][240], float C[200][240],float A[200][200],float B[200][240])
{
  
  int i;
  int j;
  int k;
  
//BLAS PARAMS
//SIDE = 'L'
//UPLO = 'L'
// =>  Form  C := alpha*A*B + beta*C
// A is MxM
// B is MxN
// C is MxN
//note that due to Fortran array layout, the code below more closely resembles upper triangular case in BLAS
{
    
    
    
    for (i = 0; i < 200; i++) {
      for (j = 0; j < 240; j++) {
        temp2[i][j] = 0;
      }
    }
    for (i = 0; i < 200; i++) {
      for (j = 0; j < 240; j++) {
        for (k = 0; k < i; k++) {
          temp2[i][j] += B[k][j] * A[i][k];
        }
      }
    }
    for (i = 0; i < 200; i++) {
      for (j = 0; j < 240; j++) {
        C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2[i][j];
      }
    }
    for (i = 0; i < 200; i++) {
      for (j = 0; j < 240; j++) {
        for (k = 0; k < i; k++) {
          C[k][j] += alpha * B[i][j] * A[i][k];
        }
      }
    }
  }
}

void kernel_nlp(float alpha, float beta, float16 vtemp2[3000], float16 vC[3000], float8 vA[5000], float16 vB[3000]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float alpha_ori;
    float alpha_new;
    float beta_ori;
    float beta_new;
    float temp2_ori[200][240];
    float temp2_new[200][240];
    float C_ori[200][240];
    float C_new[200][240];
    float A_ori[200][200];
    float A_new[200][200];
    float B_ori[200][240];
    float B_new[200][240];
    val = ((float)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    val = ((float)rand() / RAND_MAX);
    beta_ori = val;
    beta_new = val;
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            val = ((float)rand() / RAND_MAX);
            temp2_ori[i0][i1] = val;
            temp2_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            val = ((float)rand() / RAND_MAX);
            C_ori[i0][i1] = val;
            C_new[i0][i1] = val;
        }
    }
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
    kernel_symm(alpha_ori, beta_ori, temp2_ori, C_ori, A_ori, B_ori);
    kernel_nlp(alpha_new, beta_new, (float16 *) temp2_new, (float16 *) C_new, (float8 *) A_new, (float16 *) B_new);
    if(abs(alpha_ori - alpha_new) > 0.0001){
        printf("Error in alpha...\n");
        return 1;
    }
    if(abs(beta_ori - beta_new) > 0.0001){
        printf("Error in beta...\n");
        return 1;
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            if(abs(temp2_ori[i0][i1] - temp2_new[i0][i1])/temp2_ori[i0][i1] > 0.0001){
                printf("Error in temp2[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            if(abs(C_ori[i0][i1] - C_new[i0][i1])/C_ori[i0][i1] > 0.0001){
                printf("Error in C[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
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
    printf("C-simulation passed!\n");
    return 0;
}
