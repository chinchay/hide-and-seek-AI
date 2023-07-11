#ifndef MOVABLETILE_H
#define MOVABLETILE_H

#include "tile.h"
#include <map>

class MovableTile: public Tile{
    private:
    int rows;
    int cols;
    int nCells;
    int minPos;
    int maxPos;
    // map<string, int> dPos1dim;
    map<int, int> dPos1dim;
    int futurePos1dim;
    int futureRow;
    int currentRow;

    // this line has to be at end, why????!!!!
    Tile* pTileHit = NULL;
    // int minJ; << wont' work if it is after NULL; why???
    // int maxJ;


    public:
    MovableTile(int type, int id, int pos1dim, int rows, int cols);
    int GetMinPos(){return minPos;};
    int GetMaxPos(){return maxPos;};
    void SetMinPos(int minPos){this->minPos = minPos;};
    void SetMaxPos(int maxPos){this->maxPos = maxPos;};
    int GetRows(){return rows;};
    int GetCols(){return cols;};
    void UpdateFuturePosition(int direction);
    virtual void Move(Group* pGroup);
    void EchoMove(int direction);
    void Stepback();
    virtual bool CanIPush(int direction, Group* pGroup);

};

#endif