#include "fixedTile.h"

FixedTile::FixedTile(int type, int id, int pos1dim) : Tile(type, id, pos1dim){
    canImove = false;
    amIpushable = false;
}

