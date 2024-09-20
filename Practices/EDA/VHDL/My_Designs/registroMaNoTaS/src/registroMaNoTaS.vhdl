library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity registroMaNoTaS is
	port (
		SelectReg: in std_logic_vector(1 downto 0);
		LoadReg: in std_logic;
		SelectedReg: in std_logic;
		clk: in std_logic;
		reset: in std_logic;
		entrada: in std_logic_vector(7 downto 0);
		salida: inout std_logic_vector(7 downto 0)
	);
end registroMaNoTaS;

architecture Comportamiento of registroMaNoTaS is	
	subtype registro is  std_logic_vector(7 downto 0);
	type banco is array(0 to 3) of registro;
	signal contenido: banco;
begin
	
	borrar: process(reset) --(inicializar registro) 
	begin  
		if (reset = '1') then
			for i in 0 to 3 loop
				contenido(i) <= (others => 'Z');
			end loop;
		end if;
	end process;
	
	escribir_banco: process(LoadReg, SelectReg, clk, entrada) 
	begin  
		if (clk'event and clk = '1' and LoadReg = '1') then
			contenido(conv_integer(SelectReg)) <= entrada;
		end if;
	end process;
	
	leer_banco: process(SelectReg, SelectedReg)
	begin
		if (SelectedReg = '1') then
			salida <= contenido(conv_integer(SelectReg));
		else
			salida <= (others => 'Z');
		end if;
	end process;
end Comportamiento;