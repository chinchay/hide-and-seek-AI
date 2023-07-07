#ifndef SEEKER_H
#define SEEKER_H

#include "agent.h"

class Seeker: public Agent {
    public:
    ~Seeker(){};
    Seeker(int type, int x, int y, int id);

    virtual string GetStr() const {
        return "I am a seeker. Type: " + to_string(GetType());
    };     

};

#endif