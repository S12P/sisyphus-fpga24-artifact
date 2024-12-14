#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_A (float A[400][400], float16 vA[10000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=1){
        for (int i1 = 0; i1 < 400; i1+=16){
#pragma HLS pipeline II=1
            float16 tmp_A = vA[i0 * 25 + i1/16];
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
void load_u2 (float u2[400], float16 vu2[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_u2 = vu2[i0/16];
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
void load_e1 (float e1[400], float16 ve1[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_e1 = ve1[i0/16];
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
void load_e2 (float e2[400], float16 ve2[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_e2 = ve2[i0/16];
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
void load_u1 (float u1[400], float16 vu1[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_u1 = vu1[i0/16];
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
void load_y (float y[400], float16 vy[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_y = vy[i0/16];
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
void load_x (float x[400], float16 vx[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_x = vx[i0/16];
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
void load_z (float z[400], float16 vz[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_z = vz[i0/16];
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
void load_w (float w[400], float16 vw[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_w = vw[i0/16];
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
void store_A (float A[400][400], float16 vA[10000]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=1){
        for (int i1 = 0; i1 < 400; i1+=16){
#pragma HLS pipeline II=1
            float16 tmp_A;
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
void store_x (float x[400], float16 vx[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_x;
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
void store_w (float w[400], float16 vw[25]) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 400; i0+=16){
#pragma HLS pipeline II=1
        float16 tmp_w;
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

void task0(float A[400][400], float u2[400], float e1[400], float e2[400], float u1[400], float alpha, float beta, float16 vA[10000], float16 vu1[25], float16 ve1[25], float16 vu2[25], float16 ve2[25], float16 vw[25], float16 vx[25], float16 vy[25], float16 vz[25]) {
    int i;
    int j;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int i1 = 0; i1 < 400; i1++) {
#pragma HLS pipeline
                for (int i2 = 0; i2 < 1; i2++) {
                    for (int j2 = 0; j2 < 400; j2++) {
                        i = i0 * 400 + i1 * 1 + i2;
                        j = j0 * 400 + j2;
                        A[i][j] =A[i][j] + u1[i] * e1[j] + u2[i] * e2[j] ;
                     }
                }
            }
        }
    }
}

void task1(float A[400][400], float y[400], float x[400], float alpha, float beta, float16 vA[10000], float16 vu1[25], float16 ve1[25], float16 vu2[25], float16 ve2[25], float16 vw[25], float16 vx[25], float16 vy[25], float16 vz[25]) {
    int j;
    int i;
    for (int j0 = 0; j0 < 1; j0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int j1 = 0; j1 < 400; j1++) {
#pragma HLS pipeline
                    for (int i2 = 0; i2 < 400; i2++) {
                for (int j2 = 0; j2 < 1; j2++) {
                        j = j0 * 400 + j1 * 1 + j2;
                        i = i0 * 400 + i2;
                        x[i] =x[i] + beta * A[j][i] * y[j] ;
                     }
                }
            }
        }
    }
}

void task2(float x[400], float z[400], float alpha, float beta, float16 vA[10000], float16 vu1[25], float16 ve1[25], float16 vu2[25], float16 ve2[25], float16 vw[25], float16 vx[25], float16 vy[25], float16 vz[25]) {
    int i;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int i1 = 0; i1 < 2; i1++) {
#pragma HLS pipeline
            for (int i2 = 0; i2 < 200; i2++) {
                i = i0 * 400 + i1 * 200 + i2;
                x[i] =x[i] + z[i] ;
             }
        }
    }
}

void task3(float A[400][400], float x[400], float w[400], float alpha, float beta, float16 vA[10000], float16 vu1[25], float16 ve1[25], float16 vu2[25], float16 ve2[25], float16 vw[25], float16 vx[25], float16 vy[25], float16 vz[25]) {
    int j;
    int i;
                    float w_red[400];
    for (int j0 = 0; j0 < 1; j0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int i1 = 0; i1 < 400; i1++) {
#pragma HLS pipeline
                    for (int i2 = 0; i2 < 1; i2++) {
                    float red = 0;
                for (int j2 = 0; j2 < 400; j2++) {
                        j = j0 * 400 + j2;
                        i = i0 * 400 + i1 * 1 + i2;
                        red +=  + alpha * A[i][j] * x[j] ;
                     }
                    w_red[i] = red;
                }
            }
        }
    }
    for (int i0 = 0; i0 < 400; i0++) {
#pragma HLS pipeline II=1
        w[i0] += w_red[i0];
    }
}

void kernel_nlp(float alpha, float beta, float16 vA[10000], float16 vu1[25], float16 ve1[25], float16 vu2[25], float16 ve2[25], float16 vw[25], float16 vx[25], float16 vy[25], float16 vz[25]) {

#pragma HLS INTERFACE m_axi port=alpha offset=slave bundle=kernel_alpha
#pragma HLS INTERFACE m_axi port=beta offset=slave bundle=kernel_beta
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vu2 offset=slave bundle=kernel_u2
#pragma HLS INTERFACE m_axi port=vy offset=slave bundle=kernel_y
#pragma HLS INTERFACE m_axi port=vx offset=slave bundle=kernel_x
#pragma HLS INTERFACE m_axi port=vw offset=slave bundle=kernel_w
#pragma HLS INTERFACE m_axi port=ve1 offset=slave bundle=kernel_e1
#pragma HLS INTERFACE m_axi port=ve2 offset=slave bundle=kernel_e2
#pragma HLS INTERFACE m_axi port=vu1 offset=slave bundle=kernel_u1
#pragma HLS INTERFACE m_axi port=vz offset=slave bundle=kernel_z
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
#pragma HLS INTERFACE s_axilite port=beta bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vu2 bundle=control
#pragma HLS INTERFACE s_axilite port=vy bundle=control
#pragma HLS INTERFACE s_axilite port=vx bundle=control
#pragma HLS INTERFACE s_axilite port=vw bundle=control
#pragma HLS INTERFACE s_axilite port=ve1 bundle=control
#pragma HLS INTERFACE s_axilite port=ve2 bundle=control
#pragma HLS INTERFACE s_axilite port=vu1 bundle=control
#pragma HLS INTERFACE s_axilite port=vz bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float A[400][400];
    float u2[400];
    float y[400];
    float x[400];
    float w[400];
    float e1[400];
    float e2[400];
    float u1[400];
    float z[400];

#pragma HLS ARRAY_PARTITION variable=A cyclic factor=1 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=400 dim=2
#pragma HLS ARRAY_PARTITION variable=u2 cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=y cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=x cyclic factor=400 dim=1
#pragma HLS ARRAY_PARTITION variable=w cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=e1 cyclic factor=400 dim=1
#pragma HLS ARRAY_PARTITION variable=e2 cyclic factor=400 dim=1
#pragma HLS ARRAY_PARTITION variable=u1 cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=z cyclic factor=400 dim=1

    load_A(A, vA);
    load_u2(u2, vu2);
    load_e1(e1, ve1);
    load_e2(e2, ve2);
    load_u1(u1, vu1);
    load_y(y, vy);
    load_x(x, vx);
    load_z(z, vz);
    load_w(w, vw);
    task0(A, u2, e1, e2, u1, alpha, beta, vA, vu1, ve1, vu2, ve2, vw, vx, vy, vz);
    task1(A, y, x, alpha, beta, vA, vu1, ve1, vu2, ve2, vw, vx, vy, vz);
    task2(x, z, alpha, beta, vA, vu1, ve1, vu2, ve2, vw, vx, vy, vz);
    task3(A, x, w, alpha, beta, vA, vu1, ve1, vu2, ve2, vw, vx, vy, vz);
    store_A(A, vA);
    store_x(x, vx);
    store_w(w, vw);
}
