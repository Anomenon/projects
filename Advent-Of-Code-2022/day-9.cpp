#include <iostream>
#include <string>
#include <set>
#include <vector>

struct Pkt{
	int x, y;

	bool operator<(const Pkt &a) const {
        return x < a.x || (x == a.x && y < a.y);
    }

};

int sgn(int& diff) {
    return diff > 0 ? 1 : diff < 0 ? -1 : 0;
}

void position(Pkt& head_pos, Pkt& tail_pos) {
    int x_diff = head_pos.x - tail_pos.x;
    int y_diff = head_pos.y - tail_pos.y;
    if (abs(x_diff) == 2 || abs(y_diff) == 2) {
        tail_pos.x += sgn(x_diff);
        tail_pos.y += sgn(y_diff);
    }
}

int main(){
	std::vector<Pkt> rope(10, {0,0});
	std::set<Pkt> unique_last_element;
	std::set<Pkt> unique_first_element;
	char move;
	int tiles;

	unique_last_element.insert(rope[9]);
	unique_first_element.insert(rope[1]);
	while(std::cin >> move >> tiles){
		for(int i = 0; i < tiles; i++){

			if(move == 'U'){
				rope[0].y += 1;
			} else if(move == 'D'){
				rope[0].y -= 1;
			} else if(move == 'L'){
				rope[0].x -= 1;
			} else if(move == 'R'){
				rope[0].x += 1;
			}

			for(int j = 0; j < rope.size(); j++){
				position(rope[j], rope[j + 1]);
			}
			unique_last_element.insert(rope[9]);
			unique_first_element.insert(rope[1]);
		}
	}

	std::cout << unique_first_element.size() << ' ' << unique_last_element.size() << '\n';
	return 0;
}