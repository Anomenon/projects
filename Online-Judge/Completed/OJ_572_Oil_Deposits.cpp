#include <iostream>
#include <vector>
#include <utility>
#include <queue>

void DFS(std::vector<std::vector<char> >& image, int x, int y){
	image[y][x] = '*';

	if(image[y][x + 1] == '@'){
		DFS(image, x + 1, y);
	} 
	if(y - 1 > -1 && image[y - 1][x + 1] == '@'){
		DFS(image, x + 1, y - 1);
	}
	if(y - 1 > -1 && image[y - 1][x] == '@'){
		DFS(image, x, y - 1);
	}
	if(y - 1 > -1 && x - 1 > -1 && image[y - 1][x - 1] == '@'){
		DFS(image, x - 1, y - 1);
	}
	if(x - 1 > -1 && image[y][x - 1] == '@'){
		DFS(image, x - 1, y);
	}
	if(y + 1 < image.size() && x - 1 > -1 && image[y + 1][x - 1] == '@'){
		DFS(image, x - 1, y + 1);
	}
	if(y + 1 < image.size() && image[y + 1][x] == '@'){
		DFS(image, x, y + 1);
	}
	if(y + 1 < image.size() && image[y + 1][x + 1] == '@'){
		DFS(image, x + 1, y + 1);
	}
}

int main(){
	int m, n;

	while(true){
		std::cin >> m;
		if(m == 0){
			break;
		}
		std::cin >> n;

		int counter = 0;
		char oil;
		std::vector<std::vector<char> >image(m, std::vector<char>(n));

		for(int i = 0; i < image.size(); i++){
			for(int j = 0; j < image[i].size(); j++){
				std::cin >> oil;
				image[i][j] = oil;
			}			
		}
		
		for(int i = 0; i < image.size(); i++){
			for(int j = 0; j < image[i].size(); j++){
				if(image[i][j] == '@'){
					counter++;
					DFS(image, j, i);
				}
			}			
		}
		
		std::cout << counter << '\n';
	}
		

	return 0;
}