#ifndef MOVABLETILE_H
#define MOVABLETILE_H

#include "tile.h"
#include <vector>
#include <map>
using namespace std;

class MovableTile: public Tile{
    public:
    map<string, vector<int>> dPosition;
    int iRowFuture;
    int jColFuture;
    Tile* pTileHit = NULL;

    MovableTile(int type, int iRow, int jCol, int id);
    void UpdateFuturePosition(string direction, int rows, int cols);
    virtual void Move();
    void EchoMove(string direction);
    virtual bool CanIPush(vector<Tile*> &allOthers, string direction, vector<vector<int>> &matrixID);

};

#endif