#include "agent.h"
#include "hider.h"
#include <string>

Hider::Hider(int type, int id, int pos, int nRows, int nCols, string filename) : Agent(type, id, pos, nRows, nCols, filename){
    SetTileDeriv("Hider    ");
}

int Hider::GetDirection(int event){
    // 0: up - hider
    // 1: down - hider
    // 2: left - hider
    // 3: right - hider
    // 4: lockBlock - hider

    switch (event)
    {
    case 0:
        // EchoMove("-y");
        // return "up";
        // EchoMove(0);
        return 0;
        // break;
    case 1:
        // EchoMove("+y");
        // return "dw";
        // EchoMove(1);
        return 1;
        // break;
    case 2:
        // EchoMove("-x");
        // return "<-";
        // EchoMove(2);
        return 2;
        // break;
    case 3:
        // EchoMove("+x");
        // return "->";
        // EchoMove(3);
        return 3;
        // break;
    
    default:
        return -1;
        // break;
    }
    return -1;
}

// bool Hider::CanIpush(vector<Tile*> allOthers, string direction){
//     return false;
// }

