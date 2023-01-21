#include <iostream>
#include <vector>

int main(){
	int cases, W;
	std::cin >> cases;

	while(cases--){
		std::cin >> W;

		bool is_diff = false;
		int prev, y_1, y_2;

		std::cin >> y_1 >> y_2;
		int diff = y_1 - y_2;

		for(int j = 1; j < W; j++){
			std::cin >> y_1 >> y_2;
			
			if(diff != y_1 - y_2){
				is_diff = true;
			}
		}

		if(!is_diff){
			std::cout << "yes\n";
		} else {
			std::cout << "no\n";
		}

		if(cases){
			std::cout << '\n';
		}
	}
	return 0;
}