all:	main

main: main.cpp C4Col.o C4Board.o
	g++ main.cpp C4Col.cpp C4Board.cpp -o main

C4Col.o: C4Col.cpp
	g++ -c C4Col.cpp

C4Board.o: C4Board.cpp
	g++ -c C4Board.cpp

clean:
	rm -f *.o main;

