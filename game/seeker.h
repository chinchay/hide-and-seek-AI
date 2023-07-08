#ifndef SEEKER_H
#define SEEKER_H

#include "agent.h"
#include <string>

class Seeker: public Agent {
    public:
    ~Seeker(){};
    Seeker(int type, float x, float y, int id, string filename);

    virtual string GetStr() const {
        return "I am a seeker. Type: " + to_string(GetType());
    };

    virtual string GetDirection(int event);

};

#endif