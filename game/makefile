
a.out: main.o game.o scenario.o tile.o fixedTile.o movableTile.o agent.o hider.o seeker.o cube.o ramp.o group.o
	g++ main.o game.o scenario.o tile.o fixedTile.o movableTile.o agent.o hider.o seeker.o cube.o ramp.o group.o -std=c++11  -g

tile.o: tile.cpp tile.h
	g++ -c tile.cpp -std=c++11 -g

fixedTile.o: fixedTile.cpp fixedTile.h
	g++ -c fixedTile.cpp -std=c++11  -g

movableTile.o: movableTile.cpp movableTile.h
	g++ -c movableTile.cpp -std=c++11 -g

agent.o: agent.cpp agent.h
	g++ -c agent.cpp -std=c++11 -g

hider.o: hider.cpp hider.h
	g++ -c hider.cpp -std=c++11 -g

seeker.o: seeker.cpp seeker.h
	g++ -c seeker.cpp -std=c++11 -g

cube.o: cube.cpp cube.h
	g++ -c cube.cpp -std=c++11

ramp.o: ramp.cpp ramp.h
	g++ -c ramp.cpp -std=c++11

scenario.o: scenario.cpp scenario.h
	g++ -c scenario.cpp -std=c++11 -g

group.o: group.cpp group.h
	g++ -c group.cpp -std=c++11 -g

game.o: game.cpp game.h
	g++ -c game.cpp -std=c++11 -g

main.o: main.cpp
	g++ -c main.cpp -std=c++11 -g

clean:
	rm a.out *.o