library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity mux is
  port (    ie: in std_logic;
            input1: in std_logic_vector(7 downto 0);
            input0: in std_logic_vector(7 downto 0);
            output: out std_logic_vector(7 downto 0)
        );
end mux;

architecture Comportamiento of mux is
begin
    process(ie, input1, input0)
    begin
        if (ie = '0') then
            output <= input0;
        else
            output <= input1;
        end if;
    end process;
end Comportamiento; -- Comportamiento