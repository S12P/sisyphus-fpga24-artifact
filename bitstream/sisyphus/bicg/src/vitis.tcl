
catch {::common::set_param -quiet hls.xocc.mode csynth};

open_project kernel_nlp
set_top kernel_nlp

add_files "output.cpp"  
open_solution -flow_target vitis solution
set_part xcu55c-fsvh2892-2L-e

create_clock -period 220MHz -name default

config_dataflow -strict_mode warning

config_export -disable_deadlock_detection=true

config_rtl -m_axi_conservative_mode=1
config_interface -m_axi_addr64

config_interface -m_axi_auto_max_ports=0
config_export -format ip_catalog -ipname kernel_trmm
config_compile -unsafe_math_optimizations

csynth_design
export_design
close_project
puts "HLS completed successfully"
exit
    