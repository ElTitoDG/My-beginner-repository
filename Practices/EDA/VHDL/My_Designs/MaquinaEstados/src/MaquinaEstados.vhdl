library IEEE;
use IEEE.std_logic_1164.all;

entity MaquinaEstados is
    port (
        entrada: in std_logic;
        clk: in std_logic;
        resetHigh: in std_logic;
        salida: out std_logic
    );
end MaquinaEstados;

architecture MaquinaEstadosArch of MaquinaEstados is 
    type TipoEstados is (E0, E1, E2, E3, E4);
    signal EstadoActual, EstadoSiguiente: TipoEstados;
begin    
    logica_estado: process(EstadoActual, entrada)
    begin
        case EstadoActual is
            when E0 =>
                if (entrada = '1') then 
                    EstadoSiguiente <= E1;
                else 
                    EstadoSiguiente <= E4;
                end if;
            when E1 =>
                if (entrada = '1') then
                    EstadoSiguiente <= E2;
                else
                    EstadoSiguiente <= E4;
                end if;
            when E2 =>
                if (entrada = '1') then
                    EstadoSiguiente <= E3;
                else
                    EstadoSiguiente <= E4;
                end if;
            when E3 => EstadoSiguiente <= E3;
            when E4 =>
                if (entrada = '1') then
                    EstadoSiguiente <= E1;
                else
                    EstadoSiguiente <= E4;
                end if;
        end case;        
    end process logica_estado;
    
    memoria_estado: process(clk, resetHigh)
    begin  
        if (resetHigh = '1') then 
            EstadoActual <= E0;
        elsif (rising_edge(clk)) then
            EstadoActual <= EstadoSiguiente;
        end if;
    end process memoria_estado;
    
    Salida <= '1'  when (EstadoActual=E2 and entrada='1')
                else '0';
end MaquinaEstadosArch;