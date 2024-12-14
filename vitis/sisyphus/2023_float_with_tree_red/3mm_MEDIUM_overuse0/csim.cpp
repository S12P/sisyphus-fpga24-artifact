#include <hls_vector.h>
#include <cstring>
#include <ap_int.h>
#include <hls_stream.h>
#include "code_generated.h"

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

#pragma ACCEL kernel

void kernel_3mm(float E[180][190],float A[180][200],float B[200][190],float F[190][210],float C[190][220],float D[220][210],float G[180][210])
{
  int i;
  int j;
  int k;
{
    
    
    
    for (i = 0; i < 180; i++) {
      
      
      
      for (j = 0; j < 190; j++) {
        E[i][j] = 0.0;
        
        for (k = 0; k < 200; ++k) {
          E[i][j] += A[i][k] * B[k][j];
        }
      }
    }
    
    
    
    for (i = 0; i < 190; i++) {
      
      
      
      for (j = 0; j < 210; j++) {
        F[i][j] = 0.0;
        
        for (k = 0; k < 220; ++k) {
          F[i][j] += C[i][k] * D[k][j];
        }
      }
    }
    
    
    
    for (i = 0; i < 180; i++) {
      
      
      
      for (j = 0; j < 210; j++) {
        G[i][j] = 0.0;
        
        for (k = 0; k < 190; ++k) {
          G[i][j] += E[i][k] * F[k][j];
        }
      }
    }
  }
}

void kernel_nlp(float2 vE[17100], float8 vA[4500], float2 vB[19000], float2 vF[19950], float4 vC[10450], float2 vD[23100], float2 vG[18900]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float E_ori[180][190];
    float E_new[180][190];
    float A_ori[180][200];
    float A_new[180][200];
    float B_ori[200][190];
    float B_new[200][190];
    float F_ori[190][210];
    float F_new[190][210];
    float C_ori[190][220];
    float C_new[190][220];
    float D_ori[220][210];
    float D_new[220][210];
    float G_ori[180][210];
    float G_new[180][210];
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 190; i1++){
            val = ((float)rand() / RAND_MAX);
            E_ori[i0][i1] = val;
            E_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 200; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 190; i1++){
            val = ((float)rand() / RAND_MAX);
            B_ori[i0][i1] = val;
            B_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 190; i0++){
        for(int i1 = 0; i1 < 210; i1++){
            val = ((float)rand() / RAND_MAX);
            F_ori[i0][i1] = val;
            F_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 190; i0++){
        for(int i1 = 0; i1 < 220; i1++){
            val = ((float)rand() / RAND_MAX);
            C_ori[i0][i1] = val;
            C_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 220; i0++){
        for(int i1 = 0; i1 < 210; i1++){
            val = ((float)rand() / RAND_MAX);
            D_ori[i0][i1] = val;
            D_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 210; i1++){
            val = ((float)rand() / RAND_MAX);
            G_ori[i0][i1] = val;
            G_new[i0][i1] = val;
        }
    }
    kernel_3mm(E_ori, A_ori, B_ori, F_ori, C_ori, D_ori, G_ori);
    kernel_nlp((float2 *) E_new, (float8 *) A_new, (float2 *) B_new, (float2 *) F_new, (float4 *) C_new, (float2 *) D_new, (float2 *) G_new);
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 190; i1++){
            if(abs(E_ori[i0][i1] - E_new[i0][i1])/E_ori[i0][i1] > 0.0001){
                printf("Error in E[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 200; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 200; i0++){
        for(int i1 = 0; i1 < 190; i1++){
            if(abs(B_ori[i0][i1] - B_new[i0][i1])/B_ori[i0][i1] > 0.0001){
                printf("Error in B[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 190; i0++){
        for(int i1 = 0; i1 < 210; i1++){
            if(abs(F_ori[i0][i1] - F_new[i0][i1])/F_ori[i0][i1] > 0.0001){
                printf("Error in F[%d][%d]...\n", i0, i1);
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
    for(int i0 = 0; i0 < 220; i0++){
        for(int i1 = 0; i1 < 210; i1++){
            if(abs(D_ori[i0][i1] - D_new[i0][i1])/D_ori[i0][i1] > 0.0001){
                printf("Error in D[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 180; i0++){
        for(int i1 = 0; i1 < 210; i1++){
            if(abs(G_ori[i0][i1] - G_new[i0][i1])/G_ori[i0][i1] > 0.0001){
                printf("Error in G[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
