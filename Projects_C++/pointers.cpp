#include <iostream>
#include <vector>
using namespace std;
//Dfs
//Bfs
//Dijkstra
//Ford argorithm

int main(){
	int x = 5;
	int* z = &x;
	int& y = x;
	//y = 6;
	cout << z << '\n' << *z << " "<< y <<'\n';
	
	return 0;
}