#pragma ACCEL kernel
void kernel_gemm(float C[100][3072],float A[100][100],float B[100][3072])
{
    int i;
    int j;
    int k;

#pragma ACCEL PARALLEL FACTOR=10
    for (i = 0; i < 100; i++) {
        
#pragma ACCEL PARALLEL FACTOR=6
        for (j = 0; j < 3072; j++) {
            C[i][j] = 0;
#pragma ACCEL PIPELINE FLATTEN
#pragma ACCEL PARALLEL FACTOR=5
            for (k = 0; k < 100; k++) {
                C[i][j] +=  A[i][k] * B[k][j];
            }
        }
    }

}

