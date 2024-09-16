library ieee;
use ieee.std_logic_1164.all;

entity ha is
    port (
        a: in std_logic;
        b: in std_logic;
        o: out std_logic;
        c: out std_logic 
    );
end entity;

architecture behave of ha is
begin

    o <= a xor b;
    c <= a and b;

end architecture;