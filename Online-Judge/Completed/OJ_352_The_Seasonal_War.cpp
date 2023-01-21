#include <iostream>
#include <vector>
#include <utility>
#include <queue>

void DFS(std::vector<std::vector<char> >& image, int x, int y){
	image[y][x] = '0';

	if(image[y][x + 1] == '1'){
		DFS(image, x + 1, y);
	} 
	if(y - 1 > -1 && image[y - 1][x + 1] == '1'){
		DFS(image, x + 1, y - 1);
	}
	if(y - 1 > -1 && image[y - 1][x] == '1'){
		DFS(image, x, y - 1);
	}
	if(y - 1 > -1 && x - 1 > -1 && image[y - 1][x - 1] == '1'){
		DFS(image, x - 1, y - 1);
	}
	if(x - 1 > -1 && image[y][x - 1] == '1'){
		DFS(image, x - 1, y);
	}
	if(y + 1 < image.size() && x - 1 > -1 && image[y + 1][x - 1] == '1'){
		DFS(image, x - 1, y + 1);
	}
	if(y + 1 < image.size() && image[y + 1][x] == '1'){
		DFS(image, x, y + 1);
	}
	if(y + 1 < image.size() && image[y + 1][x + 1] == '1'){
		DFS(image, x + 1, y + 1);
	}
}

int main(){
	int size, num = 1;

	while(std::cin >> size){
		int counter = 0;
		char pixel;
		std::vector<std::vector<char> >image(size, std::vector<char>(size));

		for(int i = 0; i < image.size(); i++){
			for(int j = 0; j < image[i].size(); j++){
				std::cin >> pixel;
				image[i][j] = pixel;
			}			
		}
		for(int i = 0; i < image.size(); i++){
			for(int j = 0; j < image[i].size(); j++){
				if(image[i][j] == '1'){
					counter++;
					DFS(image, j, i);
				}
			}			
		}
		
		std::cout << "Image number " << num << " contains " << counter << " war eagles." << '\n';
		num++;
	}
		

	return 0;
}