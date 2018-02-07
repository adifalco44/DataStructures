all:	main
main: sSolverMain.o sSolver.o
	g++ -std=c++11 sSolverMain.o sSolver.o -o main
sSolverMain.o: sSolverMain.cpp sSolver.o
	g++ -std=c++11 -c sSolverMain.cpp
sSolver.o:  sSolver.cpp
	g++ -std=c++11 -c sSolver.cpp
clean:
	rm -f *.o main
