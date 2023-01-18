#include <iostream>
#include <string>

int main(){
	int T, hours, minutes;
	char semi_column;
	std::cin >> T;

	for(int i = 0; i < T; i++){
		std::string reverse_clock = "";
		std::cin >> hours >> semi_column >> minutes;
		
		int total_time = hours * 60 + minutes;

		if((780 - total_time) / 60 == 0){
			hours = 11;
		} else {
			if((780 - total_time) / 60 - 1 == 0){
				hours = 12;
			} else {
				hours = (780 - total_time) / 60 - 1;
				if(hours < 10){
					reverse_clock += "0";
				}
			}
		}
		reverse_clock += std::to_string(hours) + ":";

		minutes = (780 - total_time) % 60; 		

		if(minutes < 10){
			reverse_clock += "0";
		}
		reverse_clock += std::to_string(minutes);
		std::cout << reverse_clock << '\n';
	}
	return 0;
}