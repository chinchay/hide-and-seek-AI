/*******************************************************************************
 * Header File:
 *    Scenario: The representation of a scenario or physical platform
 * Author:
 *    Carlos León
 ******************************************************************************/

#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "tile.h"
#include "fixedTile.h"
#include "cube.h"
#include "ramp.h"
#include "seeker.h"
#include "hider.h"

using namespace std;

class Scenario{
    private:
    vector<Tile *> allTiles;
    vector<Tile *> blocks;
    string filename = "platform.txt";
    int nCols = 0;
    int nRows = 0;
    // map<char, int> char2type;
    vector<string> listLine;
    void LoadTiles();
    Hider* pHider;
    Seeker* pSeeker;
    vector<string> GetLines();
    void UpdateScenarioSize();
    void DisplayLines();


    public:
    ~Scenario(){
        // for (int i = 0; i < listTile.size(); i++){
        //     delete listTile[i];
        // }
        // listTile.clear();
    };
    Scenario();
    int GetnRows(){return nRows;};
    int GetnCols(){return nCols;};
    vector<Tile *>& GetAllTiles(){return allTiles;};
    vector<Tile *>& GetBlocks(){return blocks;};
    Hider*& GetpHider(){return pHider;};
    Seeker*& GetpSeeker(){return pSeeker;};

};

#endif