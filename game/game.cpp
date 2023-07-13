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
            if (pTile != nullptr){
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
    // srand (time(NULL));
//    vector<string> listRands;
    // vector<int> listRands;
    // for (int i = 0; i < 100; i++){ // 100000
    //     // listRands.push_back( to_string(rand() % 10) ); // range 0 to 10-1=9
    //     listRands.push_back( rand() % 10 ); // range 0 to 10-1=9
    // }

    
    Scenario scenario = Scenario();

    vector<Tile*> listTile = scenario.GetListTile();
    int rows = scenario.GetnRows();
    int cols = scenario.GetnCols();

    int id = listTile.size();
    if ( (id < 0) or (500 < id) ){
        cout << "size seems to big!" << endl;
        exit(0);
    }

    int pos1dm;


    pos1dm = 2;
    Tile* pCube = new Cube(7, id, pos1dm, rows, cols);
    listTile.push_back(pCube);

    id += 1;
    pos1dm = 40;
    Tile* pCube2 = new Cube(7, id, pos1dm, rows, cols);
    listTile.push_back(pCube2);

    id += 1;
    pos1dm = 43;
    Tile* pCube3 = new Cube(7, id, pos1dm, rows, cols);
    listTile.push_back(pCube3);

    id += 1;
    pos1dm = 46;
    Tile* pCube4 = new Cube(7, id, pos1dm, rows, cols);
    listTile.push_back(pCube4);

    id += 1;
    pos1dm = 49;
    Tile* pCube5 = new Cube(7, id, pos1dm, rows, cols);
    listTile.push_back(pCube5);


    vector<Tile*> listBlocks( listTile.begin(), listTile.end() );




    id += 1;
    pos1dm = 236;
    string hiderFile = "hider.txt";
    Hider* pHider  = new Hider(8, id, pos1dm, rows, cols, hiderFile);
    listTile.push_back(pHider);
    
    id += 1;
    pos1dm = 100;
    string seekerFile = "seeker.txt";
    Seeker* pSeeker = new Seeker(9, id, pos1dm, rows, cols, seekerFile);
    listTile.push_back(pSeeker);
    



    Group* pGroup = new Group(listTile, rows * cols);


    int event;
    // string event;
    string temp;
    int eventInt;

    // cout << listTile.size() << endl;
    // for (Tile* pTile: listTile){
    //     pTile->Display();
    // }
    int maxIterations = 100;
    int randomNumber = 0;
    // for (int i = 0; i < listRands.size(); i++){
    for (int i = 0; i < maxIterations; i++){
        
        system("clear");
        display3(pGroup);



        // Tile* p = listBlocks[0];
        if (pSeeker->CanIseeAgent(pHider, listBlocks)){
        // if (pSeeker->CanIseeAgent(pHider, p)){
            cout << "I see an agent!" << endl;
            // exit(0);
        }else{
            cout << "***" << endl;
        }

        // eventInt = listRands[i];
        // eventInt = rand() % 10;
        // cout << "enter digit: " + event << ". Iteration = " + to_string(i) << endl;
        cout << "enter digit: ";
        getline(cin, temp);
        eventInt = stoi(temp);




        // eventInt = listRands[i];

        
        pHider->ProcessEvent(eventInt, pGroup);
        pSeeker->ProcessEvent(eventInt, pGroup);
        

        // cout << "enter digit: ";
        // getline(cin, temp);
        // eventInt = stoi(temp);


        
        // getline(cin, temp);


        
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
    // delete pCube;
    // delete pCube2;
    // delete pCube2;

}

int main(){
    // auto start = std::chrono::high_resolution_clock::now();
    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();


    thegame();


    // auto end = std::chrono::high_resolution_clock::now();
    end = std::chrono::system_clock::now();

    // auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;


    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";    

    



    return 0;
}
