
#ifdef __cplusplus
extern "C" {
#endif
extern int __merlin_init(const char * bitstream);
extern int __merlin_release();
extern void __merlin_kernel_gemm(float C[100][64],float A[100][100],float B[100][64]);
#ifdef __cplusplus
}
#endif
