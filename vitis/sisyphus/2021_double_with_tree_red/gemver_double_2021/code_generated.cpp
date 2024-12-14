#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

void load_u1 (double u1[400], double16 vu1[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_u1 = vu1[i0/16];
        u1[i0 + 0] = tmp_u1[0];
        u1[i0 + 1] = tmp_u1[1];
        u1[i0 + 2] = tmp_u1[2];
        u1[i0 + 3] = tmp_u1[3];
        u1[i0 + 4] = tmp_u1[4];
        u1[i0 + 5] = tmp_u1[5];
        u1[i0 + 6] = tmp_u1[6];
        u1[i0 + 7] = tmp_u1[7];
        u1[i0 + 8] = tmp_u1[8];
        u1[i0 + 9] = tmp_u1[9];
        u1[i0 + 10] = tmp_u1[10];
        u1[i0 + 11] = tmp_u1[11];
        u1[i0 + 12] = tmp_u1[12];
        u1[i0 + 13] = tmp_u1[13];
        u1[i0 + 14] = tmp_u1[14];
        u1[i0 + 15] = tmp_u1[15];
    }
}
void load_e1 (double e1[400], double16 ve1[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_e1 = ve1[i0/16];
        e1[i0 + 0] = tmp_e1[0];
        e1[i0 + 1] = tmp_e1[1];
        e1[i0 + 2] = tmp_e1[2];
        e1[i0 + 3] = tmp_e1[3];
        e1[i0 + 4] = tmp_e1[4];
        e1[i0 + 5] = tmp_e1[5];
        e1[i0 + 6] = tmp_e1[6];
        e1[i0 + 7] = tmp_e1[7];
        e1[i0 + 8] = tmp_e1[8];
        e1[i0 + 9] = tmp_e1[9];
        e1[i0 + 10] = tmp_e1[10];
        e1[i0 + 11] = tmp_e1[11];
        e1[i0 + 12] = tmp_e1[12];
        e1[i0 + 13] = tmp_e1[13];
        e1[i0 + 14] = tmp_e1[14];
        e1[i0 + 15] = tmp_e1[15];
    }
}
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
void load_u2 (double u2[400], double16 vu2[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_u2 = vu2[i0/16];
        u2[i0 + 0] = tmp_u2[0];
        u2[i0 + 1] = tmp_u2[1];
        u2[i0 + 2] = tmp_u2[2];
        u2[i0 + 3] = tmp_u2[3];
        u2[i0 + 4] = tmp_u2[4];
        u2[i0 + 5] = tmp_u2[5];
        u2[i0 + 6] = tmp_u2[6];
        u2[i0 + 7] = tmp_u2[7];
        u2[i0 + 8] = tmp_u2[8];
        u2[i0 + 9] = tmp_u2[9];
        u2[i0 + 10] = tmp_u2[10];
        u2[i0 + 11] = tmp_u2[11];
        u2[i0 + 12] = tmp_u2[12];
        u2[i0 + 13] = tmp_u2[13];
        u2[i0 + 14] = tmp_u2[14];
        u2[i0 + 15] = tmp_u2[15];
    }
}
void load_e2 (double e2[400], double16 ve2[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_e2 = ve2[i0/16];
        e2[i0 + 0] = tmp_e2[0];
        e2[i0 + 1] = tmp_e2[1];
        e2[i0 + 2] = tmp_e2[2];
        e2[i0 + 3] = tmp_e2[3];
        e2[i0 + 4] = tmp_e2[4];
        e2[i0 + 5] = tmp_e2[5];
        e2[i0 + 6] = tmp_e2[6];
        e2[i0 + 7] = tmp_e2[7];
        e2[i0 + 8] = tmp_e2[8];
        e2[i0 + 9] = tmp_e2[9];
        e2[i0 + 10] = tmp_e2[10];
        e2[i0 + 11] = tmp_e2[11];
        e2[i0 + 12] = tmp_e2[12];
        e2[i0 + 13] = tmp_e2[13];
        e2[i0 + 14] = tmp_e2[14];
        e2[i0 + 15] = tmp_e2[15];
    }
}
void load_y (double y[400], double16 vy[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_y = vy[i0/16];
        y[i0 + 0] = tmp_y[0];
        y[i0 + 1] = tmp_y[1];
        y[i0 + 2] = tmp_y[2];
        y[i0 + 3] = tmp_y[3];
        y[i0 + 4] = tmp_y[4];
        y[i0 + 5] = tmp_y[5];
        y[i0 + 6] = tmp_y[6];
        y[i0 + 7] = tmp_y[7];
        y[i0 + 8] = tmp_y[8];
        y[i0 + 9] = tmp_y[9];
        y[i0 + 10] = tmp_y[10];
        y[i0 + 11] = tmp_y[11];
        y[i0 + 12] = tmp_y[12];
        y[i0 + 13] = tmp_y[13];
        y[i0 + 14] = tmp_y[14];
        y[i0 + 15] = tmp_y[15];
    }
}
void load_x (double x[400], double16 vx[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_x = vx[i0/16];
        x[i0 + 0] = tmp_x[0];
        x[i0 + 1] = tmp_x[1];
        x[i0 + 2] = tmp_x[2];
        x[i0 + 3] = tmp_x[3];
        x[i0 + 4] = tmp_x[4];
        x[i0 + 5] = tmp_x[5];
        x[i0 + 6] = tmp_x[6];
        x[i0 + 7] = tmp_x[7];
        x[i0 + 8] = tmp_x[8];
        x[i0 + 9] = tmp_x[9];
        x[i0 + 10] = tmp_x[10];
        x[i0 + 11] = tmp_x[11];
        x[i0 + 12] = tmp_x[12];
        x[i0 + 13] = tmp_x[13];
        x[i0 + 14] = tmp_x[14];
        x[i0 + 15] = tmp_x[15];
    }
}
void load_z (double z[400], double16 vz[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_z = vz[i0/16];
        z[i0 + 0] = tmp_z[0];
        z[i0 + 1] = tmp_z[1];
        z[i0 + 2] = tmp_z[2];
        z[i0 + 3] = tmp_z[3];
        z[i0 + 4] = tmp_z[4];
        z[i0 + 5] = tmp_z[5];
        z[i0 + 6] = tmp_z[6];
        z[i0 + 7] = tmp_z[7];
        z[i0 + 8] = tmp_z[8];
        z[i0 + 9] = tmp_z[9];
        z[i0 + 10] = tmp_z[10];
        z[i0 + 11] = tmp_z[11];
        z[i0 + 12] = tmp_z[12];
        z[i0 + 13] = tmp_z[13];
        z[i0 + 14] = tmp_z[14];
        z[i0 + 15] = tmp_z[15];
    }
}
void load_w (double w[400], double16 vw[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_w = vw[i0/16];
        w[i0 + 0] = tmp_w[0];
        w[i0 + 1] = tmp_w[1];
        w[i0 + 2] = tmp_w[2];
        w[i0 + 3] = tmp_w[3];
        w[i0 + 4] = tmp_w[4];
        w[i0 + 5] = tmp_w[5];
        w[i0 + 6] = tmp_w[6];
        w[i0 + 7] = tmp_w[7];
        w[i0 + 8] = tmp_w[8];
        w[i0 + 9] = tmp_w[9];
        w[i0 + 10] = tmp_w[10];
        w[i0 + 11] = tmp_w[11];
        w[i0 + 12] = tmp_w[12];
        w[i0 + 13] = tmp_w[13];
        w[i0 + 14] = tmp_w[14];
        w[i0 + 15] = tmp_w[15];
    }
}
void store_A (double A[400][400], double16 vA[10000]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=1){
        for (int i1 = 0; i1 < 400; i1+=16){
#pragma HLS pipeline II=1
            double16 tmp_A;
            tmp_A[0] = A[i0][i1 + 0];
            tmp_A[1] = A[i0][i1 + 1];
            tmp_A[2] = A[i0][i1 + 2];
            tmp_A[3] = A[i0][i1 + 3];
            tmp_A[4] = A[i0][i1 + 4];
            tmp_A[5] = A[i0][i1 + 5];
            tmp_A[6] = A[i0][i1 + 6];
            tmp_A[7] = A[i0][i1 + 7];
            tmp_A[8] = A[i0][i1 + 8];
            tmp_A[9] = A[i0][i1 + 9];
            tmp_A[10] = A[i0][i1 + 10];
            tmp_A[11] = A[i0][i1 + 11];
            tmp_A[12] = A[i0][i1 + 12];
            tmp_A[13] = A[i0][i1 + 13];
            tmp_A[14] = A[i0][i1 + 14];
            tmp_A[15] = A[i0][i1 + 15];
            vA[i0 * 25 + i1/16] = tmp_A;
        }
    }
}
void store_x (double x[400], double16 vx[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_x;
        tmp_x[0] = x[i0 + 0];
        tmp_x[1] = x[i0 + 1];
        tmp_x[2] = x[i0 + 2];
        tmp_x[3] = x[i0 + 3];
        tmp_x[4] = x[i0 + 4];
        tmp_x[5] = x[i0 + 5];
        tmp_x[6] = x[i0 + 6];
        tmp_x[7] = x[i0 + 7];
        tmp_x[8] = x[i0 + 8];
        tmp_x[9] = x[i0 + 9];
        tmp_x[10] = x[i0 + 10];
        tmp_x[11] = x[i0 + 11];
        tmp_x[12] = x[i0 + 12];
        tmp_x[13] = x[i0 + 13];
        tmp_x[14] = x[i0 + 14];
        tmp_x[15] = x[i0 + 15];
        vx[i0/16] = tmp_x;
    }
}
void store_w (double w[400], double16 vw[25]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        double16 tmp_w;
        tmp_w[0] = w[i0 + 0];
        tmp_w[1] = w[i0 + 1];
        tmp_w[2] = w[i0 + 2];
        tmp_w[3] = w[i0 + 3];
        tmp_w[4] = w[i0 + 4];
        tmp_w[5] = w[i0 + 5];
        tmp_w[6] = w[i0 + 6];
        tmp_w[7] = w[i0 + 7];
        tmp_w[8] = w[i0 + 8];
        tmp_w[9] = w[i0 + 9];
        tmp_w[10] = w[i0 + 10];
        tmp_w[11] = w[i0 + 11];
        tmp_w[12] = w[i0 + 12];
        tmp_w[13] = w[i0 + 13];
        tmp_w[14] = w[i0 + 14];
        tmp_w[15] = w[i0 + 15];
        vw[i0/16] = tmp_w;
    }
}

void task0(double u1[400], double e1[400], double A[400][400], double u2[400], double e2[400], double alpha, double beta, double16 vA[10000], double16 vu1[25], double16 ve1[25], double16 vu2[25], double16 ve2[25], double16 vw[25], double16 vx[25], double16 vy[25], double16 vz[25]) {
#pragma HLS inline
    int i;
    int j;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 10; j0++) {
            for (int i1 = 0; i1 < 400; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 1; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 40; j2++) {
#pragma HLS unroll
                        i = i0 * 400 + i1 * 1 + i2;
                        j = j0 * 40 + j2;
                        A[i][j] =A[i][j] + u1[i] * e1[j] + u2[i] * e2[j] ;
                     }
                }
            }
        }
    }
}

void task1(double y[400], double A[400][400], double x[400], double alpha, double beta, double16 vA[10000], double16 vu1[25], double16 ve1[25], double16 vu2[25], double16 ve2[25], double16 vw[25], double16 vx[25], double16 vy[25], double16 vz[25]) {
#pragma HLS inline
    int i;
    int j;
    for (int i0 = 0; i0 < 5; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int j1 = 0; j1 < 200; j1++) {
#pragma HLS pipeline II=4
                for (int i2 = 0; i2 < 80; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 2; j2++) {
#pragma HLS unroll
                        i = i0 * 80 + i2;
                        j = j0 * 400 + j1 * 2 + j2;
                        x[i] =x[i] + beta * A[j][i] * y[j] ;
                     }
                }
            }
        }
    }
}

void task2(double z[400], double x[400], double alpha, double beta, double16 vA[10000], double16 vu1[25], double16 ve1[25], double16 vu2[25], double16 ve2[25], double16 vw[25], double16 vx[25], double16 vy[25], double16 vz[25]) {
#pragma HLS inline
    int i;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int i1 = 0; i1 < 200; i1++) {
#pragma HLS pipeline II=1
            for (int i2 = 0; i2 < 2; i2++) {
#pragma HLS unroll
                i = i0 * 400 + i1 * 2 + i2;
                x[i] =x[i] + z[i] ;
             }
        }
    }
}

void task3(double w[400], double A[400][400], double x[400], double alpha, double beta, double16 vA[10000], double16 vu1[25], double16 ve1[25], double16 vu2[25], double16 ve2[25], double16 vw[25], double16 vx[25], double16 vy[25], double16 vz[25]) {
#pragma HLS inline
    int i;
    int j;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 10; j0++) {
            for (int i1 = 0; i1 < 400; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 1; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 40; j2++) {
#pragma HLS unroll
                        i = i0 * 400 + i1 * 1 + i2;
                        j = j0 * 40 + j2;
                        w[i] =w[i] + alpha * A[i][j] * x[j] ;
                     }
                }
            }
        }
    }
}

void kernel_nlp(double alpha, double beta, double16 vA[10000], double16 vu1[25], double16 ve1[25], double16 vu2[25], double16 ve2[25], double16 vw[25], double16 vx[25], double16 vy[25], double16 vz[25]) {

#pragma HLS INTERFACE m_axi port=alpha offset=slave bundle=kernel_alpha
#pragma HLS INTERFACE m_axi port=beta offset=slave bundle=kernel_beta
#pragma HLS INTERFACE m_axi port=vy offset=slave bundle=kernel_y
#pragma HLS INTERFACE m_axi port=vu1 offset=slave bundle=kernel_u1
#pragma HLS INTERFACE m_axi port=vw offset=slave bundle=kernel_w
#pragma HLS INTERFACE m_axi port=ve1 offset=slave bundle=kernel_e1
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vz offset=slave bundle=kernel_z
#pragma HLS INTERFACE m_axi port=vu2 offset=slave bundle=kernel_u2
#pragma HLS INTERFACE m_axi port=vx offset=slave bundle=kernel_x
#pragma HLS INTERFACE m_axi port=ve2 offset=slave bundle=kernel_e2
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
#pragma HLS INTERFACE s_axilite port=beta bundle=control
#pragma HLS INTERFACE s_axilite port=vy bundle=control
#pragma HLS INTERFACE s_axilite port=vu1 bundle=control
#pragma HLS INTERFACE s_axilite port=vw bundle=control
#pragma HLS INTERFACE s_axilite port=ve1 bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vz bundle=control
#pragma HLS INTERFACE s_axilite port=vu2 bundle=control
#pragma HLS INTERFACE s_axilite port=vx bundle=control
#pragma HLS INTERFACE s_axilite port=ve2 bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    double y[400];
    double u1[400];
    double w[400];
    double e1[400];
    double A[400][400];
    double z[400];
    double u2[400];
    double x[400];
    double e2[400];

#pragma HLS ARRAY_PARTITION variable=y cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=u1 cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=w cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=e1 cyclic factor=40 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=2 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=160 dim=2
#pragma HLS ARRAY_PARTITION variable=z cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=u2 cyclic factor=8 dim=1
#pragma HLS ARRAY_PARTITION variable=x cyclic factor=400 dim=1
#pragma HLS ARRAY_PARTITION variable=e2 cyclic factor=400 dim=1

    load_u1(u1, vu1);
    load_e1(e1, ve1);
    load_A(A, vA);
    load_u2(u2, vu2);
    load_e2(e2, ve2);
    load_y(y, vy);
    load_x(x, vx);
    load_z(z, vz);
    load_w(w, vw);
    task0(u1, e1, A, u2, e2, alpha, beta, vA, vu1, ve1, vu2, ve2, vw, vx, vy, vz);
    task1(y, A, x, alpha, beta, vA, vu1, ve1, vu2, ve2, vw, vx, vy, vz);
    task2(z, x, alpha, beta, vA, vu1, ve1, vu2, ve2, vw, vx, vy, vz);
    task3(w, A, x, alpha, beta, vA, vu1, ve1, vu2, ve2, vw, vx, vy, vz);
    store_A(A, vA);
    store_x(x, vx);
    store_w(w, vw);
}
