#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream File("IN_OUT/output.txt");
    ifstream inFile("IN_OUT/input.txt");

    int v, t;
    while(inFile >> v >> t){
        File << v * t * 2 << '\n';
    }
    return 0;
}