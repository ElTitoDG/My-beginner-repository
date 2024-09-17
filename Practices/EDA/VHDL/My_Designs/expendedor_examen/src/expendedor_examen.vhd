library IEEE;
use IEEE.std_logic_1164.all;

entity expendedor_examen is
	port (
		clk, reset: in std_logic;
		cent5, cent10, cent25: in std_logic;
		Nestado: out std_logic_vector(5 downto 0);
		saleExamen, dev5, dev10: out std_logic
	);
end expendedor_examen;

architecture maquinaEstadoFinita of expendedor_examen is
	type estado is (st0, st5, st10, st15, st20, st25, st30, st35, st40, st45);
	signal estadoActual, estadoSiguiente: estado;
begin											 
	--Memoria de estado
	mem_estado: process(reset, clk) 
	begin  
	  	if (reset = '1') then
		  	estadoActual <= st0;
		elsif (clk'event and clk = '1') then
			estadoActual <= estadoSiguiente;
		end if;
	end process;
	
	process(estadoActual, cent5, cent10, cent25) 	
	begin  
		case estadoActual is
			when st0 =>
				Nestado <= "000000";
				if (cent5 = '1') then
					estadoSiguiente <= st5;
				elsif (cent10 = '1') then
					estadoSiguiente <= st10;
				elsif (cent25 = '1') then
					estadoSiguiente <= st25;
				else
					estadoSiguiente <= st0;
				end if;
			when st5 =>
				Nestado <= "000101";
				if (cent5 = '1') then
					estadoSiguiente <= st10;
				elsif (cent10 = '1') then
					estadoSiguiente <= st15;
				elsif (cent25 = '1') then
					estadoSiguiente <= st30;
				else
					estadoSiguiente <= st5;
				end if;
			when st10 =>
				Nestado <= "001010";
				if (cent5 = '1') then
					estadoSiguiente <= st15;
				elsif (cent10 = '1') then
					estadoSiguiente <= st20;
				elsif (cent25 = '1') then
					estadoSiguiente <= st35;
				else
					estadoSiguiente <= st10;
				end if;
			when st15 =>
				Nestado <= "001111";
				if (cent5 = '1') then
					estadoSiguiente <= st20;
				elsif (cent10 = '1') then
					estadoSiguiente <= st25;
				elsif (cent25 = '1') then
					estadoSiguiente <= st40;
				else
					estadoSiguiente <= st15;
				end if;
			when st20 =>
				Nestado <= "010100";
				if (cent5 = '1') then
					estadoSiguiente <= st25;
				elsif (cent10 = '1') then
					estadoSiguiente <= st30;
				elsif (cent25 = '1') then
					estadoSiguiente <= st45;
				else
					estadoSiguiente <= st20;
				end if;
			when st25 =>
				Nestado <= "011001";
				estadoSiguiente <= st0;
			when st30 =>
				Nestado <= "011110";
				estadoSiguiente <= st0;
			when st35 =>
				Nestado <= "100011";
				estadoSiguiente <= st0;
			when st40 =>
				Nestado <= "101000";
				estadoSiguiente <= st0;
			when st45 =>
				Nestado <= "101101";
				estadoSiguiente <= st0;
			end case;
	end process;	
	
	--logica de salida
	saleExamen <= 	'1' when estadoActual = st25 else
					'1' when estadoActual = st30 else
					'1' when estadoActual = st35 else
					'1' when estadoActual = st35 else
					'1' when estadoActual = st40 else
					'1' when estadoActual = st45 else
					'0';
	dev5 <=		'1' when estadoActual = st30 else
				'1' when estadoActual = st40 else
				'0';
				
	dev10 <=	'1' when estadoActual = st35 else
				'1' when estadoActual = st40 else
				'1' when estadoActual = st45 else
				'0';	
end maquinaEstadoFinita;