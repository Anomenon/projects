#include <iostream>
#include <string>
#include <vector>

int main(){
	char final_item = ' ';
	std::vector<char> duplicates, badge;
	std::string rucksack, elf1, elf2, elf3;
	int priority = 0, group_priority = 0, rucksack_counter = 1;

	while(std::getline(std::cin, rucksack)){
		elf3 = elf2;
		elf2 = elf1;
		elf1 = rucksack;
		std::sort(elf1.begin(), elf1.end());

		if(rucksack_counter % 3 == 0){
			for(int i = 0; i < elf3.length(); i++){
				for(int j = 0; j < elf2.length(); j++){
					if(elf3[i] == elf2[j]){
						badge.push_back(elf3[i]);
						break;
					}
				}
			}
			std::sort(badge.begin(), badge.end());
			badge.erase(unique(badge.begin(), badge.end()), badge.end());
			for(int i = 0; i < elf1.length(); i++){
				for(int j = 0; j < badge.size(); j++){
					if(badge[j] == elf1[i]){
						if(isupper(badge[j])){
							group_priority+= badge[j] - 'A' + 27;
						} else {
							group_priority += badge[j] - 'a' + 1;
						}
						badge.erase(badge.begin() + j);
					}
				}
			}
			badge.clear();
		}
		
		
		std::string compartment1 = rucksack.substr(0, rucksack.length()/2);
   		std::string compartment2 = rucksack.substr(rucksack.length()/2);	
		
		for(int i = 0; i < compartment1.length(); i++){
			for(int j = 0; j < compartment2.length(); j++){
				if(compartment1[i] == compartment2[j]){
					duplicates.push_back(compartment1[i]);
					compartment1.erase(remove(compartment1.begin(), compartment1.end(), compartment1[i]), compartment1.end());
					compartment2.erase(remove(compartment2.begin(), compartment2.end(), compartment2[j]), compartment2.end());
					break;
				}

			}
		}
		std::sort(duplicates.begin(), duplicates.end());
		duplicates.erase(unique(duplicates.begin(), duplicates.end()), duplicates.end());
		for(int i = 0; i < duplicates.size(); i++){
			if(isupper(duplicates[i])){
				priority+= duplicates[i] - 'A' + 27;
			} else {
				priority += duplicates[i] - 'a' + 1;
			}
		}
		duplicates.clear();
		rucksack_counter++;
	}	
	std::cout << priority << ' ' << group_priority << '\n';
	return 0;
}