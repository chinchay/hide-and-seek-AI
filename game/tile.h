#ifndef TILE_H
#define TILE_H

#include <string>
#include "group.h"
#include <iostream>

using namespace std;

class Group;

//******************************************************************************
// TILE is an abstract class. The screen will be made up of several tiles which 
// can be categorized into movable or not movable objects
//******************************************************************************
class Tile{
    private:
    string tileDeriv = "";
    int type  = -1;
    int id    = -1;
    int pos   = -1;
    int row   = -1;
    int col   = -1;
    int nRows = -1;
    int nCols = -1;

    public:
    bool canImove = false;
    bool amIpushable = false;

    virtual ~Tile(){};
    Tile(int type, int id, int pos, int nRows, int nCols);
    
    int GetType() const {return type;};
    int GetID() const {return id;};
    
    int GetPos() const {return pos;};
    int GetRow() const {return row;};
    int GetCol() const {return col;};
    
    void SetPos(int pos){this->pos = pos;};
    void SetRow(int row){this->row = row;};
    void SetCol(int col){this->col = col;};

    int GetnRows(){return nRows;};
    int GetnCols(){return nCols;};

    string GetTileDeriv(){return tileDeriv;};
    void SetTileDeriv(string tileDeriv){this->tileDeriv = tileDeriv;}

    string GetStr();
    virtual void Move(Group* pGroup) = 0;
    virtual bool CanIPush(int direction, Group* pGroup) = 0;

    void Display() {
        cout << GetStr() << endl;
    }; 
};

#endif