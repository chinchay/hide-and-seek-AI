#include "cube.h"

Cube::Cube(int type, int id, int pos1dim, int rows, int cols) : MovableTile(type, id, pos1dim, rows, cols){
    canImove = true;
    amIpushable = true;
}