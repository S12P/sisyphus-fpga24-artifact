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
void load_A_S1 (float A[3072][6], float2 vA[4718592], int d1) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 3072; i0+=1){
        for (int i1 = 0; i1 < 6; i1+=2){
#pragma HLS pipeline II=1
            float2 tmp_A = vA[i0 * 1536 + (i1 + d1 * 6)/2];
            A[i0][i1 + 0] = tmp_A[0];
            A[i0][i1 + 1] = tmp_A[1];
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

void task0(float C[3072][100], float4 vC[76800], float2 vA[4718592], float4 vB[76800]) {
    int i;
    int j;
    for (int i0 = 0; i0 < 3; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int i1 = 0; i1 < 128; i1++) {
#pragma HLS pipeline
                for (int i2 = 0; i2 < 8; i2++) {
                    for (int j2 = 0; j2 < 100; j2++) {
                        i = i0 * 1024 + i1 * 8 + i2;
                        j = j0 * 100 + j2;
                        C[i][j] =0 ;
                     }
                }
            }
        }
    }
}

void task1(float C[3072][100], float B[3072][100], float A[3072][6], float4 vC[76800], float2 vA[4718592], float4 vB[76800]) {
    int k;
    int j;
    int i;
    for (int k0 = 0; k0 < 512; k0++) {
        load_A_S1(A, vA, k0);
        for (int j0 = 0; j0 < 1; j0++) {
            for (int i0 = 0; i0 < 1; i0++) {
                for (int i1 = 0; i1 < 1536; i1++) {
#pragma HLS pipeline
                        for (int j2 = 0; j2 < 100; j2++) {
                            for (int i2 = 0; i2 < 2; i2++) {
                    for (int k2 = 0; k2 < 6; k2++) {
                                k = k0 * 6 + k2;
                                j = j0 * 100 + j2;
                                i = i0 * 3072 + i1 * 2 + i2;
                                C[i][j] +=A[i][k2] * B[k][j] ;
                             }
                        }
                    }
                }
            }
        }
    }
}

void kernel_nlp(float4 vC[76800], float2 vA[4718592], float4 vB[76800]) {

#pragma HLS INTERFACE m_axi port=vC offset=slave bundle=kernel_C
#pragma HLS INTERFACE m_axi port=vB offset=slave bundle=kernel_B
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE s_axilite port=vC bundle=control
#pragma HLS INTERFACE s_axilite port=vB bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float C[3072][100];
    float B[3072][100];
    float A_S1[3072][6];

#pragma HLS ARRAY_PARTITION variable=C cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=100 dim=2
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=6 dim=1
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=100 dim=2
#pragma HLS ARRAY_PARTITION variable=A_S1 cyclic factor=2 dim=1
#pragma HLS ARRAY_PARTITION variable=A_S1 cyclic factor=6 dim=2

    load_C(C, vC);
    load_B(B, vB);
    task0(C, vC, vA, vB);
    task1(C, B, A_S1, vC, vA, vB);
    store_C(C, vC);
}
