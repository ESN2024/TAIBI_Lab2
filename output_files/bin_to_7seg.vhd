LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY bin_to_7seg IS
PORT (Entree_seg:IN STD_LOGIC_VECTOR(3 DOWNTO 0);
		Sortie_seg:OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
		);
END bin_to_7seg;

ARCHITECTURE RTL OF bin_to_7seg IS
BEGIN
	PROCESS (Entree_seg)
	BEGIN
			CASE Entree_seg IS
			WHEN "0000"=> Sortie_seg<="1000000";
			WHEN "0001"=> Sortie_seg<="1111001";
			WHEN "0010"=> Sortie_seg<="0100100";
			WHEN "0011"=> Sortie_seg<="0110000";
			WHEN "0100"=> Sortie_seg<="0011001";
			WHEN "0101"=> Sortie_seg<="0010010";
			WHEN "0110"=> Sortie_seg<="0000010";
			WHEN "0111"=> Sortie_seg<="1111000";
			WHEN "1000"=> Sortie_seg<="0000000";
			WHEN "1001"=> Sortie_seg<="0010000";
			WHEN "1010"=> Sortie_seg<="0001000";
			WHEN "1011"=> Sortie_seg<="0000011";
			WHEN "1100"=> Sortie_seg<="1000110";
			WHEN "1101"=> Sortie_seg<="0100001";
			WHEN "1110"=> Sortie_seg<="0000110";
			WHEN "1111"=> Sortie_seg<="0001110";
			WHEN OTHERS=> Sortie_seg<="0111111";
			END CASE;
	END PROCESS;
END RTL;