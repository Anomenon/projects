#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    ifstream File;
    File.open("slowa.txt");
    string str;
    string word, word_snd;
    int count_1 = 0, count_2 = 0, count_3 = 0, wrd_count = 0;
    
    while (File >> word >> word_snd){

        if(word[word.length() - 1] == 'A'){
            count_1++;
        }
        if(word_snd[word_snd.length() - 1] == 'A'){
            count_1++;
        }

        if (word_snd.find(word) != string::npos) {
            count_2++;
        } 

        if(word.length() == word_snd.length()){
            bool is_anagram = true;
            sort(word.begin(), word.end());
            sort(word_snd.begin(), word_snd.end());
            
            for(int i = 0; i < word.length(); i++){
                if(word[i] != word_snd[i]){
                    is_anagram = false;
                    break;
                }
            }

            if(is_anagram){
                count_3++;
            }
        }
        
    }
    cout << count_1 << '\n' << count_2 << '\n' << count_3 << '\n';
    return 0;
}