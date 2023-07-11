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

    // dPos1dim["up"] = -cols;
    // dPos1dim["dw"] =  cols;
    // dPos1dim["<-"] = -1;
    // dPos1dim["->"] =  1;

    dPos1dim[0] = -cols; // "-y" = up
    dPos1dim[1] =  cols; // "+y" = dw
    dPos1dim[2] = -1;    // "-x" = <-
    dPos1dim[3] =  1;    // "+x" = -> 

        
    this->minPos = (GetPos1dim() / cols) * cols;
    this->maxPos = minPos + cols - 1;

    currentRow = GetPos1dim() / cols;
    futureRow  = currentRow;

    futurePos1dim = GetPos1dim();

}

void MovableTile::UpdateFuturePosition(int direction){
    int p  = GetPos1dim();
    int dP = dPos1dim[direction];
    int k  = p + dP;
    int cols = GetCols();

    // cout << "hi there " << " "<< to_string(GetMinPos())        << " "  << to_string(k)        << " " << to_string(GetMaxPos())        << "  " << endl;
    // cout << "hi       " << " "<< to_string(GetMinPos() / cols) << " "  << to_string(k / cols) << " " << to_string(GetMaxPos() / cols) << "  " << endl;


    if ((0 <= k) and (k < nCells)){

        if (dP == -1){
            if (minPos <= k){
                futurePos1dim = k;
                futureRow = currentRow;
                // cout << "hi there " << " "<< to_string(minPos)        << " "  << to_string(k)        << " " << to_string(maxPos)        << "  " << endl;
                // cout << "hi       " << " "<< to_string(minPos / cols) << " "  << to_string(k / cols) << " " << to_string(maxPos / cols) << "  " << endl;

            }
        }else if (dP == 1){
            if (k <= maxPos){
                futurePos1dim = k;
                futureRow = currentRow;
                // cout << "hi there " << " "<< to_string(minPos)        << " "  << to_string(k)        << " " << to_string(maxPos)        << "  " << endl;
                // cout << "hi       " << " "<< to_string(minPos / cols) << " "  << to_string(k / cols) << " " << to_string(maxPos / cols) << "  " << endl;


            }            
        }else if (dP == -cols){
            futurePos1dim = k;
            futureRow = currentRow - 1;
                // cout << "hi there " << " "<< to_string(minPos)        << " "  << to_string(k)        << " " << to_string(maxPos)        << "  " << endl;
                // cout << "hi       " << " "<< to_string(minPos / cols) << " "  << to_string(k / cols) << " " << to_string(maxPos / cols) << "  " << endl;


            // SetMinJ(GetMinJ() - cols);
            // SetMaxJ(GetMaxJ() - cols);
            // minJthisRow -= cols;
            // maxJthisRow -= cols;
        }else if (dP == cols){
            futurePos1dim = k;
            futureRow = currentRow + 1;
                // cout << "hi there " << " "<< to_string(minPos)        << " "  << to_string(k)        << " " << to_string(maxPos)        << "  " << endl;
                // cout << "hi       " << " "<< to_string(minPos / cols) << " "  << to_string(k / cols) << " " << to_string(maxPos / cols) << "  " << endl;


            // SetMinJ(GetMinJ() + cols);
            // SetMaxJ(GetMaxJ() + cols);
            // minJthisRow += cols;
            // maxJthisRow += cols;            
        }
    }


    // if ((0 <= k) and (k < nCells)){
    //     if (dP == -1){
    //         if (p % cols != 0){
    //             futurePos1dim = k;
    //         }
    //     }else if (dP == 1){
    //         if (p % cols != (cols - 1)){
    //             futurePos1dim = k;
    //         }
    //     }else{
    //         futurePos1dim = k;
    //     }
    // }
}

void MovableTile::Move(Group* pGroup){
    pGroup->IDstackPush(GetID());
    SetPos1dim(futurePos1dim);


    // *************************************************************************
    // currentRow = futureRow;
    // minPos = currentRow * cols;
    // maxPos = minPos + cols - 1;

    if (futureRow != currentRow){
        if (futureRow < currentRow){
            minPos -= cols;
            maxPos = minPos + cols - 1;
        }else{
            minPos += cols;
            maxPos = minPos + cols - 1;
        }

        currentRow = futureRow;
    }


    // *************************************************************************

    if (pTileHit != NULL){
        pTileHit->Move(pGroup);
    }else{
        pGroup->IDstackEnd();
    }
}

void MovableTile::EchoMove(int direction){
    cout << GetStr();
    cout << ". I have ID=" + to_string(GetID()) + ", moving " + to_string(direction) << endl;
}

void MovableTile::Stepback(){
    futureRow = currentRow;
    // if (currentRow != futureRow){
    //     if (futureRow < currentRow){
    //         SetMinPos(GetMinPos() - cols);
    //         SetMaxPos(GetMaxPos() - cols);
    //     }else if(futureRow > currentRow){
    //         SetMinPos(GetMinPos() + cols);
    //         SetMaxPos(GetMaxPos() + cols);
    //     }
    //     futureRow = currentRow;
    // }

    futurePos1dim = GetPos1dim();
}



bool MovableTile::CanIPush(int direction, Group* pGroup){
    if (direction != -1){
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