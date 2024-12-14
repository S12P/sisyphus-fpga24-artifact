
#ifdef __cplusplus
extern "C" {
#endif
extern int __merlin_init(const char * bitstream);
extern int __merlin_release();
extern void __merlin_kernel_gemm(float alpha,float beta,float C[200][220],float A[200][240],float B[240][220]);
#ifdef __cplusplus
}
#endif
