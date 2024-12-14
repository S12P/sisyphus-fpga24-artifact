set SynModuleInfo {
  {SRCNAME kernel_gemm_Pipeline_L2 MODELNAME kernel_gemm_Pipeline_L2 RTLNAME kernel_gemm_kernel_gemm_Pipeline_L2
    SUBMODULES {
      {MODELNAME kernel_gemm_flow_control_loop_pipe_sequential_init RTLNAME kernel_gemm_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME kernel_gemm_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME kernel_gemm_Pipeline_L21 MODELNAME kernel_gemm_Pipeline_L21 RTLNAME kernel_gemm_kernel_gemm_Pipeline_L21}
  {SRCNAME kernel_gemm_Pipeline_L22 MODELNAME kernel_gemm_Pipeline_L22 RTLNAME kernel_gemm_kernel_gemm_Pipeline_L22}
  {SRCNAME kernel_gemm_Pipeline_merlinL3_merlinL2 MODELNAME kernel_gemm_Pipeline_merlinL3_merlinL2 RTLNAME kernel_gemm_kernel_gemm_Pipeline_merlinL3_merlinL2
    SUBMODULES {
      {MODELNAME kernel_gemm_fadd_32ns_32ns_32_7_full_dsp_1 RTLNAME kernel_gemm_fadd_32ns_32ns_32_7_full_dsp_1 BINDTYPE op TYPE fadd IMPL fulldsp LATENCY 6 ALLOW_PRAGMA 1}
      {MODELNAME kernel_gemm_fmul_32ns_32ns_32_4_max_dsp_1 RTLNAME kernel_gemm_fmul_32ns_32ns_32_4_max_dsp_1 BINDTYPE op TYPE fmul IMPL maxdsp LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME kernel_gemm_mux_4_2_32_1_1 RTLNAME kernel_gemm_mux_4_2_32_1_1 BINDTYPE op TYPE mux IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
    }
  }
  {SRCNAME kernel_gemm_Pipeline_L3 MODELNAME kernel_gemm_Pipeline_L3 RTLNAME kernel_gemm_kernel_gemm_Pipeline_L3}
  {SRCNAME kernel_gemm MODELNAME kernel_gemm RTLNAME kernel_gemm IS_TOP 1
    SUBMODULES {
      {MODELNAME kernel_gemm_A_5_0_buf_RAM_AUTO_1R1W RTLNAME kernel_gemm_A_5_0_buf_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME kernel_gemm_C_buf_RAM_AUTO_1R1W RTLNAME kernel_gemm_C_buf_RAM_AUTO_1R1W BINDTYPE storage TYPE ram IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME kernel_gemm_merlin_gmem_kernel_gemm_512_C_m_axi RTLNAME kernel_gemm_merlin_gmem_kernel_gemm_512_C_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME kernel_gemm_merlin_gmem_kernel_gemm_128_0_m_axi RTLNAME kernel_gemm_merlin_gmem_kernel_gemm_128_0_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME kernel_gemm_merlin_gmem_kernel_gemm_512_0_m_axi RTLNAME kernel_gemm_merlin_gmem_kernel_gemm_512_0_m_axi BINDTYPE interface TYPE adapter IMPL m_axi}
      {MODELNAME kernel_gemm_control_s_axi RTLNAME kernel_gemm_control_s_axi BINDTYPE interface TYPE interface_s_axilite}
    }
  }
}
