
j
PRunning '/mnt/software/xilinx/Vitis_HLS/2023.2/bin/unwrapped/lnx64.o/vitis_hls'
*HLSZ200-10h px 

lFor user 'spouget' on host 'amx1' (Linux_x86_64 version 5.15.0-101-generic) on Fri Apr 19 15:57:32 PDT 2024
*HLSZ200-10h px 
3
On os Ubuntu 22.04.3 LTS
*HLSZ200-10h px 
È
­In directory '/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm'
*HLSZ200-10h px 
¬
Environment variable 'C_INCLUDE_PATH' is set to /mnt/software/xilinx/Vitis_HLS/2021.1/lnx64/tools/gcc/lib/gcc/x86_64-unknown-linux-gnu/4.6.3/include/:/mnt/software/xilinx/Vitis_HLS/2021.1/include:/opt/merlin/sources/merlin-compiler/trunk/source-opt/include/apint_include/.
*HLSZ200-40h px 

@The vitis_hls executable is being deprecated. Consider using %s
2002053*hls2
vitis-run --mode hls --tclZ200-2053h px 
A
&Sourcing Tcl script 'kernel_gemm.tcl'
*HLSZ200-150h px 
N
Running: %s
2001510*hls2
open_project kernel_gemm Z200-1510h px 
å
ÊCreating and opening project '/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm'.
*HLSZ200-10h px 
I
Running: %s
2001510*hls2
set_top kernel_gemm Z200-1510h px 
ú
Running: %s
2001510*hls2Æ
Ãadd_files /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c -cflags  -D XILINX -I /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls Z200-1510h px 
ß
ÄAdding design file '/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c' to the project
*HLSZ200-10h px 
_
Running: %s
2001510*hls2,
*open_solution -flow_target vitis solution Z200-1510h px 
ï
ÔCreating and opening solution '/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution'.
*HLSZ200-10h px 
ã
Using %sflow_target '%s'
2001505*hls2
 2
vitisZ200-1505h pxFor help on HLS 200-1505 see docs.xilinx.com/access/sources/dita/topic?Doc_Version=2023.2%20English&url=ug1448-hls-guidance&resourceid=200-1505.html 

Setting %s configuration: %s
200435*hls2$
"'open_solution -flow_target vitis'2$
"config_interface -m_axi_latency=64Z200-435h px 

Setting %s configuration: %s
200435*hls2$
"'open_solution -flow_target vitis'20
.config_interface -m_axi_alignment_byte_size=64Z200-435h px 

Setting %s configuration: %s
200435*hls2$
"'open_solution -flow_target vitis'20
.config_interface -m_axi_max_widen_bitwidth=512Z200-435h px 

Setting %s configuration: %s
200435*hls2$
"'open_solution -flow_target vitis'2"
 config_rtl -register_reset_num=3Z200-435h px 
R
Running: %s
2001510*hls2
set_part xcu200-fsgd2104-2-e Z200-1510h px 
Y
Setting target device to '%s'2001611*hls2
xcu200-fsgd2104-2-eZ200-1611h px 
_
Running: %s
2001510*hls2,
*create_clock -period 250MHz -name default Z200-1510h px 
L
1Setting up clock 'default' with a period of 4ns.
*SYNZ201-201h px 
Z
Running: %s
2001510*hls2'
%config_dataflow -strict_mode warning Z200-1510h px 
X
Running: %s
2001510*hls2%
#config_rtl -deadlock_detection sim Z200-1510h px 
a
Running: %s
2001510*hls2.
,config_interface -m_axi_conservative_mode=1 Z200-1510h px 
T
Running: %s
2001510*hls2!
config_interface -m_axi_addr64 Z200-1510h px 
^
Running: %s
2001510*hls2+
)config_interface -m_axi_auto_max_ports=0 Z200-1510h px 
b
Running: %s
2001510*hls2/
-config_export -format xo -ipname kernel_gemm Z200-1510h px 
C
Running: %s
2001510*hls2
csynth_design Z200-1510h px 
Ê
®Finished File checks and directory preparation: CPU user time: 0.06 seconds. CPU system time: 0.02 seconds. Elapsed time: 0.09 seconds; current allocated memory: 260.871 MB.
*HLSZ200-111h px 
Ø
½Analyzing design file '/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c' ... 
*HLSZ200-10h px 

æthe 'self/all' option to 'Inline' pragma is not supported and will be ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128.h:33:24)
*HLSZ207-5516h px 

æthe 'self/all' option to 'Inline' pragma is not supported and will be ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128.h:74:24)
*HLSZ207-5516h px 

æthe 'self/all' option to 'Inline' pragma is not supported and will be ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h:33:24)
*HLSZ207-5516h px 

æthe 'self/all' option to 'Inline' pragma is not supported and will be ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h:74:24)
*HLSZ207-5516h px 
ô
×the pragma is not supported and will be ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:43:9)
*HLSZ207-5514h px 
ô
×the pragma is not supported and will be ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:45:9)
*HLSZ207-5514h px 
ô
×the pragma is not supported and will be ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:47:9)
*HLSZ207-5514h px 
Û
¾unknown pragma ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:49:9)
*HLSZ207-1017h px 
Û
¾unknown pragma ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:51:9)
*HLSZ207-1017h px 
Û
¾unknown pragma ignored (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:53:9)
*HLSZ207-1017h px 
Ì
°Finished Source Code Analysis and Preprocessing: CPU user time: 9.57 seconds. CPU system time: 0.31 seconds. Elapsed time: 11.11 seconds; current allocated memory: 290.742 MB.
*HLSZ200-111h px 
[
/Using interface defaults for '%s' flow target.
200777*hls2
VitisZ200-777h px 

~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
3,1002
Compile/Link2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
 
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
6,3302
Unroll/Inline (step 1)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
 
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
4,6752
Unroll/Inline (step 2)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
 
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
4,6662
Unroll/Inline (step 3)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
 
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
4,6662
Unroll/Inline (step 4)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 

~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
	1,347,0902
Array/Struct2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
 
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
19,6802
Array/Struct (step 2)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
 
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
20,3042
Array/Struct (step 3)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
 
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
20,1652
Array/Struct (step 4)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
 
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
20,1782
Array/Struct (step 5)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 

~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
19,6972
Performance (step 1)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 

~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
19,6972
Performance (step 2)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 

~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
22,8972
Performance (step 3)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 

~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
22,8972
Performance (step 4)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 

~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
22,9052
HW Transforms2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 
¡
~There were %s instructions in the design after the '%s' phase of compilation. See the Design Size Report for more details: %s
2001995*hls2
22,9252
HW Transforms (step 2)2×
Ô/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/syn/report/csynth_design_size.rptZ200-1995h px 

÷Inlining function 'merlin_get_range_512' into 'memcpy_wide_bus_read_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1698:22)
*HLSZ214-131h px 

÷Inlining function 'merlin_get_range_512' into 'memcpy_wide_bus_read_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1761:24)
*HLSZ214-131h px 

÷Inlining function 'merlin_get_range_512' into 'memcpy_wide_bus_read_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1732:28)
*HLSZ214-131h px 

÷Inlining function 'merlin_get_range_512' into 'memcpy_wide_bus_read_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1719:26)
*HLSZ214-131h px 

öInlining function 'merlin_get_range_128' into 'memcpy_wide_bus_read_float_2d_100_128' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h:1369:22)
*HLSZ214-131h px 

öInlining function 'merlin_get_range_128' into 'memcpy_wide_bus_read_float_2d_100_128' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h:1414:24)
*HLSZ214-131h px 

öInlining function 'merlin_get_range_128' into 'memcpy_wide_bus_read_float_2d_100_128' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h:1390:26)
*HLSZ214-131h px 

÷Inlining function 'merlin_set_range_512' into 'memcpy_wide_bus_write_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1802:7)
*HLSZ214-131h px 

÷Inlining function 'merlin_set_range_512' into 'memcpy_wide_bus_write_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1914:7)
*HLSZ214-131h px 

÷Inlining function 'merlin_set_range_512' into 'memcpy_wide_bus_write_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1899:9)
*HLSZ214-131h px 

øInlining function 'merlin_set_range_512' into 'memcpy_wide_bus_write_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1872:13)
*HLSZ214-131h px 

øInlining function 'merlin_set_range_512' into 'memcpy_wide_bus_write_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1860:11)
*HLSZ214-131h px 

÷Inlining function 'merlin_set_range_512' into 'memcpy_wide_bus_write_float_3d_96_8_512' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1816:7)
*HLSZ214-131h px 

õInlining function 'memcpy_wide_bus_read_float_3d_96_8_512' into 'kernel_gemm' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:74:3)
*HLSZ214-131h px 

÷Inlining function 'memcpy_wide_bus_write_float_3d_96_8_512' into 'kernel_gemm' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:133:3)
*HLSZ214-131h px 

õInlining function 'memcpy_wide_bus_read_float_3d_96_8_512' into 'kernel_gemm' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:79:5)
*HLSZ214-131h px 

ôInlining function 'memcpy_wide_bus_read_float_2d_100_128' into 'kernel_gemm' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:76:5)
*HLSZ214-131h px 

õLoop 'VITIS_LOOP_1865_4' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1865:28)
*HLSZ214-291h px 

õLoop 'VITIS_LOOP_1867_5' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1867:21)
*HLSZ214-291h px 

ëLoop 'VITIS_LOOP_93_3' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h:93:22)
*HLSZ214-291h px 

ôLoop 'merlinL1' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:106:7)
*HLSZ214-291h px 

ôLoop 'merlinL0' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:119:9)
*HLSZ214-291h px 

õLoop 'VITIS_LOOP_1726_3' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1726:28)
*HLSZ214-291h px 

õLoop 'VITIS_LOOP_1728_4' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1728:21)
*HLSZ214-291h px 

ëLoop 'VITIS_LOOP_53_3' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h:53:22)
*HLSZ214-291h px 

õLoop 'VITIS_LOOP_1386_2' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h:1386:28)
*HLSZ214-291h px 

ëLoop 'VITIS_LOOP_53_3' is marked as complete unroll implied by the pipeline pragma (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128.h:53:22)
*HLSZ214-291h px 
¾
¢Unrolling loop 'VITIS_LOOP_1865_4' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1865:28) in function 'kernel_gemm' completely with a factor of 2 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
¾
¢Unrolling loop 'VITIS_LOOP_1867_5' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1867:21) in function 'kernel_gemm' completely with a factor of 8 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
´
Unrolling loop 'VITIS_LOOP_93_3' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h:93:22) in function 'kernel_gemm' completely with a factor of 4 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
½
¡Unrolling loop 'merlinL1' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:106:7) in function 'kernel_gemm' completely with a factor of 8 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
¿
£Unrolling loop 'merlinL0' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:119:9) in function 'kernel_gemm' completely with a factor of 100 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
¾
¢Unrolling loop 'VITIS_LOOP_1726_3' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1726:28) in function 'kernel_gemm' completely with a factor of 2 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
¾
¢Unrolling loop 'VITIS_LOOP_1728_4' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1728:21) in function 'kernel_gemm' completely with a factor of 8 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
´
Unrolling loop 'VITIS_LOOP_53_3' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_512.h:53:22) in function 'kernel_gemm' completely with a factor of 4 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
¾
¢Unrolling loop 'VITIS_LOOP_1386_2' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h:1386:28) in function 'kernel_gemm' completely with a factor of 4 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
´
Unrolling loop 'VITIS_LOOP_53_3' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/memcpy_128.h:53:22) in function 'kernel_gemm' completely with a factor of 4 (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:27:0)
*HLSZ214-186h px 
ê
ÎApplying array_partition to 'B_5_0_buf': Complete partitioning on dimension 1. Cyclic partitioning with factor 2 on dimension 2. Complete partitioning on dimension 3. (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:54:8)
*HLSZ214-248h px 

öApplying array_partition to 'A_5_0_buf': Complete partitioning on dimension 2. (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:61:8)
*HLSZ214-248h px 
À
¤Applying array_partition to 'C_buf': Cyclic partitioning with factor 2 on dimension 2. Complete partitioning on dimension 3. (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64:8)
*HLSZ214-248h px 
\
AAggregating maxi variable 'B' with compact=none mode in 512-bits
*HLSZ214-241h px 
\
AAggregating maxi variable 'A' with compact=none mode in 128-bits
*HLSZ214-241h px 
\
AAggregating maxi variable 'C' with compact=none mode in 512-bits
*HLSZ214-241h px 
ü
àMultiple burst reads of length 4800 and bit width 512 in loop 'L2'(/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1705:3) has been inferred on bundle 'merlin_gmem_kernel_gemm_512_C'. These burst requests might be further partitioned into multiple requests during RTL generation, based on max_read_burst_length or max_write_burst_length settings. (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1705:3)
*HLSZ214-115h px 
Ð
´Multiple burst reads of length 625 and bit width 512 has been inferred on bundle 'merlin_gmem_kernel_gemm_128_0'. These burst requests might be further partitioned into multiple requests during RTL generation, based on max_read_burst_length or max_write_burst_length settings. (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_2d.h:1376:3)
*HLSZ214-115h px 
ü
àMultiple burst reads of length 4800 and bit width 512 in loop 'L2'(/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1705:3) has been inferred on bundle 'merlin_gmem_kernel_gemm_512_0'. These burst requests might be further partitioned into multiple requests during RTL generation, based on max_read_burst_length or max_write_burst_length settings. (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1705:3)
*HLSZ214-115h px 
ý
áMultiple burst writes of length 4800 and bit width 512 in loop 'L3'(/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1845:3) has been inferred on bundle 'merlin_gmem_kernel_gemm_512_C'. These burst requests might be further partitioned into multiple requests during RTL generation, based on max_read_burst_length or max_write_burst_length settings. (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/mars_wide_bus_3d.h:1845:3)
*HLSZ214-115h px 
Ë
¯Finished Compiling Optimization and Transform: CPU user time: 47.61 seconds. CPU system time: 0.68 seconds. Elapsed time: 56.45 seconds; current allocated memory: 306.910 MB.
*HLSZ200-111h px 
¬
Finished Checking Pragmas: CPU user time: 0 seconds. CPU system time: 0 seconds. Elapsed time: 0 seconds; current allocated memory: 306.910 MB.
*HLSZ200-111h px 
<
"Starting code transformations ...
*HLSZ200-10h px 
¸
Finished Standard Transforms: CPU user time: 2.61 seconds. CPU system time: 0.02 seconds. Elapsed time: 2.65 seconds; current allocated memory: 337.027 MB.
*HLSZ200-111h px 
8
Checking synthesizability ...
*HLSZ200-10h px 
½
¡Finished Checking Synthesizability: CPU user time: 2.2 seconds. CPU system time: 0.01 seconds. Elapsed time: 2.47 seconds; current allocated memory: 341.969 MB.
*HLSZ200-111h px 

ôBalancing expressions in function 'kernel_gemm' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:26:5)...60 expression(s) balanced.
*XFORMZ203-11h px 
Ë
¯Finished Loop, function and other optimizations: CPU user time: 7.08 seconds. CPU system time: 0.02 seconds. Elapsed time: 7.75 seconds; current allocated memory: 416.297 MB.
*HLSZ200-111h px 
î
DSuccessfully converted nested loops %s into perfectly nested loops.
2002061*hls2
ÿ'merlinL3'(/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:82:3) and 'merlinL2'(/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:92:5) in function 'kernel_gemm'Z200-2061h px 

äFlattening a loop nest 'merlinL3' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:82:3) in function 'kernel_gemm'.
*XFORMZ203-541h px 
û
ÛFound false inter dependency for variable 'C_buf.30' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.29' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.28' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.27' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.26' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.25' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.24' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.23' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.22' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.21' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.20' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.19' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.18' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.17' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
û
ÛFound false inter dependency for variable 'C_buf.16' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
ø
ØFound false inter dependency for variable 'C_buf' (/home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c:64).
*ANALYSISZ214-52h px 
½
¡Finished Architecture Synthesis: CPU user time: 29.42 seconds. CPU system time: 0.03 seconds. Elapsed time: 30.23 seconds; current allocated memory: 483.297 MB.
*HLSZ200-111h px 
:
 Starting hardware synthesis ...
*HLSZ200-10h px 
9
Synthesizing 'kernel_gemm' ...
*HLSZ200-10h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
L
2-- Implementing module 'kernel_gemm_Pipeline_L2' 
*HLSZ200-42h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
4
Starting scheduling ...
*SCHEDZ204-11h px 
2
Pipelining loop 'L2'.
*SCHEDZ204-61h px 

BPipelining result : Target II = %s, Final II = %s, Depth = %s, %s
2001470*hls2
NA2
12
32
	loop 'L2'Z200-1470h px 
1
Finished scheduling.
*SCHEDZ204-11h px 
¯
Finished Scheduling: CPU user time: 0.78 seconds. CPU system time: 0.03 seconds. Elapsed time: 4.86 seconds; current allocated memory: 486.562 MB.
*HLSZ200-111h px 
G
+Starting micro-architecture generation ...
*BINDZ205-100h px 
C
'Performing variable lifetime analysis.
*BINDZ205-101h px 
8
Exploring resource sharing.
*BINDZ205-101h px 
(
Binding ...
*BINDZ205-101h px 
D
(Finished micro-architecture generation.
*BINDZ205-100h px 
©
Finished Binding: CPU user time: 0.02 seconds. CPU system time: 0 seconds. Elapsed time: 0.16 seconds; current allocated memory: 486.562 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
M
3-- Implementing module 'kernel_gemm_Pipeline_L21' 
*HLSZ200-42h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
4
Starting scheduling ...
*SCHEDZ204-11h px 
2
Pipelining loop 'L2'.
*SCHEDZ204-61h px 

BPipelining result : Target II = %s, Final II = %s, Depth = %s, %s
2001470*hls2
NA2
12
32
	loop 'L2'Z200-1470h px 
1
Finished scheduling.
*SCHEDZ204-11h px 
¬
Finished Scheduling: CPU user time: 0.47 seconds. CPU system time: 0 seconds. Elapsed time: 0.59 seconds; current allocated memory: 490.363 MB.
*HLSZ200-111h px 
G
+Starting micro-architecture generation ...
*BINDZ205-100h px 
C
'Performing variable lifetime analysis.
*BINDZ205-101h px 
8
Exploring resource sharing.
*BINDZ205-101h px 
(
Binding ...
*BINDZ205-101h px 
D
(Finished micro-architecture generation.
*BINDZ205-100h px 
¬
Finished Binding: CPU user time: 0.04 seconds. CPU system time: 0.01 seconds. Elapsed time: 0.06 seconds; current allocated memory: 490.363 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
M
3-- Implementing module 'kernel_gemm_Pipeline_L22' 
*HLSZ200-42h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
4
Starting scheduling ...
*SCHEDZ204-11h px 
2
Pipelining loop 'L2'.
*SCHEDZ204-61h px 

BPipelining result : Target II = %s, Final II = %s, Depth = %s, %s
2001470*hls2
NA2
12
32
	loop 'L2'Z200-1470h px 
1
Finished scheduling.
*SCHEDZ204-11h px 
¯
Finished Scheduling: CPU user time: 8.95 seconds. CPU system time: 0.03 seconds. Elapsed time: 9.71 seconds; current allocated memory: 554.480 MB.
*HLSZ200-111h px 
G
+Starting micro-architecture generation ...
*BINDZ205-100h px 
C
'Performing variable lifetime analysis.
*BINDZ205-101h px 
8
Exploring resource sharing.
*BINDZ205-101h px 
(
Binding ...
*BINDZ205-101h px 
D
(Finished micro-architecture generation.
*BINDZ205-100h px 
¬
Finished Binding: CPU user time: 0.36 seconds. CPU system time: 0.02 seconds. Elapsed time: 0.63 seconds; current allocated memory: 554.480 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
[
A-- Implementing module 'kernel_gemm_Pipeline_merlinL3_merlinL2' 
*HLSZ200-42h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
4
Starting scheduling ...
*SCHEDZ204-11h px 
A
%Pipelining loop 'merlinL3_merlinL2'.
*SCHEDZ204-61h px 

BPipelining result : Target II = %s, Final II = %s, Depth = %s, %s
2001470*hls2
NA2
12
7072
loop 'merlinL3_merlinL2'Z200-1470h px 
1
Finished scheduling.
*SCHEDZ204-11h px 
°
Finished Scheduling: CPU user time: 48.94 seconds. CPU system time: 0.07 seconds. Elapsed time: 51.3 seconds; current allocated memory: 597.297 MB.
*HLSZ200-111h px 
G
+Starting micro-architecture generation ...
*BINDZ205-100h px 
C
'Performing variable lifetime analysis.
*BINDZ205-101h px 
8
Exploring resource sharing.
*BINDZ205-101h px 
(
Binding ...
*BINDZ205-101h px 
D
(Finished micro-architecture generation.
*BINDZ205-100h px 
¬
Finished Binding: CPU user time: 5.07 seconds. CPU system time: 0.04 seconds. Elapsed time: 5.65 seconds; current allocated memory: 618.051 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
L
2-- Implementing module 'kernel_gemm_Pipeline_L3' 
*HLSZ200-42h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
4
Starting scheduling ...
*SCHEDZ204-11h px 
2
Pipelining loop 'L3'.
*SCHEDZ204-61h px 

BPipelining result : Target II = %s, Final II = %s, Depth = %s, %s
2001470*hls2
NA2
12
42
	loop 'L3'Z200-1470h px 
1
Finished scheduling.
*SCHEDZ204-11h px 
¯
Finished Scheduling: CPU user time: 0.75 seconds. CPU system time: 0.04 seconds. Elapsed time: 9.28 seconds; current allocated memory: 621.707 MB.
*HLSZ200-111h px 
G
+Starting micro-architecture generation ...
*BINDZ205-100h px 
C
'Performing variable lifetime analysis.
*BINDZ205-101h px 
8
Exploring resource sharing.
*BINDZ205-101h px 
(
Binding ...
*BINDZ205-101h px 
D
(Finished micro-architecture generation.
*BINDZ205-100h px 
¬
Finished Binding: CPU user time: 0.02 seconds. CPU system time: 0.01 seconds. Elapsed time: 0.35 seconds; current allocated memory: 621.707 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
@
&-- Implementing module 'kernel_gemm' 
*HLSZ200-42h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
4
Starting scheduling ...
*SCHEDZ204-11h px 
1
Finished scheduling.
*SCHEDZ204-11h px 
¬
Finished Scheduling: CPU user time: 0.76 seconds. CPU system time: 0 seconds. Elapsed time: 6.55 seconds; current allocated memory: 633.695 MB.
*HLSZ200-111h px 
G
+Starting micro-architecture generation ...
*BINDZ205-100h px 
C
'Performing variable lifetime analysis.
*BINDZ205-101h px 
8
Exploring resource sharing.
*BINDZ205-101h px 
(
Binding ...
*BINDZ205-101h px 
D
(Finished micro-architecture generation.
*BINDZ205-100h px 
¬
Finished Binding: CPU user time: 2.09 seconds. CPU system time: 0.02 seconds. Elapsed time: 5.66 seconds; current allocated memory: 636.234 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
R
8-- Generating RTL for module 'kernel_gemm_Pipeline_L2' 
*HLSZ200-10h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
¥
NApply Unified Pipeline Control on module '%s' pipeline '%s' pipeline type '%s'2001030*hls2
kernel_gemm_Pipeline_L22
L22
loop pipelineZ200-1030h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARVALID' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARADDR' to 0.
*RTGENZ206-101h px 

cSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARID' to 0.
*RTGENZ206-101h px 

dSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARLEN' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARSIZE' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARBURST' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARLOCK' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARCACHE' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARPROT' to 0.
*RTGENZ206-101h px 

dSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARQOS' to 0.
*RTGENZ206-101h px 

gSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARREGION' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L2/m_axi_merlin_gmem_kernel_gemm_512_C_ARUSER' to 0.
*RTGENZ206-101h px 
X
;Finished creating RTL model for 'kernel_gemm_Pipeline_L2'.
*RTGENZ206-100h px 
·
Finished Creating RTL model: CPU user time: 0.32 seconds. CPU system time: 0.02 seconds. Elapsed time: 1.09 seconds; current allocated memory: 638.898 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
S
9-- Generating RTL for module 'kernel_gemm_Pipeline_L21' 
*HLSZ200-10h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
¦
NApply Unified Pipeline Control on module '%s' pipeline '%s' pipeline type '%s'2001030*hls2
kernel_gemm_Pipeline_L212
L22
loop pipelineZ200-1030h px 

gSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARVALID' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARADDR' to 0.
*RTGENZ206-101h px 

dSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARID' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARLEN' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARSIZE' to 0.
*RTGENZ206-101h px 

gSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARBURST' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARLOCK' to 0.
*RTGENZ206-101h px 

gSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARCACHE' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARPROT' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARQOS' to 0.
*RTGENZ206-101h px 

hSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARREGION' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L21/m_axi_merlin_gmem_kernel_gemm_128_0_ARUSER' to 0.
*RTGENZ206-101h px 
Y
<Finished creating RTL model for 'kernel_gemm_Pipeline_L21'.
*RTGENZ206-100h px 
·
Finished Creating RTL model: CPU user time: 0.13 seconds. CPU system time: 0.02 seconds. Elapsed time: 1.22 seconds; current allocated memory: 640.695 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
S
9-- Generating RTL for module 'kernel_gemm_Pipeline_L22' 
*HLSZ200-10h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
¦
NApply Unified Pipeline Control on module '%s' pipeline '%s' pipeline type '%s'2001030*hls2
kernel_gemm_Pipeline_L222
L22
loop pipelineZ200-1030h px 

gSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARVALID' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARADDR' to 0.
*RTGENZ206-101h px 

dSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARID' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARLEN' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARSIZE' to 0.
*RTGENZ206-101h px 

gSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARBURST' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARLOCK' to 0.
*RTGENZ206-101h px 

gSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARCACHE' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARPROT' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARQOS' to 0.
*RTGENZ206-101h px 

hSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARREGION' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L22/m_axi_merlin_gmem_kernel_gemm_512_0_ARUSER' to 0.
*RTGENZ206-101h px 
´
Estimated max fanout for 'kernel_gemm_Pipeline_L22' is 60800 from HDL expression: ((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1))
*RTGENZ206-104h px 
Y
<Finished creating RTL model for 'kernel_gemm_Pipeline_L22'.
*RTGENZ206-100h px 
·
Finished Creating RTL model: CPU user time: 0.73 seconds. CPU system time: 0.06 seconds. Elapsed time: 3.85 seconds; current allocated memory: 685.898 MB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
a
G-- Generating RTL for module 'kernel_gemm_Pipeline_merlinL3_merlinL2' 
*HLSZ200-10h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
Ã
NApply Unified Pipeline Control on module '%s' pipeline '%s' pipeline type '%s'2001030*hls2(
&kernel_gemm_Pipeline_merlinL3_merlinL22
merlinL3_merlinL22
loop pipelineZ200-1030h px 
¤
Estimated max fanout for 'kernel_gemm_Pipeline_merlinL3_merlinL2' is 8932159 from HDL expression: (1'b0 == ap_block_pp0_stage0_11001)
*RTGENZ206-104h px 
g
JGenerating core module 'fadd_32ns_32ns_32_7_full_dsp_1': 800 instance(s).
*RTGENZ206-100h px 
f
IGenerating core module 'fmul_32ns_32ns_32_4_max_dsp_1': 800 instance(s).
*RTGENZ206-100h px 
g
JFinished creating RTL model for 'kernel_gemm_Pipeline_merlinL3_merlinL2'.
*RTGENZ206-100h px 
·
Finished Creating RTL model: CPU user time: 17.87 seconds. CPU system time: 0.76 seconds. Elapsed time: 36.26 seconds; current allocated memory: 1.322 GB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
R
8-- Generating RTL for module 'kernel_gemm_Pipeline_L3' 
*HLSZ200-10h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
¥
NApply Unified Pipeline Control on module '%s' pipeline '%s' pipeline type '%s'2001030*hls2
kernel_gemm_Pipeline_L32
L32
loop pipelineZ200-1030h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWVALID' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWADDR' to 0.
*RTGENZ206-101h px 

cSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWID' to 0.
*RTGENZ206-101h px 

dSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWLEN' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWSIZE' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWBURST' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWLOCK' to 0.
*RTGENZ206-101h px 

fSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWCACHE' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWPROT' to 0.
*RTGENZ206-101h px 

dSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWQOS' to 0.
*RTGENZ206-101h px 

gSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWREGION' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_AWUSER' to 0.
*RTGENZ206-101h px 

eSetting dangling out port 'kernel_gemm_Pipeline_L3/m_axi_merlin_gmem_kernel_gemm_512_C_BREADY' to 0.
*RTGENZ206-101h px 
X
;Finished creating RTL model for 'kernel_gemm_Pipeline_L3'.
*RTGENZ206-100h px 
¶
Finished Creating RTL model: CPU user time: 21.95 seconds. CPU system time: 0.7 seconds. Elapsed time: 36.17 seconds; current allocated memory: 1.438 GB.
*HLSZ200-111h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
F
,-- Generating RTL for module 'kernel_gemm' 
*HLSZ200-10h px 
[
A----------------------------------------------------------------
*HLSZ200-10h px 
f
IDesign contains AXI ports. Reset is fixed to synchronous and active low.
*RTGENZ206-101h px 
t
WSetting interface mode on port 'kernel_gemm/merlin_gmem_kernel_gemm_512_C' to 'm_axi'.
*RTGENZ206-500h px 
t
WSetting interface mode on port 'kernel_gemm/merlin_gmem_kernel_gemm_128_0' to 'm_axi'.
*RTGENZ206-500h px 
t
WSetting interface mode on port 'kernel_gemm/merlin_gmem_kernel_gemm_512_0' to 'm_axi'.
*RTGENZ206-500h px 
f
ISetting interface mode on port 'kernel_gemm/C' to 's_axilite & ap_none'.
*RTGENZ206-500h px 
f
ISetting interface mode on port 'kernel_gemm/A' to 's_axilite & ap_none'.
*RTGENZ206-500h px 
f
ISetting interface mode on port 'kernel_gemm/B' to 's_axilite & ap_none'.
*RTGENZ206-500h px 
n
QSetting interface mode on function 'kernel_gemm' to 's_axilite & ap_ctrl_chain'.
*RTGENZ206-500h px 
`
CBundling port 'C', 'A', 'B' and 'return' to AXI-Lite port control.
*RTGENZ206-100h px 
~
aEstimated max fanout for 'kernel_gemm' is 14452 from HDL expression: (1'b1 == ap_CS_fsm_state74)
*RTGENZ206-104h px 
L
/Finished creating RTL model for 'kernel_gemm'.
*RTGENZ206-100h px 
g
KImplementing memory 'kernel_gemm_B_5_0_buf_RAM_AUTO_1R1W' using auto RAMs.
*RTMGZ210-278h px 
g
KImplementing memory 'kernel_gemm_A_5_0_buf_RAM_AUTO_1R1W' using auto RAMs.
*RTMGZ210-278h px 
c
GImplementing memory 'kernel_gemm_C_buf_RAM_AUTO_1R1W' using auto RAMs.
*RTMGZ210-278h px 
¶
Finished Creating RTL model: CPU user time: 0.88 seconds. CPU system time: 0.04 seconds. Elapsed time: 12.67 seconds; current allocated memory: 1.448 GB.
*HLSZ200-111h px 
¼
 Finished Generating all RTL models: CPU user time: 5.34 seconds. CPU system time: 0.38 seconds. Elapsed time: 9.47 seconds; current allocated memory: 1.512 GB.
*HLSZ200-111h px 
£
hDesign has inferred MAXI bursts%s, see Vitis HLS GUI synthesis summary report for detailed information.
2001603*hls2
 and missed burstsZ200-1603h px 
¹
Finished Updating report files: CPU user time: 7.22 seconds. CPU system time: 0.14 seconds. Elapsed time: 12.26 seconds; current allocated memory: 1.596 GB.
*HLSZ200-111h px 
A
%Generating VHDL RTL for kernel_gemm.
*VHDLZ208-304h px 
D
(Generating Verilog RTL for kernel_gemm.
*VLOGZ209-307h px 
j
**** Loop Constraint Status: %s200790*hls2&
$All loop constraints were satisfied.Z200-790h px 
H
**** Estimated Fmax: %s MHz200789*hls2
342.47Z200-789h px 
»
Finished Command csynth_design CPU user time: 221.34 seconds. CPU system time: 3.49 seconds. Elapsed time: 330.21 seconds; current allocated memory: 1.342 GB.
*HLSZ200-111h px 
C
Running: %s
2001510*hls2
export_design Z200-1510h px 
8
Exporting RTL as a Vivado IP.
*IMPLZ213-8h px 

ú
****** Vivado v2023.2 (64-bit)
  **** SW Build 4029153 on Fri Oct 13 20:13:54 MDT 2023
  **** IP Build 4028589 on Sat Oct 14 00:45:43 MDT 2023
  **** SharedData Build 4025554 on Tue Oct 10 17:18:54 MDT 2023
    ** Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
    ** Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.

source run_ippack.tcl -notrace
*commonh px 
³
create_project: Time (s): cpu = 00:00:05 ; elapsed = 00:00:06 . Memory (MB): peak = 1339.082 ; gain = 0.023 ; free physical = 290636 ; free virtual = 454636
*commonh px 
G
2INFO: [IP_Flow 19-234] Refreshing IP repositories
*commonh px 
O
:INFO: [IP_Flow 19-1704] No user IP repositories specified
*commonh px 
w
bINFO: [IP_Flow 19-2313] Loaded Vivado IP repository '/mnt/software/xilinx/Vivado/2023.2/data/ip'.
*commonh px 

pINFO: [IP_Flow 19-1686] Generating 'Synthesis' target for IP 'kernel_gemm_fadd_32ns_32ns_32_7_full_dsp_1_ip'...
*commonh px 

qINFO: [IP_Flow 19-1686] Generating 'Simulation' target for IP 'kernel_gemm_fadd_32ns_32ns_32_7_full_dsp_1_ip'...
*commonh px 

oINFO: [IP_Flow 19-1686] Generating 'Synthesis' target for IP 'kernel_gemm_fmul_32ns_32ns_32_4_max_dsp_1_ip'...
*commonh px 

pINFO: [IP_Flow 19-1686] Generating 'Simulation' target for IP 'kernel_gemm_fmul_32ns_32ns_32_4_max_dsp_1_ip'...
*commonh px 
G
2INFO: [IP_Flow 19-234] Refreshing IP repositories
*commonh px 
O
:INFO: [IP_Flow 19-1704] No user IP repositories specified
*commonh px 
w
bINFO: [IP_Flow 19-2313] Loaded Vivado IP repository '/mnt/software/xilinx/Vivado/2023.2/data/ip'.
*commonh px 

Running package_xo -xo_path /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/impl/export.xo -kernel_name kernel_gemm -kernel_xml /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/impl/ip/../kernel/kernel.xml -kernel_files /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/__merlinkernel_kernel_gemm.c -ip_directory /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/impl/ip/ip_unzip_dir -design_xml /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/ker*commonh px 
¿
©nel_gemm/solution/.autopilot/db/kernel_gemm.design.xml -debug_directory /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/.debug -hls_directory /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/impl/ip/hls_files -kernel_json /home/spouget/iccad_24/autodse_without_tree_reduction/bert_100_768/_done/work_dir/output/fast/0/.merlin_prj/run/implement/exec/hls/_x/kernel_gemm/kernel_gemm/kernel_gemm/solution/solution_data.json
*commonh px 
Y
DINFO: [Common 17-206] Exiting Vivado at Fri Apr 19 16:06:00 2024...
*commonh px 
c
Generated output file %s
200802*hls2%
#kernel_gemm/solution/impl/export.xoZ200-802h px 
»
Finished Command export_design CPU user time: 95.31 seconds. CPU system time: 1.85 seconds. Elapsed time: 131.56 seconds; current allocated memory: 15.461 MB.
*HLSZ200-111h px 
C
Running: %s
2001510*hls2
close_project Z200-1510h px 
6
HLS completed successfully
*HLSZ200-150h px 
«
Total CPU user time: 319.47 seconds. Total CPU system time: 5.97 seconds. Total elapsed time: 520.66 seconds; peak allocated memory: 1.596 GB.
*HLSZ200-112h px 
_
Exiting %s at %s...
206*common2
	vitis_hls2
Fri Apr 19 16:06:12 2024Z17-206h px 


End Record