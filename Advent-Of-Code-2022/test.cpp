#include <iostream>
#include <string>
#include <map>

int main(){
	int x = 5;
	int* p = &x;
	std::cout << *p << '\n';
	return 0;
}