#include "agent.h"
#include "movableTile.h"
#include "group.h"
#include <vector>

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Agent::Agent(int type, int id, int pos1dim, int rows, int cols, string filename) : MovableTile(type, id, pos1dim, rows, cols){
    this->filename = filename;
    canImove = true;
    amIpushable = false;
}

void Agent::ProcessEvent(int event, Group* pGroup){
    //*** Make tiles introduce themselves ****
    // for (Tile* pTile : pGroup->listTile){
    //     cout << pTile->GetStr() << endl;
    // }

    string direction = GetDirection(event);
    
    if (direction != "none"){
        cout << direction << endl;
        if (CanIPush(direction, pGroup)){
            // cout << "i can move it"<< endl;
            Move(pGroup);
            listMove.push_back(event);
        }
    }else{
        cout << " --- "<< endl;
    }
}

void Agent::SaveMoves(){
    ofstream f(filename);
    for (int i = 0; i < listMove.size(); i++){
        f << listMove[i];
    }
    f.close();
}

bool Agent::CanIseeAgent(Agent* pAgent, Group* pGroup){
    float alphaThreshold = 25.0; //! check if this value is good ***************

    int p1 = GetPos1dim();
    int p2 = pAgent->GetPos1dim();
    
    int alpha;
    int pt;
    int pt1;
    int it1;
    int jt1;
    int p2t;
    int i2t;
    int j2t;

    for (Tile* pTail : pGroup->listTile ){
        pt = pTail->GetPos1dim();

        pt1 = pt - p1;
        it1 = pt1 / GetCols();
        jt1 = pt1 % GetCols();

        p2t = p2 - pt;
        i2t = p2t / GetCols();
        j2t = p2t % GetCols();

        // ensure they point to the same quadrant:
        if (it1 * i2t >= 0){
            if (jt1 * j2t >= 0){
                // ensure they point to the same half of a quadrant:
                if ( (it1 - jt1) * (i2t - j2t) >= 0 ){
                    alpha = GetArcCos(it1, jt1, i2t, j2t);

                    //* It is enough one tile covering the sight to the other agent (hider)
                    if (alpha < alphaThreshold){
                        return false;
                    }                    
                }
            }
        }
    }

    //* no tile is covering the sight to the agent (hider)
    return true;
    

}

float Agent::GetArcCos(int x1, int y1, int x2, int y2){
    //! ************************************************************************
    //! TODO IMPLEMENTATION
    //! ************************************************************************
    return 0.0;
}