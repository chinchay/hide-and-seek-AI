
a.out: game.o Scenario.o
	g++ game.o Scenario.o -std=c++11

Scenario.o: Scenario.cpp Scenario.h
	g++ -c Scenario.cpp -std=c++11

game.o: game.cpp
	g++ -c game.cpp -std=c++11

clean:
	rm a.out *.o