#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


struct stop{
    int niceness;
    int n;

    stop(int x, int y) : niceness{x}, n{y} {}
};

int main(){
    ofstream out_File("IN_OUT/output.txt");
    int routes, bus_stops, n;
    cin >> routes;

    for(int j = 0; j < routes; j++){
        cin >> bus_stops;
        vector<stop>Routes;

        for(int i = 0; i < bus_stops - 1; i++){
            cin >> n;
            Routes.emplace_back(n, i);
        }

        int max_niceness = 0, niceness = 0, stop_a = 0, stop_b = 0;
        
        for(int i = 0; i < Routes.size(); i++){
            if(niceness == 0){
                stop_a = Routes[i].n + 1;
            }

            niceness += Routes[i].niceness;

            if(niceness >= max_niceness){
                max_niceness = niceness;
                stop_b = Routes[i].n + 2;

            } else if(niceness < 0){
                niceness = 0;
            }
        }

        if(stop_b == 0){
            out_File << "Route " << j + 1 << " has no nice parts" << '\n';
        } else {
            out_File << "The nicest part of route " << j + 1 << " is between stops "<< stop_a <<" and " << stop_b << '\n';
        }
    }
    

    return 0;
}