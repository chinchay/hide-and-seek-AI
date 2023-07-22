#include "agent.h"
#include "movableTile.h"
#include "group.h"
#include <vector>

#include <iostream>
#include <fstream>
#include <string>

#include <cstring> // for memset(), errors in docker if not added

#include <cmath>

using namespace std;

Agent::Agent(int type, int id, int pos, int nRows, int nCols, string filename) : MovableTile(type, id, pos, nRows, nCols){
    this->filename = filename;
    canImove = true;
    amIpushable = false;
    nCells = nRows * nCols;
    for (int i = 0; i < nCells; i++){
        blocksIcanSee.push_back(-1);
    }

}

void Agent::ProcessEvent(int event, Group* pGroup){
    //*** Make tiles introduce themselves ****
    // for (Tile* pTile : pGroup->listTile){
    //     cout << pTile->GetStr() << endl;
    // }
    Tile* pTileHit;
    int direction = GetDirection(event);
    
    if (direction != -1){
        if (direction <= 3){
            // cout << direction << endl;
            prevDirection = direction;
            if (CanIPush(direction, pGroup)){
                // cout << "i can move it"<< endl;
                Move(pGroup);
                // listMove.push_back(event);
            }

        }else{
            if (GetTileDeriv() == "Seeker" ){
                pTileHit = GetpTileHit();
                if (pTileHit != nullptr){
                    // cout << "here2" << endl;
                    // if ( pTileHit->GetTileDeriv() == "Ramp" ){
                    if ( pTileHit->GetType() == 3 ){
                        // cout << "antes:   " << GetRow() << " - " << GetCol() << " - " << GetPos() << " futurepos: " + to_string(GetFuturePos()) << endl;
                        // SetZ(1);
                        // pTileHit->GetPos()
                        // MoveRowAndCol(); // futureRow is already known since pTileHit is not null
                        // SetPos(GetFuturePos()); // futurePos is already known
                        // cout << "before: " << GetRow() << " - " << GetCol() << " - " << GetPos() << endl;

                        int prevPos = GetPos();
                        int count = 0;
                        
                        UpdateFuturePosition(prevDirection);

                        while ((pGroup->GetpTileFromPos(GetFuturePos()) != nullptr) and (count < 20) ){
                            // cout << "hi" << endl;
                            MoveRowAndCol();
                            SetPos(GetFuturePos());
                            UpdateFuturePosition(prevDirection);
                            count += 1;
                        }
                        MoveRowAndCol();
                        SetPos(GetFuturePos());


                        pGroup->pos2Tile[prevPos] = nullptr;
                        pGroup->typeSequence[prevPos] = 0; // "nothing" is there now

                        pGroup->pos2Tile[GetPos()] = this;
                        pGroup->typeSequence[GetPos()] = GetType();

                        // cout << "despues: " << GetRow() << " - " << GetCol() << " - " << GetPos() << " futurepos: " + to_string(GetFuturePos()) << endl;

                    }
                }
            }

            // cout << "here" << endl;
            // if (GetTileDeriv() == "Seeker" ){
            //     pTileHit = GetpTileHit();
            //     if (pTileHit != nullptr){
            //         cout << "here2" << endl;
            //         if ( pTileHit->GetTileDeriv() == "Ramp" ){
            //             cout << "antes:  " << GetRow() << " - " << GetCol() << " - " << GetPos() << endl;
            //             SetZ(1);
            //             // pTileHit->GetPos()
            //             MoveRowAndCol(); // futureRow is already known since pTileHit is not null
            //             SetPos(GetFuturePos()); // futurePos is already known
            //             cout << "before: " << GetRow() << " - " << GetCol() << " - " << GetPos() << endl;
            //         }
            //     }
            // }
        }

    }else{
        // cout << " --- "<< endl;
    }


}

void Agent::SaveMoves(){
    ofstream f(filename);
    for (int i = 0; i < listMove.size(); i++){
        f << listMove[i];
    }
    f.close();
}

bool Agent::CanIseeAgent(Agent* pAgent, vector<Tile*>& listBlocks){
// bool Agent::CanIseeAgent(Agent* pAgent, Tile* pTail){
    float cosThreshold = 0.90; //! check if this value is good ***************

    int i1 = GetRow();
    int j1 = GetCol();
    int i2 = pAgent->GetRow();
    int j2 = pAgent->GetCol();

    float cos;
    int it;
    int jt;
    int it1;
    int jt1;
    int i2t;
    int j2t;

    for (Tile* pTail : listBlocks){
        // cout << pTail->GetStr() << " " << to_string(pTail->GetPos()) << endl;
        
        it = pTail->GetRow();
        jt = pTail->GetCol();

        it1 = it - i1;
        jt1 = jt - j1;
        i2t = i2 - it;
        j2t = j2 - jt;

        // cout << to_string(it) << "<>" << to_string(jt) << endl;
        // cout << to_string(j2) << "<>" << to_string(jt) << endl;
        // cout << to_string(it1) << "<>" << to_string(jt1) << "..." << to_string(i2t) << "<>" << to_string(j2t) << endl;

        // ensure they point to the same quadrant:
        if (it1 * i2t >= 0){
            if (jt1 * j2t >= 0){
                // ensure they point to the same half of a quadrant:
                if ( (it1 - jt1) * (i2t - j2t) >= 0 ){
                    // pTail->Display();

                    cos = ComputeCos(it1, jt1, i2t, j2t);

                    //* It is enough one tile covering the sight to the other agent (hider)
                    // cout <<  cos << " " <<  cosThreshold << endl;
                    if (cos > cosThreshold){ //0.62 < 0.8, 0.84 < 0.8
                        return false;
                    }                    
                }
            }
        }
    }

    //* no tile is covering the sight to the agent (hider)
    return true;
    

}

void Agent::ResetBlocksIcanSee(){
    // this one is too slow!! not due to the assignment, but to the loop itself
    // for (int i = 0; i < nCells; i++){
    //     blocksIcanSee[i] = -1;
    // }

    // this one is faster
    // https://stackoverflow.com/questions/8848575/fastest-way-to-reset-every-value-of-stdvectorint-to-0
    memset(&blocksIcanSee[0], -1, blocksIcanSee.size() * sizeof blocksIcanSee[0]);


}

void Agent::UpdateBlocksIcanSee(vector<Tile*>& listBlocks){
    ResetBlocksIcanSee();
    
    int i1 = GetRow();
    int j1 = GetCol();
    int it;
    int jt;
    int it1;
    int jt1;
    int nCols = GetnCols();
    int nRows = GetnRows();

    for (Tile* pTail : listBlocks){        
        it = pTail->GetRow();
        jt = pTail->GetCol();

        it1 = it - i1;
        jt1 = jt - j1;

        if (abs(it1) <= sightRadius){
            if (abs(jt1) <= sightRadius){
                blocksIcanSee[ (it * nCols) + jt ] = pTail->GetType();
                // cout <<"it, jt, pos: " << to_string(it) << " " << to_string(jt) << "-" << to_string((it * nCols) + jt) << "-" << blocksIcanSee[ (it * nCols) + jt ] << endl;
            }
        }
    }

    int count = 0;
    int minCol = 0;
    int k = 0;
    int pos = 0;

    for (int i = i1 - sightRadius; i < i1 + sightRadius + 1; i++){
        if ( (0 <= i) and (0 < nRows) ){
            for (int j = j1 - sightRadius; j < j1 + sightRadius + 1; j++){
                if( (0 <= j) and (j < nCols) ){
                    pos = (i * nCols) + j;
                    if (blocksIcanSee[pos] == -1){
                        blocksIcanSee[pos] = 0;
                    }
                }
            }
        }
    }

    // cout << endl;
    // cout <<"see unit: " << blocksIcanSee[ 57 ] << endl;

    // for (int i = 0; i < blocksIcanSee.size(); i++){
    //     cout << blocksIcanSee[i];
    //     if (i > 0){
    //         if ((i + 1) % nCols == 0){
    //             cout << endl;
    //         }        
    //     }
    // }

}

float Agent::ComputeCos(int x1, int y1, int x2, int y2){
    //! ************************************************************************
    //! TODO IMPLEMENTATION
    //! ************************************************************************

    float norm1 = sqrt( (x1 * x1) + (y1 * y1) );
    float norm2 = sqrt( (x2 * x2) + (y2 * y2) );
    // cout << to_string(x1) << " " << to_string(y1) << "---" << to_string(x2) << " " << to_string(y2) << endl;
    // cout << to_string(norm1) << " " << to_string(norm2) << endl;
    
    float cos;
    
    try{
        cos = ((x1 * x2) + (y1 * y2)) / (norm1 * norm2);
        // cout << cos << endl;
    }catch(int e){
        cout << "x1 y1 ... values:" << endl;
        cout << to_string(x1) << endl;
        cout << to_string(y1) << endl;
        cout << to_string(x2) << endl;
        cout << to_string(y2) << endl;
    }
    
    

    return cos;
}