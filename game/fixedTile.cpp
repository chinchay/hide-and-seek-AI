#include <iostream>
// #include <string>
#include "fixedTile.h"

using namespace std;

FixedTile::FixedTile(int type, int iRow, int jCol, int id) : Tile(type, iRow, jCol, id){
    canImove = false;
    amIpushable = false;
}

