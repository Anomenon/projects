#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string input;
    ofstream outFile("aput.txt");

    for(int i = 0; i < 24; i++){
        getline(cin, input);
        outFile << ", \"" << input << "\"";
    }
    return 0;
}