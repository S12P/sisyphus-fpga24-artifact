set moduleName kernel_gemm_Pipeline_L2
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 1
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set hasInterrupt 0
set DLRegFirstOffset 0
set DLRegItemOffset 0
set C_modelName {kernel_gemm_Pipeline_L2}
set C_modelType { void 0 }
set C_modelArgList {
	{ merlin_gmem_kernel_gemm_512_C int 512 regular {axi_master 0}  }
	{ sext_ln1705 int 58 regular  }
	{ C_buf_30 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_29 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_28 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_27 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_26 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_25 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_24 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_23 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_22 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_21 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_20 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_19 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_18 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_17 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf_16 float 32 regular {array 4800 { 0 3 } 0 1 }  }
	{ C_buf float 32 regular {array 4800 { 0 3 } 0 1 }  }
}
set hasAXIMCache 0
set AXIMCacheInstList { }
set C_modelArgMapList {[ 
	{ "Name" : "merlin_gmem_kernel_gemm_512_C", "interface" : "axi_master", "bitwidth" : 512, "direction" : "READONLY", "bitSlice":[ {"cElement": [{"cName": "C","offset": { "type": "dynamic","port_name": "C","bundle": "control"},"direction": "READWRITE"}]}]} , 
 	{ "Name" : "sext_ln1705", "interface" : "wire", "bitwidth" : 58, "direction" : "READONLY"} , 
 	{ "Name" : "C_buf_30", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_29", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_28", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_27", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_26", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_25", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_24", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_23", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_22", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_21", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_20", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_19", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_18", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_17", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf_16", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} , 
 	{ "Name" : "C_buf", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 117
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWADDR sc_out sc_lv 64 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWID sc_out sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWLEN sc_out sc_lv 32 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_AWUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_WVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_WREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_WDATA sc_out sc_lv 512 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_WSTRB sc_out sc_lv 64 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_WLAST sc_out sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_WID sc_out sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_WUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARADDR sc_out sc_lv 64 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARID sc_out sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARLEN sc_out sc_lv 32 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_ARUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_RVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_RREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_RDATA sc_in sc_lv 512 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_RLAST sc_in sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_RID sc_in sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_RFIFONUM sc_in sc_lv 9 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_RUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_RRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_BVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_BREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_BRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_BID sc_in sc_lv 1 signal 0 } 
	{ m_axi_merlin_gmem_kernel_gemm_512_C_BUSER sc_in sc_lv 1 signal 0 } 
	{ sext_ln1705 sc_in sc_lv 58 signal 1 } 
	{ C_buf_30_address0 sc_out sc_lv 13 signal 2 } 
	{ C_buf_30_ce0 sc_out sc_logic 1 signal 2 } 
	{ C_buf_30_we0 sc_out sc_logic 1 signal 2 } 
	{ C_buf_30_d0 sc_out sc_lv 32 signal 2 } 
	{ C_buf_29_address0 sc_out sc_lv 13 signal 3 } 
	{ C_buf_29_ce0 sc_out sc_logic 1 signal 3 } 
	{ C_buf_29_we0 sc_out sc_logic 1 signal 3 } 
	{ C_buf_29_d0 sc_out sc_lv 32 signal 3 } 
	{ C_buf_28_address0 sc_out sc_lv 13 signal 4 } 
	{ C_buf_28_ce0 sc_out sc_logic 1 signal 4 } 
	{ C_buf_28_we0 sc_out sc_logic 1 signal 4 } 
	{ C_buf_28_d0 sc_out sc_lv 32 signal 4 } 
	{ C_buf_27_address0 sc_out sc_lv 13 signal 5 } 
	{ C_buf_27_ce0 sc_out sc_logic 1 signal 5 } 
	{ C_buf_27_we0 sc_out sc_logic 1 signal 5 } 
	{ C_buf_27_d0 sc_out sc_lv 32 signal 5 } 
	{ C_buf_26_address0 sc_out sc_lv 13 signal 6 } 
	{ C_buf_26_ce0 sc_out sc_logic 1 signal 6 } 
	{ C_buf_26_we0 sc_out sc_logic 1 signal 6 } 
	{ C_buf_26_d0 sc_out sc_lv 32 signal 6 } 
	{ C_buf_25_address0 sc_out sc_lv 13 signal 7 } 
	{ C_buf_25_ce0 sc_out sc_logic 1 signal 7 } 
	{ C_buf_25_we0 sc_out sc_logic 1 signal 7 } 
	{ C_buf_25_d0 sc_out sc_lv 32 signal 7 } 
	{ C_buf_24_address0 sc_out sc_lv 13 signal 8 } 
	{ C_buf_24_ce0 sc_out sc_logic 1 signal 8 } 
	{ C_buf_24_we0 sc_out sc_logic 1 signal 8 } 
	{ C_buf_24_d0 sc_out sc_lv 32 signal 8 } 
	{ C_buf_23_address0 sc_out sc_lv 13 signal 9 } 
	{ C_buf_23_ce0 sc_out sc_logic 1 signal 9 } 
	{ C_buf_23_we0 sc_out sc_logic 1 signal 9 } 
	{ C_buf_23_d0 sc_out sc_lv 32 signal 9 } 
	{ C_buf_22_address0 sc_out sc_lv 13 signal 10 } 
	{ C_buf_22_ce0 sc_out sc_logic 1 signal 10 } 
	{ C_buf_22_we0 sc_out sc_logic 1 signal 10 } 
	{ C_buf_22_d0 sc_out sc_lv 32 signal 10 } 
	{ C_buf_21_address0 sc_out sc_lv 13 signal 11 } 
	{ C_buf_21_ce0 sc_out sc_logic 1 signal 11 } 
	{ C_buf_21_we0 sc_out sc_logic 1 signal 11 } 
	{ C_buf_21_d0 sc_out sc_lv 32 signal 11 } 
	{ C_buf_20_address0 sc_out sc_lv 13 signal 12 } 
	{ C_buf_20_ce0 sc_out sc_logic 1 signal 12 } 
	{ C_buf_20_we0 sc_out sc_logic 1 signal 12 } 
	{ C_buf_20_d0 sc_out sc_lv 32 signal 12 } 
	{ C_buf_19_address0 sc_out sc_lv 13 signal 13 } 
	{ C_buf_19_ce0 sc_out sc_logic 1 signal 13 } 
	{ C_buf_19_we0 sc_out sc_logic 1 signal 13 } 
	{ C_buf_19_d0 sc_out sc_lv 32 signal 13 } 
	{ C_buf_18_address0 sc_out sc_lv 13 signal 14 } 
	{ C_buf_18_ce0 sc_out sc_logic 1 signal 14 } 
	{ C_buf_18_we0 sc_out sc_logic 1 signal 14 } 
	{ C_buf_18_d0 sc_out sc_lv 32 signal 14 } 
	{ C_buf_17_address0 sc_out sc_lv 13 signal 15 } 
	{ C_buf_17_ce0 sc_out sc_logic 1 signal 15 } 
	{ C_buf_17_we0 sc_out sc_logic 1 signal 15 } 
	{ C_buf_17_d0 sc_out sc_lv 32 signal 15 } 
	{ C_buf_16_address0 sc_out sc_lv 13 signal 16 } 
	{ C_buf_16_ce0 sc_out sc_logic 1 signal 16 } 
	{ C_buf_16_we0 sc_out sc_logic 1 signal 16 } 
	{ C_buf_16_d0 sc_out sc_lv 32 signal 16 } 
	{ C_buf_address0 sc_out sc_lv 13 signal 17 } 
	{ C_buf_ce0 sc_out sc_logic 1 signal 17 } 
	{ C_buf_we0 sc_out sc_logic 1 signal 17 } 
	{ C_buf_d0 sc_out sc_lv 32 signal 17 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWVALID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWREADY" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWADDR" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWLEN" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWBURST" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWPROT" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWQOS" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWREGION" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "AWUSER" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "WVALID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "WREADY" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":512, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "WDATA" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "WSTRB" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "WLAST" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "WID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "WUSER" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARVALID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARREADY" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":64, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARADDR" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARLEN" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARBURST" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARPROT" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARQOS" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARREGION" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "ARUSER" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "RVALID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "RREADY" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":512, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "RDATA" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "RLAST" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "RID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_RFIFONUM", "direction": "in", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "RFIFONUM" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "RUSER" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "RRESP" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "BVALID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "BREADY" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "BRESP" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "BID" }} , 
 	{ "name": "m_axi_merlin_gmem_kernel_gemm_512_C_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "merlin_gmem_kernel_gemm_512_C", "role": "BUSER" }} , 
 	{ "name": "sext_ln1705", "direction": "in", "datatype": "sc_lv", "bitwidth":58, "type": "signal", "bundle":{"name": "sext_ln1705", "role": "default" }} , 
 	{ "name": "C_buf_30_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_30", "role": "address0" }} , 
 	{ "name": "C_buf_30_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_30", "role": "ce0" }} , 
 	{ "name": "C_buf_30_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_30", "role": "we0" }} , 
 	{ "name": "C_buf_30_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_30", "role": "d0" }} , 
 	{ "name": "C_buf_29_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_29", "role": "address0" }} , 
 	{ "name": "C_buf_29_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_29", "role": "ce0" }} , 
 	{ "name": "C_buf_29_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_29", "role": "we0" }} , 
 	{ "name": "C_buf_29_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_29", "role": "d0" }} , 
 	{ "name": "C_buf_28_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_28", "role": "address0" }} , 
 	{ "name": "C_buf_28_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_28", "role": "ce0" }} , 
 	{ "name": "C_buf_28_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_28", "role": "we0" }} , 
 	{ "name": "C_buf_28_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_28", "role": "d0" }} , 
 	{ "name": "C_buf_27_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_27", "role": "address0" }} , 
 	{ "name": "C_buf_27_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_27", "role": "ce0" }} , 
 	{ "name": "C_buf_27_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_27", "role": "we0" }} , 
 	{ "name": "C_buf_27_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_27", "role": "d0" }} , 
 	{ "name": "C_buf_26_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_26", "role": "address0" }} , 
 	{ "name": "C_buf_26_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_26", "role": "ce0" }} , 
 	{ "name": "C_buf_26_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_26", "role": "we0" }} , 
 	{ "name": "C_buf_26_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_26", "role": "d0" }} , 
 	{ "name": "C_buf_25_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_25", "role": "address0" }} , 
 	{ "name": "C_buf_25_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_25", "role": "ce0" }} , 
 	{ "name": "C_buf_25_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_25", "role": "we0" }} , 
 	{ "name": "C_buf_25_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_25", "role": "d0" }} , 
 	{ "name": "C_buf_24_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_24", "role": "address0" }} , 
 	{ "name": "C_buf_24_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_24", "role": "ce0" }} , 
 	{ "name": "C_buf_24_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_24", "role": "we0" }} , 
 	{ "name": "C_buf_24_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_24", "role": "d0" }} , 
 	{ "name": "C_buf_23_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_23", "role": "address0" }} , 
 	{ "name": "C_buf_23_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_23", "role": "ce0" }} , 
 	{ "name": "C_buf_23_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_23", "role": "we0" }} , 
 	{ "name": "C_buf_23_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_23", "role": "d0" }} , 
 	{ "name": "C_buf_22_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_22", "role": "address0" }} , 
 	{ "name": "C_buf_22_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_22", "role": "ce0" }} , 
 	{ "name": "C_buf_22_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_22", "role": "we0" }} , 
 	{ "name": "C_buf_22_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_22", "role": "d0" }} , 
 	{ "name": "C_buf_21_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_21", "role": "address0" }} , 
 	{ "name": "C_buf_21_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_21", "role": "ce0" }} , 
 	{ "name": "C_buf_21_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_21", "role": "we0" }} , 
 	{ "name": "C_buf_21_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_21", "role": "d0" }} , 
 	{ "name": "C_buf_20_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_20", "role": "address0" }} , 
 	{ "name": "C_buf_20_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_20", "role": "ce0" }} , 
 	{ "name": "C_buf_20_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_20", "role": "we0" }} , 
 	{ "name": "C_buf_20_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_20", "role": "d0" }} , 
 	{ "name": "C_buf_19_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_19", "role": "address0" }} , 
 	{ "name": "C_buf_19_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_19", "role": "ce0" }} , 
 	{ "name": "C_buf_19_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_19", "role": "we0" }} , 
 	{ "name": "C_buf_19_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_19", "role": "d0" }} , 
 	{ "name": "C_buf_18_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_18", "role": "address0" }} , 
 	{ "name": "C_buf_18_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_18", "role": "ce0" }} , 
 	{ "name": "C_buf_18_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_18", "role": "we0" }} , 
 	{ "name": "C_buf_18_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_18", "role": "d0" }} , 
 	{ "name": "C_buf_17_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_17", "role": "address0" }} , 
 	{ "name": "C_buf_17_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_17", "role": "ce0" }} , 
 	{ "name": "C_buf_17_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_17", "role": "we0" }} , 
 	{ "name": "C_buf_17_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_17", "role": "d0" }} , 
 	{ "name": "C_buf_16_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf_16", "role": "address0" }} , 
 	{ "name": "C_buf_16_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_16", "role": "ce0" }} , 
 	{ "name": "C_buf_16_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf_16", "role": "we0" }} , 
 	{ "name": "C_buf_16_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf_16", "role": "d0" }} , 
 	{ "name": "C_buf_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "C_buf", "role": "address0" }} , 
 	{ "name": "C_buf_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf", "role": "ce0" }} , 
 	{ "name": "C_buf_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "C_buf", "role": "we0" }} , 
 	{ "name": "C_buf_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "C_buf", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1"],
		"CDFG" : "kernel_gemm_Pipeline_L2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "4803", "EstimateLatencyMax" : "4803",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"IsBlackBox" : "0",
		"Port" : [
			{"Name" : "merlin_gmem_kernel_gemm_512_C", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "merlin_gmem_kernel_gemm_512_C_blk_n_R", "Type" : "RtlSignal"}]},
			{"Name" : "sext_ln1705", "Type" : "None", "Direction" : "I"},
			{"Name" : "C_buf_30", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_29", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_28", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_27", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_26", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_25", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_24", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_23", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_22", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_21", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_20", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_19", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_18", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_17", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf_16", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "C_buf", "Type" : "Memory", "Direction" : "O"}],
		"Loop" : [
			{"Name" : "L2", "PipelineType" : "UPC",
				"LoopDec" : {"FSMBitwidth" : "1", "FirstState" : "ap_ST_fsm_pp0_stage0", "FirstStateIter" : "ap_enable_reg_pp0_iter0", "FirstStateBlock" : "ap_block_pp0_stage0_subdone", "LastState" : "ap_ST_fsm_pp0_stage0", "LastStateIter" : "ap_enable_reg_pp0_iter2", "LastStateBlock" : "ap_block_pp0_stage0_subdone", "QuitState" : "ap_ST_fsm_pp0_stage0", "QuitStateIter" : "ap_enable_reg_pp0_iter2", "QuitStateBlock" : "ap_block_pp0_stage0_subdone", "OneDepthLoop" : "0", "has_ap_ctrl" : "1", "has_continue" : "0"}}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.flow_control_loop_pipe_sequential_init_U", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	kernel_gemm_Pipeline_L2 {
		merlin_gmem_kernel_gemm_512_C {Type I LastRead 1 FirstWrite -1}
		sext_ln1705 {Type I LastRead 0 FirstWrite -1}
		C_buf_30 {Type O LastRead -1 FirstWrite 2}
		C_buf_29 {Type O LastRead -1 FirstWrite 2}
		C_buf_28 {Type O LastRead -1 FirstWrite 2}
		C_buf_27 {Type O LastRead -1 FirstWrite 2}
		C_buf_26 {Type O LastRead -1 FirstWrite 2}
		C_buf_25 {Type O LastRead -1 FirstWrite 2}
		C_buf_24 {Type O LastRead -1 FirstWrite 2}
		C_buf_23 {Type O LastRead -1 FirstWrite 2}
		C_buf_22 {Type O LastRead -1 FirstWrite 2}
		C_buf_21 {Type O LastRead -1 FirstWrite 2}
		C_buf_20 {Type O LastRead -1 FirstWrite 2}
		C_buf_19 {Type O LastRead -1 FirstWrite 2}
		C_buf_18 {Type O LastRead -1 FirstWrite 2}
		C_buf_17 {Type O LastRead -1 FirstWrite 2}
		C_buf_16 {Type O LastRead -1 FirstWrite 2}
		C_buf {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "4803", "Max" : "4803"}
	, {"Name" : "Interval", "Min" : "4803", "Max" : "4803"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	 { m_axi {  { m_axi_merlin_gmem_kernel_gemm_512_C_AWVALID VALID 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWREADY READY 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWADDR ADDR 1 64 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWID ID 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWLEN SIZE 1 32 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWSIZE BURST 1 3 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWBURST LOCK 1 2 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWLOCK CACHE 1 2 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWCACHE PROT 1 4 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWPROT QOS 1 3 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWQOS REGION 1 4 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWREGION USER 1 4 }  { m_axi_merlin_gmem_kernel_gemm_512_C_AWUSER DATA 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_WVALID VALID 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_WREADY READY 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_WDATA FIFONUM 1 512 }  { m_axi_merlin_gmem_kernel_gemm_512_C_WSTRB STRB 1 64 }  { m_axi_merlin_gmem_kernel_gemm_512_C_WLAST LAST 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_WID ID 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_WUSER DATA 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARVALID VALID 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARREADY READY 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARADDR ADDR 1 64 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARID ID 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARLEN SIZE 1 32 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARSIZE BURST 1 3 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARBURST LOCK 1 2 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARLOCK CACHE 1 2 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARCACHE PROT 1 4 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARPROT QOS 1 3 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARQOS REGION 1 4 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARREGION USER 1 4 }  { m_axi_merlin_gmem_kernel_gemm_512_C_ARUSER DATA 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_RVALID VALID 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_RREADY READY 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_RDATA FIFONUM 0 512 }  { m_axi_merlin_gmem_kernel_gemm_512_C_RLAST LAST 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_RID ID 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_RFIFONUM LEN 0 9 }  { m_axi_merlin_gmem_kernel_gemm_512_C_RUSER DATA 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_RRESP RESP 0 2 }  { m_axi_merlin_gmem_kernel_gemm_512_C_BVALID VALID 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_BREADY READY 1 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_BRESP RESP 0 2 }  { m_axi_merlin_gmem_kernel_gemm_512_C_BID ID 0 1 }  { m_axi_merlin_gmem_kernel_gemm_512_C_BUSER DATA 0 1 } } }
	sext_ln1705 { ap_none {  { sext_ln1705 in_data 0 58 } } }
	C_buf_30 { ap_memory {  { C_buf_30_address0 mem_address 1 13 }  { C_buf_30_ce0 mem_ce 1 1 }  { C_buf_30_we0 mem_we 1 1 }  { C_buf_30_d0 mem_din 1 32 } } }
	C_buf_29 { ap_memory {  { C_buf_29_address0 mem_address 1 13 }  { C_buf_29_ce0 mem_ce 1 1 }  { C_buf_29_we0 mem_we 1 1 }  { C_buf_29_d0 mem_din 1 32 } } }
	C_buf_28 { ap_memory {  { C_buf_28_address0 mem_address 1 13 }  { C_buf_28_ce0 mem_ce 1 1 }  { C_buf_28_we0 mem_we 1 1 }  { C_buf_28_d0 mem_din 1 32 } } }
	C_buf_27 { ap_memory {  { C_buf_27_address0 mem_address 1 13 }  { C_buf_27_ce0 mem_ce 1 1 }  { C_buf_27_we0 mem_we 1 1 }  { C_buf_27_d0 mem_din 1 32 } } }
	C_buf_26 { ap_memory {  { C_buf_26_address0 mem_address 1 13 }  { C_buf_26_ce0 mem_ce 1 1 }  { C_buf_26_we0 mem_we 1 1 }  { C_buf_26_d0 mem_din 1 32 } } }
	C_buf_25 { ap_memory {  { C_buf_25_address0 mem_address 1 13 }  { C_buf_25_ce0 mem_ce 1 1 }  { C_buf_25_we0 mem_we 1 1 }  { C_buf_25_d0 mem_din 1 32 } } }
	C_buf_24 { ap_memory {  { C_buf_24_address0 mem_address 1 13 }  { C_buf_24_ce0 mem_ce 1 1 }  { C_buf_24_we0 mem_we 1 1 }  { C_buf_24_d0 mem_din 1 32 } } }
	C_buf_23 { ap_memory {  { C_buf_23_address0 mem_address 1 13 }  { C_buf_23_ce0 mem_ce 1 1 }  { C_buf_23_we0 mem_we 1 1 }  { C_buf_23_d0 mem_din 1 32 } } }
	C_buf_22 { ap_memory {  { C_buf_22_address0 mem_address 1 13 }  { C_buf_22_ce0 mem_ce 1 1 }  { C_buf_22_we0 mem_we 1 1 }  { C_buf_22_d0 mem_din 1 32 } } }
	C_buf_21 { ap_memory {  { C_buf_21_address0 mem_address 1 13 }  { C_buf_21_ce0 mem_ce 1 1 }  { C_buf_21_we0 mem_we 1 1 }  { C_buf_21_d0 mem_din 1 32 } } }
	C_buf_20 { ap_memory {  { C_buf_20_address0 mem_address 1 13 }  { C_buf_20_ce0 mem_ce 1 1 }  { C_buf_20_we0 mem_we 1 1 }  { C_buf_20_d0 mem_din 1 32 } } }
	C_buf_19 { ap_memory {  { C_buf_19_address0 mem_address 1 13 }  { C_buf_19_ce0 mem_ce 1 1 }  { C_buf_19_we0 mem_we 1 1 }  { C_buf_19_d0 mem_din 1 32 } } }
	C_buf_18 { ap_memory {  { C_buf_18_address0 mem_address 1 13 }  { C_buf_18_ce0 mem_ce 1 1 }  { C_buf_18_we0 mem_we 1 1 }  { C_buf_18_d0 mem_din 1 32 } } }
	C_buf_17 { ap_memory {  { C_buf_17_address0 mem_address 1 13 }  { C_buf_17_ce0 mem_ce 1 1 }  { C_buf_17_we0 mem_we 1 1 }  { C_buf_17_d0 mem_din 1 32 } } }
	C_buf_16 { ap_memory {  { C_buf_16_address0 mem_address 1 13 }  { C_buf_16_ce0 mem_ce 1 1 }  { C_buf_16_we0 mem_we 1 1 }  { C_buf_16_d0 mem_din 1 32 } } }
	C_buf { ap_memory {  { C_buf_address0 mem_address 1 13 }  { C_buf_ce0 mem_ce 1 1 }  { C_buf_we0 mem_we 1 1 }  { C_buf_d0 mem_din 1 32 } } }
}
