#ifndef TILE_H
#define TILE_H

#include <string>
#include "group.h"
#include <iostream>

using namespace std;

class Group;

class Tile{
    private:
    int type;
    int id;
    int pos1dim;

    public:
    bool canImove = false;
    bool amIpushable = false;

    virtual ~Tile(){};
    Tile(int type, int id, int pos1dim);
    
    int GetType() const {return type;};
    int GetID() const {return id;};
    int GetPos1dim() const {return pos1dim;};
    void SetPos1dim(int pos1dim){this->pos1dim = pos1dim;};
    
    virtual string GetStr() const = 0;
    virtual void Move(Group* pGroup) = 0;
    virtual bool CanIPush(string direction, Group* pGroup) = 0;

    void Display() const {
        cout << GetStr() << endl;
    }; 
};

#endif