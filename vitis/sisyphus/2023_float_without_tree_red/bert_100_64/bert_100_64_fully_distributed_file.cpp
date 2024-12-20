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



void kernel_nlp(float C[100][64], float A[100][100], float B[100][64]) {

    int j;
    int k;
    int i;
    for ( i = 0; i < 100; i++) {
        for ( j = 0; j < 64; j++) {
            C[i][j] = 0;
        }
    }
    for ( i = 0; i < 100; i++) {
        for ( j = 0; j < 64; j++) {
            for ( k = 0; k < 100; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
