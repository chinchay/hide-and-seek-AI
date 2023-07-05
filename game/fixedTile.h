#ifndef FIXEDTILE_H
#define FIXEDTILE_H

#include "tile.h"
#include <iostream>

class FixedTile : public Tile{
    public:
    FixedTile(string filename, int x, int y, int id);


    virtual void display() const {cout << "I am a fixed tile" << endl; };

};




#endif