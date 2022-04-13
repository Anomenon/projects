#include <iostream>
#include <fstream>
#include <list>
#include <array>
#include <cmath>
using namespace std;

int main(){
    ifstream inFile;
    inFile.open("input.txt");
    
    list<int> crab_pos;

    char num;
    string num1;
    int num3;
    int fuel = 0, i =0, fuel2 = 0;;
    long long int answer1 = 1000000000000, answer2 = 1000000000000;


    while(inFile >> num){
        if(num == ','){
            num3 = stoi(num1);
            crab_pos.push_back(num3);
            num1 = "";
            
        } else {
            num1 += num;
        }
    }   

    for(int j = 0; j < 350 + 1; j++){
        
        for(int i = 0; i < crab_pos.size(); i++){
            fuel += abs(crab_pos.front() - j);
            crab_pos.push_back(crab_pos.front());
            crab_pos.pop_front();
        }

        if(fuel < answer1){
            answer1 = fuel;
            
        }
        
        fuel = 0;
        
    }
    cout << answer1 << ' ';
    

    for(int j = 0; j < 500 + 1; j++){
        
        for(int i = 0; i < crab_pos.size(); i++){
            for(int k = 1; k <= abs(crab_pos.front() - j); k++){
                fuel2 += k;
                
            }
            crab_pos.push_back(crab_pos.front());
            crab_pos.pop_front();
        }

        if(fuel2 < answer2){
            answer2 = fuel2;
        }
        fuel2 = 0;
        
    }

    cout << answer2 << '\n';    

    return 0;
}