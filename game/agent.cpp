#include "agent.h"
#include "movableTile.h"
#include <vector>

#include <iostream>
#include <string>
using namespace std;

Agent::Agent(int type, int x, int y, int id) : MovableTile(type, x, y, id){

}

Agent::~Agent(){
}

void Agent::ProcessEvent(int event, vector<Tile*> allOthers){
    cout << allOthers.size() << endl;
    for (int i = 0; i < allOthers.size(); i++){
        cout << to_string(event) << " " << allOthers[i]->GetStr() << endl;
    }
    
}

bool Agent::CanIseeAgent(Agent* pAgent, vector<Tile*> listTile){
    float alphaThreshold = 25.0; //! check if this value is good ***************

    int n = listTile.size();
    int dx1;
    int dy1;
    int dx2;
    int dy2;
    int x = this->GetX();
    int y = this->GetY();
    int xAgent = pAgent->GetX();
    int yAgent = pAgent->GetY();
    int xTile;
    int yTile;
    float alpha;

    for (int i = 0; i < n; i++){
        xTile = listTile[i]->GetX();
        yTile = listTile[i]->GetY();

        dx1 = xAgent - xTile;
        dy1 = yAgent - yTile;

        dx2 = xTile - x;
        dy2 = yTile - y;

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