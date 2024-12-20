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



void kernel_nlp(float C[200][220], float A[200][240], float B[240][220]) {

    int j;
    int i;
    int k;
    for ( i = 0; i < 200; i++) {
        for ( j = 0; j < 220; j++) {
            C[i][j] *= beta;
        }
    }
    for ( i = 0; i < 200; i++) {
        for ( j = 0; j < 220; j++) {
            for ( k = 0; k < 240; k++) {
                C[i][j] += alpha * A[i][k] * B[k][j];
            }
        }
    }
}
