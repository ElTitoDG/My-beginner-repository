acom -O3 -e 100 -work registroMaNoTaS -2002  $dsn/src/registroMaNoTaS.vhd $dsn/src/registro_tb.vhd
asim -O5 +access +r +m+tb_registromanotas tb_registromanotas testbench

wave
wave /tb_registromanotas/tb_SelectReg 
wave /tb_registromanotas/tb_LoadReg
wave /tb_registromanotas/tb_SelectedReg
wave /tb_registromanotas/tb_clk
wave /tb_registromanotas/tb_reset
wave /tb_registromanotas/tb_entrada
wave /tb_registromanotas/tb_salida
run 200 ns
endsim