CC=clang
FLAGS= -std=c11 -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL

all: build run

build:
	$(CC) $(FLAGS) lib/libraylib.a src/main.c -o game

run: 
	./game
	clear

clear:
	rm game
