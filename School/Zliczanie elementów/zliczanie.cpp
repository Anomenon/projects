#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ifstream File;
    File.open("slowa.txt");
    string str = "";
    int count_1 = 0, count_2 = 0, count_3 = 0;
    
    while (getline(File, str)){
        // for(int i = 0; i < str.length(); i++){
        //     if((str[i + 1] == ' ' || i + 1 == str.length() - 1) && str[i] == 'A'){
        //         count_1 ++;
        //     }
        // }
        

        string word = "", word_snd = "";
        for(int i = 0; i < str.length(); i++){
            if(str[i] == ' '){
                for(int j = i + 1; j < str.length(); j++){
                    word_snd += str[j];
                }
                break;
            } else {
                word += str[i];
            }
        }

        cout << word_snd << "\n";
        cout <<  word << '\n';
    
    }
    cout << count_1 << '\n' << count_2 << '\n' << count_3 << '\n';
    return 0;
}