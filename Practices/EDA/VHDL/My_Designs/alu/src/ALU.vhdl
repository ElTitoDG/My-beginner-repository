library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all; -- Se reemplazan std_logic_arith y std_logic_unsigned

entity ALU is
    port (
        A, B: in std_logic_vector(7 downto 0);
        cod_ope: in std_logic_vector(3 downto 0);
        CarryIn: in std_logic;
        CarryOut: out std_logic;
        resultado: out std_logic_vector(7 downto 0)
    );
end ALU;

architecture Estructural of ALU is
    component multiplexor
        port (
            ud_aritmetica: in std_logic_vector(7 downto 0);
            ud_logica: in std_logic_vector(7 downto 0);
            cod_ope: in std_logic_vector(3 downto 0);
            resultado: out std_logic_vector(7 downto 0)
        );
    end component;

    component Unidad_Logica
        port (
            A, B: in std_logic_vector(7 downto 0);
            cod_ope: in std_logic_vector(3 downto 0);
            salidaUL: out std_logic_vector(7 downto 0)
        );
    end component;

    component Unidad_Aritmetica
        port (
            A, B: in std_logic_vector(7 downto 0);
            cod_ope: in std_logic_vector(3 downto 0);
            CarryIn: in std_logic;
            salidaUA: out std_logic_vector(7 downto 0);
            CarryOut: out std_logic
        );
    end component;

    signal arith, logic, mux: std_logic_vector(7 downto 0);
    signal acarreo: std_logic;

begin
    u1: Unidad_Aritmetica port map (A, B, cod_ope, CarryIn, arith, acarreo);
    u2: Unidad_Logica port map (A, B, cod_ope, logic);
    u3: multiplexor port map (arith, logic, cod_ope, mux);

    resultado <= mux;
    CarryOut <= acarreo;
end Estructural;
