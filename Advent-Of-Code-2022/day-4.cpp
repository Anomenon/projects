#include <iostream>
#include <string>
#include <vector>

int main(){
	std::string ID_nums;
	int full_overlap = 0, overlap_at_all = 0;
	while(getline(std::cin, ID_nums)){
		std::string num1 = "", num2 = "",num3 = "", num4 = "";
		for(int i = 0; i < ID_nums.length(); i++){
			if(std::isdigit(ID_nums[i]) != 0){
				num1 += ID_nums[i];
			} else if(ID_nums[i] == '-'){
				num2 = num1;
				num1 = "";
			}else if(ID_nums[i] == ',' || i == ID_nums.length()){
				num3 = num1;
				num4 = num2;
				num1 = "";
			}
		} 
		if((std::stoi(num4) <= std::stoi(num2) && std::stoi(num3) >= std::stoi(num1))||(std::stoi(num4) >= std::stoi(num2) && std::stoi(num3) <= std::stoi(num1))){
			full_overlap++;
			overlap_at_all++;
		} else if((std::stoi(num4) <= std::stoi(num1) && std::stoi(num3) >= std::stoi(num2) && std::stoi(num4) <= std::stoi(num2) && std::stoi(num3) <= std::stoi(num1)) || (std::stoi(num4) >= std::stoi(num2) && std::stoi(num4) <= std::stoi(num1) && std::stoi(num3) >= std::stoi(num1) && std::stoi(num3) >= std::stoi(num2))){
			overlap_at_all++;
		}
	}
	std::cout << full_overlap << " " << overlap_at_all << '\n';
	return 0;
}