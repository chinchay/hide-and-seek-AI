#ifndef CUBE_H
#define CUBE_H

#include "movableTile.h"

//******************************************************************************
// CUBE is a class that implements the virtual methods of the MOVABLETILE
// class. A cube can be pushed by an agent, or by other tiles
//******************************************************************************
class Cube: public MovableTile{
    public:
    ~Cube(){};
    Cube(int type, int id, int pos, int nRows, int nCols);
};

#endif