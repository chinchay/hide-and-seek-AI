#ifndef HIDER_H
#define HIDER_H

#include "agent.h"
#include <string>
#include <vector>

//******************************************************************************
// HIDER is a class that implements the virtual methods of the AGENT
// class. A hider can push only ramps, and use the ramp to jump across walls
// made up of block tiles. A hider cannot see through walls.
//******************************************************************************
class Hider: public Agent{
    public:
    ~Hider(){};
    
    Hider(int type, int id, int pos, int nRows, int nCols, string filename);

    virtual int GetDirection(int event);
    // virtual bool CanIpush(vector<Tile*> allOthers, string direction);

    

};

#endif