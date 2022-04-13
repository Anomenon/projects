#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

int binary_converter(string binstr){
    int dec = 0;

    for(int i = 1; i < binstr.length() + 1; i++){
        dec += (binstr[binstr.length() - i] - '0')* pow(2, i) / 2;
    }

    return dec;
}

int main(){
    ifstream inFile;
    inFile.open("input.txt");
    
    vector<string> bin_num;
    queue<string> binary;
    queue<string> binary2;

    int i = 0, answer1, answer2;
    string num, gamma_rate, epsilon_rate;
    char leader;

    while(inFile >> num){
        bin_num.push_back(num);
        binary.push(num);
        binary2.push(num);
    }

    for(int i = 0; i < bin_num[0].length(); i++){
        int zeros = 0; 
        int ones = 0;

        for(int j = 0; j < bin_num.size(); j++){
            if(bin_num[j][i] == '1'){
                ones++;
            } else {
                zeros++;
            }
            
        }

        if(ones >= zeros){
            gamma_rate += "1";
            epsilon_rate += "0";
        } else {
            gamma_rate += "0";
            epsilon_rate += "1";
        }
        
    }

    answer1 = binary_converter(gamma_rate) * binary_converter(epsilon_rate);

    for(int i = 0; i < 13; i++){
        int zeros = 0; 
        int ones = 0;

        for(int j = 0; j < binary.size(); j++){
            if(binary.front()[i] == '1'){
                ones++;
            } else {
                zeros++;
            }
            binary.push(binary.front());
            binary.pop();
        }
        
        if(ones >= zeros){
            leader = '1';
        } else if (ones < zeros){
            leader = '0';
        }

        for(int j = 0; j < 100000; j++){
        
            if(binary.front()[i] != leader){
                binary.pop();
            } else {
                binary.push(binary.front());
                binary.pop();
            }
        }

        if(binary.size() == 1){
            break;
        }

    }

    for(int i = 0; i < 13; i++){
        int zeros = 0; 
        int ones = 0;

        
        for(int j = 0; j < binary2.size(); j++){
            if(binary2.front()[i] == '0'){
                zeros++;
            } else {
                ones++;
            }
            binary2.push(binary2.front());
            binary2.pop();
        }
        
        if(ones < zeros){
            leader = '1';
        } else if (ones >= zeros){
            leader = '0';
        }

        for(int j = 0; j < 100000; j++){
        
            if(binary2.front()[i] != leader){
                binary2.pop();
            } else {
                binary2.push(binary2.front());
                binary2.pop();
            }
        }

        if(binary2.size() == 1){
            break;
        }
    }
    

    answer2 = binary_converter(binary2.front()) * binary_converter(binary.front());
    
    cout << binary2.front() << '\n';
    cout << binary.front() << '\n';

    cout << answer1 << " " << answer2 << '\n';
    return 0;

    
}