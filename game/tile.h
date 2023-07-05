#ifndef TILE_H
#define TILE_H

#include <string>
#include <iostream>

using namespace std;

class Tile{
    private:
    string filenane;
    int x;
    int y;
    int id;
    int width = 1;
    int height = 1;
    bool canIdrawMyself = false;


    public:

    ~Tile(){}
    Tile(string filename, int x, int y, int id);

    virtual void display() const {cout << "I am a tile" << endl; };
};

#endif