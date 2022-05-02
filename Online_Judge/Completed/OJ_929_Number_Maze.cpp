#include <vector>
#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

const int INF = 1000000000;

struct Tiles{
    int x;
    int y;
    int cost;

    bool operator<(const Tiles& inny) const{
        return cost > inny.cost;
    }

    Tiles(int x, int y, int c) : x{x}, y{y}, cost{c} {}
};

int Dijkstra(const vector<vector<int>>& Maze, int X_axis, int Y_axis){

    priority_queue<Tiles> q;
    vector<vector<int> > dist (X_axis, vector<int> (Y_axis, INF));

    dist[0][0] = Maze[0][0];
    q.emplace(0, 0, Maze[0][0]);

    
    while(!q.empty()){
        Tiles tile = q.top(); q.pop();

        if(tile.x == X_axis - 1 && tile.y == Y_axis - 1){
            return dist[X_axis-1][Y_axis-1];
            break;
        }

        if (tile.x + 1 < X_axis){
            if (dist[tile.x][tile.y] + Maze[tile.x + 1][tile.y] < dist[tile.x + 1][tile.y]){
                dist[tile.x + 1][tile.y] = dist[tile.x][tile.y] + Maze[tile.x + 1][tile.y];

                q.emplace(tile.x + 1, tile.y, dist[tile.x + 1][tile.y]);
            }
            
        }

        if (tile.x - 1 >= 0){
            if (dist[tile.x][tile.y] + Maze[tile.x - 1][tile.y] < dist[tile.x - 1][tile.y]){
                dist[tile.x - 1][tile.y] = dist[tile.x][tile.y] + Maze[tile.x - 1][tile.y];

                q.emplace(tile.x - 1, tile.y, dist[tile.x - 1][tile.y]);
            }
            
        }

        if (tile.y + 1 < Y_axis){
            if (dist[tile.x][tile.y] + Maze[tile.x][tile.y + 1] < dist[tile.x][tile.y + 1]){
                dist[tile.x][tile.y + 1] = dist[tile.x][tile.y] + Maze[tile.x][tile.y + 1];

                q.emplace(tile.x, tile.y + 1, dist[tile.x][tile.y + 1]);
            }
            
        }

        if (tile.y - 1 >= 0){
            if (dist[tile.x][tile.y] + Maze[tile.x][tile.y - 1] < dist[tile.x][tile.y - 1]){
                dist[tile.x][tile.y - 1] = dist[tile.x][tile.y] + Maze[tile.x][tile.y - 1];

                q.emplace(tile.x, tile.y - 1, dist[tile.x][tile.y - 1]);
            }
            
        }
    }
    return 0;
}

int main(){
    ofstream File("IN_OUT/output.txt");
    int num, Y, X;

    for (cin >> num; num--;){
        cin >> Y >> X;
        vector<vector<int> > Maze(X, vector<int> (Y));

        for (int i = 0; i < Y; i++){
            for (int j = 0; j < X; j++){
                cin >> Maze[j][i];
            }
        }

        File << Dijkstra(Maze, X, Y) << '\n';
    }
    return 0;
}