#ifndef FIXEDTILE_H
#define FIXEDTILE_H

#include "tile.h"
#include <iostream>

class FixedTile : public Tile{
    public:
    FixedTile(int type, int iRow, int jCol, int id);

    virtual string GetStr() const {
        return "I am a fixed tile. Type: " + to_string(GetType());
    };

    virtual bool CanIPush(vector<Tile*> &allOthers, string direction, vector<vector<int>> &matrixID){
        return false;
    };

    virtual void Move(){};

};




#endif