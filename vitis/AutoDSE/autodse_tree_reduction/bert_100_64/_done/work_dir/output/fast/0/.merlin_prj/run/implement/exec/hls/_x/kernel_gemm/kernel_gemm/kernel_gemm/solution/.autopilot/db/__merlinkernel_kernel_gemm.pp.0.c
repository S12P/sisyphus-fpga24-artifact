# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 339 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/mnt/software/xilinx/Vitis_HLS/2023.2/common/technology/autopilot/etc/autopilot_ssdm_op.h" 1
# 266 "/mnt/software/xilinx/Vitis_HLS/2023.2/common/technology/autopilot/etc/autopilot_ssdm_op.h"
    void _ssdm_op_IfRead() __attribute__ ((nothrow));
    void _ssdm_op_IfWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite() __attribute__ ((nothrow));


    void _ssdm_StreamRead() __attribute__ ((nothrow));
    void _ssdm_StreamWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite() __attribute__ ((nothrow));
    void _ssdm_op_ReadReq() __attribute__ ((nothrow));
    void _ssdm_op_Read() __attribute__ ((nothrow));
    void _ssdm_op_WriteReq() __attribute__ ((nothrow));
    void _ssdm_op_Write() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_NbReadReq() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_CanReadReq() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_NbWriteReq() __attribute__ ((nothrow));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_CanWriteReq() __attribute__ ((nothrow));




    void _ssdm_op_MemShiftRead() __attribute__ ((nothrow));

    void _ssdm_op_PrintNone() __attribute__ ((nothrow));
    void _ssdm_op_PrintInt() __attribute__ ((nothrow));
    void _ssdm_op_PrintDouble() __attribute__ ((nothrow));

    void _ssdm_op_Wait(int) __attribute__ ((nothrow));
    void _ssdm_op_Poll() __attribute__ ((nothrow));

    void _ssdm_op_Return() __attribute__ ((nothrow));


    void _ssdm_op_SpecSynModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecTopModule() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDecl() __attribute__ ((nothrow));
    void _ssdm_op_SpecProcessDef() __attribute__ ((nothrow));
    void _ssdm_op_SpecPort() __attribute__ ((nothrow));
    void _ssdm_op_SpecConnection() __attribute__ ((nothrow));
    void _ssdm_op_SpecChannel() __attribute__ ((nothrow));
    void _ssdm_op_SpecSensitive() __attribute__ ((nothrow));
    void _ssdm_op_SpecModuleInst() __attribute__ ((nothrow));
    void _ssdm_op_SpecPortMap() __attribute__ ((nothrow));

    void _ssdm_op_SpecReset() __attribute__ ((nothrow));

    void _ssdm_op_SpecPlatform() __attribute__ ((nothrow));
    void _ssdm_op_SpecClockDomain() __attribute__ ((nothrow));
    void _ssdm_op_SpecPowerDomain() __attribute__ ((nothrow));

    int _ssdm_op_SpecRegionBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecRegionEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopName() __attribute__ ((nothrow));

    void _ssdm_op_SpecLoopTripCount() __attribute__ ((nothrow));

    int _ssdm_op_SpecStateBegin() __attribute__ ((nothrow));
    int _ssdm_op_SpecStateEnd() __attribute__ ((nothrow));

    void _ssdm_op_SpecInterface() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipeline() __attribute__ ((nothrow));
    void _ssdm_op_SpecDataflowPipeline() __attribute__ ((nothrow));


    void _ssdm_op_SpecLatency() __attribute__ ((nothrow));
    void _ssdm_op_SpecParallel() __attribute__ ((nothrow));
    void _ssdm_op_SpecProtocol() __attribute__ ((nothrow));
    void _ssdm_op_SpecOccurrence() __attribute__ ((nothrow));

    void _ssdm_op_SpecResource() __attribute__ ((nothrow));
    void _ssdm_op_SpecResourceLimit() __attribute__ ((nothrow));
    void _ssdm_op_SpecCHCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecFUCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIFCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecIPCore() __attribute__ ((nothrow));
    void _ssdm_op_SpecMemCore() __attribute__ ((nothrow));

    void _ssdm_op_SpecExt() __attribute__ ((nothrow));




    void _ssdm_SpecArrayDimSize() __attribute__ ((nothrow));

    void _ssdm_RegionBegin() __attribute__ ((nothrow));
    void _ssdm_RegionEnd() __attribute__ ((nothrow));

    void _ssdm_Unroll() __attribute__ ((nothrow));
    void _ssdm_UnrollRegion() __attribute__ ((nothrow));

    void _ssdm_InlineAll() __attribute__ ((nothrow));
    void _ssdm_InlineLoop() __attribute__ ((nothrow));
    void _ssdm_Inline() __attribute__ ((nothrow));
    void _ssdm_InlineSelf() __attribute__ ((nothrow));
    void _ssdm_InlineRegion() __attribute__ ((nothrow));

    void _ssdm_SpecArrayMap() __attribute__ ((nothrow));
    void _ssdm_SpecArrayPartition() __attribute__ ((nothrow));
    void _ssdm_SpecArrayReshape() __attribute__ ((nothrow));

    void _ssdm_SpecStream() __attribute__ ((nothrow));

    void _ssdm_op_SpecStable() __attribute__ ((nothrow));
    void _ssdm_op_SpecStableContent() __attribute__ ((nothrow));

    void _ssdm_op_SpecBindPort() __attribute__ ((nothrow));

    void _ssdm_op_SpecPipoDepth() __attribute__ ((nothrow));

    void _ssdm_SpecExpr() __attribute__ ((nothrow));
    void _ssdm_SpecExprBalance() __attribute__ ((nothrow));

    void _ssdm_SpecDependence() __attribute__ ((nothrow));

    void _ssdm_SpecLoopMerge() __attribute__ ((nothrow));
    void _ssdm_SpecLoopFlatten() __attribute__ ((nothrow));
    void _ssdm_SpecLoopRewind() __attribute__ ((nothrow));

    void _ssdm_SpecFuncInstantiation() __attribute__ ((nothrow));
    void _ssdm_SpecFuncBuffer() __attribute__ ((nothrow));
    void _ssdm_SpecFuncExtract() __attribute__ ((nothrow));
    void _ssdm_SpecConstant() __attribute__ ((nothrow));

    void _ssdm_DataPack() __attribute__ ((nothrow));
    void _ssdm_SpecDataPack() __attribute__ ((nothrow));

    void _ssdm_op_SpecBitsMap() __attribute__ ((nothrow));
    void _ssdm_op_SpecLicense() __attribute__ ((nothrow));
# 2 "<built-in>" 2
# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c" 2



# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128_1d.h" 1
# 24 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128_1d.h"
# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128.h" 1
# 24 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128.h"
# 1 "/usr/include/assert.h" 1 3 4
# 35 "/usr/include/assert.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 392 "/usr/include/features.h" 3 4
# 1 "/usr/include/features-time64.h" 1 3 4
# 20 "/usr/include/features-time64.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 21 "/usr/include/features-time64.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 22 "/usr/include/features-time64.h" 2 3 4
# 393 "/usr/include/features.h" 2 3 4
# 464 "/usr/include/features.h" 3 4
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 465 "/usr/include/features.h" 2 3 4
# 486 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 559 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 560 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 561 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 487 "/usr/include/features.h" 2 3 4
# 510 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 511 "/usr/include/features.h" 2 3 4
# 36 "/usr/include/assert.h" 2 3 4
# 69 "/usr/include/assert.h" 3 4
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));
# 25 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128.h" 2
# 1 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stdint.h" 1 3


# 1 "/mnt/software/xilinx/Vitis_HLS/2023.2/lnx64/tools/clang-3.9-csynth/lib/clang/7.0.0/include/stdint.h" 1 3
# 63 "/mnt/software/xilinx/Vitis_HLS/2023.2/lnx64/tools/clang-3.9-csynth/lib/clang/7.0.0/include/stdint.h" 3
# 1 "/usr/include/stdint.h" 1 3 4
# 26 "/usr/include/stdint.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 1 3 4
# 19 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 20 "/usr/include/x86_64-linux-gnu/bits/timesize.h" 2 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;






typedef __int8_t __int_least8_t;
typedef __uint8_t __uint_least8_t;
typedef __int16_t __int_least16_t;
typedef __uint16_t __uint_least16_t;
typedef __int32_t __int_least32_t;
typedef __uint32_t __uint_least32_t;
typedef __int64_t __int_least64_t;
typedef __uint64_t __uint_least64_t;



typedef long int __quad_t;
typedef unsigned long int __u_quad_t;







typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
# 141 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 142 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/time64.h" 1 3 4
# 143 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __suseconds64_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;




typedef int __sig_atomic_t;
# 28 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wchar.h" 1 3 4
# 29 "/usr/include/stdint.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 30 "/usr/include/stdint.h" 2 3 4




# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-intn.h" 3 4
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
# 35 "/usr/include/stdint.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/stdint-uintn.h" 3 4
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
# 38 "/usr/include/stdint.h" 2 3 4





typedef __int_least8_t int_least8_t;
typedef __int_least16_t int_least16_t;
typedef __int_least32_t int_least32_t;
typedef __int_least64_t int_least64_t;


typedef __uint_least8_t uint_least8_t;
typedef __uint_least16_t uint_least16_t;
typedef __uint_least32_t uint_least32_t;
typedef __uint_least64_t uint_least64_t;





typedef signed char int_fast8_t;

typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
# 71 "/usr/include/stdint.h" 3 4
typedef unsigned char uint_fast8_t;

typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
# 87 "/usr/include/stdint.h" 3 4
typedef long int intptr_t;


typedef unsigned long int uintptr_t;
# 101 "/usr/include/stdint.h" 3 4
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
# 64 "/mnt/software/xilinx/Vitis_HLS/2023.2/lnx64/tools/clang-3.9-csynth/lib/clang/7.0.0/include/stdint.h" 2 3
# 4 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stdint.h" 2 3
# 26 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128.h" 2



typedef struct merlin_uint_128 {
  unsigned char data[128 / 8];
} merlin_uint_128;
static uint64_t merlin_get_range_128(merlin_uint_128 *tmp, int low, int len) {
#pragma HLS INLINE SELF
 uint64_t ret = 0;
  int i;
  int start = low;
  switch (len) {
  case 1:
    VITIS_LOOP_39_1: for (i = 0; i >= 0; --i) {
#pragma HLS unroll
 ret <<= 8;
      ret |= tmp->data[i + start];
    }
    break;
  case 2:
    VITIS_LOOP_46_2: for (i = 1; i >= 0; --i) {
#pragma HLS unroll
 ret <<= 8;
      ret |= tmp->data[i + start];
    }
    break;
  case 4:
    VITIS_LOOP_53_3: for (i = 3; i >= 0; --i) {
#pragma HLS unroll
 ret <<= 8;
      ret |= tmp->data[i + start];
    }
    break;
  case 8:
    VITIS_LOOP_60_4: for (i = 7; i >= 0; --i) {
#pragma HLS unroll
 ret <<= 8;
      ret |= tmp->data[i + start];
    }
    break;
  default:
    ({ int _AssertPred = 0; __builtin_assume(_AssertPred); });
  }
  return ret;
}

static void merlin_set_range_128(merlin_uint_128 *tmp, int low, int len,
                                 uint64_t val) {
#pragma HLS INLINE SELF
 int i;
  int start = low;
  switch (len) {
  case 1:
    VITIS_LOOP_79_1: for (i = 0; i < 1; ++i) {
#pragma HLS unroll
 tmp->data[start + i] = val & 0xff;
      val >>= 8;
    }
    break;
  case 2:
    VITIS_LOOP_86_2: for (i = 0; i < 2; ++i) {
#pragma HLS unroll
 tmp->data[start + i] = val & 0xff;
      val >>= 8;
    }
    break;
  case 4:
    VITIS_LOOP_93_3: for (i = 0; i < 4; ++i) {
#pragma HLS unroll
 tmp->data[start + i] = val & 0xff;
      val >>= 8;
    }
    break;
  case 8:
    VITIS_LOOP_100_4: for (i = 0; i < 8; ++i) {
#pragma HLS unroll
 tmp->data[start + i] = val & 0xff;
      val >>= 8;
    }
    break;
  default:
    ({ int _AssertPred = 0; __builtin_assume(_AssertPred); });
  }
}
# 25 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128_1d.h" 2
# 35 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128_1d.h"
# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h" 1
# 22 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h"
# 1 "/usr/include/assert.h" 1 3 4
# 23 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h" 2
# 1 "/usr/include/stdlib.h" 1 3 4
# 26 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/stdlib.h" 2 3 4





# 1 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stddef.h" 1 3 4
# 212 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 324 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stddef.h" 3 4
typedef int wchar_t;
# 33 "/usr/include/stdlib.h" 2 3 4







# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 41 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 42 "/usr/include/stdlib.h" 2 3 4
# 56 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 1 3 4
# 119 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 2 3 4
# 214 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef float _Float32;
# 251 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef double _Float64;
# 268 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef double _Float32x;
# 285 "/usr/include/x86_64-linux-gnu/bits/floatn-common.h" 3 4
typedef long double _Float64x;
# 120 "/usr/include/x86_64-linux-gnu/bits/floatn.h" 2 3 4
# 57 "/usr/include/stdlib.h" 2 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
# 98 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ )) ;



extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;



extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));



extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
# 177 "/usr/include/stdlib.h" 3 4
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));



__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
# 386 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__ )) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;


typedef __loff_t loff_t;




typedef __ino_t ino_t;
# 59 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;
# 97 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;





# 1 "/usr/include/x86_64-linux-gnu/bits/types/clock_t.h" 1 3 4






typedef __clock_t clock_t;
# 127 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/clockid_t.h" 1 3 4






typedef __clockid_t clockid_t;
# 129 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/bits/types/time_t.h" 3 4
typedef __time_t time_t;
# 130 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/timer_t.h" 1 3 4






typedef __timer_t timer_t;
# 131 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 144 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stddef.h" 1 3 4
# 145 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;







typedef __uint8_t u_int8_t;
typedef __uint16_t u_int16_t;
typedef __uint32_t u_int32_t;
typedef __uint64_t u_int64_t;


typedef int register_t __attribute__ ((__mode__ (__word__)));
# 176 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 24 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
# 35 "/usr/include/x86_64-linux-gnu/bits/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endianness.h" 1 3 4
# 36 "/usr/include/x86_64-linux-gnu/bits/endian.h" 2 3 4
# 25 "/usr/include/endian.h" 2 3 4
# 35 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
# 33 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline __uint16_t
__bswap_16 (__uint16_t __bsx)
{



  return ((__uint16_t) ((((__bsx) >> 8) & 0xff) | (((__bsx) & 0xff) << 8)));

}






static __inline __uint32_t
__bswap_32 (__uint32_t __bsx)
{



  return ((((__bsx) & 0xff000000u) >> 24) | (((__bsx) & 0x00ff0000u) >> 8) | (((__bsx) & 0x0000ff00u) << 8) | (((__bsx) & 0x000000ffu) << 24));

}
# 69 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
__extension__ static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{



  return ((((__bsx) & 0xff00000000000000ull) >> 56) | (((__bsx) & 0x00ff000000000000ull) >> 40) | (((__bsx) & 0x0000ff0000000000ull) >> 24) | (((__bsx) & 0x000000ff00000000ull) >> 8) | (((__bsx) & 0x00000000ff000000ull) << 8) | (((__bsx) & 0x0000000000ff0000ull) << 24) | (((__bsx) & 0x000000000000ff00ull) << 40) | (((__bsx) & 0x00000000000000ffull) << 56));

}
# 36 "/usr/include/endian.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 1 3 4
# 32 "/usr/include/x86_64-linux-gnu/bits/uintn-identity.h" 3 4
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}

static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}

static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
# 37 "/usr/include/endian.h" 2 3 4
# 177 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 1 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types/__sigset_t.h" 1 3 4




typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
# 5 "/usr/include/x86_64-linux-gnu/bits/types/sigset_t.h" 2 3 4


typedef __sigset_t sigset_t;
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timeval.h" 1 3 4







struct timeval
{




  __time_t tv_sec;
  __suseconds_t tv_usec;

};
# 38 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
struct timespec
{



  __time_t tv_sec;




  __syscall_slong_t tv_nsec;
# 31 "/usr/include/x86_64-linux-gnu/bits/types/struct_timespec.h" 3 4
};
# 40 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 59 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 102 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 127 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 180 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 227 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 1 3 4
# 44 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes-arch.h" 2 3 4
# 45 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 1 3 4
# 25 "/usr/include/x86_64-linux-gnu/bits/atomic_wide_counter.h" 3 4
typedef union
{
  __extension__ unsigned long long int __value64;
  struct
  {
    unsigned int __low;
    unsigned int __high;
  } __value32;
} __atomic_wide_counter;
# 47 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4




typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;

typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;
# 76 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
struct __pthread_mutex_s
{
  int __lock;
  unsigned int __count;
  int __owner;

  unsigned int __nusers;



  int __kind;

  short __spins;
  short __elision;
  __pthread_list_t __list;
# 53 "/usr/include/x86_64-linux-gnu/bits/struct_mutex.h" 3 4
};
# 77 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4
# 89 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;

  int __cur_writer;
  int __shared;
  signed char __rwelision;




  unsigned char __pad1[7];


  unsigned long int __pad2;


  unsigned int __flags;
# 55 "/usr/include/x86_64-linux-gnu/bits/struct_rwlock.h" 3 4
};
# 90 "/usr/include/x86_64-linux-gnu/bits/thread-shared-types.h" 2 3 4




struct __pthread_cond_s
{
  __atomic_wide_counter __wseq;
  __atomic_wide_counter __g1_start;
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};

typedef unsigned int __tss_t;
typedef unsigned long int __thrd_t;

typedef struct
{
  int __data ;
} __once_flag;
# 24 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4



typedef unsigned long int pthread_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;




typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;


typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;





typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 228 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 396 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) __attribute__ ((__nothrow__ ));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ ));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));





extern int rand (void) __attribute__ ((__nothrow__ ));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ ));



extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ ));







extern double drand48 (void) __attribute__ ((__nothrow__ ));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ ));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ ));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ ));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));




extern void *malloc (size_t __size) __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__))
                                         ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) ;






extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__warn_unused_result__)) ;


extern void free (void *__ptr) __attribute__ ((__nothrow__ ));







extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__warn_unused_result__))

                       ;


extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ )) ;




# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ ));
# 575 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__))
                                         ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1))) ;
# 598 "/usr/include/stdlib.h" 3 4
extern void abort (void) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
# 617 "/usr/include/stdlib.h" 3 4
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));





extern void exit (int __status) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));
# 636 "/usr/include/stdlib.h" 3 4
extern void _Exit (int __status) __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern char *getenv (const char *__name) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1))) ;
# 654 "/usr/include/stdlib.h" 3 4
extern int putenv (char *__string) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ ));
# 682 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
# 695 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 717 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 738 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1))) ;
# 791 "/usr/include/stdlib.h" 3 4
extern int system (const char *__command) ;
# 808 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ )) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 828 "/usr/include/stdlib.h" 3 4
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 848 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;


__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;






extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;


__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__)) ;
# 880 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (3, 4, 5)));





extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ ));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ ));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ ));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ ))
                                      ;

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ ))

                                    ;






extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1))) ;
# 967 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 1013 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
# 1023 "/usr/include/stdlib.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
# 1024 "/usr/include/stdlib.h" 2 3 4
# 24 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h" 2
# 48 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h"
static char memcpy_wide_bus_single_read_char_128(merlin_uint_128 *a,
                                                          size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  char ret = merlin_get_range_128(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_char_128(merlin_uint_128 *c, char c_buf,

                                              size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_128(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static short memcpy_wide_bus_single_read_short_128(merlin_uint_128 *a,

                                               size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  short ret = merlin_get_range_128(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_short_128(merlin_uint_128 *c,

                                              short c_buf, size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_128(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static int memcpy_wide_bus_single_read_int_128(merlin_uint_128 *a,
                                                        size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  int ret = merlin_get_range_128(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_int_128(merlin_uint_128 *c,
                                                          int c_buf,
                                                          size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_128(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static long memcpy_wide_bus_single_read_long_128(merlin_uint_128 *a,
                                                          size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  long ret = merlin_get_range_128(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_long_128(merlin_uint_128 *c, long c_buf,

                                              size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_128(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static long long memcpy_wide_bus_single_read_long_long_128(merlin_uint_128 *a,

                                                   size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  long long ret = merlin_get_range_128(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_long_long_128(merlin_uint_128 *c,

                                              long long c_buf,
                                              size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_128(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static float memcpy_wide_bus_single_read_float_128(merlin_uint_128 *a,

                                               size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;

  int raw_bits = merlin_get_range_128(&a[start], (head_align * data_width), data_width);
  float ret = *(float *)(&raw_bits);
  return ret;
}

static void memcpy_wide_bus_single_write_float_128(merlin_uint_128 *c,

                                              float c_buf, size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  float buf_tmp = c_buf;
  int raw_bits = *(int *)&buf_tmp;
  merlin_set_range_128(&c[start], (head_align * data_width), data_width, raw_bits);
  return;
}

static double memcpy_wide_bus_single_read_double_128(merlin_uint_128 *a,

                                                size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;

  int64_t raw_bits = merlin_get_range_128(&a[start], (head_align * data_width), data_width);
  double ret = *(double *)(&raw_bits);
  return ret;
}

static void memcpy_wide_bus_single_write_double_128(merlin_uint_128 *c,

                                              double c_buf,
                                              size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  double buf_tmp = c_buf;
  int64_t raw_bits = *(int64_t *)&buf_tmp;
  merlin_set_range_128(&c[start], (head_align * data_width), data_width, raw_bits);
  return;
}

static void memcpy_wide_bus_read_long_128(long *a_buf, merlin_uint_128 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  long len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_275_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_294_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_304_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_316_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_328_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_340_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_352_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_364_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 7) {
      VITIS_LOOP_376_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 7] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 8) {
      VITIS_LOOP_388_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 8] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 9) {
      VITIS_LOOP_400_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 9] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 10) {
      VITIS_LOOP_412_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 10] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 11) {
      VITIS_LOOP_424_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 11] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 12) {
      VITIS_LOOP_436_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 12] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 13) {
      VITIS_LOOP_448_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 13] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 14) {
      VITIS_LOOP_460_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 14] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else {
      VITIS_LOOP_472_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_long_128(merlin_uint_128 *c, long *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_506_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_517_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_541_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_550_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_558_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_566_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_574_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_582_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_590_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else if (data_width == 4 && head_align == 7) {
      VITIS_LOOP_598_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 9]);

      }
    }

    else if (data_width == 4 && head_align == 8) {
      VITIS_LOOP_606_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 8]);

      }
    }

    else if (data_width == 4 && head_align == 9) {
      VITIS_LOOP_614_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 7]);

      }
    }

    else if (data_width == 4 && head_align == 10) {
      VITIS_LOOP_622_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 6]);

      }
    }

    else if (data_width == 4 && head_align == 11) {
      VITIS_LOOP_630_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 5]);

      }
    }

    else if (data_width == 4 && head_align == 12) {
      VITIS_LOOP_638_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 4]);

      }
    }

    else if (data_width == 4 && head_align == 13) {
      VITIS_LOOP_646_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 3]);

      }
    }

    else if (data_width == 4 && head_align == 14) {
      VITIS_LOOP_654_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 2]);

      }
    }

    else {
      VITIS_LOOP_662_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_672_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_long_long_128(long long *a_buf, merlin_uint_128 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_705_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_724_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_734_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_746_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_758_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_770_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_782_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_794_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else {
      VITIS_LOOP_806_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_long_long_128(merlin_uint_128 *c, long long *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_840_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_851_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_875_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_884_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_892_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_900_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_908_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_916_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_924_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else {
      VITIS_LOOP_932_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_942_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_int_128(int *a_buf, merlin_uint_128 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_975_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_994_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_1004_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_1016_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_1028_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_1040_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_1052_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_1064_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_1076_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 7] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_1088_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 8] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_1100_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 9] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_1112_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 10] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_1124_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 11] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_1136_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 12] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_1148_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 13] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_1160_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 14] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else {
      VITIS_LOOP_1172_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_int_128(merlin_uint_128 *c, int *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1206_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1217_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_1241_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_1250_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_1258_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_1266_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_1274_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_1282_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_1290_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_1298_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 9]);

      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_1306_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 8]);

      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_1314_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 7]);

      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_1322_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 6]);

      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_1330_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 5]);

      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_1338_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 4]);

      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_1346_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 3]);

      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_1354_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 2]);

      }
    }

    else {
      VITIS_LOOP_1362_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1372_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_short_128(short *a_buf, merlin_uint_128 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1405_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L3:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_1424_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_1434_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_1446_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_1458_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_1470_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_1482_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_1494_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_1506_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 7] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_1518_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 8] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_1530_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 9] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_1542_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 10] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_1554_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 11] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_1566_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 12] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_1578_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 13] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_1590_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 14] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 15) {
      VITIS_LOOP_1600_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 16) {
      VITIS_LOOP_1610_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 16)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 16] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 17) {
      VITIS_LOOP_1620_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 17)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 17] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 18) {
      VITIS_LOOP_1630_20: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 18)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 18] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 19) {
      VITIS_LOOP_1640_21: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 19)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 19] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 20) {
      VITIS_LOOP_1650_22: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 20)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 20] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 21) {
      VITIS_LOOP_1660_23: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 21)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 21] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 22) {
      VITIS_LOOP_1670_24: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 22)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 22] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 23) {
      VITIS_LOOP_1680_25: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 23)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 23] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 24) {
      VITIS_LOOP_1690_26: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 24)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 24] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 25) {
      VITIS_LOOP_1700_27: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 25)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 25] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 26) {
      VITIS_LOOP_1710_28: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 26)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 26] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 27) {
      VITIS_LOOP_1720_29: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 27)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 27] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 28) {
      VITIS_LOOP_1730_30: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 28)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 28] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 29) {
      VITIS_LOOP_1740_31: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 29)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 29] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 30) {
      VITIS_LOOP_1750_32: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 30)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 30] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else {
      VITIS_LOOP_1760_33: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 31)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 31] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_short_128(merlin_uint_128 *c, short *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1794_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1805_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_1829_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    } else if (head_align == 1) {
      VITIS_LOOP_1836_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 31]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_1844_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 30]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_1852_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 29]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_1860_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 28]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_1868_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 27]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_1876_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 26]);

      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_1884_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 25]);

      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_1892_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 24]);

      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_1900_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 23]);

      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_1908_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 22]);

      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_1916_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 21]);

      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_1924_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 20]);

      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_1932_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 19]);

      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_1940_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 18]);

      }
    }

    else if (head_align == 15) {
      VITIS_LOOP_1948_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 17]);

      }
    }

    else if (head_align == 16) {
      VITIS_LOOP_1956_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 16]);

      }
    }

    else if (head_align == 17) {
      VITIS_LOOP_1964_20: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 18) {
      VITIS_LOOP_1972_21: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 19) {
      VITIS_LOOP_1980_22: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 20) {
      VITIS_LOOP_1988_23: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 21) {
      VITIS_LOOP_1996_24: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 22) {
      VITIS_LOOP_2004_25: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else if (head_align == 23) {
      VITIS_LOOP_2012_26: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 9]);

      }
    }

    else if (head_align == 24) {
      VITIS_LOOP_2020_27: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 8]);

      }
    }

    else if (head_align == 25) {
      VITIS_LOOP_2028_28: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 7]);

      }
    }

    else if (head_align == 26) {
      VITIS_LOOP_2036_29: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 6]);

      }
    }

    else if (head_align == 27) {
      VITIS_LOOP_2044_30: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 5]);

      }
    }

    else if (head_align == 28) {
      VITIS_LOOP_2052_31: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 4]);

      }
    }

    else if (head_align == 29) {
      VITIS_LOOP_2060_32: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 3]);

      }
    }

    else if (head_align == 30) {
      VITIS_LOOP_2068_33: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 2]);

      }
    }

    else {
      VITIS_LOOP_2076_34: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_2086_35: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_char_128(char *a_buf, merlin_uint_128 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_2119_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_2138_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_2148_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_2160_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_2172_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_2184_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_2196_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_2208_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_2220_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 7] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_2232_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 8] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_2244_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 9] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_2256_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 10] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_2268_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 11] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_2280_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 12] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_2292_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 13] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_2304_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 14] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 15) {
      VITIS_LOOP_2314_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 16) {
      VITIS_LOOP_2324_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 16)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 16] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 17) {
      VITIS_LOOP_2334_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 17)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 17] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 18) {
      VITIS_LOOP_2344_20: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 18)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 18] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 19) {
      VITIS_LOOP_2354_21: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 19)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 19] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 20) {
      VITIS_LOOP_2364_22: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 20)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 20] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 21) {
      VITIS_LOOP_2374_23: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 21)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 21] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 22) {
      VITIS_LOOP_2384_24: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 22)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 22] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 23) {
      VITIS_LOOP_2394_25: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 23)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 23] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 24) {
      VITIS_LOOP_2404_26: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 24)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 24] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 25) {
      VITIS_LOOP_2414_27: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 25)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 25] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 26) {
      VITIS_LOOP_2424_28: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 26)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 26] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 27) {
      VITIS_LOOP_2434_29: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 27)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 27] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 28) {
      VITIS_LOOP_2444_30: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 28)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 28] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 29) {
      VITIS_LOOP_2454_31: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 29)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 29] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 30) {
      VITIS_LOOP_2464_32: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 30)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 30] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 31) {
      VITIS_LOOP_2474_33: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 31)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 31] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 32) {
      VITIS_LOOP_2484_34: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 32)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 32] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 33) {
      VITIS_LOOP_2494_35: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 33)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 33] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 34) {
      VITIS_LOOP_2504_36: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 34)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 34] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 35) {
      VITIS_LOOP_2514_37: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 35)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 35] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 36) {
      VITIS_LOOP_2524_38: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 36)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 36] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 37) {
      VITIS_LOOP_2534_39: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 37)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 37] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 38) {
      VITIS_LOOP_2544_40: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 38)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 38] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 39) {
      VITIS_LOOP_2554_41: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 39)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 39] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 40) {
      VITIS_LOOP_2564_42: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 40)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 40] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 41) {
      VITIS_LOOP_2574_43: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 41)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 41] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 42) {
      VITIS_LOOP_2584_44: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 42)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 42] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 43) {
      VITIS_LOOP_2594_45: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 43)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 43] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 44) {
      VITIS_LOOP_2604_46: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 44)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 44] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 45) {
      VITIS_LOOP_2614_47: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 45)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 45] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 46) {
      VITIS_LOOP_2624_48: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 46)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 46] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 47) {
      VITIS_LOOP_2634_49: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 47)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 47] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 48) {
      VITIS_LOOP_2644_50: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 48)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 48] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 49) {
      VITIS_LOOP_2654_51: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 49)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 49] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 50) {
      VITIS_LOOP_2664_52: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 50)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 50] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 51) {
      VITIS_LOOP_2674_53: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 51)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 51] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 52) {
      VITIS_LOOP_2684_54: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 52)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 52] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 53) {
      VITIS_LOOP_2694_55: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 53)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 53] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 54) {
      VITIS_LOOP_2704_56: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 54)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 54] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 55) {
      VITIS_LOOP_2714_57: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 55)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 55] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 56) {
      VITIS_LOOP_2724_58: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 56)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 56] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 57) {
      VITIS_LOOP_2734_59: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 57)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 57] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 58) {
      VITIS_LOOP_2744_60: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 58)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 58] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 59) {
      VITIS_LOOP_2754_61: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 59)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 59] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 60) {
      VITIS_LOOP_2764_62: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 60)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 60] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 61) {
      VITIS_LOOP_2774_63: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 61)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 61] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 62) {
      VITIS_LOOP_2784_64: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 62)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 62] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    } else {
      VITIS_LOOP_2794_65: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 63)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 63] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_char_128(merlin_uint_128 *c, char *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_2828_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_2839_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_2863_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    } else if (head_align == 1) {
      VITIS_LOOP_2870_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 63]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_2878_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 62]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_2886_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 61]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_2894_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 60]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_2902_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 59]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_2910_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 58]);

      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_2918_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 57]);

      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_2926_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 56]);

      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_2934_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 55]);

      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_2942_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 54]);

      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_2950_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 53]);

      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_2958_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 52]);

      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_2966_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 51]);

      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_2974_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 50]);

      }
    }

    else if (head_align == 15) {
      VITIS_LOOP_2982_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 49]);

      }
    }

    else if (head_align == 16) {
      VITIS_LOOP_2990_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 48]);

      }
    }

    else if (head_align == 17) {
      VITIS_LOOP_2998_20: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 47]);

      }
    }

    else if (head_align == 18) {
      VITIS_LOOP_3006_21: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 46]);

      }
    }

    else if (head_align == 19) {
      VITIS_LOOP_3014_22: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 45]);

      }
    }

    else if (head_align == 20) {
      VITIS_LOOP_3022_23: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 44]);

      }
    }

    else if (head_align == 21) {
      VITIS_LOOP_3030_24: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 43]);

      }
    }

    else if (head_align == 22) {
      VITIS_LOOP_3038_25: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 42]);

      }
    }

    else if (head_align == 23) {
      VITIS_LOOP_3046_26: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 41]);

      }
    }

    else if (head_align == 24) {
      VITIS_LOOP_3054_27: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 40]);

      }
    }

    else if (head_align == 25) {
      VITIS_LOOP_3062_28: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 39]);

      }
    }

    else if (head_align == 26) {
      VITIS_LOOP_3070_29: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 38]);

      }
    }

    else if (head_align == 27) {
      VITIS_LOOP_3078_30: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 37]);

      }
    }

    else if (head_align == 28) {
      VITIS_LOOP_3086_31: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 36]);

      }
    }

    else if (head_align == 29) {
      VITIS_LOOP_3094_32: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 35]);

      }
    }

    else if (head_align == 30) {
      VITIS_LOOP_3102_33: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 34]);

      }
    }

    else if (head_align == 31) {
      VITIS_LOOP_3110_34: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 33]);

      }
    }

    else if (head_align == 32) {
      VITIS_LOOP_3118_35: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 32]);

      }
    }

    else if (head_align == 33) {
      VITIS_LOOP_3126_36: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 31]);

      }
    }

    else if (head_align == 34) {
      VITIS_LOOP_3134_37: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 30]);

      }
    }

    else if (head_align == 35) {
      VITIS_LOOP_3142_38: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 29]);

      }
    }

    else if (head_align == 36) {
      VITIS_LOOP_3150_39: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 28]);

      }
    }

    else if (head_align == 37) {
      VITIS_LOOP_3158_40: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 27]);

      }
    }

    else if (head_align == 38) {
      VITIS_LOOP_3166_41: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 26]);

      }
    }

    else if (head_align == 39) {
      VITIS_LOOP_3174_42: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 25]);

      }
    }

    else if (head_align == 40) {
      VITIS_LOOP_3182_43: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 24]);

      }
    }

    else if (head_align == 41) {
      VITIS_LOOP_3190_44: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 23]);

      }
    }

    else if (head_align == 42) {
      VITIS_LOOP_3198_45: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 22]);

      }
    }

    else if (head_align == 43) {
      VITIS_LOOP_3206_46: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 21]);

      }
    }

    else if (head_align == 44) {
      VITIS_LOOP_3214_47: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 20]);

      }
    }

    else if (head_align == 45) {
      VITIS_LOOP_3222_48: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 19]);

      }
    }

    else if (head_align == 46) {
      VITIS_LOOP_3230_49: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 18]);

      }
    }

    else if (head_align == 47) {
      VITIS_LOOP_3238_50: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 17]);

      }
    }

    else if (head_align == 48) {
      VITIS_LOOP_3246_51: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 16]);

      }
    }

    else if (head_align == 49) {
      VITIS_LOOP_3254_52: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 50) {
      VITIS_LOOP_3262_53: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 51) {
      VITIS_LOOP_3270_54: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 52) {
      VITIS_LOOP_3278_55: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 53) {
      VITIS_LOOP_3286_56: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 54) {
      VITIS_LOOP_3294_57: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else if (head_align == 55) {
      VITIS_LOOP_3302_58: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 9]);

      }
    }

    else if (head_align == 56) {
      VITIS_LOOP_3310_59: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 8]);

      }
    }

    else if (head_align == 57) {
      VITIS_LOOP_3318_60: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 7]);

      }
    }

    else if (head_align == 58) {
      VITIS_LOOP_3326_61: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 6]);

      }
    }

    else if (head_align == 59) {
      VITIS_LOOP_3334_62: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 5]);

      }
    }

    else if (head_align == 60) {
      VITIS_LOOP_3342_63: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 4]);

      }
    }

    else if (head_align == 61) {
      VITIS_LOOP_3350_64: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 3]);

      }
    }

    else if (head_align == 62) {
      VITIS_LOOP_3358_65: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 2]);

      }
    }

    else {
      VITIS_LOOP_3366_66: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_3376_67: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_float_128(float *a_buf, merlin_uint_128 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0) {
    len = (buf_size + num_elements - 1) / num_elements;
  }
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_3410_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      int raw_bits = merlin_get_range_128(&a[start], (j * data_width), data_width);
      a_buf[j - head_align] = *(float *)(&raw_bits);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_3430_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 0] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_3440_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 1] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_3452_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 2] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_3464_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 3] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_3476_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 4] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_3488_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 5] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_3500_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 6] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_3512_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 7] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_3524_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 8] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_3536_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 9] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_3548_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 10] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_3560_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 11] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_3572_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 12] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_3584_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 13] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_3596_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 14] = *(float *)(&raw_bits);
      }
    }

    else {
      VITIS_LOOP_3608_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 15] = *(float *)(&raw_bits);
      }
    }
  }
}

static void memcpy_wide_bus_write_float_128(merlin_uint_128 *c, float *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  if (len == 1) {
    VITIS_LOOP_3641_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      float buf_tmp = c_buf[j - head_align];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_128(&c[start], (j * data_width), data_width, raw_bits);
    }
    return;
  }
  unsigned align = 0;
  if (head_align != 0) {
    VITIS_LOOP_3655_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      float buf_tmp = c_buf[j - head_align];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_128(&c[start], (j * data_width), data_width, raw_bits);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_3681_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j - 0];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_3691_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 15];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_3700_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 14];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_3709_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 13];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_3718_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 12];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_3727_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 11];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_3736_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 10];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_3745_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 9];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_3754_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 8];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_3763_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 7];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_3772_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 6];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_3781_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 5];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_3790_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 4];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_3799_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 3];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_3808_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 2];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else {
      VITIS_LOOP_3817_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 1];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_3828_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      float buf_tmp = c_buf[pos + j];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, raw_bits);
    }
  }
}

static void memcpy_wide_bus_read_double_128(double *a_buf, merlin_uint_128 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_3863_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      int64_t raw_bits = merlin_get_range_128(&a[start], (j * data_width), data_width);
      a_buf[j - head_align] = *(double *)(&raw_bits);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_3883_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 0] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_3893_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 1] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_3905_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 2] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_3917_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 3] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_3929_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 4] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_3941_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 5] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_3953_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 6] = *(double *)(&raw_bits);
      }
    }

    else {
      VITIS_LOOP_3965_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 7] = *(double *)(&raw_bits);
      }
    }
  }
}

static void memcpy_wide_bus_write_double_128(merlin_uint_128 *c, double *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  if (len == 1) {
    VITIS_LOOP_3998_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      double buf_tmp = c_buf[j - head_align];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_128(&c[start], (j * data_width), data_width, raw_bits);
    }
    return;
  }
  size_t align = 0;
  if (head_align != 0) {
    VITIS_LOOP_4012_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      double buf_tmp = c_buf[j - head_align];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_128(&c[start], (j * data_width), data_width, raw_bits);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_4038_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j - 0];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_4048_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 7];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_4057_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 6];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_4066_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 5];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_4075_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 4];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_4084_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 3];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_4093_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 2];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else {
      VITIS_LOOP_4102_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 1];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_4113_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      double buf_tmp = c_buf[pos + j];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, raw_bits);
    }
  }
}
# 36 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128_1d.h" 2
# 5 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c" 2
# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512_1d.h" 1
# 24 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512_1d.h"
# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h" 1
# 27 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h"
# 1 "/usr/include/assert.h" 1 3 4
# 28 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h" 2

typedef struct merlin_uint_512 {
  unsigned char data[512 / 8];
} merlin_uint_512;
static uint64_t merlin_get_range_512(merlin_uint_512 *tmp, int low, int len) {
#pragma HLS INLINE SELF
 uint64_t ret = 0;
  int i;
  int start = low;
  switch (len) {
  case 1:
    VITIS_LOOP_39_1: for (i = 0; i >= 0; --i) {
#pragma HLS unroll
 ret <<= 8;
      ret |= tmp->data[i + start];
    }
    break;
  case 2:
    VITIS_LOOP_46_2: for (i = 1; i >= 0; --i) {
#pragma HLS unroll
 ret <<= 8;
      ret |= tmp->data[i + start];
    }
    break;
  case 4:
    VITIS_LOOP_53_3: for (i = 3; i >= 0; --i) {
#pragma HLS unroll
 ret <<= 8;
      ret |= tmp->data[i + start];
    }
    break;
  case 8:
    VITIS_LOOP_60_4: for (i = 7; i >= 0; --i) {
#pragma HLS unroll
 ret <<= 8;
      ret |= tmp->data[i + start];
    }
    break;
  default:
    ({ int _AssertPred = 0; __builtin_assume(_AssertPred); });
  }
  return ret;
}

static void merlin_set_range_512(merlin_uint_512 *tmp, int low, int len,
                                 uint64_t val) {
#pragma HLS INLINE SELF
 int i;
  int start = low;
  switch (len) {
  case 1:
    VITIS_LOOP_79_1: for (i = 0; i < 1; ++i) {
#pragma HLS unroll
 tmp->data[start + i] = val & 0xff;
      val >>= 8;
    }
    break;
  case 2:
    VITIS_LOOP_86_2: for (i = 0; i < 2; ++i) {
#pragma HLS unroll
 tmp->data[start + i] = val & 0xff;
      val >>= 8;
    }
    break;
  case 4:
    VITIS_LOOP_93_3: for (i = 0; i < 4; ++i) {
#pragma HLS unroll
 tmp->data[start + i] = val & 0xff;
      val >>= 8;
    }
    break;
  case 8:
    VITIS_LOOP_100_4: for (i = 0; i < 8; ++i) {
#pragma HLS unroll
 tmp->data[start + i] = val & 0xff;
      val >>= 8;
    }
    break;
  default:
    ({ int _AssertPred = 0; __builtin_assume(_AssertPred); });
  }
}
# 25 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512_1d.h" 2
# 35 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512_1d.h"
# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h" 1
# 22 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h"
# 1 "/usr/include/assert.h" 1 3 4
# 23 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h" 2
# 48 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus.h"
static char memcpy_wide_bus_single_read_char_512(merlin_uint_512 *a,
                                                          size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  char ret = merlin_get_range_512(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_char_512(merlin_uint_512 *c, char c_buf,

                                              size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_512(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static short memcpy_wide_bus_single_read_short_512(merlin_uint_512 *a,

                                               size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  short ret = merlin_get_range_512(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_short_512(merlin_uint_512 *c,

                                              short c_buf, size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_512(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static int memcpy_wide_bus_single_read_int_512(merlin_uint_512 *a,
                                                        size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  int ret = merlin_get_range_512(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_int_512(merlin_uint_512 *c,
                                                          int c_buf,
                                                          size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_512(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static long memcpy_wide_bus_single_read_long_512(merlin_uint_512 *a,
                                                          size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  long ret = merlin_get_range_512(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_long_512(merlin_uint_512 *c, long c_buf,

                                              size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_512(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static long long memcpy_wide_bus_single_read_long_long_512(merlin_uint_512 *a,

                                                   size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  long long ret = merlin_get_range_512(&a[start], (head_align * data_width), data_width);
  return ret;
}

static void memcpy_wide_bus_single_write_long_long_512(merlin_uint_512 *c,

                                              long long c_buf,
                                              size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  merlin_set_range_512(&c[start], (head_align * data_width), data_width, c_buf);
  return;
}

static float memcpy_wide_bus_single_read_float_512(merlin_uint_512 *a,

                                               size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;

  int raw_bits = merlin_get_range_512(&a[start], (head_align * data_width), data_width);
  float ret = *(float *)(&raw_bits);
  return ret;
}

static void memcpy_wide_bus_single_write_float_512(merlin_uint_512 *c,

                                              float c_buf, size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  float buf_tmp = c_buf;
  int raw_bits = *(int *)&buf_tmp;
  merlin_set_range_512(&c[start], (head_align * data_width), data_width, raw_bits);
  return;
}

static double memcpy_wide_bus_single_read_double_512(merlin_uint_512 *a,

                                                size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;

  int64_t raw_bits = merlin_get_range_512(&a[start], (head_align * data_width), data_width);
  double ret = *(double *)(&raw_bits);
  return ret;
}

static void memcpy_wide_bus_single_write_double_512(merlin_uint_512 *c,

                                              double c_buf,
                                              size_t offset_byte) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t start = offset / num_elements;
  double buf_tmp = c_buf;
  int64_t raw_bits = *(int64_t *)&buf_tmp;
  merlin_set_range_512(&c[start], (head_align * data_width), data_width, raw_bits);
  return;
}

static void memcpy_wide_bus_read_long_512(long *a_buf, merlin_uint_512 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  long len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_275_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_294_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_304_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_316_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_328_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_340_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_352_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_364_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 7) {
      VITIS_LOOP_376_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 7] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 8) {
      VITIS_LOOP_388_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 8] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 9) {
      VITIS_LOOP_400_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 9] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 10) {
      VITIS_LOOP_412_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 10] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 11) {
      VITIS_LOOP_424_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 11] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 12) {
      VITIS_LOOP_436_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 12] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 13) {
      VITIS_LOOP_448_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 13] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (data_width == 4 && head_align == 14) {
      VITIS_LOOP_460_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 14] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else {
      VITIS_LOOP_472_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_long_512(merlin_uint_512 *c, long *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_506_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_517_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_541_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_550_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_558_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_566_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_574_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_582_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_590_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else if (data_width == 4 && head_align == 7) {
      VITIS_LOOP_598_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 9]);

      }
    }

    else if (data_width == 4 && head_align == 8) {
      VITIS_LOOP_606_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 8]);

      }
    }

    else if (data_width == 4 && head_align == 9) {
      VITIS_LOOP_614_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 7]);

      }
    }

    else if (data_width == 4 && head_align == 10) {
      VITIS_LOOP_622_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 6]);

      }
    }

    else if (data_width == 4 && head_align == 11) {
      VITIS_LOOP_630_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 5]);

      }
    }

    else if (data_width == 4 && head_align == 12) {
      VITIS_LOOP_638_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 4]);

      }
    }

    else if (data_width == 4 && head_align == 13) {
      VITIS_LOOP_646_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 3]);

      }
    }

    else if (data_width == 4 && head_align == 14) {
      VITIS_LOOP_654_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 2]);

      }
    }

    else {
      VITIS_LOOP_662_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_672_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_long_long_512(long long *a_buf, merlin_uint_512 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_705_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_724_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_734_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_746_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_758_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_770_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_782_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_794_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else {
      VITIS_LOOP_806_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_long_long_512(merlin_uint_512 *c, long long *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_840_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_851_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_875_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_884_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_892_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_900_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_908_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_916_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_924_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else {
      VITIS_LOOP_932_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_942_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_int_512(int *a_buf, merlin_uint_512 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_975_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_994_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_1004_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_1016_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_1028_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_1040_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_1052_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_1064_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_1076_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 7] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_1088_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 8] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_1100_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 9] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_1112_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 10] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_1124_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 11] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_1136_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 12] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_1148_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 13] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_1160_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 14] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else {
      VITIS_LOOP_1172_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_int_512(merlin_uint_512 *c, int *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1206_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1217_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_1241_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_1250_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_1258_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_1266_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_1274_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_1282_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_1290_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_1298_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 9]);

      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_1306_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 8]);

      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_1314_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 7]);

      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_1322_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 6]);

      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_1330_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 5]);

      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_1338_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 4]);

      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_1346_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 3]);

      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_1354_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 2]);

      }
    }

    else {
      VITIS_LOOP_1362_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1372_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_short_512(short *a_buf, merlin_uint_512 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1405_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }

L3:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_1424_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_1434_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_1446_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_1458_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_1470_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_1482_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_1494_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_1506_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 7] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_1518_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 8] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_1530_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 9] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_1542_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 10] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_1554_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 11] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_1566_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 12] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_1578_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 13] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_1590_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 14] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 15) {
      VITIS_LOOP_1600_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 16) {
      VITIS_LOOP_1610_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 16)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 16] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 17) {
      VITIS_LOOP_1620_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 17)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 17] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 18) {
      VITIS_LOOP_1630_20: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 18)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 18] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 19) {
      VITIS_LOOP_1640_21: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 19)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 19] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 20) {
      VITIS_LOOP_1650_22: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 20)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 20] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 21) {
      VITIS_LOOP_1660_23: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 21)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 21] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 22) {
      VITIS_LOOP_1670_24: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 22)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 22] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 23) {
      VITIS_LOOP_1680_25: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 23)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 23] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 24) {
      VITIS_LOOP_1690_26: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 24)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 24] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 25) {
      VITIS_LOOP_1700_27: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 25)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 25] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 26) {
      VITIS_LOOP_1710_28: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 26)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 26] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 27) {
      VITIS_LOOP_1720_29: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 27)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 27] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 28) {
      VITIS_LOOP_1730_30: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 28)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 28] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 29) {
      VITIS_LOOP_1740_31: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 29)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 29] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 30) {
      VITIS_LOOP_1750_32: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 30)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 30] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else {
      VITIS_LOOP_1760_33: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 31)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 31] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_short_512(merlin_uint_512 *c, short *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1794_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1805_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_1829_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    } else if (head_align == 1) {
      VITIS_LOOP_1836_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 31]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_1844_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 30]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_1852_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 29]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_1860_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 28]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_1868_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 27]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_1876_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 26]);

      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_1884_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 25]);

      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_1892_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 24]);

      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_1900_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 23]);

      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_1908_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 22]);

      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_1916_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 21]);

      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_1924_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 20]);

      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_1932_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 19]);

      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_1940_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 18]);

      }
    }

    else if (head_align == 15) {
      VITIS_LOOP_1948_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 17]);

      }
    }

    else if (head_align == 16) {
      VITIS_LOOP_1956_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 16]);

      }
    }

    else if (head_align == 17) {
      VITIS_LOOP_1964_20: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 18) {
      VITIS_LOOP_1972_21: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 19) {
      VITIS_LOOP_1980_22: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 20) {
      VITIS_LOOP_1988_23: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 21) {
      VITIS_LOOP_1996_24: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 22) {
      VITIS_LOOP_2004_25: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else if (head_align == 23) {
      VITIS_LOOP_2012_26: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 9]);

      }
    }

    else if (head_align == 24) {
      VITIS_LOOP_2020_27: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 8]);

      }
    }

    else if (head_align == 25) {
      VITIS_LOOP_2028_28: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 7]);

      }
    }

    else if (head_align == 26) {
      VITIS_LOOP_2036_29: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 6]);

      }
    }

    else if (head_align == 27) {
      VITIS_LOOP_2044_30: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 5]);

      }
    }

    else if (head_align == 28) {
      VITIS_LOOP_2052_31: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 4]);

      }
    }

    else if (head_align == 29) {
      VITIS_LOOP_2060_32: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 3]);

      }
    }

    else if (head_align == 30) {
      VITIS_LOOP_2068_33: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 2]);

      }
    }

    else {
      VITIS_LOOP_2076_34: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_2086_35: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_char_512(char *a_buf, merlin_uint_512 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_2119_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      a_buf[j - head_align] = merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_2138_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 0] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_2148_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 1] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_2160_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 2] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_2172_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 3] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_2184_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 4] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_2196_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 5] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_2208_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 6] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_2220_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 7] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_2232_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 8] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_2244_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 9] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_2256_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 10] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_2268_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 11] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_2280_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 12] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_2292_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 13] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_2304_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 14] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 15) {
      VITIS_LOOP_2314_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 15] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 16) {
      VITIS_LOOP_2324_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 16)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 16] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 17) {
      VITIS_LOOP_2334_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 17)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 17] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 18) {
      VITIS_LOOP_2344_20: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 18)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 18] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 19) {
      VITIS_LOOP_2354_21: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 19)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 19] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 20) {
      VITIS_LOOP_2364_22: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 20)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 20] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 21) {
      VITIS_LOOP_2374_23: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 21)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 21] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 22) {
      VITIS_LOOP_2384_24: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 22)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 22] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 23) {
      VITIS_LOOP_2394_25: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 23)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 23] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 24) {
      VITIS_LOOP_2404_26: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 24)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 24] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 25) {
      VITIS_LOOP_2414_27: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 25)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 25] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 26) {
      VITIS_LOOP_2424_28: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 26)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 26] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 27) {
      VITIS_LOOP_2434_29: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 27)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 27] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 28) {
      VITIS_LOOP_2444_30: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 28)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 28] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 29) {
      VITIS_LOOP_2454_31: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 29)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 29] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 30) {
      VITIS_LOOP_2464_32: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 30)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 30] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 31) {
      VITIS_LOOP_2474_33: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 31)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 31] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 32) {
      VITIS_LOOP_2484_34: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 32)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 32] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 33) {
      VITIS_LOOP_2494_35: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 33)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 33] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 34) {
      VITIS_LOOP_2504_36: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 34)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 34] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 35) {
      VITIS_LOOP_2514_37: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 35)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 35] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 36) {
      VITIS_LOOP_2524_38: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 36)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 36] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 37) {
      VITIS_LOOP_2534_39: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 37)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 37] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 38) {
      VITIS_LOOP_2544_40: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 38)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 38] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 39) {
      VITIS_LOOP_2554_41: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 39)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 39] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 40) {
      VITIS_LOOP_2564_42: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 40)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 40] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 41) {
      VITIS_LOOP_2574_43: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 41)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 41] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 42) {
      VITIS_LOOP_2584_44: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 42)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 42] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 43) {
      VITIS_LOOP_2594_45: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 43)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 43] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 44) {
      VITIS_LOOP_2604_46: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 44)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 44] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 45) {
      VITIS_LOOP_2614_47: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 45)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 45] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 46) {
      VITIS_LOOP_2624_48: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 46)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 46] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 47) {
      VITIS_LOOP_2634_49: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 47)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 47] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 48) {
      VITIS_LOOP_2644_50: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 48)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 48] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 49) {
      VITIS_LOOP_2654_51: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 49)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 49] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 50) {
      VITIS_LOOP_2664_52: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 50)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 50] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 51) {
      VITIS_LOOP_2674_53: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 51)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 51] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 52) {
      VITIS_LOOP_2684_54: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 52)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 52] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 53) {
      VITIS_LOOP_2694_55: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 53)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 53] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 54) {
      VITIS_LOOP_2704_56: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 54)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 54] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 55) {
      VITIS_LOOP_2714_57: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 55)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 55] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 56) {
      VITIS_LOOP_2724_58: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 56)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 56] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 57) {
      VITIS_LOOP_2734_59: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 57)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 57] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 58) {
      VITIS_LOOP_2744_60: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 58)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 58] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 59) {
      VITIS_LOOP_2754_61: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 59)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 59] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 60) {
      VITIS_LOOP_2764_62: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 60)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 60] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 61) {
      VITIS_LOOP_2774_63: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 61)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 61] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else if (head_align == 62) {
      VITIS_LOOP_2784_64: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 62)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 62] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    } else {
      VITIS_LOOP_2794_65: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 63)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        a_buf[i * num_elements + j - 63] =
            merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_char_512(merlin_uint_512 *c, char *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_2828_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_2839_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[j - head_align]);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_2863_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j - 0]);

      }

    } else if (head_align == 1) {
      VITIS_LOOP_2870_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 63]);

      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_2878_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 62]);

      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_2886_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 61]);

      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_2894_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 60]);

      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_2902_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 59]);

      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_2910_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 58]);

      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_2918_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 57]);

      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_2926_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 56]);

      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_2934_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 55]);

      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_2942_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 54]);

      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_2950_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 53]);

      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_2958_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 52]);

      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_2966_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 51]);

      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_2974_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 50]);

      }
    }

    else if (head_align == 15) {
      VITIS_LOOP_2982_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 49]);

      }
    }

    else if (head_align == 16) {
      VITIS_LOOP_2990_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 48]);

      }
    }

    else if (head_align == 17) {
      VITIS_LOOP_2998_20: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 47]);

      }
    }

    else if (head_align == 18) {
      VITIS_LOOP_3006_21: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 46]);

      }
    }

    else if (head_align == 19) {
      VITIS_LOOP_3014_22: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 45]);

      }
    }

    else if (head_align == 20) {
      VITIS_LOOP_3022_23: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 44]);

      }
    }

    else if (head_align == 21) {
      VITIS_LOOP_3030_24: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 43]);

      }
    }

    else if (head_align == 22) {
      VITIS_LOOP_3038_25: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 42]);

      }
    }

    else if (head_align == 23) {
      VITIS_LOOP_3046_26: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 41]);

      }
    }

    else if (head_align == 24) {
      VITIS_LOOP_3054_27: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 40]);

      }
    }

    else if (head_align == 25) {
      VITIS_LOOP_3062_28: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 39]);

      }
    }

    else if (head_align == 26) {
      VITIS_LOOP_3070_29: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 38]);

      }
    }

    else if (head_align == 27) {
      VITIS_LOOP_3078_30: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 37]);

      }
    }

    else if (head_align == 28) {
      VITIS_LOOP_3086_31: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 36]);

      }
    }

    else if (head_align == 29) {
      VITIS_LOOP_3094_32: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 35]);

      }
    }

    else if (head_align == 30) {
      VITIS_LOOP_3102_33: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 34]);

      }
    }

    else if (head_align == 31) {
      VITIS_LOOP_3110_34: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 33]);

      }
    }

    else if (head_align == 32) {
      VITIS_LOOP_3118_35: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 32]);

      }
    }

    else if (head_align == 33) {
      VITIS_LOOP_3126_36: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 31]);

      }
    }

    else if (head_align == 34) {
      VITIS_LOOP_3134_37: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 30]);

      }
    }

    else if (head_align == 35) {
      VITIS_LOOP_3142_38: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 29]);

      }
    }

    else if (head_align == 36) {
      VITIS_LOOP_3150_39: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 28]);

      }
    }

    else if (head_align == 37) {
      VITIS_LOOP_3158_40: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 27]);

      }
    }

    else if (head_align == 38) {
      VITIS_LOOP_3166_41: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 26]);

      }
    }

    else if (head_align == 39) {
      VITIS_LOOP_3174_42: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 25]);

      }
    }

    else if (head_align == 40) {
      VITIS_LOOP_3182_43: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 24]);

      }
    }

    else if (head_align == 41) {
      VITIS_LOOP_3190_44: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 23]);

      }
    }

    else if (head_align == 42) {
      VITIS_LOOP_3198_45: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 22]);

      }
    }

    else if (head_align == 43) {
      VITIS_LOOP_3206_46: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 21]);

      }
    }

    else if (head_align == 44) {
      VITIS_LOOP_3214_47: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 20]);

      }
    }

    else if (head_align == 45) {
      VITIS_LOOP_3222_48: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 19]);

      }
    }

    else if (head_align == 46) {
      VITIS_LOOP_3230_49: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 18]);

      }
    }

    else if (head_align == 47) {
      VITIS_LOOP_3238_50: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 17]);

      }
    }

    else if (head_align == 48) {
      VITIS_LOOP_3246_51: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 16]);

      }
    }

    else if (head_align == 49) {
      VITIS_LOOP_3254_52: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 15]);

      }
    }

    else if (head_align == 50) {
      VITIS_LOOP_3262_53: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 14]);

      }
    }

    else if (head_align == 51) {
      VITIS_LOOP_3270_54: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 13]);

      }
    }

    else if (head_align == 52) {
      VITIS_LOOP_3278_55: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 12]);

      }
    }

    else if (head_align == 53) {
      VITIS_LOOP_3286_56: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 11]);

      }
    }

    else if (head_align == 54) {
      VITIS_LOOP_3294_57: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 10]);

      }
    }

    else if (head_align == 55) {
      VITIS_LOOP_3302_58: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 9]);

      }
    }

    else if (head_align == 56) {
      VITIS_LOOP_3310_59: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 8]);

      }
    }

    else if (head_align == 57) {
      VITIS_LOOP_3318_60: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 7]);

      }
    }

    else if (head_align == 58) {
      VITIS_LOOP_3326_61: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 6]);

      }
    }

    else if (head_align == 59) {
      VITIS_LOOP_3334_62: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 5]);

      }
    }

    else if (head_align == 60) {
      VITIS_LOOP_3342_63: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 4]);

      }
    }

    else if (head_align == 61) {
      VITIS_LOOP_3350_64: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 3]);

      }
    }

    else if (head_align == 62) {
      VITIS_LOOP_3358_65: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 2]);

      }
    }

    else {
      VITIS_LOOP_3366_66: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[i * num_elements + j + 1]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_3376_67: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[pos + j]);
    }
  }
}

static void memcpy_wide_bus_read_float_512(float *a_buf, merlin_uint_512 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0) {
    len = (buf_size + num_elements - 1) / num_elements;
  }
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_3410_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      int raw_bits = merlin_get_range_512(&a[start], (j * data_width), data_width);
      a_buf[j - head_align] = *(float *)(&raw_bits);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_3430_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 0] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_3440_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 1] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_3452_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 2] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_3464_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 3] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_3476_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 4] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_3488_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 5] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_3500_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 6] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_3512_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 7] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_3524_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 8)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 8] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_3536_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 9)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 9] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_3548_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 10)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 10] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_3560_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 11)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 11] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_3572_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 12)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 12] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_3584_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 13)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 13] = *(float *)(&raw_bits);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_3596_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 14)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 14] = *(float *)(&raw_bits);
      }
    }

    else {
      VITIS_LOOP_3608_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 15)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 15] = *(float *)(&raw_bits);
      }
    }
  }
}

static void memcpy_wide_bus_write_float_512(merlin_uint_512 *c, float *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  if (len == 1) {
    VITIS_LOOP_3641_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      float buf_tmp = c_buf[j - head_align];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_512(&c[start], (j * data_width), data_width, raw_bits);
    }
    return;
  }
  unsigned align = 0;
  if (head_align != 0) {
    VITIS_LOOP_3655_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      float buf_tmp = c_buf[j - head_align];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_512(&c[start], (j * data_width), data_width, raw_bits);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_3681_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j - 0];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_3691_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 15];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_3700_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 14];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_3709_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 13];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_3718_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 12];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_3727_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 11];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_3736_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 10];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 7) {
      VITIS_LOOP_3745_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 9];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 8) {
      VITIS_LOOP_3754_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 8];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 9) {
      VITIS_LOOP_3763_12: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 7];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 10) {
      VITIS_LOOP_3772_13: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 6];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 11) {
      VITIS_LOOP_3781_14: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 5];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 12) {
      VITIS_LOOP_3790_15: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 4];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 13) {
      VITIS_LOOP_3799_16: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 3];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 14) {
      VITIS_LOOP_3808_17: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 2];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else {
      VITIS_LOOP_3817_18: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[i * num_elements + j + 1];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_3828_19: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      float buf_tmp = c_buf[pos + j];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, raw_bits);
    }
  }
}

static void memcpy_wide_bus_read_double_512(double *a_buf, merlin_uint_512 *a,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_3863_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      int64_t raw_bits = merlin_get_range_512(&a[start], (j * data_width), data_width);
      a_buf[j - head_align] = *(double *)(&raw_bits);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_3883_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 0] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 1) {
      VITIS_LOOP_3893_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 1)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 1] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_3905_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 2)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 2] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_3917_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 3)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 3] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_3929_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 4)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 4] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_3941_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 5)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 5] = *(double *)(&raw_bits);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_3953_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 6)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 6] = *(double *)(&raw_bits);
      }
    }

    else {
      VITIS_LOOP_3965_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < 7)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[i * num_elements + j - 7] = *(double *)(&raw_bits);
      }
    }
  }
}

static void memcpy_wide_bus_write_double_512(merlin_uint_512 *c, double *c_buf,

                                       size_t offset_byte, size_t size_byte,
                                       const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  if (len == 1) {
    VITIS_LOOP_3998_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      double buf_tmp = c_buf[j - head_align];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_512(&c[start], (j * data_width), data_width, raw_bits);
    }
    return;
  }
  size_t align = 0;
  if (head_align != 0) {
    VITIS_LOOP_4012_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      double buf_tmp = c_buf[j - head_align];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_512(&c[start], (j * data_width), data_width, raw_bits);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0) {
      VITIS_LOOP_4038_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j - 0];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }

    }

    else if (head_align == 1) {
      VITIS_LOOP_4048_4: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 7];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 2) {
      VITIS_LOOP_4057_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 6];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 3) {
      VITIS_LOOP_4066_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 5];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 4) {
      VITIS_LOOP_4075_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 4];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 5) {
      VITIS_LOOP_4084_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 3];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else if (head_align == 6) {
      VITIS_LOOP_4093_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 2];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }

    else {
      VITIS_LOOP_4102_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[i * num_elements + j + 1];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_4113_11: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      double buf_tmp = c_buf[pos + j];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, raw_bits);
    }
  }
}
# 36 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512_1d.h" 2
# 6 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c" 2


# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512_3d.h" 1
# 33 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512_3d.h"
# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h" 1
# 22 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h"
# 1 "/usr/include/assert.h" 1 3 4
# 23 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h" 2
# 342 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h"
static void memcpy_wide_bus_read_char_3d_8_8_512(
    char a_buf[][8][8], size_t index3_offset, size_t index2_offset,
    size_t index1_offset, merlin_uint_512 *a, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t SIZE = 8 * 8;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_387_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
           [(buffer_index % SIZE) % 8] =
               merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }
L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_409_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          size_t buffer_index = i * num_elements + j - 0;
          a_buf[index3][index2][index1 * num_elements + j] =
              merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_420_3: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_422_4: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index3][index2 * num_elements / 8 + j0][j1] =
                merlin_get_range_512(&a[i + start], (j * data_width), data_width);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_433_5: for (j0 = 0; j0 < num_elements / SIZE; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_435_6: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_436_7: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              if (i == end - start - 1 && j > tail_align)
                continue;
              a_buf[index3 * bound0 + j0][j1][j2] =
                  merlin_get_range_512(&a[i + start], (j * data_width), data_width);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_448_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buffer_index = i * num_elements + j - head_align + index_offset;
        a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
             [(buffer_index % SIZE) % 8] =
                 merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_char_3d_8_8_512(
    merlin_uint_512 *c, char c_buf[][8][8], size_t index3_offset,
    size_t index2_offset, size_t index1_offset, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  const size_t SIZE = 8 * 8;
  size_t index_offset =
      SIZE * index3_offset + 8 * index2_offset + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_487_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_501_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_547_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 int val = c_buf[index3][index2][index1 * num_elements + j];
          merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_555_4: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_557_5: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            int val = c_buf[index3][index2 * num_elements / 8 + j0][j1];
            merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_566_6: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_567_7: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_568_8: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              int val = c_buf[index3 * bound0 + j0][j1][j2];
              merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_578_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buffer_index =
            i * num_elements + j + num_elements - head_align + index_offset;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_591_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      size_t buffer_index = pos + j;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
  }
}

static void memcpy_wide_bus_read_short_3d_8_8_512(
    short a_buf[][8][8], size_t index3_offset, size_t index2_offset,
    size_t index1_offset, merlin_uint_512 *a, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t SIZE = 8 * 8;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_648_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
           [(buffer_index % SIZE) % 8] =
               merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }
L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_670_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          size_t buffer_index = i * num_elements + j - 0;
          a_buf[index3][index2][index1 * num_elements + j] =
              merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_681_3: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_683_4: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index3][index2 * num_elements / 8 + j0][j1] =
                merlin_get_range_512(&a[i + start], (j * data_width), data_width);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_694_5: for (j0 = 0; j0 < num_elements / SIZE; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_696_6: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_697_7: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              if (i == end - start - 1 && j > tail_align)
                continue;
              a_buf[index3 * bound0 + j0][j1][j2] =
                  merlin_get_range_512(&a[i + start], (j * data_width), data_width);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_709_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buffer_index = i * num_elements + j - head_align + index_offset;
        a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
             [(buffer_index % SIZE) % 8] =
                 merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_short_3d_8_8_512(
    merlin_uint_512 *c, short c_buf[][8][8], size_t index3_offset,
    size_t index2_offset, size_t index1_offset, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  const size_t SIZE = 8 * 8;
  size_t index_offset =
      SIZE * index3_offset + 8 * index2_offset + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_748_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_762_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_808_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 int val = c_buf[index3][index2][index1 * num_elements + j];
          merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_816_4: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_818_5: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            int val = c_buf[index3][index2 * num_elements / 8 + j0][j1];
            merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_827_6: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_828_7: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_829_8: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              int val = c_buf[index3 * bound0 + j0][j1][j2];
              merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_839_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buffer_index =
            i * num_elements + j + num_elements - head_align + index_offset;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_852_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      size_t buffer_index = pos + j;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
  }
}

static void memcpy_wide_bus_read_int_3d_8_8_512(
    int a_buf[][8][8], size_t index3_offset, size_t index2_offset,
    size_t index1_offset, merlin_uint_512 *a, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t SIZE = 8 * 8;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }

  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_910_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
           [(buffer_index % SIZE) % 8] =
               merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }
L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_932_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          size_t buffer_index = i * num_elements + j - 0;
          a_buf[index3][index2][index1 * num_elements + j] =
              merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_943_3: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_945_4: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index3][index2 * num_elements / 8 + j0][j1] =
                merlin_get_range_512(&a[i + start], (j * data_width), data_width);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_956_5: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_957_6: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_958_7: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              if (i == end - start - 1 && j > tail_align)
                continue;
              a_buf[index3 * bound0 + j0][j1][j2] =
                  merlin_get_range_512(&a[i + start], (j * data_width), data_width);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_970_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buffer_index = i * num_elements + j - head_align + index_offset;
        a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
             [(buffer_index % SIZE) % 8] =
                 merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_int_3d_8_8_512(
    merlin_uint_512 *c, int c_buf[][8][8], size_t index3_offset,
    size_t index2_offset, size_t index1_offset, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  const size_t SIZE = 8 * 8;
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1009_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1023_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1069_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 int val = c_buf[index3][index2][index1 * num_elements + j];
          merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_1077_4: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_1079_5: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            int val = c_buf[index3][index2 * num_elements / 8 + j0][j1];
            merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_1088_6: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1089_7: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_1090_8: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              int val = c_buf[index3 * bound0 + j0][j1][j2];
              merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_1100_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buffer_index =
            i * num_elements + j + num_elements - head_align + index_offset;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1113_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      size_t buffer_index = pos + j;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
  }
}

static void memcpy_wide_bus_read_long_3d_8_8_512(
    long a_buf[][8][8], size_t index3_offset, size_t index2_offset,
    size_t index1_offset, merlin_uint_512 *a, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t SIZE = 8 * 8;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }

  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1171_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
           [(buffer_index % SIZE) % 8] =
               merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }
L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1193_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          size_t buffer_index = i * num_elements + j - 0;
          a_buf[index3][index2][index1 * num_elements + j] =
              merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_1204_3: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_1206_4: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index3][index2 * num_elements / 8 + j0][j1] =
                merlin_get_range_512(&a[i + start], (j * data_width), data_width);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_1217_5: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1218_6: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_1219_7: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              if (i == end - start - 1 && j > tail_align)
                continue;
              a_buf[index3 * bound0 + j0][j1][j2] =
                  merlin_get_range_512(&a[i + start], (j * data_width), data_width);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_1231_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buffer_index = i * num_elements + j - head_align + index_offset;
        a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
             [(buffer_index % SIZE) % 8] =
                 merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_long_3d_8_8_512(
    merlin_uint_512 *c, long c_buf[][8][8], size_t index3_offset,
    size_t index2_offset, size_t index1_offset, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  const size_t SIZE = 8 * 8;
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1270_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1284_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1330_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 long val = c_buf[index3][index2][index1 * num_elements + j];
          merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_1338_4: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_1340_5: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            long val = c_buf[index3][index2 * num_elements / 8 + j0][j1];
            merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_1349_6: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1350_7: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_1351_8: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              long val = c_buf[index3 * bound0 + j0][j1][j2];
              merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_1361_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buffer_index =
            i * num_elements + j + num_elements - head_align + index_offset;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1374_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      size_t buffer_index = pos + j;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
  }
}

static void memcpy_wide_bus_read_long_long_3d_8_8_512(
    long long a_buf[][8][8], size_t index3_offset,
    size_t index2_offset, size_t index1_offset, merlin_uint_512 *a,
    size_t offset_byte, size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t SIZE = 8 * 8;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }

  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1432_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
           [(buffer_index % SIZE) % 8] =
               merlin_get_range_512(&a[start], (j * data_width), data_width);
    }
    return;
  }
L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1454_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          size_t buffer_index = i * num_elements + j - 0;
          a_buf[index3][index2][index1 * num_elements + j] =
              merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_1465_3: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_1467_4: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index3][index2 * num_elements / 8 + j0][j1] =
                merlin_get_range_512(&a[i + start], (j * data_width), data_width);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_1478_5: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1479_6: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_1480_7: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              if (i == end - start - 1 && j > tail_align)
                continue;
              a_buf[index3 * bound0 + j0][j1][j2] =
                  merlin_get_range_512(&a[i + start], (j * data_width), data_width);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_1492_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buffer_index = i * num_elements + j - head_align + index_offset;
        a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
             [(buffer_index % SIZE) % 8] =
                 merlin_get_range_512(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_long_long_3d_8_8_512(
    merlin_uint_512 *c, long long c_buf[][8][8],
    size_t index3_offset, size_t index2_offset, size_t index1_offset,
    size_t offset_byte, size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  const size_t SIZE = 8 * 8;
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1531_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1545_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      merlin_set_range_512(&c[start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1591_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 long long val = c_buf[index3][index2][index1 * num_elements + j];
          merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_1599_4: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_1601_5: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            long long val =
                c_buf[index3][index2 * num_elements / 8 + j0][j1];
            merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_1611_6: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1612_7: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_1613_8: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              long long val = c_buf[index3 * bound0 + j0][j1][j2];
              merlin_set_range_512(&c[i + start], (j * data_width), data_width, val);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_1623_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buffer_index =
            i * num_elements + j + num_elements - head_align + index_offset;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1636_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      size_t buffer_index = pos + j;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8] [(buffer_index % SIZE) % 8]);


    }
  }
}

static void memcpy_wide_bus_read_float_3d_8_8_512(
    float a_buf[][8][8], size_t index3_offset, size_t index2_offset,
    size_t index1_offset, merlin_uint_512 *a, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t SIZE = 8 * 8;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1693_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      int raw_bits = merlin_get_range_512(&a[start], (j * data_width), data_width);
      a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
           [(buffer_index % SIZE) % 8] = *(float *)(&raw_bits);
    }
    return;
  }
L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1715_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
          a_buf[index3][index2][index1 * num_elements + j] =
              *(float *)(&raw_bits);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_1726_3: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_1728_4: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
            a_buf[index3][index2 * num_elements / 8 + j0][j1] =
                *(float *)(&raw_bits);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_1740_5: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1741_6: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_1742_7: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              if (i == end - start - 1 && j > tail_align)
                continue;
              int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
              a_buf[index3 * bound0 + j0][j1][j2] = *(float *)(&raw_bits);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_1754_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buffer_index = i * num_elements + j - head_align + index_offset;
        int raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
             [(buffer_index % SIZE) % 8] = *(float *)(&raw_bits);
      }
    }
  }
}

static void memcpy_wide_bus_write_float_3d_8_8_512(
    merlin_uint_512 *c, float c_buf[][8][8], size_t index3_offset,
    size_t index2_offset, size_t index1_offset, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  const size_t SIZE = 8 * 8;
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  if (len == 1) {
    VITIS_LOOP_1792_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      float buf_tmp = c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
                           [(buffer_index % SIZE) % 8];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_512(&c[start], (j * data_width), data_width, raw_bits);
    }
    return;
  }
  unsigned align = 0;
  if (head_align != 0) {
    VITIS_LOOP_1808_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      float buf_tmp = c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
                           [(buffer_index % SIZE) % 8];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_512(&c[start], (j * data_width), data_width, raw_bits);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1855_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll

 float buf_tmp = c_buf[index3][index2][index1 * num_elements + j];
          int raw_bits = *(int *)&buf_tmp;
          merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_1865_4: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_1867_5: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            float buf_tmp =
                c_buf[index3][index2 * num_elements / 8 + j0][j1];
            int raw_bits = *(int *)&buf_tmp;
            merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_1878_6: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1879_7: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_1880_8: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              float buf_tmp = c_buf[index3 * bound0 + j0][j1][j2];
              int raw_bits = *(int *)&buf_tmp;
              merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_1891_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buffer_index =
            i * num_elements + j + num_elements - head_align + index_offset;
        float buf_tmp =
            c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
                 [(buffer_index % SIZE) % 8];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1906_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      size_t buffer_index = pos + j;
      float buf_tmp = c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
                           [(buffer_index % SIZE) % 8];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, raw_bits);
    }
  }
}

static void memcpy_wide_bus_read_double_3d_8_8_512(
    double a_buf[][8][8], size_t index3_offset, size_t index2_offset,
    size_t index1_offset, merlin_uint_512 *a, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  const size_t SIZE = 8 * 8;
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  const size_t bound1 = 8 / num_elements;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1964_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;

      size_t buffer_index = j - head_align + index_offset;
      int64_t raw_bits = merlin_get_range_512(&a[start], (j * data_width), data_width);
      a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
           [(buffer_index % SIZE) % 8] = *(double *)(&raw_bits);
    }
    return;
  }
L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1987_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
          a_buf[index3][index2][index1 * num_elements + j] =
              *(double *)(&raw_bits);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_1998_3: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_2000_4: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
            a_buf[index3][index2 * num_elements / 8 + j0][j1] =
                *(double *)(&raw_bits);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_2012_5: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_2013_6: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_2014_7: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              if (i == end - start - 1 && j > tail_align)
                continue;
              int64_t raw_bits =
                  merlin_get_range_512(&a[i + start], (j * data_width), data_width);
              a_buf[index3 * bound0 + j0][j1][j2] = *(double *)(&raw_bits);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_2027_8: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buffer_index = i * num_elements + j - head_align + index_offset;
        int64_t raw_bits = merlin_get_range_512(&a[i + start], (j * data_width), data_width);
        a_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
             [(buffer_index % SIZE) % 8] = *(double *)(&raw_bits);
      }
    }
  }
}

static void memcpy_wide_bus_write_double_3d_8_8_512(
    merlin_uint_512 *c, double c_buf[][8][8], size_t index3_offset,
    size_t index2_offset, size_t index1_offset, size_t offset_byte,
    size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 512 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  const size_t bound1 = 8 / num_elements;
  const size_t SIZE = 8 * 8;
  const size_t bound2 = SIZE / num_elements;
  const size_t bound0 = num_elements / SIZE;
  int aligned = 0;
  size_t index3 = index3_offset, index2 = index2_offset, index1 = index1_offset;
  if ((8 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((SIZE % num_elements) == 0 && (num_elements % 8) == 0 &&
             ((index2_offset * 8) % num_elements) == 0 && !index1_offset) {
    aligned = 2;
    index2 = index2_offset * 8 / num_elements;
  } else if ((num_elements % SIZE) == 0 &&
             (index3_offset * SIZE % num_elements) == 0 && !index2_offset &&
             !index1_offset) {
    index3 = index3_offset * SIZE / num_elements;
    aligned = -1;
  }
  const size_t index_offset =
      index3_offset * SIZE + index2_offset * 8 + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  if (len == 1) {
    VITIS_LOOP_2083_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      double buf_tmp =
          c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
               [(buffer_index % SIZE) % 8];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_512(&c[start], (j * data_width), data_width, raw_bits);
    }
    return;
  }
  size_t align = 0;
  if (head_align != 0) {
    VITIS_LOOP_2100_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buffer_index = j - head_align + index_offset;
      double buf_tmp =
          c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
               [(buffer_index % SIZE) % 8];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_512(&c[start], (j * data_width), data_width, raw_bits);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_2130_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll

 double buf_tmp = c_buf[index3][index2][index1 * num_elements + j];
          int64_t raw_bits = *(int64_t *)&buf_tmp;
          merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
        }
        if (index1 == bound1 - 1) { index1 = 0; if (index2 == 8 - 1) { index2 = 0; ++index3; } else ++index2; } else index1++;
      } else if (aligned == 2) {
        int j0, j1;
        VITIS_LOOP_2140_4: for (j0 = 0; j0 < num_elements / 8; ++j0) {
#pragma HLS unroll
 VITIS_LOOP_2142_5: for (j1 = 0; j1 < 8; ++j1) {
            j = j0 * 8 + j1;
            double buf_tmp =
                c_buf[index3][index2 * num_elements / 8 + j0][j1];
            int64_t raw_bits = *(int64_t *)&buf_tmp;
            merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
          }
        }
        if (index2 == bound2 - 1) { index2 = 0; index3++; } else index2++;
      } else if (aligned == -1) {
        int j0, j1, j2;
        VITIS_LOOP_2153_6: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_2154_7: for (j1 = 0; j1 < 8; ++j1) {
            VITIS_LOOP_2155_8: for (j2 = 0; j2 < 8; ++j2) {
              j = j0 * SIZE + j1 * 8 + j2;
              double buf_tmp = c_buf[index3 * bound0 + j0][j1][j2];
              int64_t raw_bits = *(int64_t *)&buf_tmp;
              merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
            }
          }
        }
        ++index3;
      }
    } else {
      VITIS_LOOP_2166_9: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buffer_index =
            i * num_elements + j + num_elements - head_align + index_offset;
        double buf_tmp =
            c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
                 [(buffer_index % SIZE) % 8];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_512(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_2181_10: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      size_t buffer_index = pos + j;
      double buf_tmp =
          c_buf[buffer_index / SIZE][(buffer_index % SIZE) / 8]
               [(buffer_index % SIZE) % 8];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_512(&c[end - 1], (j * data_width), data_width, raw_bits);
    }
  }
}
# 34 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512_3d.h" 2
# 9 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c" 2



# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128_2d.h" 1
# 33 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128_2d.h"
# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h" 1
# 22 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h"
# 1 "/usr/include/assert.h" 1 3 4
# 23 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h" 2
# 275 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h"
static void memcpy_wide_bus_read_char_2d_100_128(
    char a_buf[][100], size_t index2_offset, size_t index1_offset,
    merlin_uint_128 *a, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  const size_t index_offset = index2_offset * 100 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_312_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      a_buf[buf_index / 100][buf_index % 100] =
          merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_334_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          a_buf[index2][index1 * num_elements + j] =
              merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_344_3: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_345_4: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index2 * bound0 + j0][j1] =
                merlin_get_range_128(&a[i + start], (j * data_width), data_width);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_356_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buf_index = (i * num_elements + j - head_align) + index_offset;
        a_buf[buf_index / 100][buf_index % 100] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_char_2d_100_128(
    merlin_uint_128 *c, char c_buf[][100], size_t index2_offset,
    size_t index1_offset, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(char);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t index_offset = index2_offset * 100 + index1_offset;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_392_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_405_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((num_elements % 100) == 0 &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_444_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 int val = c_buf[index2][index1 * num_elements + j];
          merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_452_4: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_453_5: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            int val = c_buf[index2 * bound0 + j0][j1];
            merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_462_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buf_index =
            (i * num_elements + j + num_elements - head_align) + index_offset;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[buf_index / 100][index_offset % 100]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements + index_offset;
    VITIS_LOOP_474_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[(pos + j) / 100][(pos + j) % 100]);

    }
  }
}

static void memcpy_wide_bus_read_short_2d_100_128(
    short a_buf[][100], size_t index2_offset, size_t index1_offset,
    merlin_uint_128 *a, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  const size_t index_offset = index2_offset * 100 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_521_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      a_buf[buf_index / 100][buf_index % 100] =
          merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_543_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          a_buf[index2][index1 * num_elements + j] =
              merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_553_3: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_554_4: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index2 * bound0 + j0][j1] =
                merlin_get_range_128(&a[i + start], (j * data_width), data_width);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_565_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buf_index = (i * num_elements + j - head_align) + index_offset;
        a_buf[buf_index / 100][buf_index % 100] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_short_2d_100_128(
    merlin_uint_128 *c, short c_buf[][100], size_t index2_offset,
    size_t index1_offset, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(short);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t index_offset = index2_offset * 100 + index1_offset;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_601_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_614_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((num_elements % 100) == 0 &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_653_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 int val = c_buf[index2][index1 * num_elements + j];
          merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_661_4: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_662_5: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            int val = c_buf[index2 * bound0 + j0][j1];
            merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_671_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buf_index =
            (i * num_elements + j + num_elements - head_align) + index_offset;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[buf_index / 100][index_offset % 100]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements;
    pos += (num_elements - head_align) % num_elements + index_offset;
    VITIS_LOOP_683_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[(pos + j) / 100][(pos + j) % 100]);

    }
  }
}

static void memcpy_wide_bus_read_long_2d_100_128(
    long a_buf[][100], size_t index2_offset, size_t index1_offset,
    merlin_uint_128 *a,

    size_t offset_byte, size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((num_elements % 100) == 0 &&
             (index2_offset * 100 % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  const size_t index_offset = index2_offset * 100 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_731_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      a_buf[buf_index / 100][buf_index % 100] =
          merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_753_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          a_buf[index2][index1 * num_elements + j] =
              merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_763_3: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_764_4: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index2 * bound0 + j0][j1] =
                merlin_get_range_128(&a[i + start], (j * data_width), data_width);
          }
        }
        index2++;
      }

    } else {
      VITIS_LOOP_776_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buf_index = (i * num_elements + j - head_align) + index_offset;
        a_buf[buf_index / 100][buf_index % 100] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_long_2d_100_128(
    merlin_uint_128 *c, long c_buf[][100], size_t index2_offset,
    size_t index1_offset, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  size_t index_offset = index2_offset * 100 + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_812_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_825_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_864_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 long val = c_buf[index2][index1 * num_elements + j];
          merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_872_4: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_873_5: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            long val = c_buf[index2 * bound0 + j0][j1];
            merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_882_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buf_index =
            (i * num_elements + j + num_elements - head_align) + index_offset;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_894_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[(pos + j) / 100][(pos + j) % 100]);

    }
  }
}

static void memcpy_wide_bus_read_int_2d_100_128(
    int a_buf[][100], size_t index2_offset, size_t index1_offset,
    merlin_uint_128 *a,

    size_t offset_byte, size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((num_elements % 100) == 0 &&
             (index2_offset * 100 % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  const size_t index_offset = index2_offset * 100 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_942_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      a_buf[buf_index / 100][buf_index % 100] =
          merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_964_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          a_buf[index2][index1 * num_elements + j] =
              merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_974_3: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_975_4: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index2 * bound0 + j0][j1] =
                merlin_get_range_128(&a[i + start], (j * data_width), data_width);
          }
        }
        index2++;
      }

    } else {
      VITIS_LOOP_987_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buf_index = (i * num_elements + j - head_align) + index_offset;
        a_buf[buf_index / 100][buf_index % 100] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_long_long_2d_100_128(
    merlin_uint_128 *c, long long c_buf[][100], size_t index2_offset,
    size_t index1_offset, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  size_t index_offset = index2_offset * 100 + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1023_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1036_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1075_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 long long val = c_buf[index2][index1 * num_elements + j];
          merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_1083_4: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1084_5: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            long long val = c_buf[index2 * bound0 + j0][j1];
            merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_1093_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buf_index =
            (i * num_elements + j + num_elements - head_align) + index_offset;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1105_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[(pos + j) / 100][(pos + j) % 100]);

    }
  }
}

static void memcpy_wide_bus_read_long_long_2d_100_128(
    long long a_buf[][100], size_t index2_offset, size_t index1_offset,
    merlin_uint_128 *a,

    size_t offset_byte, size_t size_byte, const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(long long);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if ((num_elements % 100) == 0 &&
             (index2_offset * 100 % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  const size_t index_offset = index2_offset * 100 + index1_offset;
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1153_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      a_buf[buf_index / 100][buf_index % 100] =
          merlin_get_range_128(&a[start], (j * data_width), data_width);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1175_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          a_buf[index2][index1 * num_elements + j] =
              merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_1185_3: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1186_4: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            a_buf[index2 * bound0 + j0][j1] =
                merlin_get_range_128(&a[i + start], (j * data_width), data_width);
          }
        }
        index2++;
      }

    } else {
      VITIS_LOOP_1198_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t buf_index = (i * num_elements + j - head_align) + index_offset;
        a_buf[buf_index / 100][buf_index % 100] =
            merlin_get_range_128(&a[i + start], (j * data_width), data_width);
      }
    }
  }
}

static void memcpy_wide_bus_write_int_2d_100_128(
    merlin_uint_128 *c, int c_buf[][100], size_t index2_offset,
    size_t index1_offset, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(int);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t i, j;
  size_t index_offset = index2_offset * 100 + index1_offset;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  size_t align = 0;
  if (len == 1) {
    VITIS_LOOP_1234_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    return;
  }
  if (head_align != 0) {
    VITIS_LOOP_1247_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      merlin_set_range_128(&c[start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1286_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 int val = c_buf[index2][index1 * num_elements + j];
          merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_1294_4: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1295_5: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            int val = c_buf[index2 * bound0 + j0][j1];
            merlin_set_range_128(&c[i + start], (j * data_width), data_width, val);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_1304_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t buf_index =
            (i * num_elements + j + num_elements - head_align) + index_offset;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, c_buf[buf_index / 100][buf_index % 100]);

      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1316_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, c_buf[(pos + j) / 100][(pos + j) % 100]);

    }
  }
}

static void memcpy_wide_bus_read_float_2d_100_128(
    float a_buf[][100], size_t index2_offset, size_t index1_offset,
    merlin_uint_128 *a, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index2 = index2_offset, index1 = index1_offset;
  const size_t index_offset = 100 * index2_offset + index1_offset;
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;

  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1364_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      size_t buf_index = j - head_align + index_offset;
      int raw_bits = merlin_get_range_128(&a[start], (j * data_width), data_width);
      a_buf[buf_index / 100][buf_index % 100] = *(float *)(&raw_bits);
    }
    return;
  }

L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1386_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
          a_buf[index2][index1 * num_elements + j] = *(float *)(&raw_bits);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_1396_3: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1397_4: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
            a_buf[index2 * bound0 + j0][j1] = *(float *)(&raw_bits);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_1408_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        int raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        size_t buf_index = (i * num_elements + j - head_align) + index_offset;
        a_buf[buf_index / 100][buf_index % 100] = *(float *)(&raw_bits);
      }
    }
  }
}

static void memcpy_wide_bus_write_float_2d_100_128(
    merlin_uint_128 *c, float c_buf[][100], size_t index2_offset,
    size_t index1_offset, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(float);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  const size_t index_offset = index2_offset * 100 + index1_offset;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  if (len == 1) {
    VITIS_LOOP_1443_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      float buf_tmp = c_buf[buf_index / 100][buf_index % 100];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_128(&c[start], (j * data_width), data_width, raw_bits);
    }
    return;
  }
  unsigned align = 0;
  if (head_align != 0) {
    VITIS_LOOP_1458_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      float buf_tmp = c_buf[buf_index / 100][buf_index % 100];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_128(&c[start], (j * data_width), data_width, raw_bits);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1498_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 float buf_tmp = c_buf[index2][index1 * num_elements + j];
          int raw_bits = *(int *)&buf_tmp;
          merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_1507_4: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1508_5: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            float buf_tmp = c_buf[index2 * bound0 + j0][j1];
            int raw_bits = *(int *)&buf_tmp;
            merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_1518_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t index =
            i * num_elements + j + num_elements - head_align + index_offset;
        float buf_tmp = c_buf[index / 100][index % 100];
        int raw_bits = *(int *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1531_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      float buf_tmp = c_buf[(pos + j) / 100][(pos + j) % 100];
      int raw_bits = *(int *)&buf_tmp;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, raw_bits);
    }
  }
}

static void memcpy_wide_bus_read_double_2d_100_128(
    double a_buf[][100], size_t index2_offset, size_t index1_offset,
    merlin_uint_128 *a, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;

  size_t i, j;
  size_t index2 = index2_offset, index1 = index1_offset;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  const size_t index_offset = 100 * index2_offset + index1_offset;

  int len = end - start;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  const size_t max_trip = const_buf_size / num_elements + 2;
  ({ int _AssertPred = len <= const_buf_size / num_elements + 2; __builtin_assume(_AssertPred); });
  ({ int _AssertPred = len >= buf_size / num_elements; __builtin_assume(_AssertPred); });
  if (1 == len) {
    VITIS_LOOP_1580_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align || j > tail_align)
        continue;
      int64_t raw_bits = merlin_get_range_128(&a[start], (j * data_width), data_width);
      size_t buf_index = (j - head_align) + index_offset;
      a_buf[buf_index / 100][buf_index % 100] = *(double *)(&raw_bits);
    }
    return;
  }
L2:
  for (i = 0; i < len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1601_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == end - start - 1 && j > tail_align)
            continue;
          int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
          a_buf[index2][index1 * num_elements + j] = *(double *)(&raw_bits);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_1611_3: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1612_4: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            if (i == end - start - 1 && j > tail_align)
              continue;
            int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
            a_buf[index2 * bound0 + j0][j1] = *(double *)(&raw_bits);
          }
        }
        index2++;
      }
    } else {
      VITIS_LOOP_1623_5: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (i == 0 && j < head_align)
          continue;
        if (i == end - start - 1 && j > tail_align)
          continue;
        size_t index = i * num_elements + j - head_align + index_offset;
        int64_t raw_bits = merlin_get_range_128(&a[i + start], (j * data_width), data_width);
        a_buf[index / 100][index % 100] = *(double *)(&raw_bits);
      }
    }
  }
}

static void memcpy_wide_bus_write_double_2d_100_128(
    merlin_uint_128 *c, double c_buf[][100], size_t index2_offset,
    size_t index1_offset, size_t offset_byte, size_t size_byte,
    const size_t const_buf_size) {
#pragma HLS inline
 const size_t data_width = sizeof(double);
  const size_t bus_width = 128 / 8;
  const size_t num_elements = bus_width / data_width;
  size_t buf_size = size_byte / data_width;
  size_t offset = offset_byte / data_width;
  size_t head_align = offset & (num_elements - 1);
  size_t new_offset = offset + buf_size;
  size_t tail_align = (new_offset - 1) & (num_elements - 1);
  size_t start = offset / num_elements;
  size_t end = (offset + buf_size + num_elements - 1) / num_elements;
  size_t len = end - start;
  size_t index_offset = index2_offset * 100 + index1_offset;
  size_t i, j;
  if (head_align == 0)
    len = (buf_size + num_elements - 1) / num_elements;
  if (len == 1) {
    VITIS_LOOP_1658_1: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      if (j > tail_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      double buf_tmp = c_buf[buf_index / 100][buf_index % 100];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_128(&c[start], (j * data_width), data_width, raw_bits);
    }
    return;
  }
  size_t align = 0;
  if (head_align != 0) {
    VITIS_LOOP_1673_2: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j < head_align)
        continue;
      size_t buf_index = (j - head_align) + index_offset;
      double buf_tmp = c_buf[buf_index / 100][buf_index % 100];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_128(&c[start], (j * data_width), data_width, raw_bits);
    }
    start++;
    align++;
  }
  if (tail_align != (num_elements - 1))
    align++;
  size_t index2 = index2_offset, index1 = index1_offset;
  const size_t alignment =
      (100 % num_elements) == 0 && (index1_offset % num_elements) == 0;
  int aligned = 0;
  if ((100 % num_elements) == 0 && (index1_offset % num_elements) == 0) {
    aligned = 1;
    index1 = index1_offset / num_elements;
  } else if (((num_elements % 100) == 0) &&
             ((index2_offset * 100) % num_elements) == 0 && !index1_offset) {
    aligned = -1;
    index2 = index2_offset * 100 / num_elements;
  }
  const size_t bound = 100 / num_elements;
  const size_t bound0 = num_elements / 100;
  int burst_len = len - align;
  const size_t max_trip = const_buf_size / num_elements;
  ({ int _AssertPred = burst_len <= const_buf_size / num_elements; __builtin_assume(_AssertPred); });
L3:
  for (i = 0; i < burst_len; ++i) {
#pragma HLS loop_tripcount max = max_trip



#pragma HLS pipeline


 if (head_align == 0 && aligned) {
      if (aligned == 1) {
        VITIS_LOOP_1715_3: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 double buf_tmp = c_buf[index2][index1 * num_elements + j];
          int64_t raw_bits = *(int64_t *)&buf_tmp;
          merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
        }
        if (index1 == bound - 1) { index1 = 0; ++index2; } else index1++;
      } else if (aligned == -1) {
        int j0, j1;
        VITIS_LOOP_1724_4: for (j0 = 0; j0 < bound0; ++j0) {
          VITIS_LOOP_1725_5: for (j1 = 0; j1 < 100; ++j1) {
            j = j0 * 100 + j1;
            double buf_tmp = c_buf[index2 * bound0 + j0][j1];
            int64_t raw_bits = *(int64_t *)&buf_tmp;
            merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
          }
        }
        index2++;
      }

    } else {
      VITIS_LOOP_1736_6: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 size_t index =
            i * num_elements + j + num_elements - head_align + index_offset;
        double buf_tmp = c_buf[index / 100][index % 100];
        int64_t raw_bits = *(int64_t *)&buf_tmp;
        merlin_set_range_128(&c[i + start], (j * data_width), data_width, raw_bits);
      }
    }
  }
  if (tail_align != num_elements - 1) {
    size_t pos = (len - align) * num_elements + index_offset;
    pos += (num_elements - head_align) % num_elements;
    VITIS_LOOP_1749_7: for (j = 0; j < num_elements; ++j) {
#pragma HLS unroll
 if (j > tail_align)
        continue;
      double buf_tmp = c_buf[(pos + j) / 100][(pos + j) % 100];
      int64_t raw_bits = *(int64_t *)&buf_tmp;
      merlin_set_range_128(&c[end - 1], (j * data_width), data_width, raw_bits);
    }
  }
}
# 34 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128_2d.h" 2
# 13 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c" 2

# 1 "/usr/include/string.h" 1 3 4
# 26 "/usr/include/string.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/libc-header-start.h" 1 3 4
# 27 "/usr/include/string.h" 2 3 4






# 1 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4
# 43 "/usr/include/string.h" 3 4
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));





extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
    __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2))) ;




extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 80 "/usr/include/string.h" 3 4
extern int __memcmpeq (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 107 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 141 "/usr/include/string.h" 3 4
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
    __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2))) ;




# 1 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types/__locale_t.h" 3 4
struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
};

typedef struct __locale_struct *__locale_t;
# 23 "/usr/include/x86_64-linux-gnu/bits/types/locale_t.h" 2 3 4

typedef __locale_t locale_t;
# 173 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));


extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 4)))
                                           ;





extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 246 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 273 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 293 "/usr/include/string.h" 3 4
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 323 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 350 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)));



extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2, 3)));
# 407 "/usr/include/string.h" 3 4
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern char *strerror (int __errnum) __attribute__ ((__nothrow__ ));
# 432 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (2)))


                                          ;
# 458 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ ));




# 1 "/usr/include/strings.h" 1 3 4
# 23 "/usr/include/strings.h" 3 4
# 1 "/mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/stddef.h" 1 3 4
# 24 "/usr/include/strings.h" 2 3 4
# 34 "/usr/include/strings.h" 3 4
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)));
# 68 "/usr/include/strings.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 96 "/usr/include/strings.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));






extern int ffs (int __i) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));





extern int ffsl (long int __l) __attribute__ ((__nothrow__ )) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ )) __attribute__ ((__const__));



extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));






extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));



extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ )) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));
# 463 "/usr/include/string.h" 2 3 4



extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1)))
                                                  ;



extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ ));
# 489 "/usr/include/string.h" 3 4
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ )) __attribute__ ((__nonnull__ (1, 2)));
# 15 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c" 2

# 1 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/merlin_type_define.h" 1
# 17 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c" 2
# 26 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c"
__attribute__((sdx_kernel("kernel_gemm", 0))) void kernel_gemm(merlin_uint_512 C[400],merlin_uint_128 A[2500],merlin_uint_512 B[400])
{
#line 26 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm.tcl"
#pragma HLSDIRECTIVE TOP name=kernel_gemm
# 27 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c"


#pragma HLS INTERFACE m_axi port=A offset=slave depth=2500 bundle=merlin_gmem_kernel_gemm_128_0

#pragma HLS INTERFACE m_axi port=B offset=slave depth=400 bundle=merlin_gmem_kernel_gemm_512_0

#pragma HLS INTERFACE m_axi port=C offset=slave depth=400 bundle=merlin_gmem_kernel_gemm_512_C

#pragma HLS INTERFACE s_axilite port=A bundle=control

#pragma HLS INTERFACE s_axilite port=B bundle=control

#pragma HLS INTERFACE s_axilite port=C bundle=control

#pragma HLS INTERFACE s_axilite port=return bundle=control

#pragma HLS DATA_PACK VARIABLE=B

#pragma HLS DATA_PACK VARIABLE=A

#pragma HLS DATA_PACK VARIABLE=C

#pragma ACCEL interface variable=B depth=100,64 max_depth=100,64

#pragma ACCEL interface variable=A depth=100,100 max_depth=100,100

#pragma ACCEL interface variable=C depth=100,64 max_depth=100,64
 float B_5_0_buf[100][8][8];

#pragma HLS array_partition variable=B_5_0_buf complete dim=3

#pragma HLS array_partition variable=B_5_0_buf cyclic factor=2 dim=2

#pragma HLS array_partition variable=B_5_0_buf complete dim=1
 float A_5_0_buf[100][100];

#pragma HLS array_partition variable=A_5_0_buf complete dim=2
 float C_buf[100][8][8];

#pragma HLS array_partition variable=C_buf complete dim=3

#pragma HLS array_partition variable=C_buf cyclic factor=2 dim=2
 int i;
  int j;
  int k;


  memcpy_wide_bus_read_float_3d_8_8_512(C_buf,0,0,0,(merlin_uint_512 *)C,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
{
    memcpy_wide_bus_read_float_2d_100_128(A_5_0_buf,0,0,(merlin_uint_128 *)A,(0 * 4),sizeof(float ) * ((unsigned long )10000L),10000L);
  }
{
    memcpy_wide_bus_read_float_3d_8_8_512(B_5_0_buf,0,0,0,(merlin_uint_512 *)B,(0 * 4),sizeof(float ) * ((unsigned long )6400L),6400L);
  }
  merlinL3:
  for (i = 0; i < 100; i++)







{
    merlinL2:
    for (j = 0; j < 8; j++)







{

#pragma HLS dependence variable=C_buf array inter false

#pragma HLS pipeline
 merlinL1:
      for (int j_sub = 0; j_sub < 8; ++j_sub)
# 115 "/home/spouget/iccad_24/autodse_tree_reduction/bert_100_64/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c"
{

#pragma HLS unroll
 C_buf[i][j][j_sub] = ((float )0);
        merlinL0:
        for (k = 0; k < 100; k++)



{

#pragma HLS unroll
 C_buf[i][j][j_sub] += A_5_0_buf[i][k] * B_5_0_buf[k][j][j_sub];
        }
      }
    }
  }


  memcpy_wide_bus_write_float_3d_8_8_512((merlin_uint_512 *)C,C_buf,0,0,0,(4 * 0),sizeof(float ) * ((unsigned long )6400L),6400L);
}
