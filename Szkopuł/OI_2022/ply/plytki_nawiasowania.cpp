#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n, H, counter = 0;
    string brackets;
    stack<char> bracket_collector;

    cin >> n >> H >> brackets;
    
    for(int i = 0; i < n; i++){
        if(brackets[i] == '('){
            if(bracket_collector.size() >= H){
                brackets[i] = ')';
                bracket_collector.pop();
                counter ++;
            } else {
                bracket_collector.push(brackets[i]);
            }

        } else {
            if(bracket_collector.size() < 1){
                brackets[i] = '(';
                bracket_collector.push(brackets[i]);
                counter ++;
            } else {
                bracket_collector.pop();
            }
            
        }
    }
    cout << counter << '\n';
    return 0;
}