library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity unidadALU is
  port (    cod_alu: in std_logic_vector(2 downto 0);
            A, B: in std_logic_vector(7 downto 0);
            output: out std_logic_vector(7 downto 0);
            neq0: out std_logic
        );
end unidadALU;

architecture Comportamiento of unidadALU is
begin
    process (A, B, cod_alu)
        variable resultado: std_logic_vector(7 downto 0);
    begin
        -- Realizamos las operaciones segun cod_alu
        case(cod_alu) is
            when "000" => resultado := A;
            when "001" => resultado := A and B;
            when "010" => resultado := A or B;
            when "011" => resultado := not(A);
            when "100" => resultado := A + B;
            when "101" => resultado := A - B;
            when "110" => resultado := A + 1;
            when others => resultado := A - 1;
        end case ;

        -- Analizamos el resultado, si es 0 neq0 pasa a cierto
        if (resultado = 0) then
            neq0 <= '1';
        else
            neq0 <= '0';
        end if;

        output <= resultado;
    end process;
end Comportamiento; -- Comportamiento
