#ifndef AGENT_H
#define AGENT_H

#include "movableTile.h"

class Agent : MovableTile{
    private:
        /* data */
    public:
        Agent(int c, int x, int y, int id);
        ~Agent();
};


#endif