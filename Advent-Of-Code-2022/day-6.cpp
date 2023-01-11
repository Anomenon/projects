#include <iostream>
#include <string>
#include <vector>

int main(){
	std::string signal;
	std::vector<char> chars;
	int start_of_packet = 0, start_of_message = 0, delete_chars = 1000000;
	bool is_different = true;

	std::getline(std::cin, signal);

	chars.push_back(signal[0]);

	for(int i = 1; i < signal.length(); i++){

		for(int j = 0; j < chars.size(); j++){
			if(chars.size() == 14 && start_of_message == 0){
				start_of_message = i;
			}
			
			if(chars.size() == 4 && start_of_packet == 0){
				start_of_packet = i;
			} else if(signal[i] == chars[j]){
				is_different = false;
				delete_chars = j;
			}
		}

		if(!is_different){
			for(int j = 0; j < delete_chars + 1; j++){
				chars.erase(chars.begin());
			}
			chars.push_back(signal[i]);
			is_different = true;
			delete_chars = 1000000;
		} else {
			chars.push_back(signal[i]);
		}
		
	}
	std::cout << start_of_packet << ' ' << start_of_message << '\n';
	return 0;
}