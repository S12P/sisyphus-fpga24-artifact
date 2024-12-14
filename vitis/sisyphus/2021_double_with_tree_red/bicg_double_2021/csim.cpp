#include <ap_int.h>
#include <hls_vector.h>
#include <cstring>
#include <hls_stream.h>
#include "code_generated.h"

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

#pragma ACCEL kernel

void kernel_bicg(double A[410][390],double s[390],double q[410],double p[390],double r[410])
{
  int i;
  int j;
{
    
    for (i = 0; i < 390; i++) {
      s[i] = 0.0;
    }
    
    
    
    for (i = 0; i < 410; i++) {
      q[i] = 0.0;
    }

    for (j = 0; j < 390; j++) {
      for (i = 0; i < 410; i++) {
      
        s[j] = s[j] + r[i] * A[i][j];
      }
    }
    for (i = 0; i < 410; i++) {
      for (j = 0; j < 390; j++) {
        q[i] = q[i] + A[i][j] * p[j];
      }
    }
  }
}

void kernel_nlp(double2 vA[79950], double2 vs[195], double2 vq[205], double2 vp[195], double2 vr[205]) ;

int main(){
    printf("Starting C-simulation...\n");
    double val;
    double A_ori[410][390];
    double A_new[410][390];
    double s_ori[390];
    double s_new[390];
    double q_ori[410];
    double q_new[410];
    double p_ori[390];
    double p_new[390];
    double r_ori[410];
    double r_new[410];
    for(int i0 = 0; i0 < 410; i0++){
        for(int i1 = 0; i1 < 390; i1++){
            val = ((double)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 390; i0++){
        val = ((double)rand() / RAND_MAX);
        s_ori[i0] = val;
        s_new[i0] = val;
    }
    for(int i0 = 0; i0 < 410; i0++){
        val = ((double)rand() / RAND_MAX);
        q_ori[i0] = val;
        q_new[i0] = val;
    }
    for(int i0 = 0; i0 < 390; i0++){
        val = ((double)rand() / RAND_MAX);
        p_ori[i0] = val;
        p_new[i0] = val;
    }
    for(int i0 = 0; i0 < 410; i0++){
        val = ((double)rand() / RAND_MAX);
        r_ori[i0] = val;
        r_new[i0] = val;
    }
    kernel_bicg(A_ori, s_ori, q_ori, p_ori, r_ori);
    kernel_nlp((double2 *) A_new, (double2 *) s_new, (double2 *) q_new, (double2 *) p_new, (double2 *) r_new);
    for(int i0 = 0; i0 < 410; i0++){
        for(int i1 = 0; i1 < 390; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 390; i0++){
        if(abs(s_ori[i0] - s_new[i0])/s_ori[i0] > 0.0001){
            printf("Error in s[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 410; i0++){
        if(abs(q_ori[i0] - q_new[i0])/q_ori[i0] > 0.0001){
            printf("Error in q[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 390; i0++){
        if(abs(p_ori[i0] - p_new[i0])/p_ori[i0] > 0.0001){
            printf("Error in p[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 410; i0++){
        if(abs(r_ori[i0] - r_new[i0])/r_ori[i0] > 0.0001){
            printf("Error in r[%d]...\n", i0);
            return 1;
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
