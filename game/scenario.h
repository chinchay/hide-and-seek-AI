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
    vector<Tile *> listTile;
    vector<vector<int>> types;
    vector<vector<int>> indxs;
    map<char, int> char2type;

    void LoadTiles();


    public:

    ~Scenario(){
        for (int i = 0; i < listTile.size(); i++){
            delete listTile[i];
        }        
        
        listTile.clear();

    };

    Scenario();
    int GetRows(){return rows;};
    int GetCols(){return cols;};

    vector<Tile *> GetListTile(){return listTile;};

    vector<string> GetLines();
    vector<vector<int>> GetTypes(){return types;};
    vector<vector<int>> GetIndxs(){return indxs;};

    void UpdateScenarioSize();

    void DisplayLines();

    // int GetCount(){return count;};

    // void Draw(Tile* pAgent);




};

#endif