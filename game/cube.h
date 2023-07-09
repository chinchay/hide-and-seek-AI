#ifndef CUBE_H
#define CUBE_H

#include "movableTile.h"

class Cube: public MovableTile{
    public:
    ~Cube(){};
    Cube(int type, int id, int pos1dim, int rows, int cols);

    virtual string GetStr() const {
        return "I am a cube.       Type: " + to_string(GetType()) + ", id: " + to_string(GetID());
    };    

};

#endif