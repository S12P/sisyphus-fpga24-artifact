#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

void load_A (double A[400][400], double16 vA[10000]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=1){
        for (int i1 = 0; i1 < 400; i1+=16){
#pragma HLS pipeline II=1
            double16 tmp_A = vA[i0 * 25 + i1/16];
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
void load_y_1 (double y_1[400], double16 vy_1[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_y_1 = vy_1[i0/16];
        y_1[i0 + 0] = tmp_y_1[0];
        y_1[i0 + 1] = tmp_y_1[1];
        y_1[i0 + 2] = tmp_y_1[2];
        y_1[i0 + 3] = tmp_y_1[3];
        y_1[i0 + 4] = tmp_y_1[4];
        y_1[i0 + 5] = tmp_y_1[5];
        y_1[i0 + 6] = tmp_y_1[6];
        y_1[i0 + 7] = tmp_y_1[7];
        y_1[i0 + 8] = tmp_y_1[8];
        y_1[i0 + 9] = tmp_y_1[9];
        y_1[i0 + 10] = tmp_y_1[10];
        y_1[i0 + 11] = tmp_y_1[11];
        y_1[i0 + 12] = tmp_y_1[12];
        y_1[i0 + 13] = tmp_y_1[13];
        y_1[i0 + 14] = tmp_y_1[14];
        y_1[i0 + 15] = tmp_y_1[15];
    }
}
void load_x1 (double x1[400], double16 vx1[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_x1 = vx1[i0/16];
        x1[i0 + 0] = tmp_x1[0];
        x1[i0 + 1] = tmp_x1[1];
        x1[i0 + 2] = tmp_x1[2];
        x1[i0 + 3] = tmp_x1[3];
        x1[i0 + 4] = tmp_x1[4];
        x1[i0 + 5] = tmp_x1[5];
        x1[i0 + 6] = tmp_x1[6];
        x1[i0 + 7] = tmp_x1[7];
        x1[i0 + 8] = tmp_x1[8];
        x1[i0 + 9] = tmp_x1[9];
        x1[i0 + 10] = tmp_x1[10];
        x1[i0 + 11] = tmp_x1[11];
        x1[i0 + 12] = tmp_x1[12];
        x1[i0 + 13] = tmp_x1[13];
        x1[i0 + 14] = tmp_x1[14];
        x1[i0 + 15] = tmp_x1[15];
    }
}
void load_x2 (double x2[400], double16 vx2[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_x2 = vx2[i0/16];
        x2[i0 + 0] = tmp_x2[0];
        x2[i0 + 1] = tmp_x2[1];
        x2[i0 + 2] = tmp_x2[2];
        x2[i0 + 3] = tmp_x2[3];
        x2[i0 + 4] = tmp_x2[4];
        x2[i0 + 5] = tmp_x2[5];
        x2[i0 + 6] = tmp_x2[6];
        x2[i0 + 7] = tmp_x2[7];
        x2[i0 + 8] = tmp_x2[8];
        x2[i0 + 9] = tmp_x2[9];
        x2[i0 + 10] = tmp_x2[10];
        x2[i0 + 11] = tmp_x2[11];
        x2[i0 + 12] = tmp_x2[12];
        x2[i0 + 13] = tmp_x2[13];
        x2[i0 + 14] = tmp_x2[14];
        x2[i0 + 15] = tmp_x2[15];
    }
}
void load_y_2 (double y_2[400], double16 vy_2[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_y_2 = vy_2[i0/16];
        y_2[i0 + 0] = tmp_y_2[0];
        y_2[i0 + 1] = tmp_y_2[1];
        y_2[i0 + 2] = tmp_y_2[2];
        y_2[i0 + 3] = tmp_y_2[3];
        y_2[i0 + 4] = tmp_y_2[4];
        y_2[i0 + 5] = tmp_y_2[5];
        y_2[i0 + 6] = tmp_y_2[6];
        y_2[i0 + 7] = tmp_y_2[7];
        y_2[i0 + 8] = tmp_y_2[8];
        y_2[i0 + 9] = tmp_y_2[9];
        y_2[i0 + 10] = tmp_y_2[10];
        y_2[i0 + 11] = tmp_y_2[11];
        y_2[i0 + 12] = tmp_y_2[12];
        y_2[i0 + 13] = tmp_y_2[13];
        y_2[i0 + 14] = tmp_y_2[14];
        y_2[i0 + 15] = tmp_y_2[15];
    }
}
void store_x1 (double x1[400], double16 vx1[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_x1;
        tmp_x1[0] = x1[i0 + 0];
        tmp_x1[1] = x1[i0 + 1];
        tmp_x1[2] = x1[i0 + 2];
        tmp_x1[3] = x1[i0 + 3];
        tmp_x1[4] = x1[i0 + 4];
        tmp_x1[5] = x1[i0 + 5];
        tmp_x1[6] = x1[i0 + 6];
        tmp_x1[7] = x1[i0 + 7];
        tmp_x1[8] = x1[i0 + 8];
        tmp_x1[9] = x1[i0 + 9];
        tmp_x1[10] = x1[i0 + 10];
        tmp_x1[11] = x1[i0 + 11];
        tmp_x1[12] = x1[i0 + 12];
        tmp_x1[13] = x1[i0 + 13];
        tmp_x1[14] = x1[i0 + 14];
        tmp_x1[15] = x1[i0 + 15];
        vx1[i0/16] = tmp_x1;
    }
}
void store_x2 (double x2[400], double16 vx2[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_x2;
        tmp_x2[0] = x2[i0 + 0];
        tmp_x2[1] = x2[i0 + 1];
        tmp_x2[2] = x2[i0 + 2];
        tmp_x2[3] = x2[i0 + 3];
        tmp_x2[4] = x2[i0 + 4];
        tmp_x2[5] = x2[i0 + 5];
        tmp_x2[6] = x2[i0 + 6];
        tmp_x2[7] = x2[i0 + 7];
        tmp_x2[8] = x2[i0 + 8];
        tmp_x2[9] = x2[i0 + 9];
        tmp_x2[10] = x2[i0 + 10];
        tmp_x2[11] = x2[i0 + 11];
        tmp_x2[12] = x2[i0 + 12];
        tmp_x2[13] = x2[i0 + 13];
        tmp_x2[14] = x2[i0 + 14];
        tmp_x2[15] = x2[i0 + 15];
        vx2[i0/16] = tmp_x2;
    }
}

void task0(double A[400][400], double y_1[400], double x1[400], double16 vx1[25], double16 vx2[25], double16 vy_1[25], double16 vy_2[25], double16 vA[10000]) {
#pragma HLS inline
    int i;
    int j;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 4; j0++) {
            for (int i1 = 0; i1 < 80; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 5; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 100; j2++) {
#pragma HLS unroll
                        i = i0 * 400 + i1 * 5 + i2;
                        j = j0 * 100 + j2;
                        x1[i] =x1[i] + A[i][j] * y_1[j] ;
                     }
                }
            }
        }
    }
}

void task1(double x2[400], double A[400][400], double y_2[400], double16 vx1[25], double16 vx2[25], double16 vy_1[25], double16 vy_2[25], double16 vA[10000]) {
#pragma HLS inline
    int i;
    int j;
    for (int i0 = 0; i0 < 2; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int j1 = 0; j1 < 80; j1++) {
#pragma HLS pipeline II=4
                for (int i2 = 0; i2 < 200; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 5; j2++) {
#pragma HLS unroll
                        i = i0 * 200 + i2;
                        j = j0 * 400 + j1 * 5 + j2;
                        x2[i] =x2[i] + A[j][i] * y_2[j] ;
                     }
                }
            }
        }
    }
}

void kernel_nlp(double16 vx1[25], double16 vx2[25], double16 vy_1[25], double16 vy_2[25], double16 vA[10000]) {

#pragma HLS INTERFACE m_axi port=vx2 offset=slave bundle=kernel_x2
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vy_2 offset=slave bundle=kernel_y_2
#pragma HLS INTERFACE m_axi port=vy_1 offset=slave bundle=kernel_y_1
#pragma HLS INTERFACE m_axi port=vx1 offset=slave bundle=kernel_x1
#pragma HLS INTERFACE s_axilite port=vx2 bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vy_2 bundle=control
#pragma HLS INTERFACE s_axilite port=vy_1 bundle=control
#pragma HLS INTERFACE s_axilite port=vx1 bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    double x2[400];
    double A[400][400];
    double y_2[400];
    double y_1[400];
    double x1[400];

#pragma HLS ARRAY_PARTITION variable=x2 cyclic factor=200 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=5 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=200 dim=2
#pragma HLS ARRAY_PARTITION variable=y_2 cyclic factor=40 dim=1
#pragma HLS ARRAY_PARTITION variable=y_1 cyclic factor=200 dim=1
#pragma HLS ARRAY_PARTITION variable=x1 cyclic factor=40 dim=1

    load_A(A, vA);
    load_y_1(y_1, vy_1);
    load_x1(x1, vx1);
    load_x2(x2, vx2);
    load_y_2(y_2, vy_2);
    task0(A, y_1, x1, vx1, vx2, vy_1, vy_2, vA);
    task1(x2, A, y_2, vx1, vx2, vy_1, vy_2, vA);
    store_x1(x1, vx1);
    store_x2(x2, vx2);
}
