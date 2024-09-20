library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity tb_ALU is
end tb_ALU;

architecture testbench of tb_ALU is
    -- Declaración de señales
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
    -- Mapear señales a la instancia de la ALU
    uut: ALU
        port map (
            A => tb_A,
            B => tb_B,
            cod_ope => tb_cod_ope,
            CarryIn => tb_CarryIn,
            CarryOut => tb_CarryOut,
            resultado => tb_resultado
        );

    -- Proceso de estímulos
    stimulus_process: process
    begin
        -- Inicialización
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
        tb_cod_ope <= "1000"; -- Operación lógica: NOT A
        wait for 10 ns;

        -- Prueba: A AND B
        tb_cod_ope <= "1010"; -- Operación lógica: A AND B
        wait for 10 ns;

        -- Prueba: A XOR B
        tb_cod_ope <= "1110"; -- Operación lógica: A XOR B
        wait for 10 ns;

        -- Finalización de la simulación
        wait;
    end process;
end testbench;