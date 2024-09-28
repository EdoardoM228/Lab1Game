# Specify the SFML include and library directories
SFML_INCLUDE = src/include
SFML_LIB = src/lib

all: TetrisGame

TetrisGame: figure.o game.o clear.o field.o point.o main.o
	g++ -o Tetris.exe figure.o game.o clear.o field.o point.o main.o -L"$(SFML_LIB)" -lsfml-graphics -lsfml-window -lsfml-system

figure.o:
	g++ figure.cpp -o figure.o -c -I"$(SFML_INCLUDE)"

game.o:
	g++ game.cpp -o game.o -c -I"$(SFML_INCLUDE)"

clear.o:
	g++ clear.cpp -o clear.o -c -I"$(SFML_INCLUDE)"

field.o:
	g++ field.cpp -o field.o -c -I"$(SFML_INCLUDE)"

point.o:
	g++ point.cpp -o point.o -c -I"$(SFML_INCLUDE)"

main.o:
	g++ main.cpp -o main.o -c -I"$(SFML_INCLUDE)"

clean:
	rm -f *.o *.exe