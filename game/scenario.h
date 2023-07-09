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
    vector<Tile *> listTile;
    string filename = "platform.txt";
    int cols = 0;
    int rows = 0;
    map<char, int> char2type;
    vector<string> listLine;
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
    void UpdateScenarioSize();
    void DisplayLines();

};

#endif