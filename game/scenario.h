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

using namespace std;

class Scenario{
    private:
    int tileW = 1; // 50, no need to be 50, since it'll be run in the background
    int tileH = 1; // 50
    int cols = 0;
    int rows = 0;
    int scenarioW = 0;
    int scenarioH = 0;
    string filename = "platform.txt";
    vector<string> listLine;
    int count = 0;
    vector<Tile *> listFixedTilePtr;
    map<char, int> char2int;


    public:


    ~Scenario(){
        for (int i = 0; i < listFixedTilePtr.size(); i++){
            delete listFixedTilePtr[i];
        }        
        
        listFixedTilePtr.clear();

    };

    Scenario();

    vector<string> GetLines();

    void UpdateScenarioSize();

    void DisplayLines();

    void LoadTiles();


};

#endif