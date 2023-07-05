#ifndef FIXEDTILE_H
#define FIXEDTILE_H

#include "tile.h"
#include <iostream>

class FixedTile : public Tile{
    public:
    FixedTile(int c, int x, int y, int id);


    virtual void display() const {
        cout << "I am a fixed tile " << to_string(this->c) << endl;
    };

};




#endif