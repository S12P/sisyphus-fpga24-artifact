#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_tmp (float tmp[15][12][19][10], float2 vtmp[17100]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 180; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 190; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_tmp = vtmp[i0 * 95 + i1/2];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+0) / 10;
            i1_1 = (i1+0) % 10;
            tmp[i0_0][i0_1][i1_0][i1_1] = tmp_tmp[0];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+1) / 10;
            i1_1 = (i1+1) % 10;
            tmp[i0_0][i0_1][i1_0][i1_1] = tmp_tmp[1];
        }
    }
}
void load_A (float A[15][12][21][10], float2 vA[18900]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 180; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 210; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_A = vA[i0 * 105 + i1/2];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+0) / 10;
            i1_1 = (i1+0) % 10;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[0];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+1) / 10;
            i1_1 = (i1+1) % 10;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[1];
        }
    }
}
void load_B (float B[42][5][19][10], float2 vB[19950]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 210; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 190; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_B = vB[i0 * 95 + i1/2];
            i0_0 = (i0+0) / 5;
            i0_1 = (i0+0) % 5;
            i1_0 = (i1+0) / 10;
            i1_1 = (i1+0) % 10;
            B[i0_0][i0_1][i1_0][i1_1] = tmp_B[0];
            i0_0 = (i0+0) / 5;
            i0_1 = (i0+0) % 5;
            i1_0 = (i1+1) / 10;
            i1_1 = (i1+1) % 10;
            B[i0_0][i0_1][i1_0][i1_1] = tmp_B[1];
        }
    }
}
void load_D (float D[90][2][5][44], float4 vD[9900]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 180; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 220; i1+=4){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float4 tmp_D = vD[i0 * 55 + i1/4];
            i0_0 = (i0+0) / 2;
            i0_1 = (i0+0) % 2;
            i1_0 = (i1+0) / 44;
            i1_1 = (i1+0) % 44;
            D[i0_0][i0_1][i1_0][i1_1] = tmp_D[0];
            i0_0 = (i0+0) / 2;
            i0_1 = (i0+0) % 2;
            i1_0 = (i1+1) / 44;
            i1_1 = (i1+1) % 44;
            D[i0_0][i0_1][i1_0][i1_1] = tmp_D[1];
            i0_0 = (i0+0) / 2;
            i0_1 = (i0+0) % 2;
            i1_0 = (i1+2) / 44;
            i1_1 = (i1+2) % 44;
            D[i0_0][i0_1][i1_0][i1_1] = tmp_D[2];
            i0_0 = (i0+0) / 2;
            i0_1 = (i0+0) % 2;
            i1_0 = (i1+3) / 44;
            i1_1 = (i1+3) % 44;
            D[i0_0][i0_1][i1_0][i1_1] = tmp_D[3];
        }
    }
}
void load_C (float C[190][1][5][44], float4 vC[10450]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 190; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 220; i1+=4){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float4 tmp_C = vC[i0 * 55 + i1/4];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+0) / 44;
            i1_1 = (i1+0) % 44;
            C[i0_0][i0_1][i1_0][i1_1] = tmp_C[0];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+1) / 44;
            i1_1 = (i1+1) % 44;
            C[i0_0][i0_1][i1_0][i1_1] = tmp_C[1];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+2) / 44;
            i1_1 = (i1+2) % 44;
            C[i0_0][i0_1][i1_0][i1_1] = tmp_C[2];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+3) / 44;
            i1_1 = (i1+3) % 44;
            C[i0_0][i0_1][i1_0][i1_1] = tmp_C[3];

        }
    }
}
void store_tmp (float tmp[15][12][19][10], float2 vtmp[17100]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 180; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 190; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_tmp;
            i0_0 = (i0+0) / 12; 
            i0_1 = (i0+0) % 12; 
            i1_0 = (i1+0) / 10; 
            i1_1 = (i1+0) % 10; 
            tmp_tmp[0] = tmp[i0_0][i0_1][i1_0][i1_1];
            i0_0 = (i0+0) / 12; 
            i0_1 = (i0+0) % 12; 
            i1_0 = (i1+1) / 10; 
            i1_1 = (i1+1) % 10; 
            tmp_tmp[1] = tmp[i0_0][i0_1][i1_0][i1_1];
            vtmp[i0 * 95 + i1/2] = tmp_tmp;
        }
    }
}
void store_D (float D[90][2][5][44], float4 vD[9900]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 180; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 220; i1+=4){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float4 tmp_D;
            i0_0 = (i0+0) / 2; 
            i0_1 = (i0+0) % 2; 
            i1_0 = (i1+0) / 44; 
            i1_1 = (i1+0) % 44; 
            tmp_D[0] = D[i0_0][i0_1][i1_0][i1_1];
            i0_0 = (i0+0) / 2; 
            i0_1 = (i0+0) % 2; 
            i1_0 = (i1+1) / 44; 
            i1_1 = (i1+1) % 44; 
            tmp_D[1] = D[i0_0][i0_1][i1_0][i1_1];
            i0_0 = (i0+0) / 2; 
            i0_1 = (i0+0) % 2; 
            i1_0 = (i1+2) / 44; 
            i1_1 = (i1+2) % 44; 
            tmp_D[2] = D[i0_0][i0_1][i1_0][i1_1];
            i0_0 = (i0+0) / 2; 
            i0_1 = (i0+0) % 2; 
            i1_0 = (i1+3) / 44; 
            i1_1 = (i1+3) % 44; 
            tmp_D[3] = D[i0_0][i0_1][i1_0][i1_1];
            vD[i0 * 55 + i1/4] = tmp_D;
        }
    }
}

void task0(float tmp[15][12][19][10], float alpha, float beta, float2 vtmp[17100], float2 vA[18900], float2 vB[19950], float4 vC[10450], float4 vD[9900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int i_tmp_0;
    int i_tmp_1;
    int j_tmp_0;
    int j_tmp_1;
    for (int i0 = 0; i0 < 5; i0++) {
        for (int j0 = 0; j0 < 19; j0++) {
            for (int i1 = 0; i1 < 3; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 12; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 10; j2++) {
#pragma HLS unroll
                        i = i0 * 36 + i1 * 12 + i2;
                        j = j0 * 10 + j2;
i_tmp_0 = (i0*36+i1*12+0)/12;
i_tmp_1 = i2;
j_tmp_0 = (j0*10+0)/10;
j_tmp_1 = j2;
tmp[i_tmp_0][i_tmp_1][j_tmp_0][j_tmp_1]=0.0;
                    }
                }
            }
        }
    }
}

void task1(float A[15][12][21][10], float tmp[15][12][19][10], float B[42][5][19][10], float alpha, float beta, float2 vtmp[17100], float2 vA[18900], float2 vB[19950], float4 vC[10450], float4 vD[9900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int k, k_0, k_1;
    int i_tmp_0;
    int i_tmp_1;
    int j_tmp_0;
    int j_tmp_1;
    int i_A_0;
    int i_A_1;
    int k_A_0;
    int k_A_1;
    int k_B_0;
    int k_B_1;
    int j_B_0;
    int j_B_1;
    for (int i0 = 0; i0 < 15; i0++) {
        for (int j0 = 0; j0 < 19; j0++) {
            for (int k0 = 0; k0 < 1; k0++) {
                for (int k1 = 0; k1 < 42; k1++) {
#pragma HLS pipeline II=6
                    for (int i2 = 0; i2 < 12; i2++) {
#pragma HLS unroll
                        for (int j2 = 0; j2 < 10; j2++) {
#pragma HLS unroll
                            for (int k2 = 0; k2 < 5; k2++) {
#pragma HLS unroll
                                i = i0 * 12 + i2;
                                j = j0 * 10 + j2;
                                k = k0 * 210 + k1 * 5 + k2;
i_tmp_0 = (i0*12+0)/12;
i_tmp_1 = i2;
j_tmp_0 = (j0*10+0)/10;
j_tmp_1 = j2;
i_A_0 = (i0*12+0)/12;
i_A_1 = i2;
k_A_0 = k / 10;
k_A_1 = k % 10;
k_B_0 = (k0*210+k1*5+0)/5;
k_B_1 = k2;
j_B_0 = (j0*10+0)/10;
j_B_1 = j2;
tmp[i_tmp_0][i_tmp_1][j_tmp_0][j_tmp_1] += alpha*A[i_A_0][i_A_1][k_A_0][k_A_1]*B[k_B_0][k_B_1][j_B_0][j_B_1];
                            }
                        }
                    }
                }
            }
        }
    }
}

void task2(float D[90][2][5][44], float alpha, float beta, float2 vtmp[17100], float2 vA[18900], float2 vB[19950], float4 vC[10450], float4 vD[9900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int i_D_0;
    int i_D_1;
    int j_D_0;
    int j_D_1;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 20; j0++) {
            for (int i1 = 0; i1 < 180; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 1; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 11; j2++) {
#pragma HLS unroll
                        i = i0 * 180 + i1 * 1 + i2;
                        j = j0 * 11 + j2;
i_D_0 = i / 2;
i_D_1 = i % 2;
j_D_0 = j / 44;
j_D_1 = j % 44;
D[i_D_0][i_D_1][j_D_0][j_D_1] *= beta;
                    }
                }
            }
        }
    }
}

void task3(float D[90][2][5][44], float tmp[15][12][19][10], float C[190][1][5][44], float alpha, float beta, float2 vtmp[17100], float2 vA[18900], float2 vB[19950], float4 vC[10450], float4 vD[9900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int k, k_0, k_1;
    int i_D_0;
    int i_D_1;
    int j_D_0;
    int j_D_1;
    int i_tmp_0;
    int i_tmp_1;
    int k_tmp_0;
    int k_tmp_1;
    int k_C_0;
    int k_C_1;
    int j_C_0;
    int j_C_1;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 5; j0++) {
            for (int k0 = 0; k0 < 190; k0++) {
                for (int i1 = 0; i1 < 90; i1++) {
#pragma HLS pipeline II=1
                    for (int i2 = 0; i2 < 2; i2++) {
#pragma HLS unroll
                        for (int j2 = 0; j2 < 44; j2++) {
#pragma HLS unroll
                            for (int k2 = 0; k2 < 1; k2++) {
#pragma HLS unroll
                                i = i0 * 180 + i1 * 2 + i2;
                                j = j0 * 44 + j2;
                                k = k0 * 1 + k2;
i_D_0 = (i0*180+i1*2+0)/2;
i_D_1 = i2;
j_D_0 = (j0*44+0)/44;
j_D_1 = j2;
i_tmp_0 = i / 12;
i_tmp_1 = i % 12;
k_tmp_0 = k / 10;
k_tmp_1 = k % 10;
k_C_0 = k0;
k_C_1 = k2;
j_C_0 = j0;
j_C_1 = j2;
D[i_D_0][i_D_1][j_D_0][j_D_1] += tmp[i_tmp_0][i_tmp_1][k_tmp_0][k_tmp_1]*C[k_C_0][k_C_1][j_C_0][j_C_1];
                            }
                        }
                    }
                }
            }
        }
    }
}

// extern "C" {
void kernel_nlp(float alpha, float beta, float2 vtmp[17100], float2 vA[18900], float2 vB[19950], float4 vC[10450], float4 vD[9900]) {

#pragma HLS INTERFACE m_axi port=alpha offset=slave bundle=kernel_alpha
#pragma HLS INTERFACE m_axi port=beta offset=slave bundle=kernel_beta
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vD offset=slave bundle=kernel_D
#pragma HLS INTERFACE m_axi port=vtmp offset=slave bundle=kernel_tmp
#pragma HLS INTERFACE m_axi port=vC offset=slave bundle=kernel_C
#pragma HLS INTERFACE m_axi port=vB offset=slave bundle=kernel_B
#pragma HLS INTERFACE s_axilite port=alpha bundle=control
#pragma HLS INTERFACE s_axilite port=beta bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vD bundle=control
#pragma HLS INTERFACE s_axilite port=vtmp bundle=control
#pragma HLS INTERFACE s_axilite port=vC bundle=control
#pragma HLS INTERFACE s_axilite port=vB bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float A[15][12][21][10];
    float D[90][2][5][44];
    float tmp[15][12][19][10];
    float C[190][1][5][44];
    float B[42][5][19][10];

#pragma HLS ARRAY_PARTITION variable=A cyclic factor=12 dim=2
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=10 dim=4
#pragma HLS ARRAY_PARTITION variable=D cyclic factor=2 dim=2
#pragma HLS ARRAY_PARTITION variable=D cyclic factor=44 dim=4
#pragma HLS ARRAY_PARTITION variable=tmp cyclic factor=12 dim=2
#pragma HLS ARRAY_PARTITION variable=tmp cyclic factor=10 dim=4
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=1 dim=2
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=44 dim=4
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=5 dim=2
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=10 dim=4

    load_tmp(tmp, vtmp);
    load_A(A, vA);
    load_B(B, vB);
    load_D(D, vD);
    load_C(C, vC);
    task0(tmp, alpha, beta, vtmp, vA, vB, vC, vD);
    task1(A, tmp, B, alpha, beta, vtmp, vA, vB, vC, vD);
    task2(D, alpha, beta, vtmp, vA, vB, vC, vD);
    task3(D, tmp, C, alpha, beta, vtmp, vA, vB, vC, vD);
    store_tmp(tmp, vtmp);
    store_D(D, vD);
}
// }