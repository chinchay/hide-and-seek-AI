#ifndef RAMP_H
#define RAMP_H

#include "movableTile.h"

//******************************************************************************
// RAMP is a class that implements the virtual methods of the MOVABLETILE
// class. A ramp can be pushed by a seeker, and be used to jump accross walls
// made of cubes.
//******************************************************************************
class Ramp: public MovableTile{
    public:
    ~Ramp(){};
    Ramp(int type, int id, int pos, int nRows, int nCols);
};

#endif