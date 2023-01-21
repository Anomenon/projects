#include <iostream>
#include <string>
#include <map>
#include <vector>

int main(){
	while(!std::cin.eof()){
		std::string phone_char, phone_num;
		std::cin >> phone_char;

		for(int i = 0; i < phone_char.length(); i++){
			if(isalpha(phone_char[i])){
				if((int)phone_char[i] <= 67){
					phone_num += '2';
				} else if((int)phone_char[i] <= 70){
					phone_num += '3';
				} else if((int)phone_char[i] <= 73){
					phone_num += '4';
				} else if((int)phone_char[i] <= 76){
					phone_num += '5';
				} else if((int)phone_char[i] <= 79){
					phone_num += '6';
				} else if((int)phone_char[i] <= 83){
					phone_num += '7';
				} else if((int)phone_char[i] <= 86){
					phone_num += '8';
				} else if((int)phone_char[i] <= 90){
					phone_num += '9';
				}
			} else {
				phone_num += phone_char[i];
			}
		}
		std::cout << phone_num;
		if(!std::cin.eof()){
			std::cout  << '\n';
		}
	}
	return 0;
}