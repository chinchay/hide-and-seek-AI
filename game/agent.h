#ifndef AGENT_H
#define AGENT_H

#include "movableTile.h"
#include <vector>

class Agent : public MovableTile{
    private:
    float GetArcCos(int x1, int y1, int x2, int y2);

    public:
    Agent(int type, int x, int y, int id);
    ~Agent();

    bool CanIseeAgent(Agent* pAgent, vector<Tile*> listTile);
    void virtual ProcessEvent(int event, vector<Tile*> allOthers);

        
};


#endif