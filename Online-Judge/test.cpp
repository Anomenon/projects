#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    int R, C, row_num, bomb_num, bomb_location, root_x, root_y, bomb_rows;
    cin >> R >> C;

    std::vector<std::vector<int> > Bombs(C, std::vector<int>(R, 0));
    
    std::cin >> bomb_rows;

    for(int i = 0; i < bomb_rows; i++){
        cin >> row_num >> bomb_num;
        for(int j = 0; j < bomb_num; j++){
            std::cin >> bomb_location;
            Bombs[row_num][bomb_location] = 1;
        }
    }
    for(int i = 0; i < Bombs.size(); i++){
        for(int j = 0; j < Bombs[i].size(); j++){
            cout << Bombs[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}