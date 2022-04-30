#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main(){
    ifstream inFile;
    inFile.open("input.txt");
    char fday;
    string fday2;
    int fday3;
    int64_t answer1 = 0, answer2 = 0;
    map<int64_t, int64_t> fish;
    map<int64_t, int64_t> fish2;

    for(int i = 0; i < 10; i++){
        fish.insert(make_pair(i, 0));
        fish2.insert(make_pair(i, 0));
    }
    
        
    while(inFile >> fday){
        if(fday == ','){
            fday3 = stoi(fday2);
            for(int i = 0; i < 9; i++){
                if(fday3 == i ){
                    fish[i] += 1;
                    fish2[i] += 1;
                }
            }
            fday2 = "";
        } else {
            fday2 += fday;
        }
    }
    
    for(int i = 1; i < 80 + 1; i++){
        fish[9] = fish[0];
        fish[0] = fish[1];
        fish[1] = fish[2];
        fish[2] = fish[3];
        fish[3] = fish[4];
        fish[4] = fish[5];
        fish[5] = fish[6];
        fish[6] = fish[7] + fish[9];
        fish[7] = fish[8];
        fish[8] = fish[9];
        fish[9] = 0;
    }

    for(int i = 0; i < 9; i++){
        answer1 += fish[i];
    }
    cout << answer1 << ' ';

    for(int i = 1; i < 256 + 1; i++){
        fish2[9] = fish2[0];
        fish2[0] = fish2[1];
        fish2[1] = fish2[2];
        fish2[2] = fish2[3];
        fish2[3] = fish2[4];
        fish2[4] = fish2[5];
        fish2[5] = fish2[6];
        fish2[6] = fish2[7] + fish2[9];
        fish2[7] = fish2[8];
        fish2[8] = fish2[9];
        fish2[9] = 0;
        
    }

    for(int i = 0; i < 9; i++){
        answer2 += fish2[i];
    }
    cout << answer2 << '\n';
    return 0;
}