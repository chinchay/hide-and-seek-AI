#ifndef HIDER_H
#define HIDER_H

#include "agent.h"

class Hider: public Agent{
    public:
    ~Hider(){};
    
    Hider(int type, int x, int y, int id);

    virtual string GetStr() const {
        return "I am a hider. Type: " + to_string(GetType());
    };     

};

#endif