library IEEE;
use IEEE.std_logic_1164.all;

entity tb_MaquinaEstados is
end tb_MaquinaEstados;

architecture tb_MaquinaEstados_arch of tb_MaquinaEstados is
    component MaquinaEstados
        port (
            entrada : in std_logic;
            clk : in std_logic;
            resetHigh : in std_logic;
            salida : out std_logic
        );
    end component;

    signal tb_entrada : std_logic := '0';
    signal tb_clk : std_logic := '0';
    signal tb_resetHigh : std_logic := '0';
    signal tb_salida : std_logic;

    constant CLK_PERIOD : time := 10 ns;

begin
    UUT : MaquinaEstados
        port map (
            entrada => tb_entrada,
            clk => tb_clk,
            resetHigh => tb_resetHigh,
            salida => tb_salida
        );

    -- Generador de reloj
    clk_process : process
    begin
        loop
            tb_clk <= '0';
            wait for CLK_PERIOD/2;
            tb_clk <= '1';
            wait for CLK_PERIOD/2;
        end loop;
    end process;

    -- Proceso para la secuencia de estímulos
    stim_process: process
    begin
        -- Reset de la máquina de estados
        tb_resetHigh <= '1';
        wait for 10 ns;
        tb_resetHigh <= '0';
        wait for 10 ns;

        -- Secuencia para alcanzar E2 (donde la salida será '1')
        tb_entrada <= '1';    -- Pasar de E0 a E1
        wait for 20 ns;
        
        -- En este momento la máquina debe estar en E2 y la salida debe ser '1'
        assert tb_salida = '1' report "Error en la salida: debería ser '1' en E2 con entrada '1'" severity error;

        tb_entrada <= '0';    -- Pasar de E2 a E4
        wait for 10 ns;
 		
        tb_entrada <= '1';    -- Pasar de E4 a E1	
        wait for 20 ns;

        -- Esperar un ciclo de reloj adicional para que la salida se actualice
        wait for CLK_PERIOD;

        -- Continuar la simulación
        tb_entrada <= '0';   -- Pasar de E2 a E4 (la salida debe regresar a '0')
        wait for 10 ns;
        
        assert tb_salida = '1' report "Error en la salida: debería ser '1' en E2 con entrada '1'" severity error;
        assert tb_salida = '0' report "Error en la salida: debería ser '0' después de E2" severity error;

        wait for 10 ns;
    end process;

end tb_MaquinaEstados_arch;