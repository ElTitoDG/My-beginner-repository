library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity bancoRegistro is
  port (    input: in std_logic_vector(7 downto 0);
            we, rea, rbe: in std_logic;
            wa, raa, rba: in std_logic_vector(1 downto 0);
            clk: in std_logic;
            A, B: out std_logic_vector(7 downto 0)
        );
end bancoRegistro;

architecture Comportamiento of bancoRegistro is
    subtype registro is std_logic_vector(7 downto 0);
    type banco is array (0 to 3) of registro;
    signal contenido: banco;
begin
    escritura: process (clk)
    begin
        if (clk'event and clk = '1') then
            if (we = '1') then
                contenido(conv_integer(wa)) <= input;
            end if;
        end if;
    end process escritura;

    lectura_puerto_A: process (rae, raa)
    begin
        if (rae = '1') then
            A <= contenido(conv_integer(raa));
        end if;
    end process lectura_puerto_A;

    lectura_puerto_B: process (rbe, rba)
    begin
        if (rbe = '1') then
            B <= contenido(conv_integer(rba));
        end if;
    end process lectura_puerto_B;
end Comportamiento; -- Comportamiento