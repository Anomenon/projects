#include <iostream>
#include <vector>



int main(){
    int n, l;

    std::cin >> n;
    std::vector<int> edek_nums(n + 1, false);
    for(int i = 1; i < n; i++){
        std::cin >> l;
        edek_nums[l] = true;
    }
    
    for(int i = 1; i < n + 1; i++){
        if(edek_nums[i] == false){
            std::cout << i << '\n';
        }
    }
    return 0;
}