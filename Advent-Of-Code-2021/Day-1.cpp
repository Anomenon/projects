#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream inFile;

    int a=0, b=0, c = 0, d =0;
    int next = 0;
    int number = 0;
    int answer1 = 0, answer2 = 0;

    inFile.open("input.txt");

    while(inFile >> number){
        if(number > next && next != 0){
            answer1 ++;
        }
        next = number;

        a = b;
        b = c;
        c = d;
        d = number;

        if(b != 0 && c != 0 && d != 0 && a != 0){
            int A = d + b + c;
            int B = a+b+c;
            if(B < A){
                answer2 ++;
            }
        }
        
    }
    cout << answer1 << " " << answer2 << '\n';
    return 0;
}