#include "movableTile.h"
#include <iostream>
using namespace std;

MovableTile::MovableTile(int type, int iRow, int jCol, int id) : Tile(type, iRow, jCol, id){
    canImove = true;
    amIpushable = true;

    dPosition["up"] = vector<int>{-1,  0}; // [iRow][jCol]
    dPosition["dw"] = vector<int>{ 1,  0};
    dPosition["<-"] = vector<int>{ 0, -1};
    dPosition["->"] = vector<int>{ 0,  1};

    iRowFuture = Get_iRow();
    jColFuture = Get_jCol();

}

void MovableTile::UpdateFuturePosition(string direction, int rows, int cols){
    int i = iRowFuture + dPosition[direction][0];
    int j = jColFuture + dPosition[direction][1];
    
    if ((0 <= i) and (i < rows)){
        iRowFuture = i;
    }

    if ((0 <= j) and (j < cols)){
        jColFuture = j;
    }
}

void MovableTile::Move(){
    Set_iRow(iRowFuture);
    Set_jCol(jColFuture);
    if (pTileHit != NULL){
        pTileHit->Move();
    }
}

void MovableTile::EchoMove(string direction){
    cout << GetStr();
    cout << ". I have ID=" + to_string(GetID()) + ", moving " + direction << endl;
}

bool MovableTile::CanIPush(vector<Tile*> &allOthers, string direction, vector<vector<int>> &matrixID){
    if (direction != "none"){    
        int rows = matrixID.size();
        int cols = matrixID[0].size();

        UpdateFuturePosition(direction, rows, cols);

        if ( (Get_iRow() != iRowFuture) or (Get_jCol() != jColFuture) ){
            
            
            int id = matrixID[iRowFuture][jColFuture];
            if (id != -1){
                pTileHit = allOthers[id];
                if (pTileHit->amIpushable){
                    if (not pTileHit->CanIPush(allOthers, direction, matrixID)){
                        return false;
                    }
                }else{
                    return false;
                }
            }
            pTileHit = NULL;
            return true;
        }
    }
    return false;
}