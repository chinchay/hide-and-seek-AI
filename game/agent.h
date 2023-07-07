#ifndef AGENT_H
#define AGENT_H

#include "movableTile.h"

class Agent : MovableTile{
    private:
    float GetArcCos(int x1, int y1, int x2, int y2);

    public:
    Agent(int c, int x, int y, int id);
    ~Agent();

    bool CanIseeAgent(Agent* pAgent, vector<Tile*> listTile);

        
};


#endif