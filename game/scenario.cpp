#include "scenario.h"
#include <string>
#include <fstream>
#include <vector>
#include "tile.h"
#include "fixedTile.h"
#include "agent.h"

using namespace std;

Scenario::Scenario(){
    listLine = GetLines();
    UpdateScenarioSize();
    // DisplayLines();
    
    char2type['?'] = 1;
    char2type['#'] = 2;
    char2type['='] = 3;

    LoadTiles();

}

vector<string> Scenario::GetLines(){
    vector<string> lines;
    
    ifstream f(filename);
    string textLine;
    while (getline(f, textLine)){
        lines.push_back(textLine);
    }
    f.close();

    return lines;
}

void Scenario::UpdateScenarioSize(){
    rows = listLine.size();
    cols = listLine[0].length();
    scenarioW = cols * tileW;
    scenarioH = rows * tileH;

}

void Scenario::DisplayLines(){
    for (int i = 0; i < listLine.size(); i++){
        cout << listLine[i] << endl;
    }
}

void Scenario::LoadTiles(){
    char character;
    int type;
    float x = 0.0;
    float y = 0.0;
    int count = 0;
    
    vector<vector<int>> mTypes( rows , vector<int> (cols, 0));
    vector<vector<int>> mIndxs( rows , vector<int> (cols, -1));

    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            character = listLine[i][j];
            if (character != '-'){
                type = char2type[character];
                Tile* tile = new FixedTile(type, x, y, count);
                mTypes[i][j] = type;
                mIndxs[i][j] = count;
                this->listTile.push_back(tile);
                count += 1;
            }
            x += this->tileW;
        }
        x = 0;
        y += this->tileH;
    }

    this->types = mTypes;
    this->indxs = mIndxs;
    
    // for (int i = 0; i < this->listTile.size(); i++){
    //     this->listTile[i]->Display();
    // }
}

// void Scenario::Draw(Tile* pAgent){}