#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int INF = 1000000000;

struct Edge{
    int system_1;
    int system_2;
    int time;

    Edge(int s_1, int s_2, int t) : system_1{s_1}, system_2{s_2}, time{t} {}
};

bool Ford_Algorithm(vector<Edge>& g, int v, int e){
    vector<int> dist(v, INF);
    dist[0] = 0;
 
    for (int i = 0; i < v; i++){
        for(int j = 0; j < e; j++){
            if(dist[g.at(j).system_1] + g.at(j).time < dist[g.at(j).system_2]){
                dist[g.at(j).system_2] = dist[g.at(j).system_1] + g.at(j).time;
            }
        }
    }
    
    for(int j = 0; j < e; j++){
        if(dist[g.at(j).system_1] + g.at(j).time < dist[g.at(j).system_2]){
            return true;
        }
    }
    
    return false;
}

int main(){
    ofstream File("IN_OUT/output.txt");
    int cases;

    for(cin >> cases; cases--;){
        int star_system, wormholes;
        cin >> star_system >> wormholes;

        vector<Edge> worm_H; 

        for (int i = 0; i < wormholes; i ++){
            int system_1, system_2, time_years;
            cin >> system_1 >> system_2 >> time_years;

            worm_H.emplace_back(system_1, system_2, time_years);
        }

        
        if(Ford_Algorithm(worm_H, star_system, wormholes)){
            File << "possible" << endl;
        } else {
            File << "not possible" << endl;
        }

    }
    return 0;
}