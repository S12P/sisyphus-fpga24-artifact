// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
// Tool Version Limit: 2023.10
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xkernel_gemm.h"

extern XKernel_gemm_Config XKernel_gemm_ConfigTable[];

#ifdef SDT
XKernel_gemm_Config *XKernel_gemm_LookupConfig(UINTPTR BaseAddress) {
	XKernel_gemm_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XKernel_gemm_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XKernel_gemm_ConfigTable[Index].Control_BaseAddress == BaseAddress) {
			ConfigPtr = &XKernel_gemm_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XKernel_gemm_Initialize(XKernel_gemm *InstancePtr, UINTPTR BaseAddress) {
	XKernel_gemm_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XKernel_gemm_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XKernel_gemm_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XKernel_gemm_Config *XKernel_gemm_LookupConfig(u16 DeviceId) {
	XKernel_gemm_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XKERNEL_GEMM_NUM_INSTANCES; Index++) {
		if (XKernel_gemm_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XKernel_gemm_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XKernel_gemm_Initialize(XKernel_gemm *InstancePtr, u16 DeviceId) {
	XKernel_gemm_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XKernel_gemm_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XKernel_gemm_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

