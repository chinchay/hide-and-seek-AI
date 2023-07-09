#include "seeker.h"
#include "agent.h"
#include <string>

Seeker::Seeker(int type, int id, int pos1dim, int rows, int cols, string filename) : Agent(type, id, pos1dim, rows, cols, filename){

}

string Seeker::GetDirection(int event){
    // 5: up - seeker
    // 6: down - seeker
    // 7: left - seeker
    // 8: right - seeker
    // 9: jumpRamp - seeker

    switch (event)
    {
    case 5:
        // EchoMove("-y");
        return "up";
        // break;
    case 6:
        // EchoMove("+y");
        return "dw";
        // break;
    case 7:
        // EchoMove("-x");
        return "<-";
        // break;
    case 8:
        // EchoMove("+x");
        return "->";
        // break;
    
    default:
        return "none";
        // break;
    }
    return "none";
}