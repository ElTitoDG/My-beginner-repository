library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity Unidad_Aritmetica is
    port (  A: in std_logic_vector(7 downto 0);
            B: in std_logic_vector(7 downto 0);
            cod_ope: in std_logic_vector(3 downto 0);
            CarryIn: in std_logic;
            salidaUA: out std_logic_vector(7 downto 0);
            CarryOut: out std_logic);
end Unidad_Aritmetica;

architecture Comp_Arit of Unidad_Aritmetica is
begin
    calculos_arit: process(A, B, cod_ope, CarryIn)
        variable acarreo: std_logic_vector(8 downto 0);
    begin
        acarreo(0) := CarryIn;
        case cod_ope(3 downto 0) is
            when "0000" => salidaUA <= A;
                            CarryOut <= '0';
            when "0001" => salidaUA <= A + 1;
                            CarryOut <= '0';
            when "0010" => salidaUA <= A - 1;
                            CarryOut <= '0';
            when "0011" => salidaUA <= B;
                            CarryOut <= '0';
            when "0100" => salidaUA <= B + 1;
                            CarryOut <= '0';
            when "0101" => salidaUA <= B - 1;
                            CarryOut <= '0';
            when "0110" => salidaUA <= A - B;
                            if unsigned(A) < unsigned(B) then
                                CarryOut <= '1';
                            else
                                CarryOut <= '0';
                            end if;
            when others => salidaUA <= A + B + CarryIn;
                            for i in 0 to 7 loop
                                acarreo(i+1) := (A(i) and B(i)) or
                                                (A(i) and acarreo(i)) or
                                                (B(i) and acarreo(i));
                            end loop;
                            CarryOut <= acarreo(8);
            end case;
    end process calculos_arit;
end Comp_Arit ; -- Comp_Arit