#include "__merlin_opencl_if.h"
int opencl_init_kernel_buffer();
int __merlin_release_kernel_buffer();
extern opencl_kernel __kernel_gemm_kernel;
extern cl_event __event_kernel_gemm;
#ifdef __cplusplus
extern "C" {
#endif
int __merlin_init_kernel_gemm();
int __merlin_release_kernel_gemm();
int __merlin_wait_kernel_kernel_gemm();
int __merlin_wait_write_kernel_gemm();
int __merlin_wait_read_kernel_gemm();
#ifdef __cplusplus
}
#endif
extern opencl_mem __kernel_gemm__A_buffer;
extern cl_event __event___kernel_gemm__A_buffer;
extern opencl_mem __kernel_gemm__B_buffer;
extern cl_event __event___kernel_gemm__B_buffer;
extern opencl_mem __kernel_gemm__C_buffer;
extern cl_event __event___kernel_gemm__C_buffer;
