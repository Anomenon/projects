#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

int main(){
    ofstream File("IN_OUT/output.txt");
    int num;
    string parentheses;
    stack<char> stack;

    cin >> num;
    getline(cin, parentheses);

    while(num--){
        
        getline(cin, parentheses);
        
        for(int i = 0; i < parentheses.length(); i++){

            if(stack.empty()){
                stack.push(parentheses[i]);
            } else if (stack.empty() && parentheses[0] == ')' || parentheses[0] == ']' || parentheses.length() == 0){
                break;
            } else if(stack.top() == '(' && parentheses[i] == ')'){
                stack.pop();
            } else if(stack.top() == '[' && parentheses[i] == ']'){
                stack.pop();
            } else {
                stack.push(parentheses[i]);
            } 

        }
        if(stack.empty()){
            File << "Yes\n";
        } else {
            File << "No\n";
        }

        for(int i = stack.size(); i--;){
            stack.pop();
        }
    }

    return 0;
}