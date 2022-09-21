#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
    int v;
    int cost;

    bool operator<(const Edge& different) const {
        return cost > different.cost;
    }

    Edge(int v, int c) : v{v}, cost{c} {}
};

int Dijkstra(const std::vector<std::vector<Edge> >& g, int src, int trgt) {
    std::priority_queue<Edge> q;
    std::vector<int> dist(g.size(), 1000000000);
    dist[src] = 0;
    q.push(Edge{src, 0});

    while (!q.empty()) {
        Edge top = q.top(); q.pop();

        for (int i = 0; i < g[top.v].size(); i++){
            if (g[top.v][i].cost + dist[top.v] < dist[g[top.v][i].v]){
                dist[g[top.v][i].v] = g[top.v][i].cost + dist[top.v];

                q.push(Edge{g[top.v][i].v, dist[g[top.v][i].v]});
            }
        }
    }

    return dist[trgt];
}

int main(){
    int n;
    cin >> n;

    vector<vector<Edge> > graph(2*n +1);

    for(int i = 1; i < n + 1; i++){
        int k;
        cin >> k;
        graph[i].emplace_back(i + n, k/2);
    }

    int m;
    cin >> m;
    for(int i = 1; i < m + 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[a + n].emplace_back(b + n, c);
    }

    cout << Dijkstra(graph, 1, 1+n);
    return 0;
}