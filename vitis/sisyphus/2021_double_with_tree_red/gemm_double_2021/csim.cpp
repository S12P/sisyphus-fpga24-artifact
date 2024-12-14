#include <hls_stream.h>
#include <cstring>
#include <ap_int.h>
#include <hls_vector.h>
#include "code_generated.h"

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

#pragma ACCEL kernel

void kernel_gemm(double alpha,double beta,double C[200][220],double A[200][240],double B[240][220])
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

void kernel_nlp(double alpha, double beta, double4 vC[11000], double16 vA[3000], double4 vB[13200]) ;

int main(){
    printf("Starting C-simulation...\n");
    double val;
    double alpha_ori;
    double alpha_new;
    double beta_ori;
    double beta_new;
    double C_ori[200][220];
    double C_new[200][220];
    double A_ori[200][240];
    double A_new[200][240];
    double B_ori[240][220];
    double B_new[240][220];
    val = ((double)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    val = ((double)rand() / RAND_MAX);
    beta_ori = val;
    beta_new = val;
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            val = ((double)rand() / RAND_MAX);
            C_ori[i0][i1] = val;
            C_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 240; i1++){
            val = ((double)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 240; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            val = ((double)rand() / RAND_MAX);
            B_ori[i0][i1] = val;
            B_new[i0][i1] = val;
        }
    }
    kernel_gemm(alpha_ori, beta_ori, C_ori, A_ori, B_ori);
    kernel_nlp(alpha_new, beta_new, (double4 *) C_new, (double16 *) A_new, (double4 *) B_new);
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
