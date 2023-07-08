#ifndef TILE_H
#define TILE_H

#include <string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tile{
    private:

    int type;
    int iRow;
    int jCol;
    int id;

    public:
    bool canImove = false;
    bool amIpushable = false;

    virtual ~Tile(){};
    Tile(int type, int iRow, int jCol, int id);
    
    int GetType() const {return type;};
    int Get_iRow(){return iRow;};
    int Get_jCol(){return jCol;};
    int GetID(){return id;};
    void Set_iRow(float iRow){this->iRow = iRow;};
    void Set_jCol(float jCol){this->jCol = jCol;};
    
    
    virtual string GetStr() const = 0;
    virtual void Move() = 0;
    virtual bool CanIPush(vector<Tile*> &allOthers, string direction, vector<vector<int>> &matrixID) = 0;

    void Display() const {
        cout << GetStr() << endl;
    };
    
};

#endif