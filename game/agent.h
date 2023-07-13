#ifndef AGENT_H
#define AGENT_H

#include "movableTile.h"
#include <vector>
#include <string>

class Agent : public MovableTile{
    
    protected:
    string filename = "";
    vector<int> listMove;
    void SaveMoves();
    float ComputeCos(int x1, int y1, int x2, int y2);
    vector<Tile*> listpContact;

    public:
    ~Agent(){};
    Agent(int type, int id, int pos, int nRows, int nCols, string filename);
    bool CanIseeAgent(Agent* pAgent, vector<Tile*>& listBlocks);
    // bool CanIseeAgent(Agent* pAgent, Tile* pTile);
    void ProcessEvent(int event, Group* pGroup);
    virtual int GetDirection(int event) = 0;
        
};


#endif