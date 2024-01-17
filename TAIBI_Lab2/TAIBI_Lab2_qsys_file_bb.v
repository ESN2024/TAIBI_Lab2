
module TAIBI_Lab2_qsys_file (
	clk_clk,
	digit_1_external_connection_export,
	digit_2_external_connection_export,
	digit_3_external_connection_export,
	reset_reset_n,
	start_external_connection_export);	

	input		clk_clk;
	output	[3:0]	digit_1_external_connection_export;
	output	[3:0]	digit_2_external_connection_export;
	output	[3:0]	digit_3_external_connection_export;
	input		reset_reset_n;
	input		start_external_connection_export;
endmodule
