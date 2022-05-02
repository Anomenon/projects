#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
int main(){
    ofstream File("IN_OUT/output.txt");
    int n;
    while(cin >> n, n != 0){
        queue<int> deck;
        vector<int> discarded;
        for(int i = 1; i < n + 1; i++){
            deck.push(i);
        }
        
        while (deck.size() > 1){
            discarded.push_back(deck.front());
            deck.pop();
            deck.push(deck.front());
            deck.pop();
        }
        File << "Discarded cards:";
        for(int i = 0; i < discarded.size(); i++){
            File << " " << discarded[i];
            if(i + 1 != discarded.size()){
                File << ",";
            }  
        }
        File << '\n' << "Remaining card: " << deck.front() << '\n';
    
    }
    return 0;
}