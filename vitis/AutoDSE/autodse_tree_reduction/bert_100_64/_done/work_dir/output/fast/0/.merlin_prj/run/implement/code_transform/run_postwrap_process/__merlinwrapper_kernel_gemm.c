#include "merlin_type_define.h"
static void __merlin_dummy_0();
void kernel_gemm(float C[100][64],float A[100][100],float B[100][64]);
extern int __merlin_include__LB___merlinhead_kernel_top_h_0;
#include "__merlinhead_kernel_top.h"
extern int __merlin_include__LE___merlinhead_kernel_top_h_0;

void __merlinwrapper_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
  
#pragma ACCEL kernel
  kernel_gemm(C,A,B);
}

void __merlin_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
  
#pragma ACCEL string __merlin_check_opencl();
  
#pragma ACCEL string __merlin_init_kernel_gemm();
  __merlinwrapper_kernel_gemm(C,A,B);
  
#pragma ACCEL string __merlin_release_kernel_gemm();
}

void __merlin_write_buffer_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
}

void __merlin_read_buffer_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
}

void __merlin_execute_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
}
