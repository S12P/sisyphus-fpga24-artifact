
#ifdef __cplusplus
extern "C" {
#endif
extern int __merlin_init(const char * bitstream);
extern int __merlin_release();
extern void __merlin_kernel_gemver(float alpha,float beta,float A[400][400],float u1[400],float v1[400],float u2[400],float v2[400],float w[400],float x[400],float y[400],float z[400]);
#ifdef __cplusplus
}
#endif
