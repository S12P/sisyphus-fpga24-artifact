set clock_constraint { \
    name clk \
    module kernel_gemm \
    port ap_clk \
    period 4 \
    uncertainty 1.08 \
}

set all_path {}

set false_path {}

