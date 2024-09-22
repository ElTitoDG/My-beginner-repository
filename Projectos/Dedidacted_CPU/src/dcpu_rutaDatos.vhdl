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
    component mux is -- Multiplexor 2 a 1
        Port (
            ie: in std_logic;
            input1: in std_logic_vector(7 downto 0);
            input0: in std_logic_vector(7 downto 0);
            output: out std_logic_vector(7 downto 0);
        );
    end component;

    component bancoRegistro is -- Banco de Registro 4x8
        Port (
            input: in std_logic_vector(7 downto 0);
            we: in std_logic;
            wa: in std_logic_vector(1 downto 0);
            rae: in std_logic;
            raa: in std_logic_vector(1 downto 0);
            rbe: in std_logic;
            rba: in std_logic_vector(1 downto 0);
            clk: in std_logic;
            A: out std_logic_vector(7 downto 0);
            B: out std_logic_vector(7 downto 0);
        );
    end component;

    component unidadALU is -- Unidad Aritmetico-Logica
        Port (
            cod_alu: in std_logic_vector(2 downto 0);
            A: in std_logic_vector(7 downto 0);
            B: in std_logic_vector(7 downto 0);
            output: out std_logic_vector(7 downto 0);
            neq0: out std_logic;
        );
    end component;

    component shifter is -- Registro de desplazamiento
        Port (
            input: in std_logic_vector(7 downto 0);
            shift: in std_logic_vector(2 downto 0);
            output: out std_logic_vector(7 downto 0);
        );
    end component;

    component triestado is -- Buffer triestado
        Port (
            input: in std_logic_vector(7 downto 0);
            oe: in std_logic;
            output: out std_logic_vector(7 downto 0);
        );
    end component;

    -- Signals de interconexion del circuito
    signal muxOut: std_logic_vector(7 downto 0);
    signal broutA: std_logic_vector(7 downto 0);    -- Banco Registro Out A (broutA)
    signal broutB: std_logic_vector(7 downto 0);    -- Banco Registro Out B (broutB)
    signal aluOut: std_logic_vector(7 downto 0);
    signal shiftOut: std_logic_vector(7 downto 0);

begin
    -- Mapeo de puertos
    U1: mux port map (
        ie,
        input,
        shiftOut,
        muxOut);
    U2: bancoRegistro port map (
        muxOut,
        we,
        wa,
        rae,
        raa,
        rbe,
        rba,
        clk,
        broutA,
        broutB);
    U3: unidadAlu port map (
        cod_alu,
        broutA,
        broutB,
        aluOut,
        neq0);
    U4: shifter port map (
        aluOut,
        shift,
        shiftOut);
    U5: triestado port map (
        shiftOut,
        oe,
        output);

end Estructural; -- Estructural