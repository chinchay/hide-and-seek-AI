#include <iostream>
#include <vector>
#include "scenario.h"
#include "hider.h"
#include "seeker.h"
#include "cube.h"
#include "group.h"
#include <stdlib.h>
#include <map>

#include <chrono>

using namespace std;

void display3(Group* pGroup){
    map<int, char> type2Symbol;
    type2Symbol[0] = '-';
    type2Symbol[1] = '?';
    type2Symbol[2] = '#';
    type2Symbol[3] = '=';
    type2Symbol[7] = 'c';
    type2Symbol[8] = 'H';
    type2Symbol[9] = 'S';

    int rows = 12;
    int cols = 26;

    int count = 0;
    Tile* pTile;
    cout << endl;
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            pTile = pGroup->pos2Tile[count];
            if (pTile != NULL){
                cout << type2Symbol[ pTile->GetType() ];
            }
            else{
                // cout << " ";
                cout << "-";
            }
            count += 1;
            if (count % cols == 0){
                cout << endl;
            }
        }
    }
    cout << endl;
}

// void display2(vector<Tile*> &listTile){
//     // cout << "----" << endl;
//     map<int, char> type2Symbol;
//     type2Symbol[0] = '-';
//     type2Symbol[1] = '?';
//     type2Symbol[2] = '#';
//     type2Symbol[3] = '=';
//     type2Symbol[7] = 'c';
//     type2Symbol[8] = 'H';
//     type2Symbol[9] = 'S';

//     int rows = 12;
//     int cols = 26;
//     int i;
//     int j;
//     int p;
//     // vector<vector<int>> mTypes( rows , vector<int> (cols, 0)); // <<< why it gives errors after a random number of callings to display2() ???
//     for (Tile* pTail : listTile){
//         p = pTail->GetPos1dim();
//         i = p / cols;
//         j = p % cols;
//         // cout << to_string(rows) + " " + to_string(cols) + " " + to_string(i) + " " + to_string(j) << endl;
//         // mTypes[i][j] = pTail->GetType();
//     }

//     int count = 0;
//     for(int ii = 0; ii < rows; ii++){
//         for (int jj = 0; jj < cols; jj++){
//             cout << to_string(0);
//             // cout << type2Symbol[ mTypes[i][j] ]; // << " ";
//             count += 1;
//             if (count % cols == 0){
//                 cout << endl;
//             }
//         }
//     }
// }

void thegame(){
    srand (time(NULL));
//    vector<string> listRands;
    vector<int> listRands;
    for (int i = 0; i < 1000; i++){ // 100000
        // listRands.push_back( to_string(rand() % 10) ); // range 0 to 10-1=9
        listRands.push_back( rand() % 10 ); // range 0 to 10-1=9
    }

    
    Scenario scenario = Scenario();

    vector<Tile*> listTile = scenario.GetListTile();
    int rows = scenario.GetRows();
    int cols = scenario.GetCols();

    int id = listTile.size();
    int pos1dm;
    
    pos1dm = 10;
    string hiderFile = "hider.txt";
    Hider* pHider  = new Hider(8, id, pos1dm, rows, cols, hiderFile);
    listTile.push_back(pHider);
    
    id += 1;
    pos1dm = 20;
    string seekerFile = "seeker.txt";
    Seeker* pSeeker = new Seeker(9, id, pos1dm, rows, cols, seekerFile);
    listTile.push_back(pSeeker);
    

    id += 1;
    pos1dm = 30;
    Tile* pCube = new Cube(7, id, pos1dm, rows, cols);
    listTile.push_back(pCube);

    id += 1;
    pos1dm = 40;
    Tile* pCube2 = new Cube(7, id, pos1dm, rows, cols);
    listTile.push_back(pCube2);


    Group* pGroup = new Group(listTile);

    int event;
    // string event;
    string temp;
    int eventInt;
    for (int i = 0; i < listRands.size(); i++){
        system("clear");
        display3(pGroup);
        eventInt = listRands[i];
        // cout << "enter digit: " + event << ". Iteration = " + to_string(i) << endl;
        // cout << "enter digit: ";
        // getline(cin, temp);
        // eventInt = stoi(temp);




        // eventInt = listRands[i];

        
        pHider->ProcessEvent(eventInt, pGroup);
        pSeeker->ProcessEvent(eventInt, pGroup);


        
    }

    // pHider->SaveMoves();


    



    // *************************************************************************
    // Free memory
    // *************************************************************************
    // for (int i = 0; i < listFixedTile.size(); i++){
    //     delete listFixedTile[i];
    // }
    listTile.clear();

    delete pHider;
    delete pSeeker;
    delete pCube;
    delete pCube2;

}

int main(){
    auto start = std::chrono::high_resolution_clock::now();


    thegame();


    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    double seconds = duration.count();
    std::cout << "Runtime: " << seconds << " seconds" << std::endl;



    return 0;
}
