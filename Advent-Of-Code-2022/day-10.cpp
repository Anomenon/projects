#include <iostream>
#include <string>
#include <vector>
int main(){
	std::string command;
	int x = 1, cycles = 1, r = 20, num, signal = 0, line = 0, pixel = 0;

	std::vector<std::vector<char> > CRT_Drawing(6, std::vector<char>(40));
	std::vector<char> Sprite_Pos(40, '.');

	while(std::cin >> command){
		int fors = 1;

		if(command == "addx"){
			std::cin >> num;
			fors = 2;
		}

		Sprite_Pos[x - 1] = '#';
		Sprite_Pos[x] = '#';
		Sprite_Pos[x + 1] = '#';

		for(int i = 0; i < fors; i++){

			if(cycles == r){
				signal += cycles * x;
				r += 40;
			}

			if(Sprite_Pos[(cycles - 1) % 40] == '#'){
				CRT_Drawing[line][pixel] = '#';
			} else {
				CRT_Drawing[line][pixel] = '.';
			}

			if(cycles % 40 == 0){
				line += 1;
				pixel = -1;
			}
			
			pixel++;
			cycles++;
		}	
		Sprite_Pos[x - 1] = '.';
		Sprite_Pos[x] = '.';
		Sprite_Pos[x + 1] = '.';

		if(command == "addx"){
			x = x + num;
		}	
	}

	std::cout << '\n';
	for(int j = 0; j < CRT_Drawing.size(); j++){
		for(int k = 0; k < CRT_Drawing[j].size(); k++){
			std::cout << CRT_Drawing[j][k];
		}
		std::cout << '\n';
	}
	std::cout << '\n';

	std::cout << signal << '\n';

	return 0;
}