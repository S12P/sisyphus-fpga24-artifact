#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

void load_C (double C[200][220], double4 vC[11000]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 200; i0+=1){
        for (int i1 = 0; i1 < 220; i1+=4){
#pragma HLS pipeline II=1
            double4 tmp_C = vC[i0 * 55 + i1/4];
            C[i0][i1 + 0] = tmp_C[0];
            C[i0][i1 + 1] = tmp_C[1];
            C[i0][i1 + 2] = tmp_C[2];
            C[i0][i1 + 3] = tmp_C[3];
        }
    }
}
void load_B (double B[240][220], double4 vB[13200]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 240; i0+=1){
        for (int i1 = 0; i1 < 220; i1+=4){
#pragma HLS pipeline II=1
            double4 tmp_B = vB[i0 * 55 + i1/4];
            B[i0][i1 + 0] = tmp_B[0];
            B[i0][i1 + 1] = tmp_B[1];
            B[i0][i1 + 2] = tmp_B[2];
            B[i0][i1 + 3] = tmp_B[3];
        }
    }
}
void load_A (double A[200][240], double16 vA[3000]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 200; i0+=1){
        for (int i1 = 0; i1 < 240; i1+=16){
#pragma HLS pipeline II=1
            double16 tmp_A = vA[i0 * 15 + i1/16];
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
void store_C (double C[200][220], double4 vC[11000]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 200; i0+=1){
        for (int i1 = 0; i1 < 220; i1+=4){
#pragma HLS pipeline II=1
            double4 tmp_C;
            tmp_C[0] = C[i0][i1 + 0];
            tmp_C[1] = C[i0][i1 + 1];
            tmp_C[2] = C[i0][i1 + 2];
            tmp_C[3] = C[i0][i1 + 3];
            vC[i0 * 55 + i1/4] = tmp_C;
        }
    }
}

void task0(double C[200][220], double alpha, double beta, double4 vC[11000], double16 vA[3000], double4 vB[13200]) {
#pragma HLS inline
    int i;
    int j;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 5; j0++) {
            for (int i1 = 0; i1 < 25; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 8; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 44; j2++) {
#pragma HLS unroll
                        i = i0 * 200 + i1 * 8 + i2;
                        j = j0 * 44 + j2;
                        C[i][j] *=beta ;
                     }
                }
            }
        }
    }
}

void task1(double B[240][220], double C[200][220], double A[200][240], double alpha, double beta, double4 vC[11000], double16 vA[3000], double4 vB[13200]) {
#pragma HLS inline
    int i;
    int j;
    int k;
    for (int i0 = 0; i0 < 25; i0++) {
        for (int j0 = 0; j0 < 5; j0++) {
            for (int k0 = 0; k0 < 1; k0++) {
                for (int k1 = 0; k1 < 60; k1++) {
#pragma HLS pipeline II=4
                    for (int i2 = 0; i2 < 8; i2++) {
#pragma HLS unroll
                        for (int j2 = 0; j2 < 44; j2++) {
#pragma HLS unroll
                            for (int k2 = 0; k2 < 4; k2++) {
#pragma HLS unroll
                                i = i0 * 8 + i2;
                                j = j0 * 44 + j2;
                                k = k0 * 240 + k1 * 4 + k2;
                                C[i][j] +=alpha * A[i][k] * B[k][j] ;
                             }
                        }
                    }
                }
            }
        }
    }
}

void kernel_nlp(double alpha, double beta, double4 vC[11000], double16 vA[3000], double4 vB[13200]) {

#pragma HLS INTERFACE m_axi port=alpha offset=slave bundle=kernel_alpha
#pragma HLS INTERFACE m_axi port=beta offset=slave bundle=kernel_beta
#pragma HLS INTERFACE m_axi port=vB offset=slave bundle=kernel_B
#pragma HLS INTERFACE m_axi port=vC offset=slave bundle=kernel_C
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
#pragma HLS INTERFACE s_axilite port=beta bundle=control
#pragma HLS INTERFACE s_axilite port=vB bundle=control
#pragma HLS INTERFACE s_axilite port=vC bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    double B[240][220];
    double C[200][220];
    double A[200][240];

#pragma HLS ARRAY_PARTITION variable=B cyclic factor=4 dim=1
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=44 dim=2
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=88 dim=2
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=8 dim=2

    load_C(C, vC);
    load_B(B, vB);
    load_A(A, vA);
    task0(C, alpha, beta, vC, vA, vB);
    task1(B, C, A, alpha, beta, vC, vA, vB);
    store_C(C, vC);
}
