library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity tb_expendedor_examen is
end tb_expendedor_examen;

architecture testbench of tb_expendedor_examen is
    -- Señales para conectar con la unidad bajo prueba (UUT)
    signal tb_clk, tb_reset: std_logic := '0';
    signal tb_cent5, tb_cent10, tb_cent25: std_logic := '0';
    signal tb_Nestado: std_logic_vector(5 downto 0);
    signal tb_saleExamen, tb_dev5, tb_dev10: std_logic;
    
    -- Periodo de reloj
    constant clk_period : time := 10 ns;

begin
    -- Instancia de la UUT (Unidad Bajo Prueba)
    uut: entity work.expendedor_examen
        port map (
            clk => tb_clk,
            reset => tb_reset,
            cent5 => tb_cent5,
            cent10 => tb_cent10,
            cent25 => tb_cent25,
            Nestado => tb_Nestado,
            saleExamen => tb_saleExamen,
            dev5 => tb_dev5,
            dev10 => tb_dev10
        );

    -- Proceso para generar el reloj
    clk_process: process
    begin
        while true loop
            tb_clk <= '0';
            wait for clk_period / 2;
            tb_clk <= '1';
            wait for clk_period / 2;
        end loop;
    end process;
    
    -- Proceso de estímulos (prueba de todos los casos)
    stimulus_process: process
    begin
        -- Inicialización
        tb_reset <= '1';
        wait for 20 ns;
        tb_reset <= '0';
        wait for 20 ns;
        
        -- Prueba 1: Ingresar 5 centavos
        tb_cent5 <= '1';
        wait for clk_period;
        tb_cent5 <= '0';
        wait for clk_period;
        
        -- Prueba 2: Ingresar otros 5 centavos (total 10 centavos)
        tb_cent5 <= '1';
        wait for clk_period;
        tb_cent5 <= '0';
        wait for clk_period;
        
        -- Prueba 3: Ingresar 10 centavos (total 20 centavos)
        tb_cent10 <= '1';
        wait for clk_period;
        tb_cent10 <= '0';
        wait for clk_period;
        
        -- Prueba 4: Ingresar 5 centavos (total 25 centavos, sale examen)
        tb_cent5 <= '1';
        wait for clk_period;
        tb_cent5 <= '0';
        wait for clk_period;
        
        -- Prueba 5: Ingresar 25 centavos directamente (sale examen)
        tb_cent25 <= '1';
        wait for clk_period;
        tb_cent25 <= '0';
        wait for clk_period;
        
        -- Prueba 6: Ingresar 10 centavos y luego 25 centavos (debería devolver cambio)
        tb_cent10 <= '1';
        wait for clk_period;
        tb_cent10 <= '0';
        wait for clk_period;
        tb_cent25 <= '1';
        wait for clk_period;
        tb_cent25 <= '0';
        wait for clk_period;
        
        -- Prueba 7: Ingresar 25 centavos y luego otros 25 centavos (debería devolver cambio)
        tb_cent25 <= '1';
        wait for clk_period;
        tb_cent25 <= '0';
        wait for clk_period;
        tb_cent25 <= '1';
        wait for clk_period;
        tb_cent25 <= '0';
        wait for clk_period;
        
        -- Prueba 8: Ingresar varias monedas hasta exceder el valor
        tb_cent5 <= '1';  -- 5 centavos
        wait for clk_period;
        tb_cent5 <= '0';
        wait for clk_period;
        tb_cent10 <= '1';  -- 15 centavos
        wait for clk_period;
        tb_cent10 <= '0';
        wait for clk_period;
        tb_cent25 <= '1';  -- 40 centavos, debería devolver cambio
        wait for clk_period;
        tb_cent25 <= '0';
        wait for clk_period;
        
        -- Finalizar simulación
        wait;
    end process;
    
end architecture testbench;