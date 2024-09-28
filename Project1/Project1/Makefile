all: TetrisGame

TetrisGame: figure.o game.o clear.o field.o point.o main.o
	g++ -o Tetris.exe figure.o game.o clear.o field.o point.o main.o -lsfml-graphics -lsfml-window -lsfml-system

figure.o:
	g++ figure.cpp -o figure.o -c

game.o:
	g++ game.cpp -o game.o -c

clear.o:
	g++ clear.cpp -o clear.o -c

field.o:
	g++ field.cpp -o field.o -c

point.o:
	g++ point.cpp -o point.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o *.exe
