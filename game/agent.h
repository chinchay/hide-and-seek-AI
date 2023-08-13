#ifndef AGENT_H
#define AGENT_H

#include "movableTile.h"
#include <vector>
#include <string>

//******************************************************************************
// AGENT is a class that implements the virtual methods of the MOVABLETILE
// class. An agent can push other movable objects, but cannot push another
// agent. The AGENT class is still an abstract method, which can derive into
// Seeker or Hider class.
//******************************************************************************
class Agent : public MovableTile{
    
    protected:
    string filename = "";
    vector<int> listMove;
    void SaveMoves();
    float ComputeCos(int x1, int y1, int x2, int y2);
    vector<Tile*> listpContact;
    vector<int> blocksIcanSee;
    int nCells = -1;
    int sightRadius = 5;
    // vector<int*> listpB;

    public:
    ~Agent(){};
    Agent(int type, int id, int pos, int nRows, int nCols, string filename);
    bool CanIseeAgent(Agent* pAgent, vector<Tile*>& listBlocks);
    // bool CanIseeAgent(Agent* pAgent, Tile* pTile);
    void ProcessEvent(int event, Group* pGroup);
    virtual int GetDirection(int event) = 0;
    void ResetBlocksIcanSee();
    void UpdateBlocksIcanSee(vector<Tile*>& listBlocks);
    vector<int>& GetWhatIcanSee(){return blocksIcanSee;};
        
};


#endif