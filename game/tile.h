#ifndef TILE_H
#define TILE_H

#include <string>
#include <iostream>
#include <vector>
#include <string>


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

    virtual string GetStr() const {
        return "I am a tile " + to_string(type);
    };

    virtual void Display() const {
        cout << GetStr() << endl;
    };

    // void Draw(Tile* pAgent);

    virtual void ProcessEvent(int event, vector<Tile*> allOthers){};

    
};

#endif