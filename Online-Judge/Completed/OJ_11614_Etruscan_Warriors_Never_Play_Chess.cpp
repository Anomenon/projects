#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    ofstream File("IN_OUT/output.txt");
    int64_t n;
    int64_t warriors;

    for(cin >> n; n--;){
        cin >> warriors;
        warriors = floor(sqrt(2 * warriors + 0.25) + 0.5) - 1;
        File << warriors << '\n';
    }

    return 0;
}