#ifndef GROUP_H
#define GROUP_H

#include "tile.h"
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Tile; // << I had to add this line, otherwise I got errors: ./group.h:13:14: error: use of undeclared identifier 'Tile' map<int, Tile*> id2pTile;

class Group{
    private:
    map<int, Tile*> id2pTile;
    stack<int> idStack;
    vector<int> typeSequence;
    
    public:
    map<int, Tile*> pos2Tile;
    
    vector<Tile*> listTile;
    ~Group(){};
    Group(vector<Tile*> listTile);
    int GetStackSize(){return idStack.size();};
    // vector<Tile*>& GetListTile(){return listTile;};
    Tile* GetpTileFromPos1dim(int pos1dim);
    void IDstackPush(int id);
    void IDstackEnd();


};

#endif