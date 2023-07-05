#include "tile.h"
#include <string>
// #include <iostream>
using namespace std;

Tile::Tile(string filename, int x, int y, int id){
    this->filenane = filename;
    this->x = x;
    this->y = y;
    this->id = id;

}
