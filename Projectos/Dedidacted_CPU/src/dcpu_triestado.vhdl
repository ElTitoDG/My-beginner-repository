library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity triestado is
  port (    input: in std_logic_vector(7 downto 0);
            oe: in std_logic;
            output: out std_logic_vector(7 downto 0)
        );
end triestado;

architecture Comportamiento of triestado is
begin
    process (input, oe)
    begin
        if (oe = '1') then
            output <= input;
        else
            output <= (others => 'Z');
        end if;
    end process;
end Comportamiento; -- Comportamiento