#include <iostream>
#include <string>

int main(){
	char Elf, Player;
	int score = 0, secret_score = 0;
	while(std::cin >> Elf >> Player){
		if(Elf == 'A'){
			if(Player == 'X'){
				score += 4;
				secret_score += 3;
			} else if(Player == 'Y'){
				score += 8;
				secret_score += 4;
			} else if(Player == 'Z'){
				score += 3;
				secret_score += 8;
			}
		} else if(Elf == 'B'){
			if(Player == 'X'){
				score += 1;
				secret_score += 1;
			} else if(Player == 'Y'){
				score += 5;
				secret_score += 5;
			} else if(Player == 'Z'){
				score += 9;
				secret_score += 9;
			}
		} else if(Elf == 'C'){
			if(Player == 'X'){
				score += 7;
				secret_score += 2;
			} else if(Player == 'Y'){
				score += 2;
				secret_score += 6;
			} else if(Player == 'Z'){
				score += 6;
				secret_score += 7;
			}
		}
	}
	std::cout << "Answer 1: "<< score << '\n';
	std::cout << "Answer 2: "<< secret_score << '\n';
	return 0;
}