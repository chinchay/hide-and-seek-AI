#ifndef MOVABLETILE_H
#define MOVABLETILE_H

#include "tile.h"
#include <map>

class MovableTile: public Tile{
    private:
    int rows;
    int cols;
    int nCells;
    map<string, int> dPos1dim;
    int futurePos1dim;
    Tile* pTileHit = NULL;

    public:
    MovableTile(int type, int id, int pos1dim, int rows, int cols);
    int GetRows(){return rows;};
    int GetCols(){return cols;};
    void UpdateFuturePosition(string direction);
    virtual void Move(Group* pGroup);
    void EchoMove(string direction);
    void Stepback();
    virtual bool CanIPush(string direction, Group* pGroup);

};

#endif