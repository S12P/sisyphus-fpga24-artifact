#include <cstring>
#include <hls_stream.h>
#include <ap_int.h>
#include <hls_vector.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_doitgen(float A[50][40][60],float C4[60][60],float sum[50][40][60])
{
  int r;
  int q;
  int p;
  int s;
{
    
    
    
    for (r = 0; r < 50; r++) {
      
      
      
      for (q = 0; q < 40; q++) {
        
        
        
        for (p = 0; p < 60; p++) {
          sum[r][q][p] = 0.0;
          
          for (s = 0; s < 60; s++) {
            sum[r][q][p] += A[r][q][s] * C4[s][p];
          }
        }
        
        for (p = 0; p < 60; p++) {
          A[r][q][p] = sum[r][q][p];
        }
      }
    }
  }
}

void kernel_nlp(float4 vA[30000], float4 vC4[900], float4 vsum[30000]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float A_ori[50][40][60];
    float A_new[50][40][60];
    float C4_ori[60][60];
    float C4_new[60][60];
    float sum_ori[50][40][60];
    float sum_new[50][40][60];
    for(int i0 = 0; i0 < 50; i0++){
        for(int i1 = 0; i1 < 40; i1++){
            for(int i2 = 0; i2 < 60; i2++){
                val = ((float)rand() / RAND_MAX);
                A_ori[i0][i1][i2] = val;
                A_new[i0][i1][i2] = val;
            }
        }
    }
    for(int i0 = 0; i0 < 60; i0++){
        for(int i1 = 0; i1 < 60; i1++){
            val = ((float)rand() / RAND_MAX);
            C4_ori[i0][i1] = val;
            C4_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 50; i0++){
        for(int i1 = 0; i1 < 40; i1++){
            for(int i2 = 0; i2 < 60; i2++){
                val = ((float)rand() / RAND_MAX);
                sum_ori[i0][i1][i2] = val;
                sum_new[i0][i1][i2] = val;
            }
        }
    }
    kernel_doitgen(A_ori, C4_ori, sum_ori);
    kernel_nlp((float4 *) A_new, (float4 *) C4_new, (float4 *) sum_new);
    for(int i0 = 0; i0 < 50; i0++){
        for(int i1 = 0; i1 < 40; i1++){
            for(int i2 = 0; i2 < 60; i2++){
                if(abs(A_ori[i0][i1][i2] - A_new[i0][i1][i2])/A_ori[i0][i1][i2] > 0.0001){
                    printf("Error in A[%d][%d][%d]...\n", i0, i1, i2);
                    return 1;
                }
            }
        }
    }
    for(int i0 = 0; i0 < 60; i0++){
        for(int i1 = 0; i1 < 60; i1++){
            if(abs(C4_ori[i0][i1] - C4_new[i0][i1])/C4_ori[i0][i1] > 0.0001){
                printf("Error in C4[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 50; i0++){
        for(int i1 = 0; i1 < 40; i1++){
            for(int i2 = 0; i2 < 60; i2++){
                if(abs(sum_ori[i0][i1][i2] - sum_new[i0][i1][i2])/sum_ori[i0][i1][i2] > 0.0001){
                    printf("Error in sum[%d][%d][%d]...\n", i0, i1, i2);
                    return 1;
                }
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
