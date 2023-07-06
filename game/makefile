
a.out: game.o scenario.o tile.o fixedTile.o movableTile.o agent.o
	g++ game.o scenario.o tile.o fixedTile.o movableTile.o agent.o -std=c++11

tile.o: tile.cpp tile.h
	g++ -c tile.cpp -std=c++11

fixedTile.o: fixedTile.cpp fixedTile.h tile.h
	g++ -c fixedTile.cpp -std=c++11

movableTile.o: movableTile.cpp movableTile.h tile.h
	g++ -c movableTile.cpp -std=c++11

agent.o: agent.cpp agent.h movableTile.h tile.h
	g++ -c agent.cpp -std=c++11

scenario.o: scenario.cpp scenario.h tile.h fixedTile.h
	g++ -c scenario.cpp -std=c++11

game.o: game.cpp
	g++ -c game.cpp -std=c++11

clean:
	rm a.out *.o