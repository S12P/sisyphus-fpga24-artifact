#include "cmost.h"
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include "merlin_type_define.h"
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_extern_int_merlin_include_G_();
static void __merlin_dummy_0();
void kernel_gemm(float C[6400],float A[10000],float B[6400]);
static void __merlin_dummy_extern_int_merlin_include_L_();
#include "__merlinhead_kernel_top.h"
static void __merlin_dummy_extern_int_merlin_include_L_();

void __merlinwrapper_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
//   commands;
{
    
#pragma ACCEL wrapper VARIABLE=C port=C data_type=float depth=100,64 max_depth=100,64 io=RW continue=1 copy=true
    
#pragma ACCEL wrapper VARIABLE=A port=A data_type=float depth=100,100 max_depth=100,100 io=RW continue=1 copy=true
    
#pragma ACCEL wrapper VARIABLE=B port=B data_type=float depth=100,64 max_depth=100,64 io=RW continue=1 copy=true
  }
//  static  __m_C;
//  static  __m_A;
//  static  __m_B;
{
/*
    static float __m_C[6400];
    static float __m_A[10000];
    static float __m_B[6400];
*/
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "C", "100 * 64 * sizeof(float )");
      
#pragma ACCEL debug fflush(stdout);
      if (C != 0) {
//         __kernel_gemm__C_buffer;
        opencl_write_buffer(__kernel_gemm__C_buffer,commands[0],0 * sizeof(float ),(float *)C[0],((unsigned long )(100 * 64)) * sizeof(float ));
      }
       else {
        printf("Error! Detected null pointer 'C' for external memory.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "C");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "A", "100 * 100 * sizeof(float )");
      
#pragma ACCEL debug fflush(stdout);
      if (A != 0) {
//         __kernel_gemm__A_buffer;
        opencl_write_buffer(__kernel_gemm__A_buffer,commands[0],0 * sizeof(float ),(float *)A[0],((unsigned long )(100 * 100)) * sizeof(float ));
      }
       else {
        printf("Error! Detected null pointer 'A' for external memory.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "A");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "B", "100 * 64 * sizeof(float )");
      
#pragma ACCEL debug fflush(stdout);
      if (B != 0) {
//         __kernel_gemm__B_buffer;
        opencl_write_buffer(__kernel_gemm__B_buffer,commands[0],0 * sizeof(float ),(float *)B[0],((unsigned long )(100 * 64)) * sizeof(float ));
      }
       else {
        printf("Error! Detected null pointer 'B' for external memory.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "B");
      
#pragma ACCEL debug fflush(stdout);
    }
  }
  
#pragma ACCEL kernel
{
	#pragma ACCEL debug printf("[Merlin Info] Start set kernel %s argument....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
	opencl_set_kernel_arg(__kernel_gemm_kernel, 0, sizeof(opencl_mem), &__kernel_gemm__C_buffer);
	opencl_set_kernel_arg(__kernel_gemm_kernel, 1, sizeof(opencl_mem), &__kernel_gemm__A_buffer);
	opencl_set_kernel_arg(__kernel_gemm_kernel, 2, sizeof(opencl_mem), &__kernel_gemm__B_buffer);
	#pragma ACCEL debug printf("[Merlin Info] Finish set kernel %s argument....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
}
{
	#pragma ACCEL debug printf("[Merlin Info] Start execute kernel %s....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
	size_t __gid[1];
	__gid[0] = 1;
	opencl_enqueue_kernel(__kernel_gemm_kernel, commands[0], 1, __gid, &__event_kernel_gemm);
}
{
	clWaitForEvents(1, &__event_kernel_gemm);
	#pragma ACCEL debug printf("[Merlin Info] Finish execute kernel %s....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
}
{
/*
    static float __m_C[6400];
    static float __m_A[10000];
    static float __m_B[6400];
*/
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "C", "100 * 64 * sizeof(float )");
      
#pragma ACCEL debug fflush(stdout);
      if (C != 0) {
//         __kernel_gemm__C_buffer;
        opencl_read_buffer(__kernel_gemm__C_buffer,commands[0],0 * sizeof(float ),(float *)C[0],((unsigned long )(100 * 64)) * sizeof(float ));
      }
       else {
        printf("Error! Detected null pointer 'C' for external memory.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "C");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "A", "100 * 100 * sizeof(float )");
      
#pragma ACCEL debug fflush(stdout);
      if (A != 0) {
//         __kernel_gemm__A_buffer;
        opencl_read_buffer(__kernel_gemm__A_buffer,commands[0],0 * sizeof(float ),(float *)A[0],((unsigned long )(100 * 100)) * sizeof(float ));
      }
       else {
        printf("Error! Detected null pointer 'A' for external memory.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "A");
      
#pragma ACCEL debug fflush(stdout);
    }
{
      
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "B", "100 * 64 * sizeof(float )");
      
#pragma ACCEL debug fflush(stdout);
      if (B != 0) {
//         __kernel_gemm__B_buffer;
        opencl_read_buffer(__kernel_gemm__B_buffer,commands[0],0 * sizeof(float ),(float *)B[0],((unsigned long )(100 * 64)) * sizeof(float ));
      }
       else {
        printf("Error! Detected null pointer 'B' for external memory.\n");
        exit(1);
      }
      
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "B");
      
#pragma ACCEL debug fflush(stdout);
    }
  }
}

void __merlin_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
  
__merlin_check_opencl();
  
__merlin_init_kernel_gemm();
  __merlinwrapper_kernel_gemm(C,A,B);
  
__merlin_release_kernel_gemm();
}

void __merlin_write_buffer_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
  static float __m_C[6400];
  static float __m_A[10000];
  static float __m_B[6400];
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "C", "100 * 64 * sizeof(float )");
    
#pragma ACCEL debug fflush(stdout);
    if (C != 0) {
//       __kernel_gemm__C_buffer;
//       __event___kernel_gemm__C_buffer;
/* __MERLIN_EVENT_WRITE__ __event___kernel_gemm__C_buffer */
      int __MERLIN_EVENT_WRITE____event___kernel_gemm__C_buffer;
      opencl_write_buffer_nb(__kernel_gemm__C_buffer,commands[0],0 * sizeof(float ),(float *)C[0],((unsigned long )(100 * 64)) * sizeof(float ),&__event___kernel_gemm__C_buffer);
    }
     else {
      printf("Error! Detected null pointer 'C' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "C");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "A", "100 * 100 * sizeof(float )");
    
#pragma ACCEL debug fflush(stdout);
    if (A != 0) {
//       __kernel_gemm__A_buffer;
//       __event___kernel_gemm__A_buffer;
/* __MERLIN_EVENT_WRITE__ __event___kernel_gemm__A_buffer */
      int __MERLIN_EVENT_WRITE____event___kernel_gemm__A_buffer;
      opencl_write_buffer_nb(__kernel_gemm__A_buffer,commands[0],0 * sizeof(float ),(float *)A[0],((unsigned long )(100 * 100)) * sizeof(float ),&__event___kernel_gemm__A_buffer);
    }
     else {
      printf("Error! Detected null pointer 'A' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "A");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy in", "B", "100 * 64 * sizeof(float )");
    
#pragma ACCEL debug fflush(stdout);
    if (B != 0) {
//       __kernel_gemm__B_buffer;
//       __event___kernel_gemm__B_buffer;
/* __MERLIN_EVENT_WRITE__ __event___kernel_gemm__B_buffer */
      int __MERLIN_EVENT_WRITE____event___kernel_gemm__B_buffer;
      opencl_write_buffer_nb(__kernel_gemm__B_buffer,commands[0],0 * sizeof(float ),(float *)B[0],((unsigned long )(100 * 64)) * sizeof(float ),&__event___kernel_gemm__B_buffer);
    }
     else {
      printf("Error! Detected null pointer 'B' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy in", "B");
    
#pragma ACCEL debug fflush(stdout);
  }
}

void __merlin_read_buffer_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
  static float __m_C[6400];
  static float __m_A[10000];
  static float __m_B[6400];
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "C", "100 * 64 * sizeof(float )");
    
#pragma ACCEL debug fflush(stdout);
    if (C != 0) {
//       __kernel_gemm__C_buffer;
//       __event___kernel_gemm__C_buffer;
/* __MERLIN_EVENT_READ__ __event___kernel_gemm__C_buffer */
      int __MERLIN_EVENT_READ____event___kernel_gemm__C_buffer;
      opencl_read_buffer_nb(__kernel_gemm__C_buffer,commands[0],0 * sizeof(float ),(float *)C[0],((unsigned long )(100 * 64)) * sizeof(float ),&__event___kernel_gemm__C_buffer);
    }
     else {
      printf("Error! Detected null pointer 'C' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "C");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "A", "100 * 100 * sizeof(float )");
    
#pragma ACCEL debug fflush(stdout);
    if (A != 0) {
//       __kernel_gemm__A_buffer;
//       __event___kernel_gemm__A_buffer;
/* __MERLIN_EVENT_READ__ __event___kernel_gemm__A_buffer */
      int __MERLIN_EVENT_READ____event___kernel_gemm__A_buffer;
      opencl_read_buffer_nb(__kernel_gemm__A_buffer,commands[0],0 * sizeof(float ),(float *)A[0],((unsigned long )(100 * 100)) * sizeof(float ),&__event___kernel_gemm__A_buffer);
    }
     else {
      printf("Error! Detected null pointer 'A' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "A");
    
#pragma ACCEL debug fflush(stdout);
  }
{
    
#pragma ACCEL debug printf("[Merlin Info] Start %s data for %s, data size = %s...\n", "copy out", "B", "100 * 64 * sizeof(float )");
    
#pragma ACCEL debug fflush(stdout);
    if (B != 0) {
//       __kernel_gemm__B_buffer;
//       __event___kernel_gemm__B_buffer;
/* __MERLIN_EVENT_READ__ __event___kernel_gemm__B_buffer */
      int __MERLIN_EVENT_READ____event___kernel_gemm__B_buffer;
      opencl_read_buffer_nb(__kernel_gemm__B_buffer,commands[0],0 * sizeof(float ),(float *)B[0],((unsigned long )(100 * 64)) * sizeof(float ),&__event___kernel_gemm__B_buffer);
    }
     else {
      printf("Error! Detected null pointer 'B' for external memory.\n");
      exit(1);
    }
    
#pragma ACCEL debug printf("[Merlin Info] Finish %s data for %s.\n", "copy out", "B");
    
#pragma ACCEL debug fflush(stdout);
  }
}

void __merlin_execute_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
  int i;
{
	#pragma ACCEL debug printf("[Merlin Info] Start set kernel %s argument....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
	opencl_set_kernel_arg(__kernel_gemm_kernel, 0, sizeof(opencl_mem), &__kernel_gemm__C_buffer);
	opencl_set_kernel_arg(__kernel_gemm_kernel, 1, sizeof(opencl_mem), &__kernel_gemm__A_buffer);
	opencl_set_kernel_arg(__kernel_gemm_kernel, 2, sizeof(opencl_mem), &__kernel_gemm__B_buffer);
	#pragma ACCEL debug printf("[Merlin Info] Finish set kernel %s argument....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
}
{
	#pragma ACCEL debug printf("[Merlin Info] Start execute kernel %s....\n", "kernel_gemm");
	#pragma ACCEL debug fflush(stdout);
	size_t __gid[1];
	__gid[0] = 1;
	opencl_enqueue_kernel(__kernel_gemm_kernel, commands[0], 1, __gid, &__event_kernel_gemm);
}
}
