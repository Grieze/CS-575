output: main.o
	g++ main.o -o submission 

main.o: main.cpp
	g++ -c main.cpp
