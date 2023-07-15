#ifndef GAME_H
#define GAME_H

#include "group.h"
#include <vector>
#include "hider.h"
#include "seeker.h"

using namespace std;

class Game{
    private:
    int nSleepIter;
    Group* pGroup;
    Hider*  pHider;
    Seeker* pSeeker;
    int nRows;
    int nCols;
    vector<Tile*> blocks;
    vector<Tile*> allTiles;
    int display = 0;
    
    public:
    vector<int> sceneHider;
    vector<int> sceneSeeker;
    int rewardHider = 0;
    int rewardSeeker = 0;
    int isDay = 0;
    int gameOver = 0;

    ~Game(){};
    Game(int nSleepIter, int display);
    void DisplayOnTerminal();
    void RunOneEvent(int event, int iteration);

};

#endif