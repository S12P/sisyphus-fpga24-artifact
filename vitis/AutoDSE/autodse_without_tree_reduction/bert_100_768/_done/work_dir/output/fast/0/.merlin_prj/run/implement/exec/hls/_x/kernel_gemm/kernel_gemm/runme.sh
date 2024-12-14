#!/bin/sh

# 
# v++(TM)
# runme.sh: a v++-generated Runs Script for UNIX
# Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
# Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
# 

if [ -z "$PATH" ]; then
  PATH=/mnt/software/xilinx/Vitis_HLS/2023.2/bin:/mnt/software/xilinx/Vitis/2023.2/bin:/mnt/software/xilinx/Vitis/2023.2/bin
else
  PATH=/mnt/software/xilinx/Vitis_HLS/2023.2/bin:/mnt/software/xilinx/Vitis/2023.2/bin:/mnt/software/xilinx/Vitis/2023.2/bin:$PATH
fi
export PATH

if [ -z "$LD_LIBRARY_PATH" ]; then
  LD_LIBRARY_PATH=
else
  LD_LIBRARY_PATH=:$LD_LIBRARY_PATH
fi
export LD_LIBRARY_PATH

HD_PWD='/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm'
cd "$HD_PWD"

HD_LOG=runme.log
/bin/touch $HD_LOG

ISEStep="./ISEWrap.sh"
EAStep()
{
     $ISEStep $HD_LOG "$@" >> $HD_LOG 2>&1
     if [ $? -ne 0 ]
     then
         exit
     fi
}

EAStep vitis_hls -f kernel_gemm.tcl -messageDb vitis_hls.pb
