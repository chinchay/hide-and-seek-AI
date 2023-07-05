#include "scenario.h"
#include <string>
#include <fstream>
#include <vector>
#include "tile.h"
#include "fixedTile.h"

using namespace std;

Scenario::Scenario(){
    listLine = GetLines();
    UpdateScenarioSize();
    // DisplayLines();
    letter2file['?'] = "images/tile.jpg";
    letter2file['#'] = "images/brick.png";
    letter2file['='] = "images/brick.png";

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
    this->rows = listLine.size();
    this->cols = listLine[0].length();
    // scenarioW = cols * tileW;
    // scenarioH = rows * tileH;

}

void Scenario::DisplayLines(){
    for (int i = 0; i < listLine.size(); i++){
        cout << listLine[i] << endl;
    }
}

void Scenario::LoadTiles(){
    char letter;
    int x = 0;
    int y = 0;
    int count = 0;
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            letter = listLine[i][j];
            if (letter != '-'){
                string filename4tile = letter2file[letter];
                Tile* tile = new FixedTile(filename4tile, x, y, count);
                this->listFixedTilePtr.push_back(tile);
                count += 1;
            }
            x += this->tileW;
        }
        x = 0;
        y += this->tileH;
    }



    for (int i = 0; i < this->listFixedTilePtr.size(); i++){
        this->listFixedTilePtr[i]->display();
    }


}