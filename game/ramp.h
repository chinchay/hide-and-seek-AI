#ifndef RAMP_H
#define RAMP_H

#include "movableTile.h"

class Ramp: public MovableTile{
    public:
    ~Ramp(){};
    Ramp(int type, int id, int pos, int nRows, int nCols);
};

#endif