#include <iostream>
#include <vector>
using namespace std;
//Dfs
//Bfs
//Dijkstra
bool isPointInside(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y){
        cout << abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0) << '\n';
        cout << abs((x1*(y-y3) + x*(y3-y1)+ x3*(y1-y))/2.0) << '\n';
        cout << abs((x1*(y2-y) + x2*(y-y1)+ x*(y1-y2))/2.0) << '\n';
        cout << abs((x*(y2-y3) + x2*(y3-y)+ x3*(y-y2))/2.0) << '\n';
    }

int main(){
    isPointInside(20.3, 9.8, 10.0, -3.2, 17.5, -7.7, 20.0, 20.0);
    // int x = 5;
    // int* z = &x;
    // int& y = x;
    // //y = 6;
    // cout << z << '\n' << *z << " "<< y <<'\n';
    // return 0;
}