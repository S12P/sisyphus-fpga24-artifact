
#ifdef __cplusplus
extern "C" {
#endif
extern int __merlin_init(const char * bitstream);
extern int __merlin_release();
extern void __merlin_kernel_bicg(int m,int n,float A[410][390],float s[390],float q[410],float p[390],float r[410]);
#ifdef __cplusplus
}
#endif
