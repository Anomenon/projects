#include <vector>
#include <iostream>

void counting_sort(std::vector<int>& unsorted_list, int max) {
    std::vector<int>counter(max + 1, 0);

    for(int i = 0; i < unsorted_list.size(); i++){
        counter[unsorted_list[i]] += 1;
    }

    int num = 0;

    for(int i = 0; i < unsorted_list.size(); i++){
        if(counter[num] <= 0){
            num += 1;
            i -= 1;
            continue;
        }

        unsorted_list[i] = num;
        counter[num] -= 1;
    }
}

void print(std::vector<int>& vec){
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << ' ';
    }
    std::cout << '\n';
}

int main(){
    std::vector<int> unsorted_list = {10, 3, 6, 2, 2, 1, 10, 1, 0, 1, 8, 5, 4, 10, 2, 0};
    print(unsorted_list);
    counting_sort(unsorted_list, 10);
    print(unsorted_list);
}