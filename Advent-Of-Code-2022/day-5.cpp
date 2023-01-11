#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>
int main(){
	std::string crates, command, top_crates, top_crates9001;
	getline(std::cin, crates);
	std::vector<std::vector<char> > crates_stack(crates.length()/4.0 + 0.25);
	std::vector<std::vector<char> > CrateMover9001_stack(crates.length()/4.0 + 0.25);
	
	while(!crates.empty()){
		for(int i = 0; i < crates.length(); i++){
			if(crates[i] == '['){
				crates_stack[i/4].push_back(crates[i + 1]);
				CrateMover9001_stack[i/4].push_back(crates[i + 1]);
			}
		}

		getline(std::cin, crates);
	}

	for(int i = 0; i < crates_stack.size(); i++){
		reverse(crates_stack[i].begin(), crates_stack[i].end());
		reverse(CrateMover9001_stack[i].begin(), CrateMover9001_stack[i].end());
	}

	int count = 1;
	int move = 0, from = 0, to = 0;

	while(std::cin >> command){
		std::vector<int> inputs;

		for(int i = 0; i < command.length(); i++){
			if(std::isdigit(command[i]) == 0){
				break;
			} else {
				if(count % 2 == 0){
					if(move == 0){
						move = stoi(command);
					} else if(from == 0){
						from = stoi(command);
					} else if(to == 0){
						to = stoi(command);
					}
				}

			}
			break;
		} 
		if(count % 6 == 0){
			std::vector<char> crates_to_move;

			for(int i = 0; i < move; i++){
				crates_stack[to - 1].push_back(crates_stack[from - 1].back());
				crates_stack[from - 1].pop_back();

				crates_to_move.push_back(CrateMover9001_stack[from - 1].back());
				CrateMover9001_stack[from - 1].pop_back();
			}

			reverse(crates_to_move.begin(), crates_to_move.end());
			for(int i = 0; i < crates_to_move.size(); i++){
				CrateMover9001_stack[to - 1].push_back(crates_to_move[i]);
			}
			crates_to_move.clear();
			
			move = 0, from = 0, to = 0;
		}
		count++;
	}

	for(int i = 0; i < crates_stack.size(); i++){
		top_crates += crates_stack[i].back();
		top_crates9001 += CrateMover9001_stack[i].back();
	}
	std::cout << top_crates << ' ' << top_crates9001 << '\n';
	return 0;
}