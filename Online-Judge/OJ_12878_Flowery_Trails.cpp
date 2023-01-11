#include <iostream>
#include <vector>
#define INFINITY = 1000000000;

struct Edge{
	int point;
	int length;

	//Edge(int x, int y) : point{x}, length{y} {};
};

int Dijkstra(std::vector<std::vector<Edge> >& graph){
	
	return 0;
}

int main(){
	int P, T, p1, p2, l;
	std::cin >> P >> T;
	std::vector<std::vector<Edge> > graph(P);

	for(int i = 0; i < T; i++){
		std::cin >> p1 >> p2 >> l;
		graph[p1].push_back(Edge{p2, l});
		graph[p2].push_back(Edge{p1, l});
	}	

	// for(int i = 0; i < graph.size(); i++){
	// 	for(int j = 0; j < graph[i].size(); j++){
	// 		std::cout << i << " " << graph[i][j].point << "  " << graph[i][j].length << '\n';
	// 	}
	// }
	return 0;
}