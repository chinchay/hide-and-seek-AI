#include <iostream>
#include <vector>
#include "scenario.h"
#include "hider.h"
#include "seeker.h"
#include "cube.h"
#include <stdlib.h>

using namespace std;

int main(){

    srand (time(NULL));
    vector<int> listRands;
    for (int i = 0; i < 100; i++){
        listRands.push_back( rand() % 10 ); // range 0 to 10-1=9
    }

    
    Scenario scenario = Scenario();

    vector<Tile*> listFixedTile = scenario.GetListTile();
    vector<vector<int>> matrixTypes = scenario.GetTypes();
    vector<vector<int>> matrixID = scenario.GetIndxs();
    // int rows = scenario.GetRows();
    // int cols = scenario.GetCols();

    // for(int i = 0; i < 12; i++)
    // {
    //     for (int j = 0; j < 26; j++)
    //     {
    //         cout << matrixTypes[i][j] << " ";
    //     }    
    //     cout << endl;
    // }

    int n = listFixedTile.size();

    float hiderX  = 0.0;
    float hiderY  = 0.0;
    string hiderFile = "hider.txt";
    
    float seekerX = 10.0;
    float seekerY = 10.0;
    string seekerFile = "seeker.txt";
    
    // Tile* pHider  = new Hider(8, hiderX, hiderY, n + 1, hiderFile);
    // Tile* pSeeker = new Seeker(9, seekerX, seekerY, n + 2, seekerFile);
    Hider* pHider  = new Hider(8, hiderX, hiderY, n + 1, hiderFile);
    Seeker* pSeeker = new Seeker(9, seekerX, seekerY, n + 2, seekerFile);


    float cubeX  = 20.0;
    float cubeY  = 20.0;
    // Tile* pCube = new Cube(7, cubeX, cubeY, n + 3);
    Cube* pCube = new Cube(7, cubeX, cubeY, n + 3);

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

    
    int event;
    for (int i = 0; i < listRands.size(); i++){
        // int event = 8;
        event = listRands[i];
        
        pHider->ProcessEvent(event, allOthersForHider, matrixID);
        // pSeeker->ProcessEvent(event, allOthersForSeeker, matrixID);
        
    }

    // pHider->SaveMoves();


    



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