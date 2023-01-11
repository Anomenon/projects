#include <iostream>
#include <vector>

int main(){
	int input;
	std::vector<int *> v;
	while(std::cin >> input){
		int * pt = &input;
		std::cout << pt << '\n';
	}
	
	return 0;
}