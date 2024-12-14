#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;

void load_s (double s[390], double2 vs[195]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 390; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_s = vs[i0/2];
        s[i0 + 0] = tmp_s[0];
        s[i0 + 1] = tmp_s[1];
    }
}
void load_q (double q[410], double2 vq[205]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 410; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_q = vq[i0/2];
        q[i0 + 0] = tmp_q[0];
        q[i0 + 1] = tmp_q[1];
    }
}
void load_A (double A[410][390], double2 vA[79950]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 410; i0+=1){
        for (int i1 = 0; i1 < 390; i1+=2){
#pragma HLS pipeline II=1
            double2 tmp_A = vA[i0 * 195 + i1/2];
            A[i0][i1 + 0] = tmp_A[0];
            A[i0][i1 + 1] = tmp_A[1];
        }
    }
}
void load_r (double r[410], double2 vr[205]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 410; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_r = vr[i0/2];
        r[i0 + 0] = tmp_r[0];
        r[i0 + 1] = tmp_r[1];
    }
}
void load_p (double p[390], double2 vp[195]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 390; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_p = vp[i0/2];
        p[i0 + 0] = tmp_p[0];
        p[i0 + 1] = tmp_p[1];
    }
}
void store_s (double s[390], double2 vs[195]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 390; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_s;
        tmp_s[0] = s[i0 + 0];
        tmp_s[1] = s[i0 + 1];
        vs[i0/2] = tmp_s;
    }
}
void store_q (double q[410], double2 vq[205]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 410; i0+=2){
#pragma HLS pipeline II=1
        double2 tmp_q;
        tmp_q[0] = q[i0 + 0];
        tmp_q[1] = q[i0 + 1];
        vq[i0/2] = tmp_q;
    }
}

void task0(double s[390], double2 vA[79950], double2 vs[195], double2 vq[205], double2 vp[195], double2 vr[205]) {
#pragma HLS inline
    int i;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int i1 = 0; i1 < 2; i1++) {
#pragma HLS pipeline II=1
            for (int i2 = 0; i2 < 195; i2++) {
#pragma HLS unroll
                i = i0 * 390 + i1 * 195 + i2;
                s[i] =0.0 ;
             }
        }
    }
}

void task1(double q[410], double2 vA[79950], double2 vs[195], double2 vq[205], double2 vp[195], double2 vr[205]) {
#pragma HLS inline
    int i;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int i1 = 0; i1 < 2; i1++) {
#pragma HLS pipeline II=1
            for (int i2 = 0; i2 < 205; i2++) {
#pragma HLS unroll
                i = i0 * 410 + i1 * 205 + i2;
                q[i] =0.0 ;
             }
        }
    }
}

void task2(double A[410][390], double r[410], double s[390], double2 vA[79950], double2 vs[195], double2 vq[205], double2 vp[195], double2 vr[205]) {
#pragma HLS inline
    int j;
    int i;
    for (int j0 = 0; j0 < 1; j0++) {
        for (int i0 = 0; i0 < 1; i0++) {
            for (int j1 = 0; j1 < 390; j1++) {
#pragma HLS pipeline II=1
                for (int j2 = 0; j2 < 1; j2++) {
#pragma HLS unroll
                    double red = 0;
                    for (int i2 = 0; i2 < 410; i2++) {
#pragma HLS unroll
                        j = j0 * 390 + j1 * 1 + j2;
                        i = i0 * 410 + i2;
                        red +=  + r[i] * A[i][j] ;
                     }
                    s[j] = red;
                }
            }
        }
    }
}

void task3(double q[410], double A[410][390], double p[390], double2 vA[79950], double2 vs[195], double2 vq[205], double2 vp[195], double2 vr[205]) {
#pragma HLS inline
    int i;
    int j;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int j1 = 0; j1 < 195; j1++) {
#pragma HLS pipeline II=4
                for (int i2 = 0; i2 < 410; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 2; j2++) {
#pragma HLS unroll
                        i = i0 * 410 + i2;
                        j = j0 * 390 + j1 * 2 + j2;
                        q[i] =q[i] + A[i][j] * p[j] ;
                     }
                }
            }
        }
    }
}

void kernel_nlp(double2 vA[79950], double2 vs[195], double2 vq[205], double2 vp[195], double2 vr[205]) {

#pragma HLS INTERFACE m_axi port=vq offset=slave bundle=kernel_q
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vr offset=slave bundle=kernel_r
#pragma HLS INTERFACE m_axi port=vp offset=slave bundle=kernel_p
#pragma HLS INTERFACE m_axi port=vs offset=slave bundle=kernel_s
#pragma HLS INTERFACE s_axilite port=vq bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vr bundle=control
#pragma HLS INTERFACE s_axilite port=vp bundle=control
#pragma HLS INTERFACE s_axilite port=vs bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    double q[410];
    double A[410][390];
    double r[410];
    double p[390];
    double s[390];

#pragma HLS ARRAY_PARTITION variable=q cyclic factor=410 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=410 dim=1
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=2 dim=2
#pragma HLS ARRAY_PARTITION variable=r cyclic factor=410 dim=1
#pragma HLS ARRAY_PARTITION variable=p cyclic factor=2 dim=1
#pragma HLS ARRAY_PARTITION variable=s cyclic factor=390 dim=1

    load_s(s, vs);
    load_q(q, vq);
    load_A(A, vA);
    load_r(r, vr);
    load_p(p, vp);
    task0(s, vA, vs, vq, vp, vr);
    task1(q, vA, vs, vq, vp, vr);
    task2(A, r, s, vA, vs, vq, vp, vr);
    task3(q, A, p, vA, vs, vq, vp, vr);
    store_s(s, vs);
    store_q(q, vq);
}
