#include "seeker.h"
#include "agent.h"
#include <string>

Seeker::Seeker(int type, float x, float y, int id, string filename) : Agent(type, x, y, id, filename){

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
        // EchoMove("+y");
        return "dw";
        // break;
    case 6:
        // EchoMove("-y");
        return "up";
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