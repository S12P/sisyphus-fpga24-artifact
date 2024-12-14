# ==============================================================
# Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2023.2 (64-bit)
# Tool Version Limit: 2023.10
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
# 
# ==============================================================
cmake_minimum_required(VERSION 3.15)
project(kernel_gemm)
find_package(common)
collector_create (PROJECT_LIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}")
collect (PROJECT_LIB_SOURCES xkernel_gemm.c)
collect (PROJECT_LIB_SOURCES xkernel_gemm_sinit.c)
collect (PROJECT_LIB_SOURCES xkernel_gemm_linux.c)
collect (PROJECT_LIB_SOURCES xkernel_gemm_g.c)
collector_list (_sources PROJECT_LIB_SOURCES)
collector_create (PROJECT_LIB_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}")
collect (PROJECT_LIB_HEADERS xkernel_gemm.h)
collect (PROJECT_LIB_HEADERS xkernel_gemm_hw.h)
collector_list (_headers PROJECT_LIB_HEADERS)
file(COPY ${_headers} DESTINATION ${CMAKE_BINARY_DIR}/include)
include_directories(${CMAKE_BINARY_DIR}/include)
add_library(kernel_gemm STATIC ${_sources})
set_target_properties(kernel_gemm PROPERTIES LINKER_LANGUAGE C)

