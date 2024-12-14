#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_B (float B[250][250], float2 vB[31250]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 250; i0+=1){
        for (int i1 = 0; i1 < 250; i1+=2){
#pragma HLS pipeline II=1
            float2 tmp_B = vB[i0 * 125 + i1/2];
            B[i0][i1 + 0] = tmp_B[0];
            B[i0][i1 + 1] = tmp_B[1];
        }
    }
}
void load_A (float A[250][250], float2 vA[31250]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 250; i0+=1){
        for (int i1 = 0; i1 < 250; i1+=2){
#pragma HLS pipeline II=1
            float2 tmp_A = vA[i0 * 125 + i1/2];
            A[i0][i1 + 0] = tmp_A[0];
            A[i0][i1 + 1] = tmp_A[1];
        }
    }
}
void store_B (float B[250][250], float2 vB[31250]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 250; i0+=1){
        for (int i1 = 0; i1 < 250; i1+=2){
#pragma HLS pipeline II=1
            float2 tmp_B;
            tmp_B[0] = B[i0][i1 + 0];
            tmp_B[1] = B[i0][i1 + 1];
            vB[i0 * 125 + i1/2] = tmp_B;
        }
    }
}
void store_A (float A[250][250], float2 vA[31250]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 250; i0+=1){
        for (int i1 = 0; i1 < 250; i1+=2){
#pragma HLS pipeline II=1
            float2 tmp_A;
            tmp_A[0] = A[i0][i1 + 0];
            tmp_A[1] = A[i0][i1 + 1];
            vA[i0 * 125 + i1/2] = tmp_A;
        }
    }
}

void task0(float B[250][250], float A[250][250], float2 vA[31250], float2 vB[31250]) {
    int i;
    int j;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int j1 = 0; j1 < 249; j1++) {
#pragma HLS pipeline
                for (int i2 = 0; i2 < 249; i2++) {
                    for (int j2 = 0; j2 < 1; j2++) {
                        i = i0 * 249 + i2;
                        j = j0 * 249 + j1 * 1 + j2;
                        B[i][j] =0.2 * (A[i][j] + A[i][j-1] + A[i][1+j] + A[1+i][j] + A[i-1][j]) ;
                     }
                }
            }
        }
    }
}

void task1(float B[250][250], float A[250][250], float2 vA[31250], float2 vB[31250]) {
    int j;
    int i;
    for (int j0 = 0; j0 < 1; j0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int j1 = 0; j1 < 249; j1++) {
#pragma HLS pipeline
                for (int j2 = 0; j2 < 1; j2++) {
                    for (int i2 = 0; i2 < 249; i2++) {
                        j = j0 * 249 + j1 * 1 + j2;
                        i = i0 * 249 + i2;
                        A[i][j] =0.2 * (B[i][j] + B[i][j-1] + B[i][1+j] + B[1+i][j] + B[i-1][j]) ;
                     }
                }
            }
        }
    }
}

void kernel_nlp(float2 vA[31250], float2 vB[31250]) {

#pragma HLS INTERFACE m_axi port=vB offset=slave bundle=kernel_B
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE s_axilite port=vB bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float B[250][250];
    float A[250][250];

#pragma HLS ARRAY_PARTITION variable=B cyclic factor=249 dim=1
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=4 dim=2
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=249 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=4 dim=2

    load_B(B, vB);
    load_A(A, vA);
    task0(B, A, vA, vB);
    task1(B, A, vA, vB);
    store_B(B, vB);
    store_A(A, vA);
}
