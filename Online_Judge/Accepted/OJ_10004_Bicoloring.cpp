#include <iostream>
#include <vector>
using namespace std;
void DFS(int v, int prev, vector<bool>& vis, vector< vector<int> >& g, vector<string>& colors){
    vis[v] = true; 
    for (int i = 0; i < g[v].size(); i++){
        if(v == 0){
            colors[v] = "red";
        } else {
            if(colors[prev] == "red"){
                colors[v]= "green";
            } else {
                colors[v] = "red";
            }
        }
        if (vis[g[v][i]] == false){
            int prev = v;
            DFS(g[v][i], prev, vis, g, colors);
        }
    }     
}
void addEdge(int node_a, int node_b, vector<vector<int> >& graph){
    graph[node_a].push_back(node_b);
    graph[node_b].push_back(node_a);
}
int main(){
    int nodes, edges, node_a, node_b;    
    while(cin >> nodes){
        if(nodes == 0){
            break;
        }
        cin >> edges;
        vector <vector<int> > graph(nodes);
        vector<bool> visited(nodes, false);
        vector<string> colors(nodes, "no color");        
        for(int i = 0; i < edges; i++){
            cin >> node_a >> node_b;
            addEdge(node_a, node_b, graph);
        }
        DFS(0, 0, visited, graph, colors);
        string is_bicolorable = " ";
        bool bnot = false;
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++){
                if(colors[i] != colors[graph[i][j]]){
                    is_bicolorable = "BICOLORABLE.";
                } else {
                    is_bicolorable = "NOT BICOLORABLE.";
                    bnot = true;
                    break;
                }
            }
            if(bnot){
                break;
            }        
        }
        cout << is_bicolorable << '\n';       
    }
    return 0;
}