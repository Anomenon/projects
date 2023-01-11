#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int m, p, n, row = 0, column = 0, color, com_row, com_col, time = 0;
    char command;
    cin >> m >> p >> n;
    vector<vector<int> > Grid(m, vector<int>(m, -1));
    vector<vector<int> > color_Grid(m, vector<int>(m, -1));
    vector<int> colors;

    colors.push_back(time);
    Grid[row][column] = time;

    for(int i = 0; i < p; i++){
        cin >> row >> column >> color;
        color_Grid[row - 1][column - 1] = color;
    }

    row = 0, column = 0;
    for(int i = 0; i < n; i++){
        
        cin >> command;
        if(command == 'Z'){
            cin >> com_col >> com_row;
            int key = Grid[com_col - 1][com_row - 1];
            int length = colors.size() - 1;
            if((key - time) + length > -1){
                cout << colors[(key - time) + length] << '\n';
            } else {
                cout << "-1 \n";
            }
            
        } else {
            time += 1;
            if(command == 'G'){
                row -= 1;
            } else if (command == 'D'){
                row += 1;
            } else if (command == 'P'){
                column += 1;
            } else if (command == 'L'){
                column -= 1;
            }
            
            if(color_Grid[row][column] != -1){
                colors.push_back(color_Grid[row][column]);
                color_Grid[row][column] = -1;
            }
            Grid[row][column] = time;
        }

    }
    return 0;
}