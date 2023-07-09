#include "agent.h"
#include "hider.h"
#include <string>

Hider::Hider(int type, int id, int pos1dim, int rows, int cols, string filename) : Agent(type, id, pos1dim, rows, cols, filename){

}

string Hider::GetDirection(int event){
    // 0: up - hider
    // 1: down - hider
    // 2: left - hider
    // 3: right - hider
    // 4: lockBlock - hider

    switch (event)
    {
    case 0:
        // EchoMove("-y");
        return "up";
        // break;
    case 1:
        // EchoMove("+y");
        return "dw";
        // break;
    case 2:
        // EchoMove("-x");
        return "<-";
        // break;
    case 3:
        // EchoMove("+x");
        return "->";
        // break;
    
    default:
        return "none";
        // break;
    }
    return "none";
}

// bool Hider::CanIpush(vector<Tile*> allOthers, string direction){
//     return false;
// }

