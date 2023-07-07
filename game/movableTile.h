#ifndef MOVABLETILE_H
#define MOVABLETILE_H

#include "tile.h"

class MovableTile: public Tile{
    public:
    MovableTile(int type, int x, int y, int id);

};

#endif