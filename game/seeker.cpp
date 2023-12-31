#include "seeker.h"
#include "agent.h"
#include <string>

Seeker::Seeker(int type, int id, int pos, int nRows, int nCols, string filename) : Agent(type, id, pos, nRows, nCols, filename){
    SetTileDeriv("Seeker");
}

int Seeker::GetDirection(int event){
    // 5: up - seeker
    // 6: down - seeker
    // 7: left - seeker
    // 8: right - seeker
    // 9: jumpRamp - seeker

    switch (event)
    {
    case 5:
        // EchoMove("-y");
        // return "up";
        return 0;
        // break;
    case 6:
        // EchoMove("+y");
        // return "dw";
        return 1;
        // break;
    case 7:
        // EchoMove("-x");
        // return "<-";
        return 2;
        // break;
    case 8:
        // EchoMove("+x");
        // return "->";
        return 3;
        // break;
    case 9:
        return 4;
    default:
        return -1;
        // break;
    }
    return -1;
}