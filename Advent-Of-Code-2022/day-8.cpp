#include <iostream>
#include <vector>

bool visible_tree(std::vector<std::vector<int>>& forest, int y, int x, int* p){
	bool up = true, down = true, left = true, right = true;
	int num = 1;

	for(int i = x - 1; i >= 0; i--){
		if(forest[y][x] < forest[y][i] || forest[y][x] == forest[y][i]){
			left = false;
			break;
		}
		if(forest[y][x] > forest[y][i] && i != 0){
			num++;
		}
	}
	*p *= num;
	num = 1;

	for(int i = x + 1; i < forest[x].size(); i++){
		if(forest[y][x] < forest[y][i] || forest[y][x] == forest[y][i]){
			right = false;
			break;
		}
		if(forest[y][x] > forest[y][i] && i != forest[x].size() - 1){
			num++;
		}
	}
	*p *= num;
	num = 1;

	for(int i = y - 1; i >= 0; i--){
		if(forest[y][x] < forest[i][x] || forest[y][x] == forest[i][x]){
			up = false;
			break;
		}
		if(forest[y][x] > forest[y][i] && i != 0){
			num++;
		}
	}
	*p *= num;
	num = 1;

	for(int i = y + 1; i < forest[y].size(); i++){
		if(forest[y][x] < forest[i][x] || forest[y][x] == forest[i][x]){
			down = false;
			break;
		}
		if(forest[y][x] > forest[y][i] && i != forest[y].size() - 1){
			num++;
		}
	}
	*p *= num;

	if(up || down || left || right){
		return true;
	}
	return false;
}

int is_visible(std::vector<std::vector<int>>& forest, int* p){
	int visible = 0;
	for(int i = 0; i < forest.size(); i++){
		for(int j = 0; j < forest[i].size(); j++){
			if(i == 0 || j == 0 || j == forest[i].size() - 1 || i == forest.size() - 1){
				visible++;
			} else {
				int scenic_score = 1;
				if(visible_tree(forest, i, j, &scenic_score)){
					visible++;
				}
				if(*p < scenic_score){
					*p = scenic_score;
				}
			}
		}
	}

	return visible;
}

int main(){
	char tree;
	int rows = 0, max_scenic_score = 1;
	std::vector<std::vector<int>> forest(100, std::vector<int>());

	while(std::cin.get(tree)){
		if (tree == '\n' || tree == ' '){
		 	rows++;
		} else {
			forest[rows].push_back(tree - '0');
		}
	}
	forest.resize(rows + 1);

	std::cout << is_visible(forest, &max_scenic_score) << ' ' << max_scenic_score << '\n';
	
	return 0;
}