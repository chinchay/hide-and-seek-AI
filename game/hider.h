#ifndef HIDER_H
#define HIDER_H

#include "agent.h"
#include <string>
#include <vector>

class Hider: public Agent{
    public:
    ~Hider(){};
    
    Hider(int type, float x, float y, int id, string filename);

    virtual string GetStr() const {
        return "I am a hider. Type: " + to_string(GetType());
    };

    virtual string GetDirection(int event);
    // virtual bool CanIpush(vector<Tile*> allOthers, string direction);

    

};

#endif