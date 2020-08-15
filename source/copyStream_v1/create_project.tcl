############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
#reset the project
open_project -reset copyStream 
set_top copyStream
add_files copyStream.cpp
add_files -tb test.cpp

#reset the solution 
open_solution -reset "solution1"
set_part {xc7z020clg400-2} -tool vivado
create_clock -period 10 -name default

#add directives
source "./directives.tcl"

csim_design
csynth_design
cosim_design -trace_level all
export_design -format ip_catalog

exit
