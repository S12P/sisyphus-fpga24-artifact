set ModuleHierarchy {[{
"Name" : "kernel_gemm","ID" : "0","Type" : "sequential",
"SubInsts" : [
	{"Name" : "grp_kernel_gemm_Pipeline_L2_fu_6991","ID" : "1","Type" : "sequential",
		"SubLoops" : [
		{"Name" : "L2","ID" : "2","Type" : "pipeline"},]},
	{"Name" : "grp_kernel_gemm_Pipeline_L21_fu_7014","ID" : "3","Type" : "sequential",
		"SubLoops" : [
		{"Name" : "L2","ID" : "4","Type" : "pipeline"},]},
	{"Name" : "grp_kernel_gemm_Pipeline_L22_fu_7121","ID" : "5","Type" : "sequential",
		"SubLoops" : [
		{"Name" : "L2","ID" : "6","Type" : "pipeline"},]},
	{"Name" : "grp_kernel_gemm_Pipeline_merlinL3_merlinL2_fu_8728","ID" : "7","Type" : "sequential",
		"SubLoops" : [
		{"Name" : "merlinL3_merlinL2","ID" : "8","Type" : "pipeline"},]},
	{"Name" : "grp_kernel_gemm_Pipeline_L3_fu_10448","ID" : "9","Type" : "sequential",
		"SubLoops" : [
		{"Name" : "L3","ID" : "10","Type" : "pipeline"},]},]
}]}