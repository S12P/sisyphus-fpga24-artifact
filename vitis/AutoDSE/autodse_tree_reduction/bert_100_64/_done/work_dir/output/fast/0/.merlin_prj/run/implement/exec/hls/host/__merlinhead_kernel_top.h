#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern int __merlin_init(const char * bitstream);
extern int __merlin_release();
extern int __merlin_init_kernel_gemm();
extern int __merlin_release_kernel_gemm();
extern int __merlin_wait_kernel_kernel_gemm();
extern int __merlin_wait_write_kernel_gemm();
extern int __merlin_wait_read_kernel_gemm();
extern void __merlinwrapper_kernel_gemm(float C[100][64],float A[100][100],float B[100][64]);
extern void __merlin_write_buffer_kernel_gemm(float C[100][64],float A[100][100],float B[100][64]);
extern void __merlin_read_buffer_kernel_gemm(float C[100][64],float A[100][100],float B[100][64]);
extern void __merlin_execute_kernel_gemm(float C[100][64],float A[100][100],float B[100][64]);
extern void __merlin_kernel_gemm(float C[100][64],float A[100][100],float B[100][64]);
#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
}
#endif