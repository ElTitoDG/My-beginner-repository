library IEEE;
use IEEE.std_logic_1164.all;

entity test is
  port (
    a: in std_logic;
    b: in std_logic;
    y: out std_logic
);
end test;

architecture Behavioral of test is
begin
  y <= a and b;
end Behavioral;
