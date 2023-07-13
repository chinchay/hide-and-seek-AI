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
    nRows = listLine.size();
    nCols = listLine[0].length();
}

void Scenario::DisplayLines(){
    for (int i = 0; i < listLine.size(); i++){
        cout << listLine[i] << endl;
    }
}

void Scenario::LoadTiles(){
    char character;
    int type;
    int id = 0;
    int pos = 0;
    
    for(int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            character = listLine[i][j];
            if (character != '-'){
                type = char2type[character];
                Tile* pTile = new FixedTile(type, id, pos, nRows, nCols);
                // pTile->Display();
                this->listTile.push_back(pTile);
                id += 1;
            }
            pos += 1;
        }
    }
    
    // for (int i = 0; i < this->listTile.size(); i++){
    //     this->listTile[i]->Display();
    // }
}

// void Scenario::Draw(Tile* pAgent){}