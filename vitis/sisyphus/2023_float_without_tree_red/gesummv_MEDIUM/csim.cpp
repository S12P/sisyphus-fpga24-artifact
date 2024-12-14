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

void kernel_gesummv(float alpha,float beta,float A[250][250],float B[250][250],float tmp[250],float x[250],float y[250])
{
  int i;
  int j;
{
    
    
    
    for (i = 0; i < 250; i++) {
      tmp[i] = 0.0;
      y[i] = 0.0;
      
      for (j = 0; j < 250; j++) {
        tmp[i] += A[i][j] * x[j];
        y[i] += B[i][j] * x[j];
      }
      y[i] = alpha * tmp[i] + beta * y[i];
    }
  }
}

void kernel_nlp(float alpha, float beta, float2 vA[31250], float2 vB[31250], float2 vtmp[125], float2 vx[125], float2 vy[125]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float alpha_ori;
    float alpha_new;
    float beta_ori;
    float beta_new;
    float A_ori[250][250];
    float A_new[250][250];
    float B_ori[250][250];
    float B_new[250][250];
    float tmp_ori[250];
    float tmp_new[250];
    float x_ori[250];
    float x_new[250];
    float y_ori[250];
    float y_new[250];
    val = ((float)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    val = ((float)rand() / RAND_MAX);
    beta_ori = val;
    beta_new = val;
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
    for(int i0 = 0; i0 < 250; i0++){
        val = ((float)rand() / RAND_MAX);
        tmp_ori[i0] = val;
        tmp_new[i0] = val;
    }
    for(int i0 = 0; i0 < 250; i0++){
        val = ((float)rand() / RAND_MAX);
        x_ori[i0] = val;
        x_new[i0] = val;
    }
    for(int i0 = 0; i0 < 250; i0++){
        val = ((float)rand() / RAND_MAX);
        y_ori[i0] = val;
        y_new[i0] = val;
    }
    kernel_gesummv(alpha_ori, beta_ori, A_ori, B_ori, tmp_ori, x_ori, y_ori);
    kernel_nlp(alpha_new, beta_new, (float2 *) A_new, (float2 *) B_new, (float2 *) tmp_new, (float2 *) x_new, (float2 *) y_new);
    if(abs(alpha_ori - alpha_new) > 0.0001){
        printf("Error in alpha...\n");
        return 1;
    }
    if(abs(beta_ori - beta_new) > 0.0001){
        printf("Error in beta...\n");
        return 1;
    }
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
    for(int i0 = 0; i0 < 250; i0++){
        if(abs(tmp_ori[i0] - tmp_new[i0])/tmp_ori[i0] > 0.0001){
            printf("Error in tmp[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 250; i0++){
        if(abs(x_ori[i0] - x_new[i0])/x_ori[i0] > 0.0001){
            printf("Error in x[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 250; i0++){
        if(abs(y_ori[i0] - y_new[i0])/y_ori[i0] > 0.0001){
            printf("Error in y[%d]...\n", i0);
            return 1;
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
