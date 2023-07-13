#ifndef HIDER_H
#define HIDER_H

#include "agent.h"
#include <string>
#include <vector>

class Hider: public Agent{
    public:
    ~Hider(){};
    
    Hider(int type, int id, int pos, int nRows, int nCols, string filename);

    virtual int GetDirection(int event);
    // virtual bool CanIpush(vector<Tile*> allOthers, string direction);

    

};

#endif