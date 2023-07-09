
a.out: game.o scenario.o tile.o fixedTile.o movableTile.o agent.o hider.o seeker.o cube.o group.o
	g++ game.o scenario.o tile.o fixedTile.o movableTile.o agent.o hider.o seeker.o cube.o group.o -std=c++11

tile.o: tile.cpp tile.h
	g++ -c tile.cpp -std=c++11

fixedTile.o: fixedTile.cpp fixedTile.h
	g++ -c fixedTile.cpp -std=c++11

movableTile.o: movableTile.cpp movableTile.h
	g++ -c movableTile.cpp -std=c++11

agent.o: agent.cpp agent.h
	g++ -c agent.cpp -std=c++11

hider.o: hider.cpp hider.h
	g++ -c hider.cpp -std=c++11

seeker.o: seeker.cpp seeker.h
	g++ -c seeker.cpp -std=c++11

cube.o: cube.cpp cube.h
	g++ -c cube.cpp -std=c++11

scenario.o: scenario.cpp scenario.h
	g++ -c scenario.cpp -std=c++11

group.o: group.cpp group.h
	g++ -c group.cpp -std=c++11

game.o: game.cpp
	g++ -c game.cpp -std=c++11

clean:
	rm a.out *.o