#ifndef FIXEDTILE_H
#define FIXEDTILE_H

#include "tile.h"
#include <iostream>

class FixedTile : public Tile{
    public:
    FixedTile(int type, int x, int y, int id);


    virtual void Display() const {
        cout << "I am a fixed tile " << to_string(GetType()) << endl;
    };

};




#endif