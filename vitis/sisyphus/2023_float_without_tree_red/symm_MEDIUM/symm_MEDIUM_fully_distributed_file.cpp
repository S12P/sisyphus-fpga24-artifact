#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

/*************************************************
 This file was automatically generated by Sisyphus
*************************************************/

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;



void kernel_nlp(float temp2[200][240], float C[200][240], float A[200][200], float B[200][240]) {

    int j;
    int i;
    int k;
    for ( i = 0; i < 200; i++) {
        for ( j = 0; j < 240; j++) {
            temp2[i][j] = 0;
        }
    }
    for ( i = 0; i < 200; i++) {
        for ( j = 0; j < 240; j++) {
            for ( k = 0; k < i; k++) {
                temp2[i][j] += B[k][j] * A[i][k];
            }
        }
    }
    for ( i = 0; i < 200; i++) {
        for ( j = 0; j < 240; j++) {
            C[i][j] = beta * C[i][j] + alpha * B[i][j] * A[i][i] + alpha * temp2[i][j];
        }
    }
    for ( i = 0; i < 200; i++) {
        for ( j = 0; j < 240; j++) {
            for ( k = 0; k < i; k++) {
                C[k][j] += alpha * B[i][j] * A[i][k];
            }
        }
    }
}
