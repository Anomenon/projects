#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

bool no_zeros = true;

struct Sudoku_Tile{
    int num = 0;
    bool is_used = false;
    int square_num = 0;
    int Values[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
};

void print(vector<vector<Sudoku_Tile> >&Grid){
    system("clear");
    ofstream OutFile("Sudoku_PrintOut.txt");
    OutFile << "┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓" << '\n';
    cout << "┏━━━┯━━━┯━━━┳━━━┯━━━┯━━━┳━━━┯━━━┯━━━┓" << '\n';
    for(int i = 0; i < Grid.size(); i++){
        if(i % 3 == 0 && i != 0){
            OutFile << "┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫" << '\n';
            cout << "┣━━━┿━━━┿━━━╋━━━┿━━━┿━━━╋━━━┿━━━┿━━━┫" << '\n';
        } else if(i != 0){
            OutFile << "┠───┼───┼───╂───┼───┼───╂───┼───┼───┨" << '\n';
            cout << "┠───┼───┼───╂───┼───┼───╂───┼───┼───┨" << '\n';
        }
        OutFile << "┃";
        cout << "┃";
        
        for(int j = 0; j < Grid[i].size(); j++){
            if(Grid[i][j].num != 0){
                OutFile << " " << Grid[i][j].num << " ";
                cout << " " << Grid[i][j].num << " ";
            } else {
                OutFile << "   ";
                cout << "   ";
            }
            
            if(j % 3 == 2){
                OutFile << "┃";
                cout << "┃";
            } else {
                OutFile << "│";
                cout << "│";
            }
        }
        OutFile << '\n';
        cout << '\n';
    }
    OutFile << "┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛" << '\n';
    cout << "┗━━━┷━━━┷━━━┻━━━┷━━━┷━━━┻━━━┷━━━┷━━━┛" << '\n';
}

void Generator(vector<vector<Sudoku_Tile> >& Sudoku_Grid, int& y, int& x, int& n){
    Sudoku_Grid[y][x].num = n;
    Sudoku_Grid[y][x].is_used = true;
    no_zeros = true;

    for(int i = 0; i < Sudoku_Grid.size(); i++){
        for(int j = 0; j < Sudoku_Grid[i].size(); j++){
            if(Sudoku_Grid[i][j].square_num == Sudoku_Grid[y][x].square_num){
                if(i == y && j == x){
                    for(int k = 1; k < 10; k++){
                        if(k != n){
                            Sudoku_Grid[i][j].Values[k] = 0;
                        }
                    }
                } else {
                    Sudoku_Grid[i][j].Values[n] = 0;
                }
            }
        }
    }

    for(int i = 0; i < 9; i++){
        if(i != x){
            Sudoku_Grid[y][i].Values[n] = 0;
        }
        if(i != y){
            Sudoku_Grid[i][x].Values[n] = 0;
        }
    }
    
    int min_values_count = 11;
    int value_counter = 0;

    for(int i = 0; i < Sudoku_Grid.size(); i++){
        for(int j = 0; j < Sudoku_Grid[i].size(); j++){
            for(int k = 1; k < 10; k++){
                if(Sudoku_Grid[i][j].Values[k] == 1 && Sudoku_Grid[i][j].is_used == false){
                    value_counter++;
                } 
            }
            if(value_counter >= 1 && value_counter < min_values_count){
                min_values_count = value_counter;
                y = i;
                x = j;
            }
            value_counter = 0;
        }
    }

    int k = 10;
    n = 0;
    while(n != k){
        for(int i = 0; i < 10; i++){
            k = (rand() % 9) + 1;
            if(Sudoku_Grid[y][x].Values[k] == 1){
                n = k;
            }
        }
    }

    
    if(min_values_count == 11){
        for(int i = 0; i < Sudoku_Grid.size(); i++){
            for(int j = 0; j < Sudoku_Grid[i].size(); j++){
                if(Sudoku_Grid[i][j].num == 0){
                    no_zeros = false;
                    return;
                }
            }
        }
        return;
    } else {
        Generator(Sudoku_Grid, y, x, n);
    }
}

void Grid_Hide(vector<vector<Sudoku_Tile> >&Sudoku_Grid, int& difficulty){
    vector<vector<Sudoku_Tile> > Hidden_Grid(9, vector<Sudoku_Tile>(9));

    for(int i = 0; i < Sudoku_Grid.size(); i++){
        for(int j = 0; j < Sudoku_Grid[i].size(); j++){
            int random = rand() % (1 + difficulty);
			if(random == 1){
				Hidden_Grid[i][j].num = Sudoku_Grid[i][j].num;
			}
        }
    }
    print(Hidden_Grid);
}

int main(){
    int x, y, n, difficulty;
    string str;
    system("clear");
    srand( time(NULL) );
    while (true)
    {
        cout << "Set difficulty by pressing number from 1 to 10 (press 0 to exit): ";
        cin >> difficulty;
        cout << '\n';
        if(difficulty == 0){
            system("clear");
            break;
        }

        while(true){
            vector<vector<Sudoku_Tile> >Sudoku_Grid(9, vector<Sudoku_Tile>(9));
            for(int i = 0; i < Sudoku_Grid.size(); i++){
                for(int j = 0; j < Sudoku_Grid[j].size(); j++){
                    if(i < 3){
                        if(j < 3){
                        Sudoku_Grid[i][j].square_num = 1;
                        } else if(j > 2 && j < 6){
                            Sudoku_Grid[i][j].square_num = 2;
                        } else {
                            Sudoku_Grid[i][j].square_num = 3;
                        }
                    } else if(i > 2 && i < 6){
                        if(j < 3){
                        Sudoku_Grid[i][j].square_num = 4;
                        } else if(j > 2 && j < 6){
                            Sudoku_Grid[i][j].square_num = 5;
                        } else {
                            Sudoku_Grid[i][j].square_num = 6;
                        }
                    } else {
                        if(j < 3){
                        Sudoku_Grid[i][j].square_num = 7;
                        } else if(j > 2 && j < 6){
                            Sudoku_Grid[i][j].square_num = 8;
                        } else {
                            Sudoku_Grid[i][j].square_num = 9;
                        }
                    }
                }
            }
            y = rand() % 9;
            x = rand() % 9;
            n = rand() % 9 + 1;

            Generator(Sudoku_Grid, y, x, n);
            if(no_zeros){
                Grid_Hide(Sudoku_Grid, difficulty);
                getline(cin, str);
                if(str == "e" || str == "E"){
                    break;
                } else if(str.empty() == false){
                    print(Sudoku_Grid);
                    getline(cin, str);
                    if(str.empty() == false){
                        break;
                    }
                }
            }

        }
    }
    return 0;
}