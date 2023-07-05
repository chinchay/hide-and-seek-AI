#include <iostream>
#include <string>
#include "fixedTile.h"

using namespace std;

FixedTile::FixedTile(
    string filename, int x, int y, int id) : Tile(filename, x, y, id){
        // cout << filename << endl;
    }

