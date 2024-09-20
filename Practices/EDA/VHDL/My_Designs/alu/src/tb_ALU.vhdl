library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity tb_ALU is
end tb_ALU;

architecture testbench of tb_ALU is
    -- Declaracion de senales
    signal tb_A, tb_B: std_logic_vector(7 downto 0);
    signal tb_cod_ope: std_logic_vector(3 downto 0);
    signal tb_CarryIn, tb_CarryOut: std_logic;
    signal tb_resultado: std_logic_vector(7 downto 0);

    -- Instancia de la ALU
    component ALU
        port (
            A, B: in std_logic_vector(7 downto 0);
            cod_ope: in std_logic_vector(3 downto 0);
            CarryIn: in std_logic;
            CarryOut: out std_logic;
            resultado: out std_logic_vector(7 downto 0)
        );
    end component;

begin
    -- Mapear se�ales a la instancia de la ALU
    uut: ALU
        port map (
            A => tb_A,
            B => tb_B,
            cod_ope => tb_cod_ope,
            CarryIn => tb_CarryIn,
            CarryOut => tb_CarryOut,
            resultado => tb_resultado
        );

    -- Proceso de est�mulos
    stimulus_process: process
    begin
        -- Inicializaci�n
        tb_A <= (others => '0');
        tb_B <= (others => '0');
        tb_cod_ope <= (others => '0');
        tb_CarryIn <= '0';
        wait for 10 ns;

        -- Prueba: A - B (sin CarryIn)
		tb_A <= "00000011";   -- A = 3
		tb_B <= "00000101";   -- B = 5
        tb_cod_ope <= "0110"; -- Suma: A - B
        wait for 10 ns;

        -- Prueba: A + B + CarryIn
        tb_CarryIn <= '1';    -- CarryIn = 1
        wait for 10 ns;

        -- Prueba: A - 1
        tb_cod_ope <= "0010"; -- Resta: A - 1
        wait for 10 ns;

        -- Prueba: NOT A
        tb_cod_ope <= "1000"; -- Operaci�n l�gica: NOT A
        wait for 10 ns;

        -- Prueba: A AND B
        tb_cod_ope <= "1010"; -- Operaci�n l�gica: A AND B
        wait for 10 ns;

        -- Prueba: A XOR B
        tb_cod_ope <= "1110"; -- Operaci�n l�gica: A XOR B
        wait for 10 ns;

        -- Finalizaci�n de la simulaci�n
        wait;
    end process;
end testbench;