#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ofstream out_File("IN_OUT/output.txt");
    int routes, bus_stops;

    cin >> routes;
    for(int i = 1; i < routes + 1; i++){
        cin >> bus_stops;

        int niceness = 0, sum = 0, max = 0, current_stop = 1, start_stop = 0, end_stop = 0;

        for(int j = 1; j < bus_stops; j++){
            cin >> niceness;
            sum += niceness;

            if(sum > max || (sum == max && j + 1 - current_stop > end_stop - start_stop)){
                max = sum;
                start_stop = current_stop;
                end_stop = j + 1;

            } else if(sum < 0){
                sum = 0;
                current_stop = j + 1;
            } 
        }

        if (end_stop == 0){
            out_File << "Route " << i << " has no nice parts\n";

        } else{
            out_File << "The nicest part of route " << i << " is between stops " << start_stop << " and " << end_stop << '\n';
        }
    }
    return 0;
}