# Directorios
SRC := src
OBJ := obj

# Max Sim Time
SIM_TIME := 150ns

# Lista de archivos VHDL (puedes agregar más si es necesario)
VHDL_FILES := $(wildcard $(SRC)/*.vhdl)

# Nombre del testbench (puedes cambiarlo por el que necesites)
TESTBENCH := tb_ALU

# Archivos generados
VCD_FILE := $(TESTBENCH).vcd
EXECUTABLE := $(OBJ)/$(TESTBENCH)

# Reglas
all: analyze execute run clean

# Regla para analizar todos los archivos VHDL
analyze: $(VHDL_FILES)
	@mkdir -p $(OBJ)
	ghdl -a -fsynopsys --workdir=$(OBJ) $(VHDL_FILES)

# Regla para compilar el testbench
execute: analyze
	ghdl -e -fsynopsys --workdir=$(OBJ) $(TESTBENCH)

# Regla para ejecutar la simulación y generar el archivo VCD
run: execute
	ghdl -r -fsynopsys --workdir=$(OBJ) $(TESTBENCH) --vcd=$(VCD_FILE) --stop-time=$(SIM_TIME)
	gtkwave $(VCD_FILE)

# Limpieza de archivos generados
clean:
	rm -rf $(OBJ)/*.o $(OBJ)/*.cf $(VCD_FILE) $(EXECUTABLE) *.vcd

.PHONY: all analyze execute run clean