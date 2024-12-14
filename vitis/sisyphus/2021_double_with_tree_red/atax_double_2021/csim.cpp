#include <hls_vector.h>
#include <ap_int.h>
#include <cstring>
#include <hls_stream.h>
#include "code_generated.h"

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

#pragma ACCEL kernel

void kernel_atax(double A[390][410],double x[410],double y[410],double tmp[390])
{
  int i;
  int j;
{
    
    for (j = 0; j < 410; j++) {
      y[j] = 0.0;
    }

    for (i = 0; i < 390; i++) {
      tmp[i] = 0.0;
    }

    for (i = 0; i < 390; i++) {
      for (j = 0; j < 410; j++) {
      
        tmp[i] = tmp[i] + A[i][j] * x[j];
      }
    }
    for (j = 0; j < 410; j++) {
      for (i = 0; i < 390; i++) {
      
        y[j] = y[j] + A[i][j] * tmp[i];
      }
    }
  }
}

void kernel_nlp(double2 vA[79950], double2 vx[205], double2 vy[205], double2 vtmp[195]) ;

int main(){
    printf("Starting C-simulation...\n");
    double val;
    double A_ori[390][410];
    double A_new[390][410];
    double x_ori[410];
    double x_new[410];
    double y_ori[410];
    double y_new[410];
    double tmp_ori[390];
    double tmp_new[390];
    for(int i0 = 0; i0 < 390; i0++){
        for(int i1 = 0; i1 < 410; i1++){
            val = ((double)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 410; i0++){
        val = ((double)rand() / RAND_MAX);
        x_ori[i0] = val;
        x_new[i0] = val;
    }
    for(int i0 = 0; i0 < 410; i0++){
        val = ((double)rand() / RAND_MAX);
        y_ori[i0] = val;
        y_new[i0] = val;
    }
    for(int i0 = 0; i0 < 390; i0++){
        val = ((double)rand() / RAND_MAX);
        tmp_ori[i0] = val;
        tmp_new[i0] = val;
    }
    kernel_atax(A_ori, x_ori, y_ori, tmp_ori);
    kernel_nlp((double2 *) A_new, (double2 *) x_new, (double2 *) y_new, (double2 *) tmp_new);
    for(int i0 = 0; i0 < 390; i0++){
        for(int i1 = 0; i1 < 410; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 410; i0++){
        if(abs(x_ori[i0] - x_new[i0])/x_ori[i0] > 0.0001){
            printf("Error in x[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 410; i0++){
        if(abs(y_ori[i0] - y_new[i0])/y_ori[i0] > 0.0001){
            printf("Error in y[%d]...\n", i0);
            return 1;
        }
    }
    for(int i0 = 0; i0 < 390; i0++){
        if(abs(tmp_ori[i0] - tmp_new[i0])/tmp_ori[i0] > 0.0001){
            printf("Error in tmp[%d]...\n", i0);
            return 1;
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
