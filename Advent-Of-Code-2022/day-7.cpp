#include <iostream>
#include <string>
#include <map>

struct folder{
	std::map<std::string, folder> reference;
	folder* prevDir;
};

int main(){
	std::string command, str1, str2, str3 = "";

	folder fs;
	folder* currentDir = &fs;

	while(std::cin >> str1 >> str2){
		if(str1 == "$"){
			if(str2 != "ls"){
				std::cin >> str3;
				str1 = str2;
				str2 = str3;
			} else {
				str1 = str2;
				str2 = "";
			}
			
		}
		for(int i = 0; i < *currentDir->reference.size(); i++){
			std::cout << *currentDir->reference[i] << '\n';
		}

		// if(str1 == "cd"){
		// 	if(str2 != ".."){
		// 		if(str2 == "/"){
		// 			currentDir = &fs;
		// 		} else {
		// 			folder* prevDir = currentDir;
		// 			currentDir = &currentDir->reference[str2];
		// 			currentDir->prevDir = prevDir;
		// 		}
		// 	} else {
		// 		currentDir = currentDir->prevDir;
		// 	}
		// } else if(str1 == "ls"){

		// }

	}
	return 0;
}