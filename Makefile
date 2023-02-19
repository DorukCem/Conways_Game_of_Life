all: compile link

compile:
	g++ -Isrc/include -c main.cpp Grid.cpp

link:
	g++ main.o Grid.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
