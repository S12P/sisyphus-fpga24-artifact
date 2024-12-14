#include <hls_stream.h>
#include <cstring>
#include <hls_vector.h>
#include <ap_int.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_gemver(float alpha,float beta,float A[400][400],float u1[400],float e1[400],float u2[400],float e2[400],float w[400],float x[400],float y[400],float z[400])
{
  int i;
  int j;
{
    
    
    
    for (i = 0; i < 400; i++) {
      
      for (j = 0; j < 400; j++) {
        A[i][j] = A[i][j] + u1[i] * e1[j] + u2[i] * e2[j];
      }
    }
    
    
    
    for (i = 0; i < 400; i++) {
      
      for (j = 0; j < 400; j++) {
        x[i] = x[i] + beta * A[j][i] * y[j];
      }
    }
    
    for (i = 0; i < 400; i++) {
      x[i] = x[i] + z[i];
    }
    
    
    
    for (i = 0; i < 400; i++) {
      
      for (j = 0; j < 400; j++) {
        w[i] = w[i] + alpha * A[i][j] * x[j];
      }
    }
  }
}

void kernel_nlp(float alpha, float beta, float16 vA[10000], float16 vu1[25], float16 ve1[25], float16 vu2[25], float16 ve2[25], float16 vw[25], float16 vx[25], float16 vy[25], float16 vz[25]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float alpha_ori;
    float alpha_new;
    float beta_ori;
    float beta_new;
    float A_ori[400][400];
    float A_new[400][400];
    float u1_ori[400];
    float u1_new[400];
    float e1_ori[400];
    float e1_new[400];
    float u2_ori[400];
    float u2_new[400];
    float e2_ori[400];
    float e2_new[400];
    float w_ori[400];
    float w_new[400];
    float x_ori[400];
    float x_new[400];
    float y_ori[400];
    float y_new[400];
    float z_ori[400];
    float z_new[400];
    val = ((float)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    val = ((float)rand() / RAND_MAX);
    beta_ori = val;
    beta_new = val;
    for(int i0 = 0; i0 < 400; i0++){
        for(int i1 = 0; i1 < 400; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        u1_ori[i0] = val;
        u1_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        e1_ori[i0] = val;
        e1_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        u2_ori[i0] = val;
        u2_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        e2_ori[i0] = val;
        e2_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        w_ori[i0] = val;
        w_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        x_ori[i0] = val;
        x_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        y_ori[i0] = val;
        y_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((float)rand() / RAND_MAX);
        z_ori[i0] = val;
        z_new[i0] = val;
    }
    kernel_gemver(alpha_ori, beta_ori, A_ori, u1_ori, e1_ori, u2_ori, e2_ori, w_ori, x_ori, y_ori, z_ori);
    kernel_nlp(alpha_new, beta_new, (float16 *) A_new, (float16 *) u1_new, (float16 *) e1_new, (float16 *) u2_new, (float16 *) e2_new, (float16 *) w_new, (float16 *) x_new, (float16 *) y_new, (float16 *) z_new);
    if(abs(alpha_ori - alpha_new) > 0.0001){
        printf("Error in alpha...\n");
        return 1;
    }
    if(abs(beta_ori - beta_new) > 0.0001){
        printf("Error in beta...\n");
        return 1;
    }
    for(int i0 = 0; i0 < 400; i0++){
        for(int i1 = 0; i1 < 400; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(u1_ori[i0] - u1_new[i0])/u1_ori[i0] > 0.0001){
            printf("Error in u1[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(e1_ori[i0] - e1_new[i0])/e1_ori[i0] > 0.0001){
            printf("Error in e1[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(u2_ori[i0] - u2_new[i0])/u2_ori[i0] > 0.0001){
            printf("Error in u2[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(e2_ori[i0] - e2_new[i0])/e2_ori[i0] > 0.0001){
            printf("Error in e2[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(w_ori[i0] - w_new[i0])/w_ori[i0] > 0.0001){
            printf("Error in w[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(x_ori[i0] - x_new[i0])/x_ori[i0] > 0.0001){
            printf("Error in x[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(y_ori[i0] - y_new[i0])/y_ori[i0] > 0.0001){
            printf("Error in y[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        if(abs(z_ori[i0] - z_new[i0])/z_ori[i0] > 0.0001){
            printf("Error in z[%d]...\n", i0);
            return 1;
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
