#ifndef TILE_H
#define TILE_H

#include <string>
#include <iostream>


using namespace std;

class Tile{
    private:

    int type;
    int x;
    int y;
    int id;
    int width = 1;
    int height = 1;
    bool canIdrawMyself = false;


    public:

    ~Tile(){}
    Tile(int c, int x, int y, int id);
    
    int GetX(){return x;};
    int GetY() {return y;};
    int GetType() const {return type;};

    virtual void Display() const {
        cout << "I am a tile " << to_string(type) << endl;
    };

    // void Draw(Tile* pAgent);

    
};

#endif