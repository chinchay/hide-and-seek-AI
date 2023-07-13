#include "fixedTile.h"

FixedTile::FixedTile(int type, int id, int pos, int nRows, int nCols) : Tile(type, id, pos, nRows, nCols){
    SetTileDeriv("FixedTile");
    canImove = false;
    amIpushable = false;
}

