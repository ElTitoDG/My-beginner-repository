library ieee;
use ieee.std_logic_1164.all;

entity ha_testbench is
end entity;

architecture test of ha_testbench is
    component ha
        port (
            a: in std_logic;
            b: in std_logic;
            o: out std_logic;
            c: out std_logic 
        );
    end component;

    signal A, B, result, carry: std_logic;
begin
    half_adder: ha port map (a => A, b => B, c => carry, o => result);

    process begin
        
    
        a <= 'X';
        b <= 'X';
        wait for 1 ns;

        a <= '0';
        b <= '0';
        wait for 1 ns;

        a <= '0';
        b <= '1';
        wait for 1 ns;

        a <= '1';
        b <= '0';
        wait for 1 ns;

        a <= '1';
        b <= '1';
        wait for 1 ns;

        assert false
            report "Reached end of test";
        wait;
    end process;  

end architecture;