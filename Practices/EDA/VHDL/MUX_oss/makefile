all: analyze execute run

analyze: mux.vhdl mux_testbench.vhdl
	ghdl -a mux.vhdl
	ghdl -a mux_testbench.vhdl

execute:
	ghdl -e mux_testbench

run:
	ghdl -r mux_testbench --vcd=mux.vcd
	gtkwave mux.vcd