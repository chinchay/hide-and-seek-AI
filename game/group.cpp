#include "group.h"
#include <iostream>

Group::Group(vector<Tile*> listTile){
    this->listTile = listTile;

    int id;
    int pos1dim;
    int type;
    for (Tile* pTile : listTile){
        id = pTile->GetID();
        id2pTile[id] = pTile;

        pos1dim = pTile->GetPos1dim();
        pos2Tile[pos1dim] = pTile;

        type = pTile->GetType();
        typeSequence.push_back(type);
    }
    
}

Tile* Group::GetpTileFromPos1dim(int pos1dim){
    return pos2Tile[pos1dim];
}

void Group::IDstackPush(int id){
    // do this operation before moving the tile outside in movabletile.cpp !
    idStack.push(id);
    int pos1dim = id2pTile[id]->GetPos1dim();
    pos2Tile[pos1dim] = NULL;
    typeSequence[pos1dim] = 0; // "nothing" is there now
}

void Group::IDstackEnd(){
    Tile* pTile;
    int pos1dim;

    while (!idStack.empty()){
        pTile = id2pTile[ idStack.top() ];
        pos1dim = pTile->GetPos1dim();
        pos2Tile[pos1dim] = pTile;
        idStack.pop();
        typeSequence[pos1dim] = pTile->GetType();
    }
}


