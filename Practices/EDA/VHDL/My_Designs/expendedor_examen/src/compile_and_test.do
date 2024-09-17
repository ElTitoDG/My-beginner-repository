acom -O3 -e 100 -work expendedor_examen -2002  $dsn/src/expendedor_examen.vhd $dsn/src/tb_expendedor_examenes.vhd
asim -O5 +access +r +m+tb_expendedor_examen tb_expendedor_examen testbench

wave
wave /tb_expendedor_examen/tb_cent5
wave /tb_expendedor_examen/tb_cent10 
wave /tb_expendedor_examen/tb_cent25
wave /tb_expendedor_examen/tb_Nestado
wave /tb_expendedor_examen/tb_clk
wave /tb_expendedor_examen/tb_reset
wave /tb_expendedor_examen/tb_saleExamen
wave /tb_expendedor_examen/tb_dev5 
wave /tb_expendedor_examen/tb_dev10
run 280 ns
endsim