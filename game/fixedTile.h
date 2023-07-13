#ifndef FIXEDTILE_H
#define FIXEDTILE_H

#include "tile.h"

class FixedTile : public Tile{
    public:
    FixedTile(int type, int id, int pos, int nRows, int nCols);
    
    virtual void Move(Group* pGroup){};
    virtual bool CanIPush(int direction, Group* pGroup){return false;}

};




#endif