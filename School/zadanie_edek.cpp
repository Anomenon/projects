#include <iostream>
#include <vector>
using namespace std;


int main(){
    vector<int> edek_nums;
    int n, l;

    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> l;
        edek_nums.push_back(l);
    }
    sort(edek_nums.begin(), edek_nums.end());

    for(int i = 0; i < edek_nums.size(); i++){
        if(i + edek_nums[0] != edek_nums[i]){
            cout << i + edek_nums[0] << '\n';
            break; 
        }
    }
    return 0;
}