all:	main

main: main.cpp Pokemon.o waterType.o fireType.o
	g++ main.cpp Pokemon.cpp waterType.cpp fireType.cpp -o main

Pokemon.o: Pokemon.cpp waterType.o fireType.o
	g++ -c Pokemon.cpp waterType.cpp fireType.cpp 

waterType.o: waterType.cpp
	g++ -c waterType.cpp

fireType.o: fireType.cpp
	g++ -c fireType.cpp

clean:
	rm -f *.o main;
