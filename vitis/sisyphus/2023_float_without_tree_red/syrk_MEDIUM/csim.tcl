
catch {::common::set_param -quiet hls.xocc.mode csynth};

open_project csim.prj
set_top csim
add_files "code_generated.cpp" -cflags " -O3 -D XILINX "
add_files -tb "csim.cpp"
open_solution -flow_target vitis solution
set_part xcu200-fsgd2104-2-e
create_clock -period 250MHz -name default
csim_design
close_project
puts "HLS completed successfully"
exit
        