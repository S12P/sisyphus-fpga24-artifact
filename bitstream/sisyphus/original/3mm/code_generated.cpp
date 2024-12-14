#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_E (float E[15][12][19][10], float2 vE[17100]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 180; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 190; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_E = vE[i0 * 95 + i1/2];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+0) / 10;
            i1_1 = (i1+0) % 10;
            E[i0_0][i0_1][i1_0][i1_1] = tmp_E[0];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+1) / 10;
            i1_1 = (i1+1) % 10;
            E[i0_0][i0_1][i1_0][i1_1] = tmp_E[1];
        }
    }
}
void load_A (float A[15][12][25][8], float8 vA[4500]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 180; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 200; i1+=8){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float8 tmp_A = vA[i0 * 25 + i1/8];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+0) / 8;
            i1_1 = (i1+0) % 8;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[0];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+1) / 8;
            i1_1 = (i1+1) % 8;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[1];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+2) / 8;
            i1_1 = (i1+2) % 8;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[2];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+3) / 8;
            i1_1 = (i1+3) % 8;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[3];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+4) / 8;
            i1_1 = (i1+4) % 8;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[4];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+5) / 8;
            i1_1 = (i1+5) % 8;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[5];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+6) / 8;
            i1_1 = (i1+6) % 8;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[6];
            i0_0 = (i0+0) / 12;
            i0_1 = (i0+0) % 12;
            i1_0 = (i1+7) / 8;
            i1_1 = (i1+7) % 8;
            A[i0_0][i0_1][i1_0][i1_1] = tmp_A[7];
        }
    }
}
void load_B (float B[50][4][19][10], float2 vB[19000]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 200; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 190; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_B = vB[i0 * 95 + i1/2];
            i0_0 = (i0+0) / 4;
            i0_1 = (i0+0) % 4;
            i1_0 = (i1+0) / 10;
            i1_1 = (i1+0) % 10;
            B[i0_0][i0_1][i1_0][i1_1] = tmp_B[0];
            i0_0 = (i0+0) / 4;
            i0_1 = (i0+0) % 4;
            i1_0 = (i1+1) / 10;
            i1_1 = (i1+1) % 10;
            B[i0_0][i0_1][i1_0][i1_1] = tmp_B[1];
        }
    }
}
void load_F (float F[190][1][3][70], float2 vF[19950]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 190; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 210; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_F = vF[i0 * 105 + i1/2];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+0) / 70;
            i1_1 = (i1+0) % 70;
            F[i0_0][i0_1][i1_0][i1_1] = tmp_F[0];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+1) / 70;
            i1_1 = (i1+1) % 70;
            F[i0_0][i0_1][i1_0][i1_1] = tmp_F[1];
        }
    }
}
void load_D (float D[20][11][21][10], float2 vD[23100]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 220; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 210; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_D = vD[i0 * 105 + i1/2];
            i0_0 = (i0+0) / 11;
            i0_1 = (i0+0) % 11;
            i1_0 = (i1+0) / 10;
            i1_1 = (i1+0) % 10;
            D[i0_0][i0_1][i1_0][i1_1] = tmp_D[0];
            i0_0 = (i0+0) / 11;
            i0_1 = (i0+0) % 11;
            i1_0 = (i1+1) / 10;
            i1_1 = (i1+1) % 10;
            D[i0_0][i0_1][i1_0][i1_1] = tmp_D[1];
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
void load_G_S4 (float G[12][1][3][70], float2 vG[18900], int d0, int d1) {
#pragma HLS inline
    for (int i0 = 0; i0 < 12; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 210; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_G = vG[(i0 + d0 * 12) * 105 + (i1 + d1 * 210)/2];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+0) / 70;
            i1_1 = (i1+0) % 70;
            G[i0_0][i0_1][i1_0][i1_1] = tmp_G[0];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+1) / 70;
            i1_1 = (i1+1) % 70;
            G[i0_0][i0_1][i1_0][i1_1] = tmp_G[1];
        }
    }
}

void store_G_S4 (float G[12][1][3][70], float2 vG[18900], int d0, int d1) {
#pragma HLS inline
    for (int i0 = 0; i0 < 12; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 210; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_G;// = vG[(i0 + d0 * 90) * 105 + (i1 + d1 * 210)/2];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+0) / 70;
            i1_1 = (i1+0) % 70;
            tmp_G[0] = G[i0_0][i0_1][i1_0][i1_1];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+1) / 70;
            i1_1 = (i1+1) % 70;
            tmp_G[1] = G[i0_0][i0_1][i1_0][i1_1];
            vG[(i0 + d0 * 12) * 105 + (i1 + d1 * 210)/2] = tmp_G;
        }
    }
}

void load_G_S5 (float G[90][1][3][70], float2 vG[18900], int d0, int d1) {
#pragma HLS inline
    for (int i0 = 0; i0 < 90; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 210; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_G = vG[(i0 + d0 * 90) * 105 + (i1 + d1 * 210)/2];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+0) / 70;
            i1_1 = (i1+0) % 70;
            G[i0_0][i0_1][i1_0][i1_1] = tmp_G[0];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+1) / 70;
            i1_1 = (i1+1) % 70;
            G[i0_0][i0_1][i1_0][i1_1] = tmp_G[1];
        }
    }
}
void store_E (float E[15][12][19][10], float2 vE[17100]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 180; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 190; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_E;
            i0_0 = (i0+0) / 12; 
            i0_1 = (i0+0) % 12; 
            i1_0 = (i1+0) / 10; 
            i1_1 = (i1+0) % 10; 
            tmp_E[0] = E[i0_0][i0_1][i1_0][i1_1];
            i0_0 = (i0+0) / 12; 
            i0_1 = (i0+0) % 12; 
            i1_0 = (i1+1) / 10; 
            i1_1 = (i1+1) % 10; 
            tmp_E[1] = E[i0_0][i0_1][i1_0][i1_1];
            vE[i0 * 95 + i1/2] = tmp_E;
        }
    }
}
void store_G_S5 (float G[90][1][3][70], float2 vG[18900], int d0, int d1) {
#pragma HLS inline
    for (int i0 = 0; i0 < 90; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 210; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_G;// = vG[(i0 + d0 * 90) * 105 + (i1 + d1 * 210)/2];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+0) / 70;
            i1_1 = (i1+0) % 70;
            tmp_G[0] = G[i0_0][i0_1][i1_0][i1_1];
            i0_0 = (i0+0) / 1;
            i0_1 = (i0+0) % 1;
            i1_0 = (i1+1) / 70;
            i1_1 = (i1+1) % 70;
            tmp_G[1] = G[i0_0][i0_1][i1_0][i1_1];
            vG[(i0 + d0 * 90) * 105 + (i1)/2] = tmp_G;
        }
    }
}
void store_F (float F[190][1][3][70], float2 vF[19950]) {
#pragma HLS inline
    for (int i0 = 0; i0 < 190; i0+=1){
       int i0_0;
       int i0_1;
        for (int i1 = 0; i1 < 210; i1+=2){
           int i1_0;
           int i1_1;
#pragma HLS pipeline II=1
            float2 tmp_F;
            i0_0 = (i0+0) / 1; 
            i0_1 = (i0+0) % 1; 
            i1_0 = (i1+0) / 70; 
            i1_1 = (i1+0) % 70; 
            tmp_F[0] = F[i0_0][i0_1][i1_0][i1_1];
            i0_0 = (i0+0) / 1; 
            i0_1 = (i0+0) % 1; 
            i1_0 = (i1+1) / 70; 
            i1_1 = (i1+1) % 70; 
            tmp_F[1] = F[i0_0][i0_1][i1_0][i1_1];
            vF[i0 * 105 + i1/2] = tmp_F;
        }
    }
}

void task0(float E[15][12][19][10], float2 vE[17100], float8 vA[4500], float2 vB[19000], float2 vF[19950], float4 vC[10450], float2 vD[23100], float2 vG[18900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int i_E_0;
    int i_E_1;
    int j_E_0;
    int j_E_1;
    for (int i0 = 0; i0 < 15; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
            for (int j1 = 0; j1 < 19; j1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 12; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 10; j2++) {
#pragma HLS unroll
                        i = i0 * 12 + i2;
                        j = j0 * 190 + j1 * 10 + j2;
i_E_0 = (i0*12+0)/12;
i_E_1 = i2;
j_E_0 = (j0*190+j1*10+0)/10;
j_E_1 = j2;
E[i_E_0][i_E_1][j_E_0][j_E_1]=0.0;
                    }
                }
            }
        }
    }
}

void task1(float E[15][12][19][10], float A[15][12][25][8], float B[50][4][19][10], float2 vE[17100], float8 vA[4500], float2 vB[19000], float2 vF[19950], float4 vC[10450], float2 vD[23100], float2 vG[18900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int k, k_0, k_1;
    int i_E_0;
    int i_E_1;
    int j_E_0;
    int j_E_1;
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
                for (int k1 = 0; k1 < 50; k1++) {
#pragma HLS pipeline II=6
                    for (int i2 = 0; i2 < 12; i2++) {
#pragma HLS unroll
                        for (int j2 = 0; j2 < 10; j2++) {
#pragma HLS unroll
                            for (int k2 = 0; k2 < 4; k2++) {
#pragma HLS unroll
                                i = i0 * 12 + i2;
                                j = j0 * 10 + j2;
                                k = k0 * 200 + k1 * 4 + k2;
i_E_0 = (i0*12+0)/12;
i_E_1 = i2;
j_E_0 = (j0*10+0)/10;
j_E_1 = j2;
i_A_0 = (i0*12+0)/12;
i_A_1 = i2;
k_A_0 = k / 8;
k_A_1 = k % 8;
k_B_0 = (k0*200+k1*4+0)/4;
k_B_1 = k2;
j_B_0 = (j0*10+0)/10;
j_B_1 = j2;
E[i_E_0][i_E_1][j_E_0][j_E_1] += A[i_A_0][i_A_1][k_A_0][k_A_1]*B[k_B_0][k_B_1][j_B_0][j_B_1];
                            }
                        }
                    }
                }
            }
        }
    }
}

void task2(float F[190][1][3][70], float2 vE[17100], float8 vA[4500], float2 vB[19000], float2 vF[19950], float4 vC[10450], float2 vD[23100], float2 vG[18900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int i_F_0;
    int i_F_1;
    int j_F_0;
    int j_F_1;
    for (int i0 = 0; i0 < 10; i0++) {
        for (int j0 = 0; j0 < 3; j0++) {
            for (int i1 = 0; i1 < 19; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 1; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 70; j2++) {
#pragma HLS unroll
                        i = i0 * 19 + i1 * 1 + i2;
                        j = j0 * 70 + j2;
i_F_0 = (i0*19+i1*1+0)/1;
i_F_1 = i2;
j_F_0 = (j0*70+0)/70;
j_F_1 = j2;
F[i_F_0][i_F_1][j_F_0][j_F_1]=0.0;
                    }
                }
            }
        }
    }
}

void task3(float F[190][1][3][70], float D[20][11][21][10], float C[190][1][5][44], float2 vE[17100], float8 vA[4500], float2 vB[19000], float2 vF[19950], float4 vC[10450], float2 vD[23100], float2 vG[18900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int k, k_0, k_1;
    int i_F_0;
    int i_F_1;
    int j_F_0;
    int j_F_1;
    int i_C_0;
    int i_C_1;
    int k_C_0;
    int k_C_1;
    int k_D_0;
    int k_D_1;
    int j_D_0;
    int j_D_1;
    for (int i0 = 0; i0 < 1; i0++) {
        for (int j0 = 0; j0 < 21; j0++) {
            for (int k0 = 0; k0 < 20; k0++) {
                for (int i1 = 0; i1 < 190; i1++) {
#pragma HLS pipeline II=1
                    for (int i2 = 0; i2 < 1; i2++) {
#pragma HLS unroll
                        for (int j2 = 0; j2 < 10; j2++) {
#pragma HLS unroll
                            for (int k2 = 0; k2 < 11; k2++) {
#pragma HLS unroll
                                i = i0 * 190 + i1 * 1 + i2;
                                j = j0 * 10 + j2;
                                k = k0 * 11 + k2;
i_F_0 = (i0*190+i1*1+0)/1;
i_F_1 = i2;
j_F_0 = j / 70;
j_F_1 = j % 70;
i_C_0 = (i0*190+i1*1+0)/1;
i_C_1 = i2;
k_C_0 = k / 44;
k_C_1 = k % 44;
k_D_0 = (k0*11+0)/11;
k_D_1 = k2;
j_D_0 = (j0*10+0)/10;
j_D_1 = j2;
F[i_F_0][i_F_1][j_F_0][j_F_1] += C[i_C_0][i_C_1][k_C_0][k_C_1]*D[k_D_0][k_D_1][j_D_0][j_D_1];
                            }
                        }
                    }
                }
            }
        }
    }
}

void task4(float G[12][1][3][70], float2 vE[17100], float8 vA[4500], float2 vB[19000], float2 vF[19950], float4 vC[10450], float2 vD[23100], float2 vG[18900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int j_G_0;
    int j_G_1;
    for (int i0 = 0; i0 < 15; i0++) {
        load_G_S4(G, vG, i0, 0);
        for (int j0 = 0; j0 < 3; j0++) {
            for (int i1 = 0; i1 < 12; i1++) {
#pragma HLS pipeline II=1
                for (int i2 = 0; i2 < 1; i2++) {
#pragma HLS unroll
                    for (int j2 = 0; j2 < 70; j2++) {
#pragma HLS unroll
                        i = i0 * 12 + i1 * 1 + i2;
                        j = j0 * 70 + j2;
j_G_0 = j / 12;
j_G_1 = j % 12;
G[i1][0][j0][j2]=0.0;
                    }
                }
            }
        }
        store_G_S4(G, vG, i0, 0);
    }
}

void task5(float F[190][1][3][70], float E[15][12][19][10], float G[90][1][3][70], float2 vE[17100], float8 vA[4500], float2 vB[19000], float2 vF[19950], float4 vC[10450], float2 vD[23100], float2 vG[18900]) {
#pragma HLS inline
    int i, i_0, i_1;
    int j, j_0, j_1;
    int k, k_0, k_1;
    int j_G_0;
    int j_G_1;
    int i_E_0;
    int i_E_1;
    int k_E_0;
    int k_E_1;
    int k_F_0;
    int k_F_1;
    int j_F_0;
    int j_F_1;
    for (int i0 = 0; i0 < 2; i0++) {
        load_G_S5(G, vG, i0, 0);
        for (int j0 = 0; j0 < 3; j0++) {
            for (int k0 = 0; k0 < 190; k0++) {
                for (int i1 = 0; i1 < 90; i1++) {
#pragma HLS pipeline II=1
                    for (int i2 = 0; i2 < 1; i2++) {
#pragma HLS unroll
                        for (int j2 = 0; j2 < 70; j2++) {
#pragma HLS unroll
                            for (int k2 = 0; k2 < 1; k2++) {
#pragma HLS unroll
                                i = i0 * 90 + i1 * 1 + i2;
                                j = j0 * 70 + j2;
                                k = k0 * 1 + k2;
j_G_0 = j / 90;
j_G_1 = j % 90;
i_E_0 = i / 12;
i_E_1 = i % 12;
k_E_0 = k / 10;
k_E_1 = k % 10;
k_F_0 = (k0*1+0)/1;
k_F_1 = k2;
j_F_0 = (j0*70+0)/70;
j_F_1 = j2;
G[i1][0][j0][j2] += E[i_E_0][i_E_1][k_E_0][k_E_1]*F[k_F_0][k_F_1][j_F_0][j_F_1];
                            }
                        }
                    }
                }
            }
        }
        store_G_S5(G, vG, i0, 0);
    }
}

void kernel_nlp(float2 vE[17100], float8 vA[4500], float2 vB[19000], float2 vF[19950], float4 vC[10450], float2 vD[23100], float2 vG[18900]) {

#pragma HLS INTERFACE m_axi port=vF offset=slave bundle=kernel_F
#pragma HLS INTERFACE m_axi port=vE offset=slave bundle=kernel_E
#pragma HLS INTERFACE m_axi port=vA offset=slave bundle=kernel_A
#pragma HLS INTERFACE m_axi port=vB offset=slave bundle=kernel_B
#pragma HLS INTERFACE m_axi port=vD offset=slave bundle=kernel_D
#pragma HLS INTERFACE m_axi port=vC offset=slave bundle=kernel_C
#pragma HLS INTERFACE m_axi port=vG offset=slave bundle=kernel_G
#pragma HLS INTERFACE s_axilite port=vF bundle=control
#pragma HLS INTERFACE s_axilite port=vE bundle=control
#pragma HLS INTERFACE s_axilite port=vA bundle=control
#pragma HLS INTERFACE s_axilite port=vB bundle=control
#pragma HLS INTERFACE s_axilite port=vD bundle=control
#pragma HLS INTERFACE s_axilite port=vC bundle=control
#pragma HLS INTERFACE s_axilite port=vG bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float F[190][1][3][70];
    float E[15][12][19][10];
    float A[15][12][25][8];
    float B[50][4][19][10];
    float D[20][11][21][10];
    float C[190][1][5][44];
    float G_S4[12][1][3][70];
    float G_S5[90][1][3][70];

#pragma HLS ARRAY_PARTITION variable=F cyclic factor=1 dim=2
#pragma HLS ARRAY_PARTITION variable=F cyclic factor=70 dim=4
#pragma HLS ARRAY_PARTITION variable=E cyclic factor=12 dim=2
#pragma HLS ARRAY_PARTITION variable=E cyclic factor=10 dim=4
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=12 dim=2
#pragma HLS ARRAY_PARTITION variable=A cyclic factor=8 dim=4
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=4 dim=2
#pragma HLS ARRAY_PARTITION variable=B cyclic factor=10 dim=4
#pragma HLS ARRAY_PARTITION variable=D cyclic factor=11 dim=2
#pragma HLS ARRAY_PARTITION variable=D cyclic factor=10 dim=4
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=1 dim=2
#pragma HLS ARRAY_PARTITION variable=C cyclic factor=44 dim=4
#pragma HLS ARRAY_PARTITION variable=G_S4 cyclic factor=1 dim=2
#pragma HLS ARRAY_PARTITION variable=G_S5 cyclic factor=1 dim=2
#pragma HLS ARRAY_PARTITION variable=G_S4 cyclic factor=70 dim=4
#pragma HLS ARRAY_PARTITION variable=G_S5 cyclic factor=70 dim=4

    load_E(E, vE);
    load_A(A, vA);
    load_B(B, vB);
    load_F(F, vF);
    load_D(D, vD);
    load_C(C, vC);
    task0(E, vE, vA, vB, vF, vC, vD, vG);
    task1(E, A, B, vE, vA, vB, vF, vC, vD, vG);
    task2(F, vE, vA, vB, vF, vC, vD, vG);
    task3(F, D, C, vE, vA, vB, vF, vC, vD, vG);
    task4(G_S4, vE, vA, vB, vF, vC, vD, vG);
    task5(F, E, G_S5, vE, vA, vB, vF, vC, vD, vG);
    store_E(E, vE);
    store_F(F, vF);
}
