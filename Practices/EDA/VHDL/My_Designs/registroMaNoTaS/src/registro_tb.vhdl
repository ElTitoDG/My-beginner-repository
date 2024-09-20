library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity tb_registroMaNoTaS is
end tb_registroMaNoTaS;

architecture testbench of tb_registroMaNoTaS is
    -- Señales para conectar al DUT (Device Under Test - Dispositivo bajo prueba)
    signal tb_SelectReg : std_logic_vector(1 downto 0);
    signal tb_LoadReg : std_logic;
    signal tb_SelectedReg : std_logic;
    signal tb_clk : std_logic := '0';
    signal tb_reset : std_logic;
    signal tb_entrada : std_logic_vector(7 downto 0);
    signal tb_salida : std_logic_vector(7 downto 0);
    
    -- Constante para el periodo de reloj
    constant clk_period : time := 10 ns;
    
begin
    -- Instancia del DUT
    dut: entity work.registroMaNoTaS
        port map (
            SelectReg => tb_SelectReg,
            LoadReg => tb_LoadReg,
            SelectedReg => tb_SelectedReg,
            clk => tb_clk,
            reset => tb_reset,
            entrada => tb_entrada,
            salida => tb_salida
        );

    -- Proceso del reloj
    clk_process : process
    begin
        while now < 200 ns loop  -- Extiende el tiempo de simulación para abarcar los 4 registros
            tb_clk <= '0';
            wait for clk_period / 2;
            tb_clk <= '1';
            wait for clk_period / 2;
        end loop;
        wait;
    end process;

    -- Proceso de estímulos
    stimulus : process
    begin
        -- Resetear el sistema
        tb_reset <= '1';
        wait for 20 ns;
        tb_reset <= '0';

        -- Escribir en el registro 0
        tb_SelectReg <= "00";
        tb_LoadReg <= '1';
        tb_entrada <= "10101010";  -- Valor de entrada para el registro 0
        wait for clk_period;
        tb_LoadReg <= '0';
        wait for clk_period;

        -- Escribir en el registro 1
        tb_SelectReg <= "01";
        tb_LoadReg <= '1';
        tb_entrada <= "11001100";  -- Valor de entrada para el registro 1
        wait for clk_period;
        tb_LoadReg <= '0';
        wait for clk_period;

        -- Escribir en el registro 2
        tb_SelectReg <= "10";
        tb_LoadReg <= '1';
        tb_entrada <= "11110000";  -- Valor de entrada para el registro 2
        wait for clk_period;
        tb_LoadReg <= '0';
        wait for clk_period;

        -- Escribir en el registro 3
        tb_SelectReg <= "11";
        tb_LoadReg <= '1';
        tb_entrada <= "00001111";  -- Valor de entrada para el registro 3
        wait for clk_period;
        tb_LoadReg <= '0';
        wait for clk_period;

        -- Leer del registro 0
        tb_SelectReg <= "00";
        tb_SelectedReg <= '1';
        wait for clk_period;
        tb_SelectedReg <= '0';
        wait for clk_period;

        -- Leer del registro 1
        tb_SelectReg <= "01";
        tb_SelectedReg <= '1';
        wait for clk_period;
        tb_SelectedReg <= '0';
        wait for clk_period;

        -- Leer del registro 2
        tb_SelectReg <= "10";
        tb_SelectedReg <= '1';
        wait for clk_period;
        tb_SelectedReg <= '0';
        wait for clk_period;

        -- Leer del registro 3
        tb_SelectReg <= "11";
        tb_SelectedReg <= '1';
        wait for clk_period;
        tb_SelectedReg <= '0';
        wait for clk_period;

        -- Finalizar simulación después de leer y escribir en los 4 registros
        wait for 50 ns;
        wait;
    end process;

end testbench;