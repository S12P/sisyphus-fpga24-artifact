#include <cstring>
#include <hls_stream.h>
#include <ap_int.h>
#include <hls_vector.h>
#include "code_generated.h"

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

#pragma ACCEL kernel

void kernel_gemver(double alpha,double beta,double A[400][400],double u1[400],double e1[400],double u2[400],double e2[400],double w[400],double x[400],double y[400],double z[400])
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

void kernel_nlp(double alpha, double beta, double16 vA[10000], double16 vu1[25], double16 ve1[25], double16 vu2[25], double16 ve2[25], double16 vw[25], double16 vx[25], double16 vy[25], double16 vz[25]) ;

int main(){
    printf("Starting C-simulation...\n");
    double val;
    double alpha_ori;
    double alpha_new;
    double beta_ori;
    double beta_new;
    double A_ori[400][400];
    double A_new[400][400];
    double u1_ori[400];
    double u1_new[400];
    double e1_ori[400];
    double e1_new[400];
    double u2_ori[400];
    double u2_new[400];
    double e2_ori[400];
    double e2_new[400];
    double w_ori[400];
    double w_new[400];
    double x_ori[400];
    double x_new[400];
    double y_ori[400];
    double y_new[400];
    double z_ori[400];
    double z_new[400];
    val = ((double)rand() / RAND_MAX);
    alpha_ori = val;
    alpha_new = val;
    val = ((double)rand() / RAND_MAX);
    beta_ori = val;
    beta_new = val;
    for(int i0 = 0; i0 < 400; i0++){
        for(int i1 = 0; i1 < 400; i1++){
            val = ((double)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((double)rand() / RAND_MAX);
        u1_ori[i0] = val;
        u1_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((double)rand() / RAND_MAX);
        e1_ori[i0] = val;
        e1_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((double)rand() / RAND_MAX);
        u2_ori[i0] = val;
        u2_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((double)rand() / RAND_MAX);
        e2_ori[i0] = val;
        e2_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((double)rand() / RAND_MAX);
        w_ori[i0] = val;
        w_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((double)rand() / RAND_MAX);
        x_ori[i0] = val;
        x_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((double)rand() / RAND_MAX);
        y_ori[i0] = val;
        y_new[i0] = val;
    }
    for(int i0 = 0; i0 < 400; i0++){
        val = ((double)rand() / RAND_MAX);
        z_ori[i0] = val;
        z_new[i0] = val;
    }
    kernel_gemver(alpha_ori, beta_ori, A_ori, u1_ori, e1_ori, u2_ori, e2_ori, w_ori, x_ori, y_ori, z_ori);
    kernel_nlp(alpha_new, beta_new, (double16 *) A_new, (double16 *) u1_new, (double16 *) e1_new, (double16 *) u2_new, (double16 *) e2_new, (double16 *) w_new, (double16 *) x_new, (double16 *) y_new, (double16 *) z_new);
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
