#include <iostream>
#include <chrono>
#include <stdlib.h> // rand
#include "game.h"

int main(){
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();
    
    //**************************************************************************
    // RUN THE GAME
    //**************************************************************************
    int nSleepIter = 50;
    int display = 1; // only 0 (false) or 1 (true) to display on terminal
    Game game = Game(nSleepIter, display);

    int maxIter = 1000;
    int event;

    for (int iter = 0; iter < maxIter; iter++){
        event = rand() % 10;
        game.RunOneEvent(event, iter);
        
        // game.sceneHider
        // game.sceneSeeker
        // game.gameOver
        // game.isDay
    }

    //************************************************************************** 

    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";    



    return 0;
}
