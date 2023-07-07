#ifndef CUBE_H
#define CUBE_H

#include "movableTile.h"

class Cube: public MovableTile{
    public:
    ~Cube(){};
    Cube(int type, int x, int y, int id);
};

#endif