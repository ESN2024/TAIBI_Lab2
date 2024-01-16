Library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;


entity TAIBI_Lab2 is
	port (
	clk : in std_logic;
	reset : in std_logic;
	start : in std_logic;
	leds_digit_1 : out std_logic_vector(6 downto 0);
	leds_digit_2 : out std_logic_vector(6 downto 0);
	leds_digit_3 : out std_logic_vector(6 downto 0)
	);
end entity TAIBI_Lab2;

architecture behav of TAIBI_Lab2 is


	component bin_to_7seg is
		PORT (Entree_seg:IN STD_LOGIC_VECTOR(3 DOWNTO 0);
				Sortie_seg:OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
				);
	end component bin_to_7seg;

    component TAIBI_Lab2_qsys_file is
        port (
            clk_clk                            : in  std_logic                    := 'X'; -- clk
            digit_1_external_connection_export : out std_logic_vector(3 downto 0);        -- export
            reset_reset_n                      : in  std_logic                    := 'X'; -- reset_n
            start_external_connection_export   : in  std_logic                    := 'X'; -- export
            digit_2_external_connection_export : out std_logic_vector(3 downto 0);        -- export
            digit_3_external_connection_export : out std_logic_vector(3 downto 0)         -- export
        );
    end component TAIBI_Lab2_qsys_file;

	signal digit2_seg_1: std_logic_vector(3 downto 0);
	signal digit2_seg_2: std_logic_vector(3 downto 0);
	signal digit2_seg_3: std_logic_vector(3 downto 0);


	begin
	
    u0 : component TAIBI_Lab2_qsys_file
        port map (
            clk_clk                            => clk,                            --                         clk.clk
            digit_1_external_connection_export => digit2_seg_1, -- digit_1_external_connection.export
            reset_reset_n                      => reset,                      --                       reset.reset_n
            start_external_connection_export   => start,   --   start_external_connection.export
            digit_2_external_connection_export => digit2_seg_2, -- digit_2_external_connection.export
            digit_3_external_connection_export => digit2_seg_3  -- digit_3_external_connection.export
        );
	 u1 : bin_to_7seg port map(digit2_seg_1,leds_digit_1);
	 u2 : bin_to_7seg port map(digit2_seg_2,leds_digit_2);
	 u3 : bin_to_7seg port map(digit2_seg_3,leds_digit_3);


			
end architecture behav;
