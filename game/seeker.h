#ifndef SEEKER_H
#define SEEKER_H

#include "agent.h"
#include <string>

class Seeker: public Agent {
    public:
    ~Seeker(){};
    Seeker(int type, int id, int pos, int nRows, int nCols, string filename);

    virtual int GetDirection(int event);

};

#endif