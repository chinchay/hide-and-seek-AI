#include <iostream>
#include <vector>
#include "scenario.h"
#include "hider.h"
#include "seeker.h"


int main(){
    
    Scenario scenario = Scenario();

    vector<Tile*> listFixedTile = scenario.GetListTile();

    int n = listFixedTile.size();

    int hiderX  = 0;
    int hiderY  = 0;
    int seekerX = 10;
    int seekerY = 10;
    Hider* pHider   = new Hider(8, hiderX, hiderY, n + 1);
    Seeker* pSeeker = new Seeker(9, seekerX, seekerY, n + 2);



    return 0;
}