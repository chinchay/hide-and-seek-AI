#ifndef MOVABLETILE_H
#define MOVABLETILE_H

#include "tile.h"
#include <map>

class MovableTile: public Tile{
    private:
    int nCells = -1;
    int minPos = -1;
    int maxPos = -1;
    // map<int, int> dPos;
    vector<int> dPos;
    int futurePos = 0;
    int futureRow = 0;

    // this line has to be at end, why????!!!!
    Tile* pTileHit = nullptr;
    // int minJ; << wont' work if it is after NULL; why???
    // int maxJ;


    public:
    int prevDirection = -1;
    MovableTile(int type, int id, int pos, int nRows, int nCols);

    int GetMinPos(){return minPos;};
    int GetMaxPos(){return maxPos;};
    void SetMinPos(int minPos){this->minPos = minPos;};
    void SetMaxPos(int maxPos){this->maxPos = maxPos;};
    int GetFuturePos(){return futurePos;};
    Tile*& GetpTileHit(){return pTileHit;};
    
    void UpdateFuturePosition(int direction);
    void MoveRowAndCol();
    virtual void Move(Group* pGroup);
    void EchoMove(int direction);
    void Stepback();
    virtual bool CanIPush(int direction, Group* pGroup);

};

#endif