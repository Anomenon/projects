#include <iostream>
#include <string>
#include <vector>
int main(){
	std::string each_snack;
	int max_cal = 0, one_cal_sum = 0;
	std::vector<int> calories;

	while(std::getline(std::cin, each_snack)){
		if(each_snack.size() == 0){
			calories.push_back(one_cal_sum);
			one_cal_sum = 0;
			
		} else {
			one_cal_sum += stoi(each_snack);
		}
	}
	for(int i = 0; i < calories.size(); i++){
		if(calories[i] > max_cal){
			max_cal = calories[i];
		}
	}
	std::cout << "Answer 1: " << max_cal << '\n';

	max_cal = 0;
	sort(calories.begin(), calories.end(), std::greater<int>());
	for(int i = 0; i < 3; i++){
		max_cal+= calories[i];
	}
	std::cout << "Answer 2: " << max_cal << '\n';
	return 0;
}