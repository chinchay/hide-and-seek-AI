#ifndef GROUP_H
#define GROUP_H

#include "tile.h"
#include <vector>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

class Tile; // << I had to add this line, otherwise I got errors: ./group.h:13:14: error: use of undeclared identifier 'Tile' map<int, Tile*> id2pTile;

class Group{
    // private:
    // map<int, Tile*> id2pTile;
    // stack<int> idStack;
    // vector<int> typeSequence;
    
    public:
    map<int, Tile*> id2pTile;
    stack<int> idStack;
    vector<int> typeSequence;

    map<int, Tile*> pos2Tile;
    
    vector<Tile*> listTile;
    ~Group(){};
    Group(vector<Tile*>& listTile, int len);
    // int GetStackSize(){
    //     // return idStack.size();

    //     int size = idStack.size();
    //     if ( (size < 0) or (500 < size) ){
    //         cout << "size seems to big!" << endl;
    //         exit(0);
    //     }
    //     return size;
    // };
    // vector<Tile*>& GetListTile(){return listTile;};
    Tile* GetpTileFromPos(int pos);
    void IDstackPush(int id);
    void IDstackEnd();


};

#endif