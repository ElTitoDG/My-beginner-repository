library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all; -- Se reemplazan std_logic_arith y std_logic_unsigned

entity multiplexor is
    port (
        ud_aritmetica: in std_logic_vector(7 downto 0);
        ud_logica: in std_logic_vector(7 downto 0);
        cod_ope: in std_logic_vector(3 downto 0);
        resultado: out std_logic_vector(7 downto 0)
    );
end multiplexor;

architecture Comp_mul of multiplexor is
begin
    process(ud_aritmetica, ud_logica, cod_ope) 
    begin  
        if (cod_ope(3) = '0') then
            resultado <= ud_aritmetica;
        else
            resultado <= ud_logica;
        end if;
    end process;	
end Comp_mul;