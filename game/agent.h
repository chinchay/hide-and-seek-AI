#ifndef AGENT_H
#define AGENT_H

#include "movableTile.h"
#include <vector>
#include <string>

class Agent : public MovableTile{
    
    protected:
    string filename;
    vector<int> listMove;
    void SaveMoves();
    float GetArcCos(int x1, int y1, int x2, int y2);
    vector<Tile*> listpContact;

    public:
    ~Agent();
    Agent(int type, int iRow, int jCol, int id, string filename);
    bool CanIseeAgent(Agent* pAgent, vector<Tile*> &listTile);
    void ProcessEvent(int event, vector<Tile*> &allOthers, vector<vector<int>> &matrixID);
    virtual string GetDirection(int event) = 0;
        
};


#endif