#include <iostream>
#include <vector>
#include <queue>
#include <utility>

void BFS(std::vector<std::vector<int> >& Plane, std::vector<std::vector<int> >& Bombs, int x, int y){
	std::queue<std::pair<int, int> > Q;
	Plane[y][x] = 0;
	Q.emplace(x, y);

	while(!Q.empty()){
		auto v = Q.front();
		Q.pop();

		if(v.first + 1 < Plane[v.second].size() && Plane[v.second][v.first + 1] == -1 && Bombs[v.second][v.first + 1] == 0){
			Q.emplace(v.first + 1, v.second);
			Plane[v.second][v.first + 1] = Plane[v.second][v.first] + 1;
		} 

		if(v.first - 1 > -1 && Plane[v.second][v.first - 1] == -1 && Bombs[v.second][v.first - 1] == 0){
			Q.emplace(v.first - 1, v.second);
			Plane[v.second][v.first - 1] = Plane[v.second][v.first] + 1;
		}

		if(v.second + 1 < Plane.size() && Plane[v.second + 1][v.first] == -1 && Bombs[v.second + 1][v.first] == 0){
			Q.emplace(v.first, v.second + 1);
			Plane[v.second + 1][v.first] = Plane[v.second][v.first] + 1;
		}

		if(v.second - 1 > -1 && Plane[v.second - 1][v.first] == -1 && Bombs[v.second - 1][v.first] == 0){
			Q.emplace(v.first, v.second - 1);
			Plane[v.second - 1][v.first] = Plane[v.second][v.first] + 1;
		}
	}
}

int main(){
	int R, C, row_num, bomb_num, bomb_location, root_x, root_y, bomb_rows;
	while(std::cin >> R >> C){
		if(R == 0 && C == 0){
			break;
		}

		std::vector<std::vector<int> > Plane(R, std::vector<int>(C, -1));
		std::vector<std::vector<int> > Bombs(R, std::vector<int>(C, 0));
    
	    std::cin >> bomb_rows;

	    for(int i = 0; i < bomb_rows; i++){
	        std::cin >> row_num >> bomb_num;
	        for(int j = 0; j < bomb_num; j++){
	            std::cin >> bomb_location;
	            Bombs[row_num][bomb_location] = 1;
	        }
	    }

		std::cin >> root_x >> root_y;
		BFS(Plane, Bombs, root_x, root_y);

		std::cin >> R >> C;
		std::cout << Plane[R][C] << '\n';

	}
	return 0;	
}