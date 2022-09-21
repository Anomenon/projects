#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream File("IN_OUT/output.txt");
    ifstream inFile("IN_OUT/input.txt");
    int32_t x, y, z, min, max;

    while(inFile >> x >> y){
        if(x < y){
            min = x;
            max = y;
        } else {
            min = y;
            max = x;
        }

        int prev_cycle = 0;

        while(min <= max){
            
            z = min;
            int cycles = 1;
            while(z != 1){
                if(z % 2 != 0){
                    z = z * 3 + 1;
                } else {
                   z = z / 2;
                }
                cycles++;
            }
            if(prev_cycle < cycles){
                prev_cycle = cycles;
            }
            min++;
        }
        File << x << ' ' << y << ' ' << prev_cycle << '\n';
    }

    return 0;
}