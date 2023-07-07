#ifndef FIXEDTILE_H
#define FIXEDTILE_H

#include "tile.h"
#include <iostream>

class FixedTile : public Tile{
    public:
    FixedTile(int type, int x, int y, int id);


    virtual string GetStr() const {
        return "I am a fixed tile. Type: " + to_string(GetType());
    };  

};




#endif