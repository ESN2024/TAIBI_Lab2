	component TAIBI_Lab2_qsys_file is
		port (
			clk_clk                            : in  std_logic                    := 'X'; -- clk
			digit_1_external_connection_export : out std_logic_vector(3 downto 0);        -- export
			digit_2_external_connection_export : out std_logic_vector(3 downto 0);        -- export
			digit_3_external_connection_export : out std_logic_vector(3 downto 0);        -- export
			reset_reset_n                      : in  std_logic                    := 'X'; -- reset_n
			start_external_connection_export   : in  std_logic                    := 'X'  -- export
		);
	end component TAIBI_Lab2_qsys_file;

	u0 : component TAIBI_Lab2_qsys_file
		port map (
			clk_clk                            => CONNECTED_TO_clk_clk,                            --                         clk.clk
			digit_1_external_connection_export => CONNECTED_TO_digit_1_external_connection_export, -- digit_1_external_connection.export
			digit_2_external_connection_export => CONNECTED_TO_digit_2_external_connection_export, -- digit_2_external_connection.export
			digit_3_external_connection_export => CONNECTED_TO_digit_3_external_connection_export, -- digit_3_external_connection.export
			reset_reset_n                      => CONNECTED_TO_reset_reset_n,                      --                       reset.reset_n
			start_external_connection_export   => CONNECTED_TO_start_external_connection_export    --   start_external_connection.export
		);

