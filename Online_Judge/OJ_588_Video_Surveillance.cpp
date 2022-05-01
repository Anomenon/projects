#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

struct Vertex{
    int x, y;

    Vertex(int x, int y) : x{x}, y{y} {}
};

int main(){
    ofstream File("IN_OUT/output.txt");
    int n, vid_num = 1;

    while(cin >> n, n != 0){
        queue<Vertex> vertices;
        bool is_possible = false;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            vertices.emplace(x, y);
        }

        for(int i = 0; i < n; i++){
            Vertex top = vertices.front(); 
            vertices.push(vertices.front()); 
            vertices.pop();

            if(top.x == vertices.front().x && (top.y == vertices.front().y - 1 || top.y == vertices.front().y + 1)){
                is_possible = true;
            } else if (top.y == vertices.front().y && (top.x == vertices.front().x - 1 || top.x == vertices.front().x + 1)){
                is_possible = true;
            } else {
                is_possible = false;
                break;
            }
        }
        cout << "Floor #" << vid_num << '\n';
        if(is_possible){
            cout << "Surveillance is possible.\n\n";
        } else {
            cout << "Surveillance is impossible.\n\n";
        }
        vid_num++;
    }
    return 0;
}