#include <iostream>
#include <vector>
using namespace std;

struct Position{
    int x;
    int y;

    Position(int x, int y) : x{x}, y{y} {}
};

void Print_Labirynth(vector<vector<int> >& Labirynth){
    for(int y = 0; y < Labirynth.size(); y++){
        for(int x = 0; x < Labirynth[y].size(); x++){
            switch (Labirynth[y][x]){
                case 2:
                    cout << "▀ ";
                    break;
                case 1:
                    cout << "  ";
                    break;
                case 9: 
                    cout << "× ";
                    break;
                default:
                    cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

bool Labirynth_algorithm(vector<vector<int> >& Labirynth, int X, int Y, Position Ending_Point){
    Labirynth[Y][X] = 9;

    if(X == Ending_Point.x && Y == Ending_Point.y){
        Print_Labirynth(Labirynth);
        return true;
    }

    if(X < Labirynth[0].size() && Labirynth[Y][X + 1] != 2 && Labirynth[Y][X + 1] != 9 && Labirynth_algorithm(Labirynth, X + 1, Y, Ending_Point)){
        return true;
    }
    if(X > 0 && Labirynth[Y][X - 1] != 2 && Labirynth[Y][X - 1] != 9 && Labirynth_algorithm(Labirynth, X - 1, Y, Ending_Point)){
        return true;
    }
    if(Y < Labirynth.size() && Labirynth[Y + 1][X] != 2 && Labirynth[Y + 1][X] != 9 && Labirynth_algorithm(Labirynth, X, Y + 1, Ending_Point)){
        return true;
    }
    if(Y > 0 && Labirynth[Y - 1][X] != 2 && Labirynth[Y - 1][X] != 9 && Labirynth_algorithm(Labirynth, X, Y - 1, Ending_Point)){
        return true;
    }
    
    return false;
}

int main(){
    vector<vector<int> > Labirynth =
    {
        {2, 3, 2, 2, 2, 2, 2, 2, 2},
        {2, 1, 2, 1, 1, 1, 1, 1, 2},
        {2, 1, 2, 2, 2, 1, 2, 1, 2},
        {2, 1, 2, 1, 1, 1, 2, 1, 2},
        {2, 1, 2, 1, 2, 1, 2, 2, 2},
        {2, 1, 1, 1, 2, 1, 2, 1, 2},
        {2, 1, 2, 2, 2, 1, 2, 1, 2},
        {2, 1, 1, 1, 2, 1, 1, 1, 2},
        {2, 2, 2, 2, 2, 2, 2, 0, 2}
    };
    Position Starting_Point = {0, 0}, Ending_point = {0, 0};

    for(int y = 0; y < Labirynth.size(); y++){
        for(int x = 0; x < Labirynth[y]. size(); x++){
            switch (Labirynth[y][x]){
                case 3:
                    Starting_Point = {x, y};
                    break;
                
                case 0:
                    Ending_point = {x, y};
                    break;
            }
        }
    }

    Labirynth_algorithm(Labirynth, Starting_Point.x, Starting_Point.y, Ending_point);
    
    return 0;
}