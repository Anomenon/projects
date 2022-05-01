#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
int main(){
    int n;

    while(cin >> n, n != 0){
        queue<int> deck;
        vector<int> discarded;
        for(int i = 1; i < n + 1; i++){
            deck.push(i);
        }
        if(n >= 2){
            while (deck.size() > 1){
                discarded.push_back(deck.front());
                deck.pop();
                deck.push(deck.front());
                deck.pop();
            }
            cout << "Discarded cards: ";
            for(int i = 0; i < discarded.size(); i++){
                cout << discarded[i];
                if(i + 1 != discarded.size()){
                    cout << ", ";
                }  
            }
            cout << '\n' << "Remaining card: " << deck.front() << '\n';
        } else if (n == 1){
            cout << "Discarded cards:" << '\n' << "Remaining card: " << deck.front() << '\n';
        }
    }
    return 0;
}