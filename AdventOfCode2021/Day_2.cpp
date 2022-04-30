#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream inFile, inFile2;

    inFile.open("input.txt");
    inFile2.open("input.txt");

    string x;
    int y, horizontal = 0, depth = 0, aim = 0;
    int answer1, answer2;

    while(inFile >> x >> y){
        if(x == "forward"){
            horizontal += y;
        } 

        if(x == "down"){
            depth += y;
        } else if (x == "up"){
            depth -= y;
        }
    }
    answer1 = depth * horizontal;

    horizontal = 0;
    depth = 0;

    while(inFile2 >> x >> y){

        if(x == "forward"){
            horizontal += y;
            depth = aim * y + depth;
        } 

        if(x == "down"){
            aim += y;
        } else if (x == "up"){
            aim -= y;
        }
    }
    answer2 = depth * horizontal;

    cout << answer1 << ' ' << answer2 << '\n';
    return 0;

    
}