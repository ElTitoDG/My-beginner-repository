library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity registro_bi is
	port (
		entrada: in std_logic_vector(7 downto 0);
		salida: inout std_logic_vector(7 downto 0);
		clear: in std_logic;
		sentido: in std_logic;
		clk: in std_logic
	);
end registro_bi;

architecture Comp_registro_bi of registro_bi is
begin
	desplazar: process(entrada, clear, sentido, clk) 
	begin  
		if (clk'event) then
			if (clear = '1') then
				for i in 0 to salida'high loop
					salida(i) <= '0';
				end loop;
			elsif (sentido = '0') then
				salida(salida'high) <= '0';
				for i in 0 to entrada'high-1 loop
					salida(i) <= entrada(i+1);
				end loop;
			else
				salida(0) <= '0';
				for i in 1 to entrada'high loop
					salida(i) <= entrada(i-1);
				end loop;
			end if;
		end if;
	end process;
end Comp_registro_bi;