#include "tile.h"

Tile::Tile(int type, int id, int pos, int nRows, int nCols){
    this->tileDeriv = "Tile";
    this->type  = type;
    this->id    = id;
    this->pos   = pos;
    this->nRows = nRows;
    this->nCols = nCols;
    this->row = pos / nCols;
    this->col = pos % nCols;
}

string Tile::GetStr(){
    string str = "I am a " + tileDeriv;
    str += ". type: " + to_string(GetType());
    str += ". id: " + to_string(GetID());
    str += ". pos: " + to_string(GetPos());
    str += ". row, col: " + to_string(GetRow()) + ", " + to_string(GetCol());
    return str;

}