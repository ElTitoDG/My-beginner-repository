acom -O3 -e 100 -work MaquinaEstados -2002  $dsn/src/MaquinaEstados.vhd $dsn/src/tb_MaquinaEstados.vhd
asim -O5 +access +r +m+tb_maquinaestados tb_maquinaestados tb_maquinaestados_arch

wave
wave /tb_MaquinaEstados/tb_entrada 
wave /tb_MaquinaEstados/tb_clk
wave /tb_MaquinaEstados/tb_resetHigh
wave /tb_MaquinaEstados/tb_salida
run 90 ns
endsim