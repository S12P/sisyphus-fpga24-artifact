// ==============================================================
// Generated by Vitis HLS v2023.2
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
// ==============================================================

`timescale 1 ns / 1 ps 

module kernel_gemm_kernel_gemm_Pipeline_L2 (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWVALID,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWREADY,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWADDR,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWID,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWLEN,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWSIZE,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWBURST,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWLOCK,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWCACHE,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWPROT,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWQOS,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWREGION,
        m_axi_merlin_gmem_kernel_gemm_512_C_AWUSER,
        m_axi_merlin_gmem_kernel_gemm_512_C_WVALID,
        m_axi_merlin_gmem_kernel_gemm_512_C_WREADY,
        m_axi_merlin_gmem_kernel_gemm_512_C_WDATA,
        m_axi_merlin_gmem_kernel_gemm_512_C_WSTRB,
        m_axi_merlin_gmem_kernel_gemm_512_C_WLAST,
        m_axi_merlin_gmem_kernel_gemm_512_C_WID,
        m_axi_merlin_gmem_kernel_gemm_512_C_WUSER,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARVALID,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARREADY,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARADDR,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARID,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARLEN,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARSIZE,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARBURST,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARLOCK,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARCACHE,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARPROT,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARQOS,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARREGION,
        m_axi_merlin_gmem_kernel_gemm_512_C_ARUSER,
        m_axi_merlin_gmem_kernel_gemm_512_C_RVALID,
        m_axi_merlin_gmem_kernel_gemm_512_C_RREADY,
        m_axi_merlin_gmem_kernel_gemm_512_C_RDATA,
        m_axi_merlin_gmem_kernel_gemm_512_C_RLAST,
        m_axi_merlin_gmem_kernel_gemm_512_C_RID,
        m_axi_merlin_gmem_kernel_gemm_512_C_RFIFONUM,
        m_axi_merlin_gmem_kernel_gemm_512_C_RUSER,
        m_axi_merlin_gmem_kernel_gemm_512_C_RRESP,
        m_axi_merlin_gmem_kernel_gemm_512_C_BVALID,
        m_axi_merlin_gmem_kernel_gemm_512_C_BREADY,
        m_axi_merlin_gmem_kernel_gemm_512_C_BRESP,
        m_axi_merlin_gmem_kernel_gemm_512_C_BID,
        m_axi_merlin_gmem_kernel_gemm_512_C_BUSER,
        sext_ln1705,
        C_buf_30_address0,
        C_buf_30_ce0,
        C_buf_30_we0,
        C_buf_30_d0,
        C_buf_29_address0,
        C_buf_29_ce0,
        C_buf_29_we0,
        C_buf_29_d0,
        C_buf_28_address0,
        C_buf_28_ce0,
        C_buf_28_we0,
        C_buf_28_d0,
        C_buf_27_address0,
        C_buf_27_ce0,
        C_buf_27_we0,
        C_buf_27_d0,
        C_buf_26_address0,
        C_buf_26_ce0,
        C_buf_26_we0,
        C_buf_26_d0,
        C_buf_25_address0,
        C_buf_25_ce0,
        C_buf_25_we0,
        C_buf_25_d0,
        C_buf_24_address0,
        C_buf_24_ce0,
        C_buf_24_we0,
        C_buf_24_d0,
        C_buf_23_address0,
        C_buf_23_ce0,
        C_buf_23_we0,
        C_buf_23_d0,
        C_buf_22_address0,
        C_buf_22_ce0,
        C_buf_22_we0,
        C_buf_22_d0,
        C_buf_21_address0,
        C_buf_21_ce0,
        C_buf_21_we0,
        C_buf_21_d0,
        C_buf_20_address0,
        C_buf_20_ce0,
        C_buf_20_we0,
        C_buf_20_d0,
        C_buf_19_address0,
        C_buf_19_ce0,
        C_buf_19_we0,
        C_buf_19_d0,
        C_buf_18_address0,
        C_buf_18_ce0,
        C_buf_18_we0,
        C_buf_18_d0,
        C_buf_17_address0,
        C_buf_17_ce0,
        C_buf_17_we0,
        C_buf_17_d0,
        C_buf_16_address0,
        C_buf_16_ce0,
        C_buf_16_we0,
        C_buf_16_d0,
        C_buf_address0,
        C_buf_ce0,
        C_buf_we0,
        C_buf_d0
);

parameter    ap_ST_fsm_pp0_stage0 = 1'd1;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output   m_axi_merlin_gmem_kernel_gemm_512_C_AWVALID;
input   m_axi_merlin_gmem_kernel_gemm_512_C_AWREADY;
output  [63:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWADDR;
output  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWID;
output  [31:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWLEN;
output  [2:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWSIZE;
output  [1:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWBURST;
output  [1:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWLOCK;
output  [3:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWCACHE;
output  [2:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWPROT;
output  [3:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWQOS;
output  [3:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWREGION;
output  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_AWUSER;
output   m_axi_merlin_gmem_kernel_gemm_512_C_WVALID;
input   m_axi_merlin_gmem_kernel_gemm_512_C_WREADY;
output  [511:0] m_axi_merlin_gmem_kernel_gemm_512_C_WDATA;
output  [63:0] m_axi_merlin_gmem_kernel_gemm_512_C_WSTRB;
output   m_axi_merlin_gmem_kernel_gemm_512_C_WLAST;
output  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_WID;
output  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_WUSER;
output   m_axi_merlin_gmem_kernel_gemm_512_C_ARVALID;
input   m_axi_merlin_gmem_kernel_gemm_512_C_ARREADY;
output  [63:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARADDR;
output  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARID;
output  [31:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARLEN;
output  [2:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARSIZE;
output  [1:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARBURST;
output  [1:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARLOCK;
output  [3:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARCACHE;
output  [2:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARPROT;
output  [3:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARQOS;
output  [3:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARREGION;
output  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_ARUSER;
input   m_axi_merlin_gmem_kernel_gemm_512_C_RVALID;
output   m_axi_merlin_gmem_kernel_gemm_512_C_RREADY;
input  [511:0] m_axi_merlin_gmem_kernel_gemm_512_C_RDATA;
input   m_axi_merlin_gmem_kernel_gemm_512_C_RLAST;
input  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_RID;
input  [8:0] m_axi_merlin_gmem_kernel_gemm_512_C_RFIFONUM;
input  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_RUSER;
input  [1:0] m_axi_merlin_gmem_kernel_gemm_512_C_RRESP;
input   m_axi_merlin_gmem_kernel_gemm_512_C_BVALID;
output   m_axi_merlin_gmem_kernel_gemm_512_C_BREADY;
input  [1:0] m_axi_merlin_gmem_kernel_gemm_512_C_BRESP;
input  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_BID;
input  [0:0] m_axi_merlin_gmem_kernel_gemm_512_C_BUSER;
input  [57:0] sext_ln1705;
output  [8:0] C_buf_30_address0;
output   C_buf_30_ce0;
output   C_buf_30_we0;
output  [31:0] C_buf_30_d0;
output  [8:0] C_buf_29_address0;
output   C_buf_29_ce0;
output   C_buf_29_we0;
output  [31:0] C_buf_29_d0;
output  [8:0] C_buf_28_address0;
output   C_buf_28_ce0;
output   C_buf_28_we0;
output  [31:0] C_buf_28_d0;
output  [8:0] C_buf_27_address0;
output   C_buf_27_ce0;
output   C_buf_27_we0;
output  [31:0] C_buf_27_d0;
output  [8:0] C_buf_26_address0;
output   C_buf_26_ce0;
output   C_buf_26_we0;
output  [31:0] C_buf_26_d0;
output  [8:0] C_buf_25_address0;
output   C_buf_25_ce0;
output   C_buf_25_we0;
output  [31:0] C_buf_25_d0;
output  [8:0] C_buf_24_address0;
output   C_buf_24_ce0;
output   C_buf_24_we0;
output  [31:0] C_buf_24_d0;
output  [8:0] C_buf_23_address0;
output   C_buf_23_ce0;
output   C_buf_23_we0;
output  [31:0] C_buf_23_d0;
output  [8:0] C_buf_22_address0;
output   C_buf_22_ce0;
output   C_buf_22_we0;
output  [31:0] C_buf_22_d0;
output  [8:0] C_buf_21_address0;
output   C_buf_21_ce0;
output   C_buf_21_we0;
output  [31:0] C_buf_21_d0;
output  [8:0] C_buf_20_address0;
output   C_buf_20_ce0;
output   C_buf_20_we0;
output  [31:0] C_buf_20_d0;
output  [8:0] C_buf_19_address0;
output   C_buf_19_ce0;
output   C_buf_19_we0;
output  [31:0] C_buf_19_d0;
output  [8:0] C_buf_18_address0;
output   C_buf_18_ce0;
output   C_buf_18_we0;
output  [31:0] C_buf_18_d0;
output  [8:0] C_buf_17_address0;
output   C_buf_17_ce0;
output   C_buf_17_we0;
output  [31:0] C_buf_17_d0;
output  [8:0] C_buf_16_address0;
output   C_buf_16_ce0;
output   C_buf_16_we0;
output  [31:0] C_buf_16_d0;
output  [8:0] C_buf_address0;
output   C_buf_ce0;
output   C_buf_we0;
output  [31:0] C_buf_d0;

reg ap_idle;
reg m_axi_merlin_gmem_kernel_gemm_512_C_RREADY;
reg C_buf_30_ce0;
reg C_buf_30_we0;
reg C_buf_29_ce0;
reg C_buf_29_we0;
reg C_buf_28_ce0;
reg C_buf_28_we0;
reg C_buf_27_ce0;
reg C_buf_27_we0;
reg C_buf_26_ce0;
reg C_buf_26_we0;
reg C_buf_25_ce0;
reg C_buf_25_we0;
reg C_buf_24_ce0;
reg C_buf_24_we0;
reg C_buf_23_ce0;
reg C_buf_23_we0;
reg C_buf_22_ce0;
reg C_buf_22_we0;
reg C_buf_21_ce0;
reg C_buf_21_we0;
reg C_buf_20_ce0;
reg C_buf_20_we0;
reg C_buf_19_ce0;
reg C_buf_19_we0;
reg C_buf_18_ce0;
reg C_buf_18_we0;
reg C_buf_17_ce0;
reg C_buf_17_we0;
reg C_buf_16_ce0;
reg C_buf_16_we0;
reg C_buf_ce0;
reg C_buf_we0;

(* fsm_encoding = "none" *) reg   [0:0] ap_CS_fsm;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_enable_reg_pp0_iter0;
reg    ap_enable_reg_pp0_iter1;
reg    ap_enable_reg_pp0_iter2;
reg    ap_idle_pp0;
reg    ap_block_state2_pp0_stage0_iter1;
reg    ap_block_pp0_stage0_subdone;
wire   [0:0] icmp_ln1705_fu_401_p2;
reg    ap_condition_exit_pp0_iter0_stage0;
wire    ap_loop_exit_ready;
reg    ap_ready_int;
reg    merlin_gmem_kernel_gemm_512_C_blk_n_R;
wire    ap_block_pp0_stage0;
reg    ap_block_pp0_stage0_11001;
wire   [31:0] raw_bits_fu_424_p1;
reg   [31:0] raw_bits_reg_758;
reg   [31:0] raw_bits_1_reg_763;
reg   [31:0] raw_bits_2_reg_768;
reg   [31:0] raw_bits_3_reg_773;
reg   [31:0] raw_bits_4_reg_778;
reg   [31:0] raw_bits_5_reg_783;
reg   [31:0] raw_bits_6_reg_788;
reg   [31:0] raw_bits_7_reg_793;
reg   [31:0] raw_bits_8_reg_798;
reg   [31:0] raw_bits_9_reg_803;
reg   [31:0] raw_bits_34_reg_808;
reg   [31:0] raw_bits_35_reg_813;
reg   [31:0] raw_bits_36_reg_818;
reg   [31:0] raw_bits_37_reg_823;
reg   [31:0] raw_bits_38_reg_828;
reg   [31:0] raw_bits_39_reg_833;
wire   [63:0] zext_ln1733_fu_600_p1;
reg   [8:0] i_fu_148;
wire   [8:0] i_7_fu_407_p2;
wire    ap_loop_init;
reg   [8:0] ap_sig_allocacmp_i_6;
reg   [8:0] index3_fu_152;
wire   [8:0] index3_7_fu_702_p3;
reg   [63:0] index2_fu_156;
wire   [63:0] index2_8_fu_710_p3;
wire   [8:0] shl_ln1733_fu_584_p2;
wire   [8:0] trunc_ln1705_fu_590_p1;
wire   [8:0] add_ln1733_fu_594_p2;
wire   [0:0] icmp_ln1737_fu_684_p2;
wire   [8:0] index3_6_fu_690_p2;
wire   [63:0] index2_7_fu_696_p2;
reg    ap_done_reg;
wire    ap_continue_int;
reg    ap_done_int;
reg    ap_loop_exit_ready_pp0_iter1_reg;
reg   [0:0] ap_NS_fsm;
wire    ap_enable_pp0;
wire    ap_start_int;
wire    ap_ce_reg;

// power-on initialization
initial begin
#0 ap_CS_fsm = 1'd1;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 i_fu_148 = 9'd0;
#0 index3_fu_152 = 9'd0;
#0 index2_fu_156 = 64'd0;
#0 ap_done_reg = 1'b0;
end

kernel_gemm_flow_control_loop_pipe_sequential_init flow_control_loop_pipe_sequential_init_U(
    .ap_clk(ap_clk),
    .ap_rst(ap_rst),
    .ap_start(ap_start),
    .ap_ready(ap_ready),
    .ap_done(ap_done),
    .ap_start_int(ap_start_int),
    .ap_loop_init(ap_loop_init),
    .ap_ready_int(ap_ready_int),
    .ap_loop_exit_ready(ap_condition_exit_pp0_iter0_stage0),
    .ap_loop_exit_done(ap_done_int),
    .ap_continue_int(ap_continue_int),
    .ap_done_int(ap_done_int)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_pp0_stage0;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_done_reg <= 1'b0;
    end else begin
        if ((ap_continue_int == 1'b1)) begin
            ap_done_reg <= 1'b0;
        end else if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_loop_exit_ready_pp0_iter1_reg == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_done_reg <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if ((1'b1 == ap_condition_exit_pp0_iter0_stage0)) begin
            ap_enable_reg_pp0_iter1 <= 1'b0;
        end else if (((1'b0 == ap_block_pp0_stage0_subdone) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            ap_enable_reg_pp0_iter1 <= ap_start_int;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((1'b0 == ap_block_pp0_stage0_subdone)) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        if (((icmp_ln1705_fu_401_p2 == 1'd0) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
            i_fu_148 <= i_7_fu_407_p2;
        end else if ((ap_loop_init == 1'b1)) begin
            i_fu_148 <= 9'd0;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b0 == ap_block_pp0_stage0_11001)) begin
        if (((ap_loop_init == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            index2_fu_156 <= 64'd0;
        end else if ((ap_enable_reg_pp0_iter2 == 1'b1)) begin
            index2_fu_156 <= index2_8_fu_710_p3;
        end
    end
end

always @ (posedge ap_clk) begin
    if ((1'b0 == ap_block_pp0_stage0_11001)) begin
        if (((ap_loop_init == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
            index3_fu_152 <= 9'd0;
        end else if ((ap_enable_reg_pp0_iter2 == 1'b1)) begin
            index3_fu_152 <= index3_7_fu_702_p3;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_loop_exit_ready_pp0_iter1_reg <= ap_loop_exit_ready;
        raw_bits_1_reg_763 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[63:32]}};
        raw_bits_2_reg_768 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[95:64]}};
        raw_bits_34_reg_808 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[351:320]}};
        raw_bits_35_reg_813 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[383:352]}};
        raw_bits_36_reg_818 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[415:384]}};
        raw_bits_37_reg_823 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[447:416]}};
        raw_bits_38_reg_828 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[479:448]}};
        raw_bits_39_reg_833 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[511:480]}};
        raw_bits_3_reg_773 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[127:96]}};
        raw_bits_4_reg_778 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[159:128]}};
        raw_bits_5_reg_783 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[191:160]}};
        raw_bits_6_reg_788 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[223:192]}};
        raw_bits_7_reg_793 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[255:224]}};
        raw_bits_8_reg_798 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[287:256]}};
        raw_bits_9_reg_803 <= {{m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[319:288]}};
        raw_bits_reg_758 <= raw_bits_fu_424_p1;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_16_ce0 = 1'b1;
    end else begin
        C_buf_16_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_16_we0 = 1'b1;
    end else begin
        C_buf_16_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_17_ce0 = 1'b1;
    end else begin
        C_buf_17_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_17_we0 = 1'b1;
    end else begin
        C_buf_17_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_18_ce0 = 1'b1;
    end else begin
        C_buf_18_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_18_we0 = 1'b1;
    end else begin
        C_buf_18_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_19_ce0 = 1'b1;
    end else begin
        C_buf_19_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_19_we0 = 1'b1;
    end else begin
        C_buf_19_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_20_ce0 = 1'b1;
    end else begin
        C_buf_20_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_20_we0 = 1'b1;
    end else begin
        C_buf_20_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_21_ce0 = 1'b1;
    end else begin
        C_buf_21_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_21_we0 = 1'b1;
    end else begin
        C_buf_21_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_22_ce0 = 1'b1;
    end else begin
        C_buf_22_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_22_we0 = 1'b1;
    end else begin
        C_buf_22_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_23_ce0 = 1'b1;
    end else begin
        C_buf_23_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_23_we0 = 1'b1;
    end else begin
        C_buf_23_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_24_ce0 = 1'b1;
    end else begin
        C_buf_24_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_24_we0 = 1'b1;
    end else begin
        C_buf_24_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_25_ce0 = 1'b1;
    end else begin
        C_buf_25_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_25_we0 = 1'b1;
    end else begin
        C_buf_25_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_26_ce0 = 1'b1;
    end else begin
        C_buf_26_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_26_we0 = 1'b1;
    end else begin
        C_buf_26_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_27_ce0 = 1'b1;
    end else begin
        C_buf_27_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_27_we0 = 1'b1;
    end else begin
        C_buf_27_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_28_ce0 = 1'b1;
    end else begin
        C_buf_28_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_28_we0 = 1'b1;
    end else begin
        C_buf_28_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_29_ce0 = 1'b1;
    end else begin
        C_buf_29_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_29_we0 = 1'b1;
    end else begin
        C_buf_29_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_30_ce0 = 1'b1;
    end else begin
        C_buf_30_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_30_we0 = 1'b1;
    end else begin
        C_buf_30_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_ce0 = 1'b1;
    end else begin
        C_buf_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        C_buf_we0 = 1'b1;
    end else begin
        C_buf_we0 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln1705_fu_401_p2 == 1'd1) & (1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_condition_exit_pp0_iter0_stage0 = 1'b1;
    end else begin
        ap_condition_exit_pp0_iter0_stage0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_loop_exit_ready_pp0_iter1_reg == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_done_int = 1'b1;
    end else begin
        ap_done_int = ap_done_reg;
    end
end

always @ (*) begin
    if (((ap_start_int == 1'b0) & (ap_idle_pp0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_subdone) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_ready_int = 1'b1;
    end else begin
        ap_ready_int = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_loop_init == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        ap_sig_allocacmp_i_6 = 9'd0;
    end else begin
        ap_sig_allocacmp_i_6 = i_fu_148;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        m_axi_merlin_gmem_kernel_gemm_512_C_RREADY = 1'b1;
    end else begin
        m_axi_merlin_gmem_kernel_gemm_512_C_RREADY = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        merlin_gmem_kernel_gemm_512_C_blk_n_R = m_axi_merlin_gmem_kernel_gemm_512_C_RVALID;
    end else begin
        merlin_gmem_kernel_gemm_512_C_blk_n_R = 1'b1;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_pp0_stage0 : begin
            ap_NS_fsm = ap_ST_fsm_pp0_stage0;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign C_buf_16_address0 = zext_ln1733_fu_600_p1;

assign C_buf_16_d0 = raw_bits_1_reg_763;

assign C_buf_17_address0 = zext_ln1733_fu_600_p1;

assign C_buf_17_d0 = raw_bits_2_reg_768;

assign C_buf_18_address0 = zext_ln1733_fu_600_p1;

assign C_buf_18_d0 = raw_bits_3_reg_773;

assign C_buf_19_address0 = zext_ln1733_fu_600_p1;

assign C_buf_19_d0 = raw_bits_4_reg_778;

assign C_buf_20_address0 = zext_ln1733_fu_600_p1;

assign C_buf_20_d0 = raw_bits_5_reg_783;

assign C_buf_21_address0 = zext_ln1733_fu_600_p1;

assign C_buf_21_d0 = raw_bits_6_reg_788;

assign C_buf_22_address0 = zext_ln1733_fu_600_p1;

assign C_buf_22_d0 = raw_bits_7_reg_793;

assign C_buf_23_address0 = zext_ln1733_fu_600_p1;

assign C_buf_23_d0 = raw_bits_8_reg_798;

assign C_buf_24_address0 = zext_ln1733_fu_600_p1;

assign C_buf_24_d0 = raw_bits_9_reg_803;

assign C_buf_25_address0 = zext_ln1733_fu_600_p1;

assign C_buf_25_d0 = raw_bits_34_reg_808;

assign C_buf_26_address0 = zext_ln1733_fu_600_p1;

assign C_buf_26_d0 = raw_bits_35_reg_813;

assign C_buf_27_address0 = zext_ln1733_fu_600_p1;

assign C_buf_27_d0 = raw_bits_36_reg_818;

assign C_buf_28_address0 = zext_ln1733_fu_600_p1;

assign C_buf_28_d0 = raw_bits_37_reg_823;

assign C_buf_29_address0 = zext_ln1733_fu_600_p1;

assign C_buf_29_d0 = raw_bits_38_reg_828;

assign C_buf_30_address0 = zext_ln1733_fu_600_p1;

assign C_buf_30_d0 = raw_bits_39_reg_833;

assign C_buf_address0 = zext_ln1733_fu_600_p1;

assign C_buf_d0 = raw_bits_reg_758;

assign add_ln1733_fu_594_p2 = (shl_ln1733_fu_584_p2 + trunc_ln1705_fu_590_p1);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd0];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

always @ (*) begin
    ap_block_pp0_stage0_11001 = ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_block_state2_pp0_stage0_iter1));
end

always @ (*) begin
    ap_block_pp0_stage0_subdone = ((ap_enable_reg_pp0_iter1 == 1'b1) & (1'b1 == ap_block_state2_pp0_stage0_iter1));
end

always @ (*) begin
    ap_block_state2_pp0_stage0_iter1 = (m_axi_merlin_gmem_kernel_gemm_512_C_RVALID == 1'b0);
end

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign ap_enable_reg_pp0_iter0 = ap_start_int;

assign ap_loop_exit_ready = ap_condition_exit_pp0_iter0_stage0;

assign i_7_fu_407_p2 = (ap_sig_allocacmp_i_6 + 9'd1);

assign icmp_ln1705_fu_401_p2 = ((ap_sig_allocacmp_i_6 == 9'd400) ? 1'b1 : 1'b0);

assign icmp_ln1737_fu_684_p2 = ((index2_fu_156 == 64'd3) ? 1'b1 : 1'b0);

assign index2_7_fu_696_p2 = (index2_fu_156 + 64'd1);

assign index2_8_fu_710_p3 = ((icmp_ln1737_fu_684_p2[0:0] == 1'b1) ? 64'd0 : index2_7_fu_696_p2);

assign index3_6_fu_690_p2 = (index3_fu_152 + 9'd1);

assign index3_7_fu_702_p3 = ((icmp_ln1737_fu_684_p2[0:0] == 1'b1) ? index3_6_fu_690_p2 : index3_fu_152);

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARADDR = 64'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARBURST = 2'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARCACHE = 4'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARID = 1'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARLEN = 32'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARLOCK = 2'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARPROT = 3'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARQOS = 4'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARREGION = 4'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARSIZE = 3'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARUSER = 1'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_ARVALID = 1'b0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWADDR = 64'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWBURST = 2'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWCACHE = 4'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWID = 1'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWLEN = 32'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWLOCK = 2'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWPROT = 3'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWQOS = 4'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWREGION = 4'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWSIZE = 3'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWUSER = 1'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_AWVALID = 1'b0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_BREADY = 1'b0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_WDATA = 512'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_WID = 1'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_WLAST = 1'b0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_WSTRB = 64'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_WUSER = 1'd0;

assign m_axi_merlin_gmem_kernel_gemm_512_C_WVALID = 1'b0;

assign raw_bits_fu_424_p1 = m_axi_merlin_gmem_kernel_gemm_512_C_RDATA[31:0];

assign shl_ln1733_fu_584_p2 = index3_fu_152 << 9'd2;

assign trunc_ln1705_fu_590_p1 = index2_fu_156[8:0];

assign zext_ln1733_fu_600_p1 = add_ln1733_fu_594_p2;

endmodule //kernel_gemm_kernel_gemm_Pipeline_L2