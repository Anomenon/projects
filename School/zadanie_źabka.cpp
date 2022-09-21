#include <iostream>
#include <vector>
using namespace std;


int main(){
    int x, y, s;
    
    cin >> x >> y >> s;
    int  count = x;

    while(count < abs(y - x)){
        count += s;
    }

    cout << (count - x) / s << '\n';
    return 0;
}