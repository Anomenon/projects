#include <iostream>
#include <vector>
#include <string>

int main(){
	std::string zeros_and_ones;
	int counter = 1, n, i, j;

	while(std::cin >> zeros_and_ones){
		
		std::cin >> n;
		std::cout << "Case " << counter << ":" << '\n';

		for(int m = 0; m < n; m++){
			bool is_same = true;
			std::cin >> i >> j;
			if(i < j){
				for(int k = i; k < j + 1; k++){
					if(zeros_and_ones[i] != zeros_and_ones[k]){
						std::cout << "No" << '\n';
						is_same = false;
						break;
					}
				}
			} else {
				for(int k = j; k < i + 1; k++){
					if(zeros_and_ones[j] != zeros_and_ones[k]){
						std::cout << "No" << '\n';
						is_same = false;
						break;
					}
				}
			}

			if(is_same){
				std::cout << "Yes" << '\n';
			}
		}
		counter ++;
	}
	return 0;
}