#include "scenario.h"
#include <string>

Scenario::Scenario(){
    UpdateMapSize();

}



std::string ReadFile(std::string filename){
    std::string content = "testing";
    std::cout << content << std::endl;
    return content;
}

void Scenario::UpdateMapSize(){
    std::string content = ReadFile(filename);
}


