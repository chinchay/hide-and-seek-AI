#include "ramp.h"

Ramp::Ramp(int type, int id, int pos, int nRows, int nCols) : MovableTile(type, id, pos, nRows, nCols){
    SetTileDeriv("Ramp");
    canImove = true;
    amIpushable = true;    
}