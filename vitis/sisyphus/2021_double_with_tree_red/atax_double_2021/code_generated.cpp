#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

void load_y (double y[410], double2 vy[205]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 410; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_y = vy[i0/2];
        y[i0 + 0] = tmp_y[0];
        y[i0 + 1] = tmp_y[1];
    }
}
void load_tmp (double tmp[390], double2 vtmp[195]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 390; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_tmp = vtmp[i0/2];
        tmp[i0 + 0] = tmp_tmp[0];
        tmp[i0 + 1] = tmp_tmp[1];
    }
}
void load_x (double x[410], double2 vx[205]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 410; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_x = vx[i0/2];
        x[i0 + 0] = tmp_x[0];
        x[i0 + 1] = tmp_x[1];
    }
}
void load_A (double A[390][410], double2 vA[79950]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 390; i0+=1){
        for (int i1 = 0; i1 < 410; i1+=2){
#pragma HLS pipeline II=1
            double2 tmp_A = vA[i0 * 205 + i1/2];
            A[i0][i1 + 0] = tmp_A[0];
            A[i0][i1 + 1] = tmp_A[1];
        }
    }
}
void store_y (double y[410], double2 vy[205]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 410; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_y;
        tmp_y[0] = y[i0 + 0];
        tmp_y[1] = y[i0 + 1];
        vy[i0/2] = tmp_y;
    }
}
void store_tmp (double tmp[390], double2 vtmp[195]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 390; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_tmp;
        tmp_tmp[0] = tmp[i0 + 0];
        tmp_tmp[1] = tmp[i0 + 1];
        vtmp[i0/2] = tmp_tmp;
    }
}

void task0(double y[410], double2 vA[79950], double2 vx[205], double2 vy[205], double2 vtmp[195]) {
#pragma HLS inline
    int j;
    for (int j0 = 0; j0 < 1; j0++) {
        for (int j1 = 0; j1 < 2; j1++) {
#pragma HLS pipeline II=1
            for (int j2 = 0; j2 < 205; j2++) {
#pragma HLS unroll
                j = j0 * 410 + j1 * 205 + j2;
                y[j] =0.0 ;
             }
        }
    }
}

void task1(double tmp[390], double2 vA[79950], double2 vx[205], double2 vy[205], double2 vtmp[195]) {
#pragma HLS inline
    int i;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int i1 = 0; i1 < 2; i1++) {
#pragma HLS pipeline II=1
            for (int i2 = 0; i2 < 195; i2++) {
#pragma HLS unroll
                i = i0 * 390 + i1 * 195 + i2;
                tmp[i] =0.0 ;
             }
        }
    }
}

void task2(double tmp[390], double x[410], double A[390][410], double2 vA[79950], double2 vx[205], double2 vy[205], double2 vtmp[195]) {
#pragma HLS inline
    int i;
    int j;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int i1 = 0; i1 < 390; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 1; i2++) {
#pragma HLS unroll
                    double red = 0;
                    for (int j2 = 0; j2 < 410; j2++) {
#pragma HLS unroll
                        i = i0 * 390 + i1 * 1 + i2;
                        j = j0 * 410 + j2;
                        red +=  + A[i][j] * x[j] ;
                     }
                    tmp[i] = red;
                }
            }
        }
    }
}

void task3(double tmp[390], double A[390][410], double y[410], double2 vA[79950], double2 vx[205], double2 vy[205], double2 vtmp[195]) {
#pragma HLS inline
    int j;
    int i;
    for (int j0 = 0; j0 < 1; j0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int i1 = 0; i1 < 195; i1++) {
#pragma HLS pipeline II=4
                for (int j2 = 0; j2 < 410; j2++) {
#pragma HLS unroll
                    for (int i2 = 0; i2 < 2; i2++) {
#pragma HLS unroll
                        j = j0 * 410 + j2;
                        i = i0 * 390 + i1 * 2 + i2;
                        y[j] =y[j] + A[i][j] * tmp[i] ;
                     }
                }
            }
        }
    }
}

void kernel_nlp(double2 vA[79950], double2 vx[205], double2 vy[205], double2 vtmp[195]) {

#pragma HLS INTERFACE m_axi port=vtmp offset=slave bundle=kernel_tmp
#pragma HLS INTERFACE m_axi port=vx offset=slave bundle=kernel_x
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vy offset=slave bundle=kernel_y
#pragma HLS INTERFACE s_axilite port=vtmp bundle=control
#pragma HLS INTERFACE s_axilite port=vx bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vy bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    double tmp[390];
    double x[410];
    double A[390][410];
    double y[410];

#pragma HLS ARRAY_PARTITION variable=tmp cyclic factor=390 dim=1
#pragma HLS ARRAY_PARTITION variable=x cyclic factor=410 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=2 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=410 dim=2
#pragma HLS ARRAY_PARTITION variable=y cyclic factor=410 dim=1

    load_y(y, vy);
    load_tmp(tmp, vtmp);
    load_x(x, vx);
    load_A(A, vA);
    task0(y, vA, vx, vy, vtmp);
    task1(tmp, vA, vx, vy, vtmp);
    task2(tmp, x, A, vA, vx, vy, vtmp);
    task3(tmp, A, y, vA, vx, vy, vtmp);
    store_tmp(tmp, vtmp);
    store_y(y, vy);
}