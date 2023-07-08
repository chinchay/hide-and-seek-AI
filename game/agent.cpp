#include "agent.h"
#include "movableTile.h"
#include <vector>

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Agent::Agent(int type, int iRow, int jCol, int id, string filename) : MovableTile(type, iRow, jCol, id){
    this->filename = filename;
    canImove = true;
    amIpushable = false;
}

Agent::~Agent(){
}

void Agent::ProcessEvent(int event, vector<Tile*> &allOthers, vector<vector<int>> &matrixID){
    // // Make tiles introduce themselves
    // cout << allOthers.size() << endl;
    // for (int i = 0; i < allOthers.size(); i++){
    //     cout << to_string(event) << " " << allOthers[i]->GetStr() << endl;
    // }

    string direction = GetDirection(event);
    if (direction != "none"){
        if (CanIPush(allOthers, direction, matrixID)){
            Move();
            listMove.push_back(event);
        }
    }
}

void Agent::SaveMoves(){
    ofstream f(filename);
    for (int i = 0; i < listMove.size(); i++){
        f << listMove[i];
    }
    f.close();
}

bool Agent::CanIseeAgent(Agent* pAgent, vector<Tile*> &listTile){
    float alphaThreshold = 25.0; //! check if this value is good ***************

    int n = listTile.size();
    int dx1;
    int dy1;
    int dx2;
    int dy2;
    int iRow = this->Get_iRow();
    int jCol = this->Get_jCol();
    int iRowAgent = pAgent->Get_iRow();
    int jColAgent = pAgent->Get_jCol();
    int iRowTile;
    int jColtile;
    float alpha;

    for (int i = 0; i < n; i++){
        iRowTile = listTile[i]->Get_iRow();
        jColtile = listTile[i]->Get_jCol();

        dx1 = iRowAgent - iRowTile;
        dy1 = jColAgent - jColtile;

        dx2 = iRowTile - iRow;
        dy2 = jColtile - jCol;

        alpha = GetArcCos(dx1, dy1, dx2, dy2);
        
        //* It is enough one tile covering the sight to the other agent (hider)
        if (alpha < alphaThreshold){
            return false;
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