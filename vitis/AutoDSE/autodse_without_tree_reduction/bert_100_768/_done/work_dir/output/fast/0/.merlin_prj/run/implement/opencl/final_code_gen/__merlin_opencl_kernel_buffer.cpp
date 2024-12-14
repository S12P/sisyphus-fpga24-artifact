#include "__merlin_opencl_kernel_buffer.h"
opencl_kernel __kernel_gemm_kernel;
cl_event __event_kernel_gemm;
opencl_mem __kernel_gemm__A_buffer;
cl_event __event___kernel_gemm__A_buffer;
opencl_mem __kernel_gemm__B_buffer;
cl_event __event___kernel_gemm__B_buffer;
opencl_mem __kernel_gemm__C_buffer;
cl_event __event___kernel_gemm__C_buffer;
int __merlin_init_kernel_gemm(){
	#pragma ACCEL debug printf("[Merlin Info] Start create kernel for %s....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_kernel(&__kernel_gemm_kernel, (char *)"kernel_gemm");
	#pragma ACCEL debug printf("[Merlin Info] Successful create kernel for %s....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
	#pragma ACCEL debug printf("[Merlin Info] Start create buffer for %s....\n", "A");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_buffer(&__kernel_gemm__A_buffer, (int64_t)4*100*100, 2, NULL);
	#pragma ACCEL debug printf("[Merlin Info] Successful create buffer for %s....\n", "A");
	#pragma ACCEL debug fflush(stdout);
	#pragma ACCEL debug printf("[Merlin Info] Start create buffer for %s....\n", "B");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_buffer(&__kernel_gemm__B_buffer, (int64_t)4*100*768, 2, NULL);
	#pragma ACCEL debug printf("[Merlin Info] Successful create buffer for %s....\n", "B");
	#pragma ACCEL debug fflush(stdout);
	#pragma ACCEL debug printf("[Merlin Info] Start create buffer for %s....\n", "C");
	#pragma ACCEL debug fflush(stdout);
	opencl_create_buffer(&__kernel_gemm__C_buffer, (int64_t)4*100*768, 2, NULL);
	#pragma ACCEL debug printf("[Merlin Info] Successful create buffer for %s....\n", "C");
	#pragma ACCEL debug fflush(stdout);
	return 0;
}
int opencl_init_kernel_buffer(){
	int __merlin_init_kernel_gemm();
	return 0;
}
int __merlin_release_kernel_gemm(){
	if(__kernel_gemm_kernel) {
		opencl_release_kernel(__kernel_gemm_kernel);
	}
	if(__event_kernel_gemm) {
		opencl_release_event(__event_kernel_gemm);
	}
	if(__kernel_gemm__A_buffer) {
		opencl_release_mem_object(__kernel_gemm__A_buffer);
	}
	if(__kernel_gemm__B_buffer) {
		opencl_release_mem_object(__kernel_gemm__B_buffer);
	}
	if(__kernel_gemm__C_buffer) {
		opencl_release_mem_object(__kernel_gemm__C_buffer);
	}
	return 0;
}
int __merlin_release_kernel_buffer(){
	int __merlin_release_kernel_gemm();
	return 0;
}
int __merlin_wait_kernel_kernel_gemm(){
	opencl_wait_event(__event_kernel_gemm);
	return 0;
}
int __merlin_wait_write_kernel_gemm(){
		opencl_wait_event(__event___kernel_gemm__A_buffer);
	if(__kernel_gemm__A_buffer) {
		opencl_release_mem_object(__kernel_gemm__A_buffer);
	}
		opencl_wait_event(__event___kernel_gemm__B_buffer);
	if(__kernel_gemm__B_buffer) {
		opencl_release_mem_object(__kernel_gemm__B_buffer);
	}
		opencl_wait_event(__event___kernel_gemm__C_buffer);
	if(__kernel_gemm__C_buffer) {
		opencl_release_mem_object(__kernel_gemm__C_buffer);
	}
	return 0;
}
int __merlin_wait_read_kernel_gemm(){
		opencl_wait_event(__event___kernel_gemm__A_buffer);
	if(__kernel_gemm__A_buffer) {
		opencl_release_mem_object(__kernel_gemm__A_buffer);
	}
		opencl_wait_event(__event___kernel_gemm__B_buffer);
	if(__kernel_gemm__B_buffer) {
		opencl_release_mem_object(__kernel_gemm__B_buffer);
	}
		opencl_wait_event(__event___kernel_gemm__C_buffer);
	if(__kernel_gemm__C_buffer) {
		opencl_release_mem_object(__kernel_gemm__C_buffer);
	}
	return 0;
}
