#include "movableTile.h"
#include "group.h"
#include <iostream>
using namespace std;

MovableTile::MovableTile(int type, int id, int pos, int nRows, int nCols) : Tile(type, id, pos, nRows, nCols){
    canImove = true;
    amIpushable = true;

    this->nCells = nRows * nCols;

    // dPos1dim["up"] = -cols;
    // dPos1dim["dw"] =  cols;
    // dPos1dim["<-"] = -1;
    // dPos1dim["->"] =  1;

    // dPos[0] = -nCols; // "-y" = up
    // dPos[1] =  nCols; // "+y" = dw
    // dPos[2] = -1;    // "-x" = <-
    // dPos[3] =  1;    // "+x" = -> 

    dPos.push_back(-nCols);
    dPos.push_back( nCols);
    dPos.push_back(-1);
    dPos.push_back(1);

    this->minPos = (GetPos() / nCols) * nCols;
    this->maxPos = minPos + nCols - 1;

    this->futurePos = GetPos();
    this->futureRow = GetRow();
}

void MovableTile::UpdateFuturePosition(int direction){
    int p     = GetPos();
    int dP    = dPos[direction];
    int k     = p + dP;
    int nCols = GetnCols();

    // cout << "hi there " << " "<< to_string(GetMinPos())        << " "  << to_string(k)        << " " << to_string(GetMaxPos())        << "  " << endl;
    // cout << "hi       " << " "<< to_string(GetMinPos() / cols) << " "  << to_string(k / cols) << " " << to_string(GetMaxPos() / cols) << "  " << endl;


    if ((0 <= k) and (k < nCells)){

        if (dP == -1){
            if (minPos <= k){
                this->futurePos = k;
                this->futureRow = GetRow();
                // cout << "hi there " << " "<< to_string(minPos)        << " "  << to_string(k)        << " " << to_string(maxPos)        << "  " << endl;
                // cout << "hi       " << " "<< to_string(minPos / cols) << " "  << to_string(k / cols) << " " << to_string(maxPos / cols) << "  " << endl;

            }
        }else if (dP == 1){
            if (k <= maxPos){
                this->futurePos = k;
                this->futureRow = GetRow();
                // cout << "hi there " << " "<< to_string(minPos)        << " "  << to_string(k)        << " " << to_string(maxPos)        << "  " << endl;
                // cout << "hi       " << " "<< to_string(minPos / cols) << " "  << to_string(k / cols) << " " << to_string(maxPos / cols) << "  " << endl;


            }            
        }else if (dP == -nCols){
            this->futurePos = k;
            this->futureRow = GetRow() - 1;
                // cout << "hi there " << " "<< to_string(minPos)        << " "  << to_string(k)        << " " << to_string(maxPos)        << "  " << endl;
                // cout << "hi       " << " "<< to_string(minPos / cols) << " "  << to_string(k / cols) << " " << to_string(maxPos / cols) << "  " << endl;


            // SetMinJ(GetMinJ() - cols);
            // SetMaxJ(GetMaxJ() - cols);
            // minJthisRow -= cols;
            // maxJthisRow -= cols;
        }else if (dP == nCols){
            this->futurePos = k;
            this->futureRow = GetRow() + 1;
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

void MovableTile::MoveRowAndCol(){
    // *************************************************************************
    // currentRow = futureRow;
    // minPos = currentRow * cols;
    // maxPos = minPos + cols - 1;

    int row = GetRow();
    int nCols = GetnCols();

    if (futureRow != row){
        if (futureRow < row){
            this->minPos -= nCols;
            this->maxPos = minPos + nCols - 1;
            
        }else{
            this->minPos += nCols;
            this->maxPos = minPos + nCols - 1;
        }

        SetRow(futureRow);
    }else{ // same row
        // cout << "col:    " << GetCol() << endl;
        SetCol( GetCol() + futurePos - GetPos() );
        // currentCol += (futurePos - GetPos());
        // cout << "col:||| " << GetCol() << endl;
    }
}

void MovableTile::Move(Group* pGroup){
    MoveRowAndCol();

    pGroup->IDstackPush(GetID());
    
    SetPos(this->futurePos);

    if (pTileHit != nullptr){
        pTileHit->Move(pGroup);
    }else{
        pGroup->IDstackEnd();
    }
    // cout << GetStr() << " : moving." << endl;
}

void MovableTile::EchoMove(int direction){
    cout << GetStr();
    cout << ". I have ID=" + to_string(GetID()) + ", moving " + to_string(direction) << endl;
}

void MovableTile::Stepback(){
    futureRow = GetRow();
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

    futurePos = GetPos();
}



bool MovableTile::CanIPush(int direction, Group* pGroup){
    if (direction != -1){
        UpdateFuturePosition(direction);
        if ( GetPos() != futurePos ){ // takes care of getting out of the box, not allowed. See `UpdateFuturePosition()`
            // Display();
            this->pTileHit = pGroup->GetpTileFromPos(futurePos);
            if (this->pTileHit != nullptr){
                // pTileHit->Display();

                
                // if ( (this->pTileHit->GetTileDeriv() == "Cube") and (GetTileDeriv() == "Seeker" )){
                if ( (this->pTileHit->GetType() == 2) and (GetType() == 5 )){
                    return false;
                }


                if (this->pTileHit->amIpushable){
                    // this->pTileHit->Display();
                    if (not this->pTileHit->CanIPush(direction, pGroup)){
                        // Stepback();
                        return false;
                    }
                }else{
                    // Stepback();
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}