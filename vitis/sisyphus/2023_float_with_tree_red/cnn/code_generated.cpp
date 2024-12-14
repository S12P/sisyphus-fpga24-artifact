#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

typedef hls::vector<float,16> float16;
typedef hls::vector<float,8> float8;
typedef hls::vector<float,4> float4;
typedef hls::vector<float,2> float2;
typedef hls::vector<float,1> float1;

void load_input_S0 (float input[1][228][228], float4 vinput[3326976], int d0) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 1; i0+=1){
        for (int i1 = 0; i1 < 228; i1+=1){
            for (int i2 = 0; i2 < 228; i2+=4){
#pragma HLS pipeline II=1
                float4 tmp_input = vinput[(i0 + d0 * 1) * 12996 + i1 * 57 + i2/4];
                input[i0][i1][i2 + 0] = tmp_input[0];
                input[i0][i1][i2 + 1] = tmp_input[1];
                input[i0][i1][i2 + 2] = tmp_input[2];
                input[i0][i1][i2 + 3] = tmp_input[3];
            }
        }
    }
}
void load_output_S0 (float output[16][224][224], float16 voutput[802816], int d0) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 16; i0+=1){
        for (int i1 = 0; i1 < 224; i1+=1){
            for (int i2 = 0; i2 < 224; i2+=16){
#pragma HLS pipeline II=1
                float16 tmp_output = voutput[(i0 + d0 * 16) * 3136 + i1 * 14 + i2/16];
                output[i0][i1][i2 + 0] = tmp_output[0];
                output[i0][i1][i2 + 1] = tmp_output[1];
                output[i0][i1][i2 + 2] = tmp_output[2];
                output[i0][i1][i2 + 3] = tmp_output[3];
                output[i0][i1][i2 + 4] = tmp_output[4];
                output[i0][i1][i2 + 5] = tmp_output[5];
                output[i0][i1][i2 + 6] = tmp_output[6];
                output[i0][i1][i2 + 7] = tmp_output[7];
                output[i0][i1][i2 + 8] = tmp_output[8];
                output[i0][i1][i2 + 9] = tmp_output[9];
                output[i0][i1][i2 + 10] = tmp_output[10];
                output[i0][i1][i2 + 11] = tmp_output[11];
                output[i0][i1][i2 + 12] = tmp_output[12];
                output[i0][i1][i2 + 13] = tmp_output[13];
                output[i0][i1][i2 + 14] = tmp_output[14];
                output[i0][i1][i2 + 15] = tmp_output[15];
            }
        }
    }
}
void load_weight_S0 (float weight[16][256][5][5], float1 vweight[1638400], int d0) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 16; i0+=1){
        for (int i1 = 0; i1 < 256; i1+=1){
            for (int i2 = 0; i2 < 5; i2+=1){
                for (int i3 = 0; i3 < 5; i3+=1){
#pragma HLS pipeline II=1
                    float1 tmp_weight = vweight[(i0 + d0 * 16) * 6400 + i1 * 25 + i2 * 5 + i3/1];
                    weight[i0][i1][i2][i3 + 0] = tmp_weight[0];
                }
            }
        }
    }
}
void store_output_S0 (float output[16][224][224], float16 voutput[802816], int d0) {
#pragma HLS inline off
    for (int i0 = 0; i0 < 16; i0+=1){
        for (int i1 = 0; i1 < 224; i1+=1){
            for (int i2 = 0; i2 < 224; i2+=16){
#pragma HLS pipeline II=1
                float16 tmp_output;
                tmp_output[0] = output[i0][i1][i2 + 0];
                tmp_output[1] = output[i0][i1][i2 + 1];
                tmp_output[2] = output[i0][i1][i2 + 2];
                tmp_output[3] = output[i0][i1][i2 + 3];
                tmp_output[4] = output[i0][i1][i2 + 4];
                tmp_output[5] = output[i0][i1][i2 + 5];
                tmp_output[6] = output[i0][i1][i2 + 6];
                tmp_output[7] = output[i0][i1][i2 + 7];
                tmp_output[8] = output[i0][i1][i2 + 8];
                tmp_output[9] = output[i0][i1][i2 + 9];
                tmp_output[10] = output[i0][i1][i2 + 10];
                tmp_output[11] = output[i0][i1][i2 + 11];
                tmp_output[12] = output[i0][i1][i2 + 12];
                tmp_output[13] = output[i0][i1][i2 + 13];
                tmp_output[14] = output[i0][i1][i2 + 14];
                tmp_output[15] = output[i0][i1][i2 + 15];
                voutput[(i0 + d0 * 16) * 3136 + i1 * 14 + i2/16] = tmp_output;
            }
        }
    }
}

void task0(float input[1][228][228], float output[16][224][224], float weight[16][256][5][5], float4 vinput[3326976], float1 vweight[1638400], float16 voutput[802816]) {
    int i;
    int j;
    int h;
    int w;
    int p;
    int q;
    for (int i0 = 0; i0 < 16; i0++) {
        load_weight_S0(weight, vweight, i0);
        load_output_S0(output, voutput, i0);
        for (int j0 = 0; j0 < 256; j0++) {
            load_input_S0(input, vinput, j0);
            for (int h0 = 0; h0 < 14; h0++) {
                for (int w0 = 0; w0 < 1; w0++) {
                    for (int p0 = 0; p0 < 5; p0++) {
                        for (int q0 = 0; q0 < 1; q0++) {
                            for (int w1 = 0; w1 < 224; w1++) {
#pragma HLS pipeline
                                for (int i2 = 0; i2 < 16; i2++) {
                                        for (int h2 = 0; h2 < 16; h2++) {
                                            for (int w2 = 0; w2 < 1; w2++) {
                                    for (int j2 = 0; j2 < 1; j2++) {
                                                for (int p2 = 0; p2 < 1; p2++) {
                                                    for (int q2 = 0; q2 < 5; q2++) {
                                                        i = i0 * 16 + i2;
                                                        j = j0 * 1 + j2;
                                                        h = h0 * 16 + h2;
                                                        w = w0 * 224 + w1 * 1 + w2;
                                                        p = p0 * 1 + p2;
                                                        q = q0 * 5 + q2;
                                                        output[i2][h][w] +=weight[i2][j][p][q] * input[j2][h+p][w+q] ;
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
            }
        }
        store_output_S0(output, voutput, i0);
    }
}

void kernel_nlp(float4 vinput[3326976], float1 vweight[1638400], float16 voutput[802816]) {

#pragma HLS INTERFACE m_axi port=vinput offset=slave bundle=kernel_input
#pragma HLS INTERFACE m_axi port=voutput offset=slave bundle=kernel_output
#pragma HLS INTERFACE m_axi port=vweight offset=slave bundle=kernel_weight
#pragma HLS INTERFACE s_axilite port=vinput bundle=control
#pragma HLS INTERFACE s_axilite port=voutput bundle=control
#pragma HLS INTERFACE s_axilite port=vweight bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

    float input_S0[1][228][228];
    float output_S0[16][224][224];
    float weight_S0[16][256][5][5];

#pragma HLS ARRAY_PARTITION variable=input_S0 cyclic factor=1 dim=1
#pragma HLS ARRAY_PARTITION variable=input_S0 cyclic factor=16 dim=2
#pragma HLS ARRAY_PARTITION variable=input_S0 cyclic factor=5 dim=3
#pragma HLS ARRAY_PARTITION variable=output_S0 cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=output_S0 cyclic factor=16 dim=2
#pragma HLS ARRAY_PARTITION variable=output_S0 cyclic factor=1 dim=3
#pragma HLS ARRAY_PARTITION variable=weight_S0 cyclic factor=16 dim=1
#pragma HLS ARRAY_PARTITION variable=weight_S0 cyclic factor=1 dim=2
#pragma HLS ARRAY_PARTITION variable=weight_S0 cyclic factor=1 dim=3
#pragma HLS ARRAY_PARTITION variable=weight_S0 cyclic factor=5 dim=4

    task0(input_S0, output_S0, weight_S0, vinput, vweight, voutput);
}
