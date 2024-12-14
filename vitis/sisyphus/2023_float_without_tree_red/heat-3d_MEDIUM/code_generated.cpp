#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_A (float A[40][40][40], float8 vA[8000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 40; i0+=1){
        for (int i1 = 0; i1 < 40; i1+=1){
            for (int i2 = 0; i2 < 40; i2+=8){
#pragma HLS pipeline II=1
                float8 tmp_A = vA[i0 * 200 + i1 * 5 + i2/8];
                A[i0][i1][i2 + 0] = tmp_A[0];
                A[i0][i1][i2 + 1] = tmp_A[1];
                A[i0][i1][i2 + 2] = tmp_A[2];
                A[i0][i1][i2 + 3] = tmp_A[3];
                A[i0][i1][i2 + 4] = tmp_A[4];
                A[i0][i1][i2 + 5] = tmp_A[5];
                A[i0][i1][i2 + 6] = tmp_A[6];
                A[i0][i1][i2 + 7] = tmp_A[7];
            }
        }
    }
}
void load_B (float B[40][40][40], float8 vB[8000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 40; i0+=1){
        for (int i1 = 0; i1 < 40; i1+=1){
            for (int i2 = 0; i2 < 40; i2+=8){
#pragma HLS pipeline II=1
                float8 tmp_B = vB[i0 * 200 + i1 * 5 + i2/8];
                B[i0][i1][i2 + 0] = tmp_B[0];
                B[i0][i1][i2 + 1] = tmp_B[1];
                B[i0][i1][i2 + 2] = tmp_B[2];
                B[i0][i1][i2 + 3] = tmp_B[3];
                B[i0][i1][i2 + 4] = tmp_B[4];
                B[i0][i1][i2 + 5] = tmp_B[5];
                B[i0][i1][i2 + 6] = tmp_B[6];
                B[i0][i1][i2 + 7] = tmp_B[7];
            }
        }
    }
}
void store_B (float B[40][40][40], float8 vB[8000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 40; i0+=1){
        for (int i1 = 0; i1 < 40; i1+=1){
            for (int i2 = 0; i2 < 40; i2+=8){
#pragma HLS pipeline II=1
                float8 tmp_B;
                tmp_B[0] = B[i0][i1][i2 + 0];
                tmp_B[1] = B[i0][i1][i2 + 1];
                tmp_B[2] = B[i0][i1][i2 + 2];
                tmp_B[3] = B[i0][i1][i2 + 3];
                tmp_B[4] = B[i0][i1][i2 + 4];
                tmp_B[5] = B[i0][i1][i2 + 5];
                tmp_B[6] = B[i0][i1][i2 + 6];
                tmp_B[7] = B[i0][i1][i2 + 7];
                vB[i0 * 200 + i1 * 5 + i2/8] = tmp_B;
            }
        }
    }
}
void store_A (float A[40][40][40], float8 vA[8000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 40; i0+=1){
        for (int i1 = 0; i1 < 40; i1+=1){
            for (int i2 = 0; i2 < 40; i2+=8){
#pragma HLS pipeline II=1
                float8 tmp_A;
                tmp_A[0] = A[i0][i1][i2 + 0];
                tmp_A[1] = A[i0][i1][i2 + 1];
                tmp_A[2] = A[i0][i1][i2 + 2];
                tmp_A[3] = A[i0][i1][i2 + 3];
                tmp_A[4] = A[i0][i1][i2 + 4];
                tmp_A[5] = A[i0][i1][i2 + 5];
                tmp_A[6] = A[i0][i1][i2 + 6];
                tmp_A[7] = A[i0][i1][i2 + 7];
                vA[i0 * 200 + i1 * 5 + i2/8] = tmp_A;
            }
        }
    }
}

void task0(float A[40][40][40], float B[40][40][40], float8 vA[8000], float8 vB[8000]) {
    int k;
    int i;
    int j;
    for (int k0 = 0; k0 < 13; k0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int j0 = 0; j0 < 1; j0++) {
                for (int j1 = 0; j1 < 39; j1++) {
#pragma HLS pipeline
                    for (int k2 = 0; k2 < 3; k2++) {
                        for (int i2 = 0; i2 < 39; i2++) {
                            for (int j2 = 0; j2 < 1; j2++) {
                                k = k0 * 3 + k2;
                                i = i0 * 39 + i2;
                                j = j0 * 39 + j1 * 1 + j2;
                                B[i][j][k] =0.125 * (A[i+1][j][k] - 2.0 * A[i][j][k] + A[i-1][j][k] + ) * 0.125 - (A[i][j+1][k] * 2.0 + A[i][j][k] + A[i][j-1][k] * ) - 0.125 * (A[i][j][k+1] + 2.0 + A[i][j][k] ;
 A[i][j][k-1] ) A[i][j][k]                             }
                        }
                    }
                }
            }
        }
    }
}

void task1(float A[40][40][40], float B[40][40][40], float8 vA[8000], float8 vB[8000]) {
    int k;
    int i;
    int j;
    for (int k0 = 0; k0 < 13; k0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int j0 = 0; j0 < 1; j0++) {
                for (int j1 = 0; j1 < 39; j1++) {
#pragma HLS pipeline
                    for (int k2 = 0; k2 < 3; k2++) {
                        for (int i2 = 0; i2 < 39; i2++) {
                            for (int j2 = 0; j2 < 1; j2++) {
                                k = k0 * 3 + k2;
                                i = i0 * 39 + i2;
                                j = j0 * 39 + j1 * 1 + j2;
                                A[i][j][k] =0.125 * (B[i+1][j][k] - 2.0 * B[i][j][k] + B[i-1][j][k] + ) * 0.125 - (B[i][j+1][k] * 2.0 + B[i][j][k] + B[i][j-1][k] * ) - 0.125 * (B[i][j][k+1] + 2.0 + B[i][j][k] ;
 B[i][j][k-1] ) B[i][j][k]                             }
                        }
                    }
                }
            }
        }
    }
}

void kernel_nlp(float8 vA[8000], float8 vB[8000]) {

#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vB offset=slave bundle=kernel_B
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vB bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float A[40][40][40];
    float B[40][40][40];

#pragma HLS ARRAY_PARTITION variable=A cyclic factor=39 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=1 dim=2
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=24 dim=3
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=39 dim=1
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=1 dim=2
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=24 dim=3

    load_A(A, vA);
    load_B(B, vB);
    task0(A, B, vA, vB);
    task1(A, B, vA, vB);
    store_B(B, vB);
    store_A(A, vA);
}
