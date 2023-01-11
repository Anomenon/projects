#include <iostream>
#include <vector>

int main(){
    const int n = 5;
    int d[n] = {5, 4, 3, 2, 1};
    
    for(int j = 0; j < n; j++){

        for(int i = 0; i < n - 1; i++){
            if(d[i] > d[i + 1]){
                std::swap(d[i], d[i + 1]);
            }
            
        }
    }

    for(int k = 0; k < n; k++){
        std::cout << d[k] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}