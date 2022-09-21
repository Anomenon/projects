#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void DFS(int v, int prev, vector<vector<int> >& g, vector<char>& colors){
    
    for (int i = 0; i < g[v].size(); i++){
        if(v == 0){

            colors[v] = 'r';
        } else {

            if(colors[prev] == 'r'){
                colors[v]= 'g';
            } else {
                colors[v] = 'r';
            }
        }

        if (colors[g[v][i]] == '-'){
            int prev = v;
            DFS(g[v][i], prev, g, colors);
        }
    }     
}

void addEdge(int node_a, int node_b, vector<vector<int> >& graph){
    graph[node_a].push_back(node_b);
    graph[node_b].push_back(node_a);
}

int main(){
    ofstream File("IN_OUT/output.txt");
    int nodes, edges, node_a, node_b;    

    while(cin >> nodes, nodes != 0){

        cin >> edges;
        vector<vector<int> > graph(nodes);
        vector<char> colors(nodes, '-');   

        for(int i = 0; i < edges; i++){
            cin >> node_a >> node_b;
            addEdge(node_a, node_b, graph);
        }
        
        DFS(0, 0, graph, colors);

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

        File << is_bicolorable << '\n';       
    }
    return 0;
}