#include "scenario.h"
#include <string>
#include <fstream>
#include <vector>
#include "tile.h"

#include <iostream>
// #include "fixedTile.h"
// #include "cube.h"
// #include "ramp.h"
// #include "seeker.h"
// #include "hider.h"

using namespace std;

Scenario::Scenario(){
    listLine = GetLines();
    UpdateScenarioSize();
    // cout << nRows << " " << nCols << endl;
    // DisplayLines();
    
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

    map<char, int> char2type;
    char2type['#'] = 1; // wall, fixed tile
    char2type['='] = 2; // cube, movable tile
    char2type['?'] = 3; // ramp, movable tile
    char2type['H'] = 4; // Hider
    char2type['S'] = 5; // Seeker    

    
    
    for(int i = 0; i < nRows; i++){
        for (int j = 0; j < nCols; j++){
            character = listLine[i][j];
            
            if (character != '-'){
                type = char2type[character];


                Tile* pTile;
                switch(type){
                    // cout << nRows << " " << nCols << " - " << pos  << " " << character << endl;
                    case 1:
                        // cout << nRows << " " << nCols << " - " << pos  << " " << character << endl;
                        pTile = new FixedTile(type, id, pos, nRows, nCols);
                        this->blocks.push_back(pTile);
                        this->allTiles.push_back(pTile);
                        // pTile->Display();
                        break;
                    case 2:
                        // cout << nRows << " " << nCols << " - " << pos  << " " << character << endl;
                        pTile = new Cube(type, id, pos, nRows, nCols);
                        this->blocks.push_back(pTile);
                        this->allTiles.push_back(pTile);
                        // pTile->Display();
                        break;
                    case 3:
                        // cout << nRows << " " << nCols << " - " << pos  << " " << character << endl;
                        pTile = new Ramp(type, id, pos, nRows, nCols);
                        this->blocks.push_back(pTile);
                        this->allTiles.push_back(pTile);
                        // pTile->Display();
                        break;
                    case 4:
                        // cout << nRows << " " << nCols << " - " << pos  << " " << character << endl;
                        this->pHider = new Hider(type, id, pos, nRows, nCols, "hider.txt");
                        this->allTiles.push_back(pHider);
                        // this->pHider->Display();
                        break;
                    case 5:
                        // cout << nRows << " " << nCols << " - " << pos  << " " << character << endl;
                        this->pSeeker = new Seeker(type, id, pos, nRows, nCols, "seeker.txt");
                        this->allTiles.push_back(pSeeker);
                        // this->pSeeker->Display();
                        break;
                }
                // pTile->Display();
                // this->allTiles.push_back(pTile);
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