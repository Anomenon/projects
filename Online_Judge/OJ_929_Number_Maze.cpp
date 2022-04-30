#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
int INF = 1000000000;

struct Tiles{
    int v; 
    int cost;
    int x;
    int y;

    bool operator<(const Tiles& different) const {
        return cost > different.cost;
    }

    Tiles(int v, int c, int x, int y) : v{v}, cost{c}, x{x}, y{y} {}
};

int Dijkstra(const vector<vector<int> >& Maze, int& Y_axis, int& X_axis){
    priority_queue<Tiles> q;
    vector<int>dist(Y_axis * X_axis, INF);

    dist[0] = Maze[0][0];
    q.emplace(0, Maze[0][0], 0, 0);

    while(!q.empty()){
        Tiles tile = q.top(); q.pop();
        if(tile.v == X_axis * Y_axis - 1){
            break;
        }
        if(tile.x + 1 != X_axis){
            if(dist[tile.v] + Maze[tile.y][tile.x + 1] < dist[tile.v + 1]){
                dist[tile.v + 1] = dist[tile.v] + Maze[tile.y][tile.x + 1];
            }
            q.emplace(tile.v + 1, Maze[tile.y][tile.x + 1], tile.x + 1, tile.y);
        }
        if(tile.y + 1 != Y_axis){
            if(dist[tile.v] + Maze[tile.y + 1][tile.x] < dist[tile.v + 1 + Y_axis]){
                dist[tile.v + 1 + Y_axis] = dist[tile.v] + Maze[tile.y + 1][tile.x];
            }
            q.emplace(tile.v + Y_axis + 1, Maze[tile.y + 1][tile.x], tile.x, tile.y + 1);
        }
    }
        
    return dist[X_axis * Y_axis - 1];
}

int main(){
    ifstream in_File("IN_OUT/input.txt");
    ofstream out_File("IN_OUT/output.txt");
    int n, Y_axis, X_axis;

    for(cin >> n >> Y_axis >> X_axis; n--;){
        vector<vector<int> > Maze(Y_axis, vector<int> (X_axis));

        for(int y = 0; y < Y_axis; y++){
            for(int x = 0; x < X_axis; x++){
                int square;
                cin >> square;
                Maze[y][x] = square;
            }
        }
        
        out_File << Dijkstra(Maze, Y_axis, X_axis) << '\n';
    }
    
    return 0;
}