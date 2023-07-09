#ifndef FIXEDTILE_H
#define FIXEDTILE_H

#include "tile.h"

class FixedTile : public Tile{
    public:
    FixedTile(int type, int id, int pos1dim);

    virtual string GetStr() const {
        return "I am a fixed tile. Type: " + to_string(GetType()) + ", id: " + to_string(GetID());
    };

    virtual void Move(Group* pGroup){};
    virtual bool CanIPush(string direction, Group* pGroup){return false;}

};




#endif