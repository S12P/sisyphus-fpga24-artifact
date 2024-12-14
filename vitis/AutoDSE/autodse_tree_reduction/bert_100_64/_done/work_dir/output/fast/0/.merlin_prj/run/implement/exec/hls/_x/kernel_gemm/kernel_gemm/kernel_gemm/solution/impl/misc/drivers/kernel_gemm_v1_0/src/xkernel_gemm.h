// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XKERNEL_GEMM_H
#define XKERNEL_GEMM_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xkernel_gemm_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Control_BaseAddress;
} XKernel_gemm_Config;
#endif

typedef struct {
    u64 Control_BaseAddress;
    u32 IsReady;
} XKernel_gemm;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XKernel_gemm_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XKernel_gemm_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XKernel_gemm_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XKernel_gemm_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XKernel_gemm_Initialize(XKernel_gemm *InstancePtr, UINTPTR BaseAddress);
XKernel_gemm_Config* XKernel_gemm_LookupConfig(UINTPTR BaseAddress);
#else
int XKernel_gemm_Initialize(XKernel_gemm *InstancePtr, u16 DeviceId);
XKernel_gemm_Config* XKernel_gemm_LookupConfig(u16 DeviceId);
#endif
int XKernel_gemm_CfgInitialize(XKernel_gemm *InstancePtr, XKernel_gemm_Config *ConfigPtr);
#else
int XKernel_gemm_Initialize(XKernel_gemm *InstancePtr, const char* InstanceName);
int XKernel_gemm_Release(XKernel_gemm *InstancePtr);
#endif

void XKernel_gemm_Start(XKernel_gemm *InstancePtr);
u32 XKernel_gemm_IsDone(XKernel_gemm *InstancePtr);
u32 XKernel_gemm_IsIdle(XKernel_gemm *InstancePtr);
u32 XKernel_gemm_IsReady(XKernel_gemm *InstancePtr);
void XKernel_gemm_Continue(XKernel_gemm *InstancePtr);
void XKernel_gemm_EnableAutoRestart(XKernel_gemm *InstancePtr);
void XKernel_gemm_DisableAutoRestart(XKernel_gemm *InstancePtr);

void XKernel_gemm_Set_C(XKernel_gemm *InstancePtr, u64 Data);
u64 XKernel_gemm_Get_C(XKernel_gemm *InstancePtr);
void XKernel_gemm_Set_A(XKernel_gemm *InstancePtr, u64 Data);
u64 XKernel_gemm_Get_A(XKernel_gemm *InstancePtr);
void XKernel_gemm_Set_B(XKernel_gemm *InstancePtr, u64 Data);
u64 XKernel_gemm_Get_B(XKernel_gemm *InstancePtr);

void XKernel_gemm_InterruptGlobalEnable(XKernel_gemm *InstancePtr);
void XKernel_gemm_InterruptGlobalDisable(XKernel_gemm *InstancePtr);
void XKernel_gemm_InterruptEnable(XKernel_gemm *InstancePtr, u32 Mask);
void XKernel_gemm_InterruptDisable(XKernel_gemm *InstancePtr, u32 Mask);
void XKernel_gemm_InterruptClear(XKernel_gemm *InstancePtr, u32 Mask);
u32 XKernel_gemm_InterruptGetEnabled(XKernel_gemm *InstancePtr);
u32 XKernel_gemm_InterruptGetStatus(XKernel_gemm *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
