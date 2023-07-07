#include <iostream>
#include <vector>
#include "scenario.h"
#include "hider.h"
#include "seeker.h"
#include "cube.h"

using namespace std;

int main(){
    
    Scenario scenario = Scenario();

    vector<Tile*> listFixedTile = scenario.GetListTile();

    int n = listFixedTile.size();

    int hiderX  = 0;
    int hiderY  = 0;
    int seekerX = 10;
    int seekerY = 10;
    Tile* pHider  = new Hider(8, hiderX, hiderY, n + 1);
    Tile* pSeeker = new Seeker(9, seekerX, seekerY, n + 2);

    int cubeX  = 20;
    int cubeY  = 20;
    Tile* pCube = new Cube(7, cubeX, cubeY, n + 3);

    vector<Tile*> listMovableTile;
    listMovableTile.push_back(pCube);

    
    vector<Tile*> allOthersForHider;
    for (int i = 0; i < listFixedTile.size(); i++){
        allOthersForHider.push_back(listFixedTile[i]);
    }
    for (int i = 0; i < listMovableTile.size(); i++){
        allOthersForHider.push_back(listMovableTile[i]);
    }
    allOthersForHider.push_back(pSeeker);

    
    vector<Tile*> allOthersForSeeker;
    for (int i = 0; i < listFixedTile.size(); i++){
        allOthersForSeeker.push_back(listFixedTile[i]);
    }
    for (int i = 0; i < listMovableTile.size(); i++){
        allOthersForSeeker.push_back(listMovableTile[i]);
    }
    allOthersForSeeker.push_back(pHider);    

    
    for (int i = 0; i < 1; i++){
        int event = 100;
        
        pHider->ProcessEvent(event, allOthersForHider);
        pSeeker->ProcessEvent(event, allOthersForSeeker);
    }



    // *************************************************************************
    // Free memory
    // *************************************************************************
    // for (int i = 0; i < listFixedTile.size(); i++){
    //     delete listFixedTile[i];
    // }        
    listFixedTile.clear();

    delete pHider;
    delete pSeeker;
    delete pCube;



    return 0;
}