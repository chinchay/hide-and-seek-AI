#ifndef FIXEDTILE_H
#define FIXEDTILE_H

#include "tile.h"

//******************************************************************************
// FIXEDTILE is a class that implements the virtual methods of the TILE class.
// The screen will be made up of several fixed tiles which will work as walls
//******************************************************************************
class FixedTile : public Tile{
    public:
    FixedTile(int type, int id, int pos, int nRows, int nCols);
    
    virtual void Move(Group* pGroup){};
    virtual bool CanIPush(int direction, Group* pGroup){return false;}

};




#endif