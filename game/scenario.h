/*******************************************************************************
 * Header File:
 *    Scenario: The representation of a scenario or physical platform
 * Author:
 *    Carlos León
 ******************************************************************************/

#ifndef SCENARIO_H
#define SCENARIO_H

#include <iostream>
#include <string>

class Scenario{
    private:
    int tileW = 50;
    int tileH = 50;
    std::string filename = "platform.txt";


    public:
    ~Scenario(){};

    Scenario();

    void UpdateMapSize();



};

#endif