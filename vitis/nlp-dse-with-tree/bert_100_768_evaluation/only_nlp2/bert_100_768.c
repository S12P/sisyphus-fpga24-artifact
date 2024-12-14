#pragma ACCEL kernel
void kernel_gemm(float C[100][768],float A[100][100],float B[100][768])
{
    int i;
    int j;
    int k;

    for (i = 0; i < 100; i++) {
        
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=12
        for (j = 0; j < 768; j++) {
            C[i][j] = 0;
#pragma ACCEL PARALLEL FACTOR=100
            for (k = 0; k < 100; k++) {
                C[i][j] +=  A[i][k] * B[k][j];
            }
        }
    }

}

