#include <iostream>
#include <vector>

int main(){
    const int n = 5;
    int p = 0;
    int d[n] = {5, 4, 3, 2, 1};

    for(int j = 0; j < n; j ++){
        p = j;
        for(int i = j + 1; i <= n - 1; i++){
            if(d[i] < d[p]){
                p = i;
            }
        }
        std::swap(d[j], d[p]);
    }

    for(int k = 0; k < n; k++){
        std::cout << d[k] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}