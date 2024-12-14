#include "merlin_type_define.h"
static void __merlin_dummy_0();
void kernel_gemm(float C[100][768],float A[100][100],float B[100][768]);
static void __merlin_dummy_extern_int_merlin_include_L_();
#include "__merlinhead_kernel_top.h"
static void __merlin_dummy_extern_int_merlin_include_L_();

void __merlinwrapper_kernel_gemm(float C[100][768],float A[100][100],float B[100][768])
{
  
#pragma ACCEL kernel
  kernel_gemm(C,A,B);
}

void __merlin_kernel_gemm(float C[100][768],float A[100][100],float B[100][768])
{
  
#pragma ACCEL string __merlin_check_opencl();
  
#pragma ACCEL string __merlin_init_kernel_gemm();
  __merlinwrapper_kernel_gemm(C,A,B);
  
#pragma ACCEL string __merlin_release_kernel_gemm();
}

void __merlin_write_buffer_kernel_gemm(float C[100][768],float A[100][100],float B[100][768])
{
}

void __merlin_read_buffer_kernel_gemm(float C[100][768],float A[100][100],float B[100][768])
{
}

void __merlin_execute_kernel_gemm(float C[100][768],float A[100][100],float B[100][768])
{
}
