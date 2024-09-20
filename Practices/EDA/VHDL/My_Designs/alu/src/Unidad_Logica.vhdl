library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all; -- Se reemplazan std_logic_arith y std_logic_unsigned

entity Unidad_Logica is
	port (	A, B: in std_logic_vector(7 downto 0);
			cod_ope: in std_logic_vector(3 downto 0);
			salidaUL: out std_logic_vector(7 downto 0));
end Unidad_Logica;	 

architecture Comp_Log of Unidad_Logica is
begin
	calculos_logicos:
	process(A, B, cod_ope) 
	begin
		case cod_ope(3 downto 0) is
			when "1000" => salidaUL <= not(A);
			when "1001" => salidaUL <= not(B);	
			when "1010" => salidaUL <= A and B;	
			when "1011" => salidaUL <= A or B;	
			when "1100" => salidaUL <= A nand B;
			when "1101" => salidaUL <= A nor B;	
			when "1110" => salidaUL <= A xor B;	
			when others => salidaUL <= not(A xor B);	
		 end case;
	end process calculos_logicos;	
end Comp_Log;