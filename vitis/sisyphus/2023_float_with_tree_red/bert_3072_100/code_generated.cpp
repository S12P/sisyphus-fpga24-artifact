#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_C (float C[3072][100], float4 vC[76800]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 3072; i0+=1){
        for (int i1 = 0; i1 < 100; i1+=4){
#pragma HLS pipeline II=1
            float4 tmp_C = vC[i0 * 25 + i1/4];
            C[i0][i1 + 0] = tmp_C[0];
            C[i0][i1 + 1] = tmp_C[1];
            C[i0][i1 + 2] = tmp_C[2];
            C[i0][i1 + 3] = tmp_C[3];
        }
    }
}
void load_A_S1 (float A[48][3072], float16 vA[589824], int d0) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 48; i0+=1){
        for (int i1 = 0; i1 < 3072; i1+=16){
#pragma HLS pipeline II=1
            float16 tmp_A = vA[(i0 + d0 * 48) * 192 + i1/16];
            A[i0][i1 + 0] = tmp_A[0];
            A[i0][i1 + 1] = tmp_A[1];
            A[i0][i1 + 2] = tmp_A[2];
            A[i0][i1 + 3] = tmp_A[3];
            A[i0][i1 + 4] = tmp_A[4];
            A[i0][i1 + 5] = tmp_A[5];
            A[i0][i1 + 6] = tmp_A[6];
            A[i0][i1 + 7] = tmp_A[7];
            A[i0][i1 + 8] = tmp_A[8];
            A[i0][i1 + 9] = tmp_A[9];
            A[i0][i1 + 10] = tmp_A[10];
            A[i0][i1 + 11] = tmp_A[11];
            A[i0][i1 + 12] = tmp_A[12];
            A[i0][i1 + 13] = tmp_A[13];
            A[i0][i1 + 14] = tmp_A[14];
            A[i0][i1 + 15] = tmp_A[15];
        }
    }
}
void load_B (float B[3072][100], float4 vB[76800]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 3072; i0+=1){
        for (int i1 = 0; i1 < 100; i1+=4){
#pragma HLS pipeline II=1
            float4 tmp_B = vB[i0 * 25 + i1/4];
            B[i0][i1 + 0] = tmp_B[0];
            B[i0][i1 + 1] = tmp_B[1];
            B[i0][i1 + 2] = tmp_B[2];
            B[i0][i1 + 3] = tmp_B[3];
        }
    }
}
void store_C (float C[3072][100], float4 vC[76800]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 3072; i0+=1){
        for (int i1 = 0; i1 < 100; i1+=4){
#pragma HLS pipeline II=1
            float4 tmp_C;
            tmp_C[0] = C[i0][i1 + 0];
            tmp_C[1] = C[i0][i1 + 1];
            tmp_C[2] = C[i0][i1 + 2];
            tmp_C[3] = C[i0][i1 + 3];
            vC[i0 * 25 + i1/4] = tmp_C;
        }
    }
}

void task0(float C[3072][100], float4 vC[76800], float16 vA[589824], float4 vB[76800]) {
    int j;
    int i;
    for (int j0 = 0; j0 < 5; j0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int i1 = 0; i1 < 64; i1++) {
#pragma HLS pipeline
                for (int j2 = 0; j2 < 20; j2++) {
                    for (int i2 = 0; i2 < 48; i2++) {
                        j = j0 * 20 + j2;
                        i = i0 * 3072 + i1 * 48 + i2;
                        C[i][j] =0 ;
                     }
                }
            }
        }
    }
}

void task1(float A[48][3072], float B[3072][100], float C[3072][100], float4 vC[76800], float16 vA[589824], float4 vB[76800]) {
    int i;
    int k;
    int j;
    for (int i0 = 0; i0 < 64; i0++) {
        load_A_S1(A, vA, i0);
        for (int k0 = 0; k0 < 1; k0++) {
            for (int j0 = 0; j0 < 5; j0++) {
                for (int k1 = 0; k1 < 384; k1++) {
#pragma HLS pipeline
                    for (int i2 = 0; i2 < 48; i2++) {
                            for (int j2 = 0; j2 < 20; j2++) {
                        for (int k2 = 0; k2 < 8; k2++) {
                                i = i0 * 48 + i2;
                                k = k0 * 3072 + k1 * 8 + k2;
                                j = j0 * 20 + j2;
                                C[i][j] +=A[i2][k] * B[k][j] ;
                             }
                        }
                    }
                }
            }
        }
    }
}

void kernel_nlp(float4 vC[76800], float16 vA[589824], float4 vB[76800]) {

#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vB offset=slave bundle=kernel_B
#pragma HLS INTERFACE m_axi port=vC offset=slave bundle=kernel_C
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vB bundle=control
#pragma HLS INTERFACE s_axilite port=vC bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float A_S1[48][3072];
    float B[3072][100];
    float C[3072][100];

#pragma HLS ARRAY_PARTITION variable=A_S1 cyclic factor=48 dim=1
#pragma HLS ARRAY_PARTITION variable=A_S1 cyclic factor=8 dim=2
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=100 dim=2
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=48 dim=1
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=20 dim=2

    load_C(C, vC);
    load_B(B, vB);
    task0(C, vC, vA, vB);
    task1(A_S1, B, C, vC, vA, vB);
    store_C(C, vC);
}
