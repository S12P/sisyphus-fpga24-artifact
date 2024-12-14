

#pragma ACCEL kernel
void gemm_merlin(float alpha, float beta, float C[200][220], float A[200][240], float B[240][220]) {
    int i;
    int j;
    for (int i0 = 0; i0 < 4; i0++) {
        for (int j0 = 0; j0 < 1; j0++) {
#pragma ACCEL pipeline flatten
            for (int j1 = 0; j1 < 11; j1++) {
                for (int i2 = 0; i2 < 50; i2++) {
                    for (int j2 = 0; j2 < 20; j2++) {
                        i = i0 * 50 + i2;
                        j = j0 * 220 + j1 * 20 + j2;
                        C[i][j] *=beta ;
                     }
                }
            }
        }
    }

    for (int j0 = 0; j0 < 11; j0++) {
        for (int k0 = 0; k0 < 1; k0++) {
            for (int i0 = 0; i0 < 4; i0++) {
#pragma ACCEL pipeline flatten
                for (int k1 = 0; k1 < 48; k1++) {

                    for (int j2 = 0; j2 < 20; j2++) {
                            for (int i2 = 0; i2 < 50; i2++) {
                        for (int k2 = 0; k2 < 5; k2++) {
                                j = j0 * 20 + j2;
                                k = k0 * 240 + k1 * 5 + k2;
                                i = i0 * 50 + i2;
                                C[i][j] +=alpha * A[i][k] * B[k][j] ;
                             }
                        }
                    }
                }
            }
        }
    }
}