library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use IEEE.std_logic_unsigned.all;

entity rutaDatos is
  port (    input: in std_logic_vector(7 downto 0);
            ie: in std_logic;
            we: in std_logic;
            wa: in std_logic_vector(1 downto 0);
            rae: in std_logic;
            raa: in std_logic_vector(1 downto 0);
            rbe: in std_logic;
            rba: in std_logic_vector(1 downto 0);
            cod_alu: in std_logic_vector(2 downto 0);
            shift: in std_logic_vector(2 downto 0);
            oe: in std_logic;
            clk: in std_logic;
            neq0: out std_logic;
            output: out std_logic_vector(7 downto 0)
        );
end rutaDatos;

architecture Estructural of rutaDatos is
    -- Definicion de componentes de la ruta de datos
    

end Estructural ; -- Estructural