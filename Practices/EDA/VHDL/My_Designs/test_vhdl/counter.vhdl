library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity counter is
    Port ( clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           count : out  UNSIGNED(3 downto 0));
end counter;

architecture Behavioral of counter is
    signal internal_count : UNSIGNED(3 downto 0) := (others => '0');
begin
    process(clk, reset)
    begin
        if reset = '1' then
            internal_count <= (others => '0');
        elsif rising_edge(clk) then
            internal_count <= internal_count + 1;
        end if;
    end process;

    count <= internal_count;
end Behavioral;