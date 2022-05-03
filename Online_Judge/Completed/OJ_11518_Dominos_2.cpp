#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int times = 0;

void DFS(int v, vector< vector<int> >& tiles, vector<bool>& vis){
    if(vis[v] == false){
        times++;
    }
    
    vis[v] = true;
    for (int i = 0; i < tiles[v].size(); i++){
        if (vis[tiles[v][i]] == false){
            DFS(tiles[v][i], tiles, vis);
        }
    }     
}

void addEdge(int node_a, int node_b, vector<vector<int> >& tiles){
    tiles[node_a].push_back(node_b);
}

int main(){
    ofstream File("IN_OUT/output.txt");
    int cases, n, m, l;

    for(cin >> cases; cases--;){
        cin >> n >> m >> l;

        vector<vector<int> > tiles(n + 1);
        vector<bool> visited(n + 1, false);

        for(int j = 0; j < m; j++){
            int x, y;
            cin >> x >> y;
            addEdge(x, y, tiles);
        }

        for(int j = 0; j < l; j++){
            int z;
            cin >> z;
            DFS(z, tiles, visited);   
        }
        
        File << times << '\n';
        times = 0;
        visited.clear();
        tiles.clear();
    }
    return 0;
}