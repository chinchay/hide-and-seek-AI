#include "cube.h"

Cube::Cube(int type, int id, int pos, int nRows, int nCols) : MovableTile(type, id, pos, nRows, nCols){
    SetTileDeriv("Cube     ");
    canImove = true;
    amIpushable = true;
}