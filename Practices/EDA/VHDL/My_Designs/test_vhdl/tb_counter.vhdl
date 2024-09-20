library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity tb_counter is
end entity;

architecture Behavioral of tb_counter is
    component counter
        Port ( clk : in  STD_LOGIC;
               reset : in  STD_LOGIC;
               count : out  UNSIGNED(3 downto 0));
    end component;

    signal clk : STD_LOGIC := '0';
    signal reset : STD_LOGIC := '0';
    signal count : UNSIGNED(3 downto 0);

    constant clock_period : time := 10 ns;
    constant sim_time : time := 200 ns;

begin
    uut : counter
        port map (clk => clk, reset => reset, count => count);

    clk_process : process
    begin
        clk <= '0';
        wait for clock_period/2;
        clk <= '1';
        wait for clock_period/2;
    end process;

    stim_process : process
    begin
        reset <= '1';
        wait for 10 ns;
        reset <= '0';
        wait for 100 ns;
        reset <= '1';
        wait for 10 ns;
        reset <= '0';
        wait for sim_time - 120 ns; -- Wait until the end of the simulation
    end process;
end Behavioral;