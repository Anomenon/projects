#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int const SIZE = 5;
int coin_types [SIZE] = {50, 25, 10, 5, 1};

int main(){
    int cents;
    
    vector<int> solutions = {7490, 0};
    solutions[0] = 1;

    for(int j = 0; j < SIZE; j++){
        for(int i = 1; i < 7490; i++){
            if(i >= coin_types[j]){
                solutions[i] += solutions[i - coin_types[j]];
            }
        }
    }

    while(cin >> cents){
        cout << solutions[cents] << '\n';
    }

}