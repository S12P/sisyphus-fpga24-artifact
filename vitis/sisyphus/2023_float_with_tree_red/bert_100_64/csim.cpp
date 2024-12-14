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



void kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
    int i;
    int j;
    int k;
    
    for (i = 0; i < 100; i++) {
        
        for (j = 0; j < 64; j++) {
            C[i][j] = 0;
            for (k = 0; k < 100; k++) {
                C[i][j] +=  A[i][k] * B[k][j];
            }
        }
    }
}


void kernel_nlp(float16 vC[400], float4 vA[2500], float16 vB[400]) ;

int main(){
    printf("Starting C-simulation...\n");
    float val;
    float C_ori[100][64];
    float C_new[100][64];
    float A_ori[100][100];
    float A_new[100][100];
    float B_ori[100][64];
    float B_new[100][64];
    for(int i0 = 0; i0 < 100; i0++){
        for(int i1 = 0; i1 < 64; i1++){
            val = ((float)rand() / RAND_MAX);
            C_ori[i0][i1] = val;
            C_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 100; i0++){
        for(int i1 = 0; i1 < 100; i1++){
            val = ((float)rand() / RAND_MAX);
            A_ori[i0][i1] = val;
            A_new[i0][i1] = val;
        }
    }
    for(int i0 = 0; i0 < 100; i0++){
        for(int i1 = 0; i1 < 64; i1++){
            val = ((float)rand() / RAND_MAX);
            B_ori[i0][i1] = val;
            B_new[i0][i1] = val;
        }
    }
    kernel_gemm(C_ori, A_ori, B_ori);
    kernel_nlp((float16 *) C_new, (float4 *) A_new, (float16 *) B_new);
    for(int i0 = 0; i0 < 100; i0++){
        for(int i1 = 0; i1 < 64; i1++){
            if(abs(C_ori[i0][i1] - C_new[i0][i1])/C_ori[i0][i1] > 0.0001){
                printf("Error in C[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 100; i0++){
        for(int i1 = 0; i1 < 100; i1++){
            if(abs(A_ori[i0][i1] - A_new[i0][i1])/A_ori[i0][i1] > 0.0001){
                printf("Error in A[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    for(int i0 = 0; i0 < 100; i0++){
        for(int i1 = 0; i1 < 64; i1++){
            if(abs(B_ori[i0][i1] - B_new[i0][i1])/B_ori[i0][i1] > 0.0001){
                printf("Error in B[%d][%d]...\n", i0, i1);
                return 1;
            }
        }
    }
    printf("C-simulation passed!\n");
    return 0;
}
