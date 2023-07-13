#include "group.h"
#include <iostream>

Group::Group(vector<Tile*>& listTile, int len){
    this->listTile = listTile;

    for (int i = 0; i < len; i++){
        pos2Tile[i] = nullptr;
    }

    int id;
    int pos;
    int type;
    for (Tile* pTile : listTile){
        id = pTile->GetID();
        id2pTile[id] = pTile;

        pos = pTile->GetPos();
        pos2Tile[pos] = pTile;

        type = pTile->GetType();
        typeSequence.push_back(type);
    }
    
}

Tile* Group::GetpTileFromPos(int pos){
    return pos2Tile[pos];
}

void Group::IDstackPush(int id){
    // do this operation before moving the tile outside in movabletile.cpp !
    idStack.push(id);
    int pos = id2pTile[id]->GetPos();
    pos2Tile[pos] = nullptr;
    typeSequence[pos] = 0; // "nothing" is there now
}

void Group::IDstackEnd(){
    Tile* pTile;
    int pos;

    while (!idStack.empty()){
        pTile = id2pTile[ idStack.top() ];
        pos = pTile->GetPos();
        pos2Tile[pos] = pTile;
        idStack.pop();
        typeSequence[pos] = pTile->GetType();
    }
}


