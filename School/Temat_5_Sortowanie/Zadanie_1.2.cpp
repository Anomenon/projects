#include <iostream>
#include <vector>

int main(){
    const int n = 5;
    int d[n] = {5, 4, 3, 2, 1};
    
    for(int j = 0; j < n; j++){
        bool swapped = false;

        for(int i = 0; i < n - 1; i++){
            if(d[i] > d[i + 1]){
                int num = d[i];
                d[i] = d[i + 1];
                d[i + 1] = num;
                swapped = true;
            }
            
        }
        
        if (swapped == false){
            break;
        }
    }

    for(int k = 0; k < n; k++){
        std::cout << d[k] << ' ';
    }
    std::cout << '\n';
    
    return 0;
}