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



void kernel_nlp(float A[40][40][40], float B[40][40][40]) {

    int i;
    int j;
    int k;
    for ( i = 1; i < 39; i++) {
        for ( j = 1; j < 39; j++) {
            for ( k = 1; k < 39; k++) {
                B[i][j][k] = 0.125 * (A[i + 1][j][k] - 2.0 * A[i][j][k] + A[i - 1][j][k]) + 0.125 * (A[i][j + 1][k] - 2.0 * A[i][j][k] + A[i][j - 1][k]) + 0.125 * (A[i][j][k + 1] - 2.0 * A[i][j][k] + A[i][j][k - 1]) + A[i][j][k];
            }
        }
    }
    for ( i = 1; i < 39; i++) {
        for ( j = 1; j < 39; j++) {
            for ( k = 1; k < 39; k++) {
                A[i][j][k] = 0.125 * (B[i + 1][j][k] - 2.0 * B[i][j][k] + B[i - 1][j][k]) + 0.125 * (B[i][j + 1][k] - 2.0 * B[i][j][k] + B[i][j - 1][k]) + 0.125 * (B[i][j][k + 1] - 2.0 * B[i][j][k] + B[i][j][k - 1]) + B[i][j][k];
            }
        }
    }
}
