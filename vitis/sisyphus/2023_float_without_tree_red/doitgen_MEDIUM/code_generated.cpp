#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_sum (float sum[50][40][60], float4 vsum[30000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 50; i0+=1){
        for (int i1 = 0; i1 < 40; i1+=1){
            for (int i2 = 0; i2 < 60; i2+=4){
#pragma HLS pipeline II=1
                float4 tmp_sum = vsum[i0 * 600 + i1 * 15 + i2/4];
                sum[i0][i1][i2 + 0] = tmp_sum[0];
                sum[i0][i1][i2 + 1] = tmp_sum[1];
                sum[i0][i1][i2 + 2] = tmp_sum[2];
                sum[i0][i1][i2 + 3] = tmp_sum[3];
            }
        }
    }
}
void load_C4 (float C4[60][60], float4 vC4[900]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 60; i0+=1){
        for (int i1 = 0; i1 < 60; i1+=4){
#pragma HLS pipeline II=1
            float4 tmp_C4 = vC4[i0 * 15 + i1/4];
            C4[i0][i1 + 0] = tmp_C4[0];
            C4[i0][i1 + 1] = tmp_C4[1];
            C4[i0][i1 + 2] = tmp_C4[2];
            C4[i0][i1 + 3] = tmp_C4[3];
        }
    }
}
void load_A (float A[50][40][60], float4 vA[30000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 50; i0+=1){
        for (int i1 = 0; i1 < 40; i1+=1){
            for (int i2 = 0; i2 < 60; i2+=4){
#pragma HLS pipeline II=1
                float4 tmp_A = vA[i0 * 600 + i1 * 15 + i2/4];
                A[i0][i1][i2 + 0] = tmp_A[0];
                A[i0][i1][i2 + 1] = tmp_A[1];
                A[i0][i1][i2 + 2] = tmp_A[2];
                A[i0][i1][i2 + 3] = tmp_A[3];
            }
        }
    }
}
void store_sum (float sum[50][40][60], float4 vsum[30000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 50; i0+=1){
        for (int i1 = 0; i1 < 40; i1+=1){
            for (int i2 = 0; i2 < 60; i2+=4){
#pragma HLS pipeline II=1
                float4 tmp_sum;
                tmp_sum[0] = sum[i0][i1][i2 + 0];
                tmp_sum[1] = sum[i0][i1][i2 + 1];
                tmp_sum[2] = sum[i0][i1][i2 + 2];
                tmp_sum[3] = sum[i0][i1][i2 + 3];
                vsum[i0 * 600 + i1 * 15 + i2/4] = tmp_sum;
            }
        }
    }
}
void store_A (float A[50][40][60], float4 vA[30000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 50; i0+=1){
        for (int i1 = 0; i1 < 40; i1+=1){
            for (int i2 = 0; i2 < 60; i2+=4){
#pragma HLS pipeline II=1
                float4 tmp_A;
                tmp_A[0] = A[i0][i1][i2 + 0];
                tmp_A[1] = A[i0][i1][i2 + 1];
                tmp_A[2] = A[i0][i1][i2 + 2];
                tmp_A[3] = A[i0][i1][i2 + 3];
                vA[i0 * 600 + i1 * 15 + i2/4] = tmp_A;
            }
        }
    }
}

void task0(float sum[50][40][60], float4 vA[30000], float4 vC4[900], float4 vsum[30000]) {
    int r;
    int q;
    int p;
    for (int r0 = 0; r0 < 25; r0++) {
        for (int q0 = 0; q0 < 4; q0++) {
            for (int p0 = 0; p0 < 1; p0++) {
                for (int r1 = 0; r1 < 2; r1++) {
#pragma HLS pipeline
                    for (int r2 = 0; r2 < 1; r2++) {
                        for (int q2 = 0; q2 < 10; q2++) {
                            for (int p2 = 0; p2 < 60; p2++) {
                                r = r0 * 2 + r1 * 1 + r2;
                                q = q0 * 10 + q2;
                                p = p0 * 60 + p2;
                                sum[r][q][p] =0.0 ;
                             }
                        }
                    }
                }
            }
        }
    }
}

void task1(float sum[50][40][60], float C4[60][60], float A[50][40][60], float4 vA[30000], float4 vC4[900], float4 vsum[30000]) {
    int r;
    int q;
    int p;
    int s;
    for (int r0 = 0; r0 < 1; r0++) {
        for (int q0 = 0; q0 < 4; q0++) {
            for (int p0 = 0; p0 < 1; p0++) {
                for (int s0 = 0; s0 < 30; s0++) {
                    for (int r1 = 0; r1 < 50; r1++) {
#pragma HLS pipeline
                        for (int r2 = 0; r2 < 1; r2++) {
                            for (int q2 = 0; q2 < 10; q2++) {
                                for (int p2 = 0; p2 < 60; p2++) {
                                    for (int s2 = 0; s2 < 2; s2++) {
                                        r = r0 * 50 + r1 * 1 + r2;
                                        q = q0 * 10 + q2;
                                        p = p0 * 60 + p2;
                                        s = s0 * 2 + s2;
                                        sum[r][q][p] +=A[r][q][s] * C4[s][p] ;
                                     }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void task2(float sum[50][40][60], float A[50][40][60], float4 vA[30000], float4 vC4[900], float4 vsum[30000]) {
    int r;
    int q;
    int p;
    for (int r0 = 0; r0 < 1; r0++) {
        for (int q0 = 0; q0 < 4; q0++) {
            for (int p0 = 0; p0 < 1; p0++) {
                for (int r1 = 0; r1 < 50; r1++) {
#pragma HLS pipeline
                    for (int r2 = 0; r2 < 1; r2++) {
                        for (int q2 = 0; q2 < 10; q2++) {
                            for (int p2 = 0; p2 < 60; p2++) {
                                r = r0 * 50 + r1 * 1 + r2;
                                q = q0 * 10 + q2;
                                p = p0 * 60 + p2;
                                A[r][q][p] =sum[r][q][p] ;
                             }
                        }
                    }
                }
            }
        }
    }
}

void kernel_nlp(float4 vA[30000], float4 vC4[900], float4 vsum[30000]) {

#pragma HLS INTERFACE m_axi port=vsum offset=slave bundle=kernel_sum
#pragma HLS INTERFACE m_axi port=vC4 offset=slave bundle=kernel_C4
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE s_axilite port=vsum bundle=control
#pragma HLS INTERFACE s_axilite port=vC4 bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float sum[50][40][60];
    float C4[60][60];
    float A[50][40][60];

#pragma HLS ARRAY_PARTITION variable=sum cyclic factor=1 dim=1
#pragma HLS ARRAY_PARTITION variable=sum cyclic factor=10 dim=2
#pragma HLS ARRAY_PARTITION variable=sum cyclic factor=60 dim=3
#pragma HLS ARRAY_PARTITION variable=C4 cyclic factor=2 dim=1
#pragma HLS ARRAY_PARTITION variable=C4 cyclic factor=60 dim=2
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=1 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=10 dim=2
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=60 dim=3

    load_sum(sum, vsum);
    load_C4(C4, vC4);
    load_A(A, vA);
    task0(sum, vA, vC4, vsum);
    task1(sum, C4, A, vA, vC4, vsum);
    task2(sum, A, vA, vC4, vsum);
    store_sum(sum, vsum);
    store_A(A, vA);
}
