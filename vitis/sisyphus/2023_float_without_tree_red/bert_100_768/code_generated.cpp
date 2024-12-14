#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_C (float C[100][768], float16 vC[4800]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 100; i0+=1){
        for (int i1 = 0; i1 < 768; i1+=16){
#pragma HLS pipeline II=1
            float16 tmp_C = vC[i0 * 48 + i1/16];
            C[i0][i1 + 0] = tmp_C[0];
            C[i0][i1 + 1] = tmp_C[1];
            C[i0][i1 + 2] = tmp_C[2];
            C[i0][i1 + 3] = tmp_C[3];
            C[i0][i1 + 4] = tmp_C[4];
            C[i0][i1 + 5] = tmp_C[5];
            C[i0][i1 + 6] = tmp_C[6];
            C[i0][i1 + 7] = tmp_C[7];
            C[i0][i1 + 8] = tmp_C[8];
            C[i0][i1 + 9] = tmp_C[9];
            C[i0][i1 + 10] = tmp_C[10];
            C[i0][i1 + 11] = tmp_C[11];
            C[i0][i1 + 12] = tmp_C[12];
            C[i0][i1 + 13] = tmp_C[13];
            C[i0][i1 + 14] = tmp_C[14];
            C[i0][i1 + 15] = tmp_C[15];
        }
    }
}
void load_B (float B[100][768], float16 vB[4800]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 100; i0+=1){
        for (int i1 = 0; i1 < 768; i1+=16){
#pragma HLS pipeline II=1
            float16 tmp_B = vB[i0 * 48 + i1/16];
            B[i0][i1 + 0] = tmp_B[0];
            B[i0][i1 + 1] = tmp_B[1];
            B[i0][i1 + 2] = tmp_B[2];
            B[i0][i1 + 3] = tmp_B[3];
            B[i0][i1 + 4] = tmp_B[4];
            B[i0][i1 + 5] = tmp_B[5];
            B[i0][i1 + 6] = tmp_B[6];
            B[i0][i1 + 7] = tmp_B[7];
            B[i0][i1 + 8] = tmp_B[8];
            B[i0][i1 + 9] = tmp_B[9];
            B[i0][i1 + 10] = tmp_B[10];
            B[i0][i1 + 11] = tmp_B[11];
            B[i0][i1 + 12] = tmp_B[12];
            B[i0][i1 + 13] = tmp_B[13];
            B[i0][i1 + 14] = tmp_B[14];
            B[i0][i1 + 15] = tmp_B[15];
        }
    }
}
void load_A (float A[100][100], float4 vA[2500]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 100; i0+=1){
        for (int i1 = 0; i1 < 100; i1+=4){
#pragma HLS pipeline II=1
            float4 tmp_A = vA[i0 * 25 + i1/4];
            A[i0][i1 + 0] = tmp_A[0];
            A[i0][i1 + 1] = tmp_A[1];
            A[i0][i1 + 2] = tmp_A[2];
            A[i0][i1 + 3] = tmp_A[3];
        }
    }
}
void store_C (float C[100][768], float16 vC[4800]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 100; i0+=1){
        for (int i1 = 0; i1 < 768; i1+=16){
#pragma HLS pipeline II=1
            float16 tmp_C;
            tmp_C[0] = C[i0][i1 + 0];
            tmp_C[1] = C[i0][i1 + 1];
            tmp_C[2] = C[i0][i1 + 2];
            tmp_C[3] = C[i0][i1 + 3];
            tmp_C[4] = C[i0][i1 + 4];
            tmp_C[5] = C[i0][i1 + 5];
            tmp_C[6] = C[i0][i1 + 6];
            tmp_C[7] = C[i0][i1 + 7];
            tmp_C[8] = C[i0][i1 + 8];
            tmp_C[9] = C[i0][i1 + 9];
            tmp_C[10] = C[i0][i1 + 10];
            tmp_C[11] = C[i0][i1 + 11];
            tmp_C[12] = C[i0][i1 + 12];
            tmp_C[13] = C[i0][i1 + 13];
            tmp_C[14] = C[i0][i1 + 14];
            tmp_C[15] = C[i0][i1 + 15];
            vC[i0 * 48 + i1/16] = tmp_C;
        }
    }
}

void task0(float C[100][768], float16 vC[4800], float4 vA[2500], float16 vB[4800]) {
    int j;
    int i;
    for (int j0 = 0; j0 < 48; j0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int i1 = 0; i1 < 2; i1++) {
#pragma HLS pipeline
                for (int j2 = 0; j2 < 16; j2++) {
                    for (int i2 = 0; i2 < 50; i2++) {
                        j = j0 * 16 + j2;
                        i = i0 * 100 + i1 * 50 + i2;
                        C[i][j] =0 ;
                     }
                }
            }
        }
    }
}

void task1(float B[100][768], float C[100][768], float A[100][100], float16 vC[4800], float4 vA[2500], float16 vB[4800]) {
    int i;
    int j;
    int k;
    for (int i0 = 0; i0 < 2; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int k0 = 0; k0 < 5; k0++) {
                for (int j1 = 0; j1 < 768; j1++) {
#pragma HLS pipeline
                    for (int i2 = 0; i2 < 50; i2++) {
                        for (int j2 = 0; j2 < 1; j2++) {
                            for (int k2 = 0; k2 < 20; k2++) {
                                i = i0 * 50 + i2;
                                j = j0 * 768 + j1 * 1 + j2;
                                k = k0 * 20 + k2;
                                C[i][j] +=A[i][k] * B[k][j] ;
                             }
                        }
                    }
                }
            }
        }
    }
}

void kernel_nlp(float16 vC[4800], float4 vA[2500], float16 vB[4800]) {

#pragma HLS INTERFACE m_axi port=vB offset=slave bundle=kernel_B
#pragma HLS INTERFACE m_axi port=vC offset=slave bundle=kernel_C
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE s_axilite port=vB bundle=control
#pragma HLS INTERFACE s_axilite port=vC bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float B[100][768];
    float C[100][768];
    float A[100][100];

#pragma HLS ARRAY_PARTITION variable=B cyclic factor=20 dim=1
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=16 dim=2
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=50 dim=1
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=16 dim=2
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=50 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=20 dim=2

    load_C(C, vC);
    load_B(B, vB);
    load_A(A, vA);
    task0(C, vC, vA, vB);
    task1(B, C, A, vC, vA, vB);
    store_C(C, vC);
}
