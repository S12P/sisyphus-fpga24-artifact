#include <cstring>
#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_2mm(float alpha,float beta,float tmp[180][190],float A[180][210],float B[210][190],float C[190][220],float D[180][220])
{
  int i;
  int j;
  int k;
{
    
    
    
    for (i = 0; i < 180; i++) {
      
      
      
      for (j = 0; j < 190; j++) {
        tmp[i][j] = 0.0;
        
        for (k = 0; k < 210; ++k) {
          tmp[i][j] += alpha * A[i][k] * B[k][j];
        }
      }
    }
    
    
    
    for (i = 0; i < 180; i++) {
      
      
      
      for (j = 0; j < 220; j++) {
        D[i][j] *= beta;
        
        for (k = 0; k < 190; ++k) {
          D[i][j] += tmp[i][k] * C[k][j];
        }
      }
    }
  }
}

void kernel_nlp(float alpha, float beta, float2 vtmp[17100], float2 vA[18900], float2 vB[19950], float4 vC[10450], float4 vD[9900]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float alpha_ori;
    float alpha_new;
    float beta_ori;
    float beta_new;
    float tmp_ori[180][190];
    float tmp_new[180][190];
    float A_ori[180][210];
    float A_new[180][210];
    float B_ori[210][190];
    float B_new[210][190];
    float C_ori[190][220];
    float C_new[190][220];
    float D_ori[180][220];
    float D_new[180][220];
    val = ((float)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    val = ((float)rand() / RAND_MAX);
    beta_ori = val;
    beta_new = val;
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 190; i1++){
            val = ((float)rand() / RAND_MAX);
            tmp_ori[i0][i1] = val;
            tmp_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 210; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 210; i0++){
        for(int i1 = 0; i1 < 190; i1++){
            val = ((float)rand() / RAND_MAX);
            B_ori[i0][i1] = val;
            B_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 190; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            val = ((float)rand() / RAND_MAX);
            C_ori[i0][i1] = val;
            C_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            val = ((float)rand() / RAND_MAX);
            D_ori[i0][i1] = val;
            D_new[i0][i1] = val;
        }
    }
    kernel_2mm(alpha_ori, beta_ori, tmp_ori, A_ori, B_ori, C_ori, D_ori);
    kernel_nlp(alpha_new, beta_new, (float2 *) tmp_new, (float2 *) A_new, (float2 *) B_new, (float4 *) C_new, (float4 *) D_new);
    if(abs(alpha_ori - alpha_new) > 0.0001){
        printf("Error in alpha...\n");
        return 1;
    }
    if(abs(beta_ori - beta_new) > 0.0001){
        printf("Error in beta...\n");
        return 1;
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 190; i1++){
            if(abs(tmp_ori[i0][i1] - tmp_new[i0][i1])/tmp_ori[i0][i1] > 0.0001){
                printf("Error in tmp[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 210; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 210; i0++){
        for(int i1 = 0; i1 < 190; i1++){
            if(abs(B_ori[i0][i1] - B_new[i0][i1])/B_ori[i0][i1] > 0.0001){
                printf("Error in B[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 190; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            if(abs(C_ori[i0][i1] - C_new[i0][i1])/C_ori[i0][i1] > 0.0001){
                printf("Error in C[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            if(abs(D_ori[i0][i1] - D_new[i0][i1])/D_ori[i0][i1] > 0.0001){
                printf("Error in D[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
