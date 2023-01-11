#include<iostream>
#include<string>

using namespace std;

int main() {
	string Upper_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

   	string msg1, msg2;
   	while(cin >> msg1 >> msg2){
   		int num1 = 1000000, num2 = 1000000;
   		for(int k = 0; k < msg1.size(); k++){
   			int key = 0, x = 0, y = 0;

	   		for(int i = 0; i <= Upper_alphabet.size(); i++){
	   			if(Upper_alphabet[i] == msg1[k]){
	   				y = i;
	   				break;
	   			}
	   		}
	   		while(true){
	   			if(Upper_alphabet[(y + x) % Upper_alphabet.size()] == msg2[k]){
	   				key = x;
	   				break;
	   			}
	   			x++;
	   		}
	   		num2 = num1;
	   		num1 = key;
	   		if(num2 != 1000000 && num1 != 1000000){
	   			//cout << num1 << ' ' << num2 << '\n';
	   			if(num1 != num2){
	   				cout << msg1 << '\n';
	   				break;
	   			}
	   		}
   		}
   		//cout << "\n\n";
   	}
    
}