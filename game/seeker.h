#ifndef SEEKER_H
#define SEEKER_H

#include "agent.h"
#include <string>

class Seeker: public Agent {
    public:
    ~Seeker(){};
    Seeker(int type, int id, int pos1dim, int rows, int cols, string filename);

    virtual string GetStr() const {
        return "I am a seeker.     Type: " + to_string(GetType()) + ", id: " + to_string(GetID());
    };

    virtual int GetDirection(int event);

};

#endif