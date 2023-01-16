#include <iostream>
#include <string>
#include <set>
#include <vector>

int main(){
    std::string signal, output = "", output2 = "";
    std::vector<std::string> vec;
    int count = 0, max_num = 0, length;

    while(std::cin >> signal){
        bool if_true = true;
        count++;
        if(count % 40 == 0){
            output += signal[9];
        }
        std::set<char> diff_letters;

        for(int i = 0; i < signal.length(); i++){
            diff_letters.insert(signal[i]);
        }

        if(diff_letters.size() > max_num){
            max_num = diff_letters.size();
            output2 = signal;
        }
        for(int i = 0; i < signal.length() - 1; i++){
            length = abs((signal[i + 1] - 'A') - (signal[i] - 'A'));
            if(length > 10){
                if_true = false;
            }
        }

        if(if_true == true){
            vec.push_back(signal);
        }
    } 

    std::cout << output << '\n' << output2 << ' ' << max_num << '\n';
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << '\n';
    }
    return 0;
}