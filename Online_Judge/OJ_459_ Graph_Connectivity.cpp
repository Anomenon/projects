#include <iostream>
#include <vector>
using namespace std;

void DFS(int v, vector<bool>& vis, vector< vector<int> >& g){
    vis[v] = true;

    for (int i = 0; i < g[v].size(); i++){
        if (vis[g[v][i]] == false){
            DFS(g[v][i], vis, g);
        }
    }     
}

void addEdge(char a, char b, vector<vector<int> >& g){
    g[a - 'A'].push_back(b - 'A');
    g[b - 'A'].push_back(a - 'A'); 
}

int main(){
    vector<vector<int> > G;
    int cases;
    char l_node;
    string edge;
    cin >> cases;
    
    for(int i = 0; i < cases; i++){
        cin >> l_node;
        vector<vector<int> > G(l_node - 'A' + 1);
        vector<bool> visited(l_node - 'A' + 1, false);
        cin.ignore(10, '\n');

        while(getline(cin, edge)){
            if(edge.empty()){
                break;
            }
            addEdge(edge[0], edge[1], G);
        }


        int graphs = 0, not_visited = -1;
        int node = l_node - 'A';
        while(not_visited != 0){
            not_visited = 0;
            DFS(node, visited, G);
            int f = 0;
            for(int j = 0; j < visited.size(); j++){
                if(visited[j] == false){
                    node = j;
                    
                    not_visited = -1;
                }
            }
            graphs++;
        }


        cout << graphs << '\n';
        G.clear();
        visited.clear();
    }
    return 0;
}