#ifndef HIDER_H
#define HIDER_H

#include "agent.h"
#include <string>
#include <vector>

class Hider: public Agent{
    public:
    ~Hider(){};
    
    Hider(int type, int id, int pos1dim, int rows, int cols, string filename);

    virtual string GetStr() const {
        return "I am a hider.      Type: " + to_string(GetType()) + ", id: " + to_string(GetID());
    };

    virtual int GetDirection(int event);
    // virtual bool CanIpush(vector<Tile*> allOthers, string direction);

    

};

#endif