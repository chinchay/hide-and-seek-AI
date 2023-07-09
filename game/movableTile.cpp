#include "movableTile.h"
#include "group.h"
#include <iostream>
using namespace std;

MovableTile::MovableTile(int type, int id, int pos1dim, int rows, int cols) : Tile(type, id, pos1dim){
    canImove = true;
    amIpushable = true;

    this->rows = rows;
    this->cols = cols;
    this->nCells = rows * cols;

    dPos1dim["up"] = -cols;
    dPos1dim["dw"] =  cols;
    dPos1dim["<-"] = -1;
    dPos1dim["->"] =  1;

    futurePos1dim = GetPos1dim();
}

void MovableTile::UpdateFuturePosition(string direction){
    int dP = dPos1dim[direction];
    int p = GetPos1dim();
    int k = p + dP;
    int cols = GetCols();
    if ((0 <= k) and (k < nCells)){
        if (dP == -1){
            if (p % cols != 0){
                futurePos1dim = k;
            }
        }else if (dP == 1){
            if (p % cols != (cols - 1)){
                futurePos1dim = k;
            }
        }else{
            futurePos1dim = k;
        }
    }
}

void MovableTile::Move(Group* pGroup){
    pGroup->IDstackPush(GetID());
    SetPos1dim(futurePos1dim);

    if (pTileHit != NULL){
        pTileHit->Move(pGroup);
    }else{
        pGroup->IDstackEnd();
    }
}

void MovableTile::EchoMove(string direction){
    cout << GetStr();
    cout << ". I have ID=" + to_string(GetID()) + ", moving " + direction << endl;
}

void MovableTile::Stepback(){
    futurePos1dim = GetPos1dim();
}

bool MovableTile::CanIPush(string direction, Group* pGroup){
    if (direction != "none"){
        UpdateFuturePosition(direction);
        if ( GetPos1dim() != futurePos1dim ){ // takes care of getting out of the box, not allowed. See `UpdateFuturePosition()`
            this->pTileHit = pGroup->GetpTileFromPos1dim(futurePos1dim);
            if (this->pTileHit != NULL){
                if (this->pTileHit->amIpushable){
                    // this->pTileHit->Display();
                    if (not this->pTileHit->CanIPush(direction, pGroup)){
                        Stepback();
                        return false;
                    }
                }else{
                    Stepback();
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}