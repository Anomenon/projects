#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, N;
    float is_permutation = true;
    cin >> n;
    vector<int> nums;

    for(int i = 0; i < n; i++){
        cin >> N;
        nums.push_back(N);
    }
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == nums[i + 1]){
            is_permutation = false;
        }
    }

    if(is_permutation){
        cout << "TAK" << '\n';
    } else {
        cout << "NIE" << '\n';
    }
    return 0;
}