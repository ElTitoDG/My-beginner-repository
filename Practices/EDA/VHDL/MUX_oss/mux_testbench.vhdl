library IEEE;
use IEEE.std_logic_1164.all;

entity mux_testbench is
end mux_testbench;

architecture Test of mux_testbench is
    component mux
        port (
            a, b: IN std_logic_vector (7 DOWNTO 0);
            sel: IN std_logic_vector (1 DOWNTO 0);
            output: OUT std_logic_vector (7 DOWNTO 0)
        );
    end component;

    signal a_test, b_test, output_test : std_logic_vector (7 DOWNTO 0);
    signal sel_test : std_logic_vector (1 DOWNTO 0);

begin
    uut: mux port map (
        a => a_test,
        b => b_test,
        sel => sel_test,
        output => output_test
    );

    process
    begin
        a_test <= "10101010";
        b_test <= "11001100";
        sel_test <= "00";
        wait for 10 ns;
        assert output_test = "00000000" report "Error: output incorrecto para sel = 00" severity error;

        sel_test <= "01";
        wait for 10 ns;
        assert output_test = a_test report "Error: output incorrecto para sel = 01" severity error;

        sel_test <= "10";
        wait for 10 ns;
        assert output_test = b_test report "Error: output incorrecto para sel = 10" severity error;
        
        sel_test <= "11";
        wait for 10 ns;
        assert output_test = "11111111" report "Error: output incorrecto para sel = 11" severity error;

        wait for 20 ns;
        wait;
    end process;
end Test;