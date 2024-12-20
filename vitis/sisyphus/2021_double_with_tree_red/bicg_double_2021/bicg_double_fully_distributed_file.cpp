#include <ap_int.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <cstring>

/*************************************************
 This file was automatically generated by Sisyphus
*************************************************/

typedef hls::vector<double,16> double16;
typedef hls::vector<double,8> double8;
typedef hls::vector<double,4> double4;
typedef hls::vector<double,2> double2;
typedef hls::vector<double,1> double1;



void kernel_nlp(double A[410][390], double s[390], double q[410], double p[390], double r[410]) {

    int j;
    int i;
    for ( i = 0; i < 390; i++) {
        s[i] = 0.0;
    }
    for ( i = 0; i < 410; i++) {
        q[i] = 0.0;
    }
    for ( j = 0; j < 390; j++) {
        for ( i = 0; i < 410; i++) {
            s[j] = s[j] + r[i] * A[i][j];
        }
    }
    for ( i = 0; i < 410; i++) {
        for ( j = 0; j < 390; j++) {
            q[i] = q[i] + A[i][j] * p[j];
        }
    }
}
