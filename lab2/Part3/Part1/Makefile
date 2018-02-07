
run: Cardmain.o CardDeck.o
	g++ Cardmain.o CardDeck.o -o run

Cardmain.o: Cardmain.cpp CardDeck.h
	g++ -c -std=c++11 Cardmain.cpp -o Cardmain.o

CardDeck.o: CardDeck.cpp CardDeck.h
	g++ -c CardDeck.cpp -o CardDeck.o

clean:
	rm *.o run
