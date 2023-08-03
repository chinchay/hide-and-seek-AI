#include "game.h"

#include <iostream>
#include <vector>
#include "scenario.h"
#include "hider.h"
#include "seeker.h"
#include "cube.h"
#include "group.h"
#include <map>
#include <queue>



using namespace std;

//******************************************************************************
// The GAME function sets up the hide and seek program
//******************************************************************************
Game::Game(int nSleepIter, int display){
    this->nSleepIter = nSleepIter;
    this->display = display;

    Scenario scenario = Scenario();
    this->nRows = scenario.GetnRows();
    this->nCols = scenario.GetnCols();
    int nCells = nRows * nCols;

    for(int i = 0; i < nCells; i++){
        this->sceneHider.push_back(-1);
        this->sceneSeeker.push_back(-1);
    }

    this->allTiles = scenario.GetAllTiles();
    this->blocks   = scenario.GetBlocks();
    this->pHider   = scenario.GetpHider();
    this->pSeeker  = scenario.GetpSeeker();

    this->pGroup = new Group(this->allTiles, nCells);

}

void Game::RunOneEvent(int event, int iteration){
    if (display == 1){
        system("clear");
        DisplayOnTerminal();
        // cout << ". Iteration = " + to_string(i) << endl;

    }

    if (gameOver == 1){
        // cout << "GAME OVER"<< endl;
        // exit(0);
    }

    if (display == 1){
        string temp;
        // cout << "Enter digit: " + to_string(event) << ". Iteration = " + to_string(iteration) << endl;
        cout << "Enter digit: ";
        getline(cin, temp);
        event = stoi(temp);
    }
    
    pHider->ProcessEvent(event, pGroup);

    // IT'S NIGHT, SEEKERS ARE SLEEPING
    if (iteration > nSleepIter){
        isDay = 1;
        pSeeker->ProcessEvent(event, pGroup);
    }

    // After having moved or made a jump, update 
    // the blocks (only blocks, not the agents) an agent can see
    pHider->UpdateBlocksIcanSee(blocks);
    sceneHider = pHider->GetWhatIcanSee();       
    
    pSeeker->UpdateBlocksIcanSee(blocks);
    sceneSeeker = pSeeker->GetWhatIcanSee();


    // IT'S NIGHT, SEEKERS ARE SLEEPING
    if (iteration > nSleepIter){
        if (pSeeker->CanIseeAgent(pHider, blocks)){
            sceneSeeker[ pHider->GetPos() ] = pHider->GetType();
            sceneHider[ pSeeker->GetPos() ] = pSeeker->GetType();
            gameOver = 1;
        }
    }

}

void Game::DisplayOnTerminal(){

    map<int, char> type2Symbol;
    type2Symbol[-1] = '.';
    type2Symbol[0]  = '-';
    type2Symbol[1]  = '#';
    type2Symbol[2]  = '=';
    type2Symbol[3]  = '?';
    type2Symbol[4]  = 'H';
    type2Symbol[5]  = 'S';

    int count = 0;
    Tile* pTile;
    
    cout << endl;

    if (( this->sceneHider.size() == 0) and ( this->sceneSeeker.size() == 0)){
        for(int i = 0; i < this->nRows; i++){
            for (int j = 0; j < this->nCols; j++){
                pTile = this->pGroup->pos2Tile[count];
                if (pTile != nullptr){
                    cout << type2Symbol[ pTile->GetType() ];
                }
                else{
                    // cout << " ";
                    cout << "-";
                }
                count += 1;
                if (count % this->nCols == 0){
                    cout << endl;
                }
            }
        }
    }else{
        string space = "     ";
        string symbol1 = "";
        string symbol2 = "";
        string symbol3 = "";
        int pos;
        queue<string> listS1;
        queue<string> listS2;
        queue<string> listS3;
        
        int count = 0;
        for(int i = 0; i < this->nRows; i++){
            for (int j = 0; j < this->nCols; j++){
                pTile = this->pGroup->pos2Tile[count];
                if (pTile != nullptr){
                    symbol1 = type2Symbol[ pTile->GetType() ];
                }
                else{
                    symbol1 = "-";
                }

                listS1.push(symbol1);

                symbol2 = type2Symbol[ this->sceneSeeker[count] ];
                listS2.push(symbol2);

                symbol3 = type2Symbol[ this->sceneHider[count] ];
                listS3.push(symbol3);

                // count addition needs to be at the end:
                count += 1;

            }
            
            for (int j = 0; j < this->nCols; j++){
                cout << listS1.front();
                listS1.pop();
            }
            cout << space;
            for (int j = 0; j < this->nCols; j++){
                cout << listS3.front();
                listS3.pop();
            }
            cout << space;
            for (int j = 0; j < this->nCols; j++){
                cout << listS2.front();
                listS2.pop();
            }

            cout << endl;

        }
    }
    cout << endl;
}


