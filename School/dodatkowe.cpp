#include <iostream>
#include <string>
using namespace std;

int add(string str1, string str2){
	return (str1 - "0") + (str2 - "0");
}

int main(){
	cout << add("22298293829842948249283429842948234234", "44444249238423948239482394823492384293482394823423432") << '\n';
	return 0;
}