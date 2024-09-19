													   library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity registro_bi_tb is
end registro_bi_tb;

architecture tb of registro_bi_tb is
    component registro_bi
        port (
            entrada: in std_logic_vector(7 downto 0);
            salida: inout std_logic_vector(7 downto 0);
            clear: in std_logic;
            sentido: in std_logic;
            clk: in std_logic
        );
    end component;

    signal entrada_tb : std_logic_vector(7 downto 0) := (others => '0');
    signal salida_tb : std_logic_vector(7 downto 0);
    signal clear_tb : std_logic := '0';
    signal sentido_tb : std_logic := '0';
    signal clk_tb : std_logic := '0';

    constant clk_period : time := 10 ns;

begin
    uut : registro_bi
        port map (
            entrada => entrada_tb,
            salida => salida_tb,
            clear => clear_tb,
            sentido => sentido_tb,
            clk => clk_tb
        );

    clk_process : process
    begin
        clk_tb <= '0';
        wait for clk_period/2;
        clk_tb <= '1';
        wait for clk_period/2;
    end process;

    stim_process : process
    begin
        -- Initialize
        entrada_tb <= "00000000";
        clear_tb <= '1';
        sentido_tb <= '0';
        wait for clk_period;

        -- Test clear
        clear_tb <= '0';
        wait for clk_period;

        -- Test shift right
        entrada_tb <= "10000000";
        sentido_tb <= '0';
        wait for clk_period;

        -- Test shift left
        entrada_tb <= "00000001";
        sentido_tb <= '1';
        wait for clk_period;

        -- Test multiple shifts
        entrada_tb <= "10101010";
        sentido_tb <= '0';
        wait for clk_period;
        sentido_tb <= '1';
        wait for clk_period;

        -- Finish
        wait;
    end process;
end tb;