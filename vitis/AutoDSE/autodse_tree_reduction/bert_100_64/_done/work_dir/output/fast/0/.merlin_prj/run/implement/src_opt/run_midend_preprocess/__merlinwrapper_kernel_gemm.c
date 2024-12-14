#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include "merlin_type_define.h"
extern int __merlin_include__GB_stdlib_h_2;
extern int __merlin_include__GB_stdio_h_1;
extern int __merlin_include__GB_string_h_0;
static void __merlin_dummy_0();
void kernel_gemm(float C[6400],float A[10000],float B[6400]);
static void __merlin_dummy_extern_int_merlin_include_L_();
#include "__merlinhead_kernel_top.h"
static void __merlin_dummy_extern_int_merlin_include_L_();

void __merlinwrapper_kernel_gemm(float C[100][64],float A[100][100],float B[100][64])
{
{
    
#pragma ACCEL wrapper VARIABLE=C port=C data_type=float depth=100,64 max_depth=100,64 io=RW continue=1 copy=true
    
#pragma ACCEL wrapper VARIABLE=A port=A data_type=float depth=100,100 max_depth=100,100 io=RW continue=1 copy=true
    
#pragma ACCEL wrapper VARIABLE=B port=B data_type=float depth=100,64 max_depth=100,64 io=RW continue=1 copy=true
  }
  static float __m_C[6400];
  static float __m_A[10000];
  static float __m_B[6400];
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
        memcpy((void *)(__m_C + 0 * 64),(const void *)C[0],100 * 64 * sizeof(float ));
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
        memcpy((void *)(__m_A + 0 * 100),(const void *)A[0],100 * 100 * sizeof(float ));
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
        memcpy((void *)(__m_B + 0 * 64),(const void *)B[0],100 * 64 * sizeof(float ));
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
  kernel_gemm(__m_C,__m_A,__m_B);
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
        memcpy((void *)C[0],(const void *)(__m_C + 0 * 64),100 * 64 * sizeof(float ));
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
        memcpy((void *)A[0],(const void *)(__m_A + 0 * 100),100 * 100 * sizeof(float ));
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
        memcpy((void *)B[0],(const void *)(__m_B + 0 * 64),100 * 64 * sizeof(float ));
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
  
#pragma ACCEL string __merlin_check_opencl();
  
#pragma ACCEL string __merlin_init_kernel_gemm();
  __merlinwrapper_kernel_gemm(C,A,B);
  
#pragma ACCEL string __merlin_release_kernel_gemm();
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
      memcpy((void *)(__m_C + 0 * 64),(const void *)C[0],100 * 64 * sizeof(float ));
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
      memcpy((void *)(__m_A + 0 * 100),(const void *)A[0],100 * 100 * sizeof(float ));
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
      memcpy((void *)(__m_B + 0 * 64),(const void *)B[0],100 * 64 * sizeof(float ));
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
      memcpy((void *)C[0],(const void *)(__m_C + 0 * 64),100 * 64 * sizeof(float ));
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
      memcpy((void *)A[0],(const void *)(__m_A + 0 * 100),100 * 100 * sizeof(float ));
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
      memcpy((void *)B[0],(const void *)(__m_B + 0 * 64),100 * 64 * sizeof(float ));
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
}
