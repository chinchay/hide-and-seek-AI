#ifndef SEEKER_H
#define SEEKER_H

#include "agent.h"
#include <string>

//******************************************************************************
// SEEKER is a class that implements the virtual methods of the AGENT
// class. A seeker can move ramp tiles, but not cube tiles
//******************************************************************************
class Seeker: public Agent {
    public:
    ~Seeker(){};
    Seeker(int type, int id, int pos, int nRows, int nCols, string filename);

    virtual int GetDirection(int event);

};

#endif