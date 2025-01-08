library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity shifter is
  port (    input: in std_logic_vector(7 downto 0);
            shift: in std_logic_vector(2 downto 0);
            output: out std_logic_vector(7 downto 0)
        );
end shifter;

architecture Comportamiento of shifter is
begin
    process (shift, input)
        variable registro: std_logic_vector(7 downto 0); -- Contenido del registro
        variable temp: std_logic; -- Variable temporal para calculos
    begin
        registro := input; -- Asocia registro al valor input

        -- Operacion a realizar segun SHIFT
        case( shift ) is

            when "000" => output <= registro;
            when "001" =>
                for i in 7 downto 1 loop
                    registro(i) := registro(i - 1);
                end loop;
                registro(0) := '0';
            when "010" =>
                for i in 0 to 6 loop
                    registro(i) := registro(i + 1);
                end loop;
                registro(7) := '0';
            when "011" => temp := registro(0);
                for i in 0 to 6 loop
                    registro(i) := registro(i + 1);
                end loop;
                registro(7) := temp;
            when others => registro := (others => '0');
        end case;

        output <= registro;
    end process;
end Comportamiento; -- Comportamiento
