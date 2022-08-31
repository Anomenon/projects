#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

struct Point{
    int x_axis;
    int y_axis;
    bool not_used = true;

    Point(int a, int b) : x_axis{a}, y_axis{b} {}
};

int sgn(double x) {
    return x > 0 ? 1 : x < 0 ? -1 : 0;
}

void Border(vector<vector<Point> >& Edge_Points, vector<Point>& All_Points, int& count){
    int e_Point = 0;
    
    Edge_Points[count].push_back(All_Points[e_Point]);
    for(int i = 0; i < All_Points.size(); i++){ // B: x/y

        bool Edge = true;
        if(e_Point != i){
            for(int j = 0; j < All_Points.size(); j++){ // x/y
                if(i != j || j != e_Point){ 
                    int sgn_ans = sgn((All_Points[i].x_axis - All_Points[e_Point].x_axis) * (All_Points[j].y_axis - All_Points[e_Point].y_axis) - (All_Points[j].x_axis  - All_Points[e_Point].x_axis) * (All_Points[i].y_axis - All_Points[e_Point].y_axis));
                    if(sgn_ans == -1){
                        Edge = false;
                    }
                }
                
            }
            if(Edge && All_Points[i].not_used){
                Edge_Points[count].push_back(All_Points[i]);
                All_Points[i].not_used = false;
                e_Point = i;
                i = 0;
            }
        }
    };
}

void Is_In_Border(vector<vector<Point> >& Edge_Points, int& X, int& Y, vector<double>& kingdom_area, double& total_destruction){
    vector<int> hit_data;
    
    for(int i = 0; i < Edge_Points.size(); i++){
        bool hit = true;

        for(int j = 0; j < Edge_Points[i].size(); j++){
            int sgn_ans = sgn((Edge_Points[i][(j + 1) % Edge_Points[i].size()].x_axis - Edge_Points[i][j].x_axis) * (Y - Edge_Points[i][j].y_axis) - (X  - Edge_Points[i][j].x_axis) * (Edge_Points[i][(j + 1) % Edge_Points[i].size()].y_axis - Edge_Points[i][j].y_axis));
            hit_data.push_back(sgn_ans);
            
        }
        for(int k = 0; k < hit_data.size(); k++){
            if(hit_data[k] == -1 && hit_data[k] != 1 && hit_data[k] != 0){
                hit = false;
                break;
            }
        }
        hit_data.clear();
        if(hit){
            total_destruction += kingdom_area[i];
            kingdom_area[i] = 0;
        }

    }
    return;
}

void Area_Calculator(vector<double>& kingdom_area, vector<vector<Point> >& Edge_Points){
    for(int i = 0; i < Edge_Points.size(); i++){
        double Area = 0;

        for(int j = 0; j < Edge_Points[i].size(); j++){
            Area += Edge_Points[i][j].x_axis * Edge_Points[i][(j + 1) % Edge_Points[i].size()].y_axis - Edge_Points[i][j].y_axis * Edge_Points[i][(j + 1) % Edge_Points[i].size()].x_axis;
        }
        Area = abs(Area/2);
        //cout << fixed << setprecision(2) << Area << '\n';
        kingdom_area.push_back(Area);
    }
}

int main(){
    //(Bx - Ax) * (y - Ay) - (x - Ax) * (By - Ay);
    system("clear");
    ofstream outFile("IN_OUT/output.txt");
    ifstream inFile("IN_OUT/input.txt");
    vector<Point> All_Points;
    vector<vector<Point> > Edge_Points(20);
    vector<double> kingdom_area;

    int N, x_axis, y_axis, count = 0;
    double total_destruction = 0.0;

    while(inFile >> N, N != -1){
        for(int i = 0; i < N; i++){
            inFile >> x_axis >> y_axis;
            All_Points.emplace_back(x_axis, y_axis);
        }
        Border(Edge_Points, All_Points, count);
        All_Points.clear();
        count++;
    }
    Edge_Points.resize(count + 1);
    Area_Calculator(kingdom_area, Edge_Points);

    while(inFile >> x_axis >> y_axis){
        Is_In_Border(Edge_Points, x_axis, y_axis, kingdom_area, total_destruction);
    }
    cout << fixed << setprecision(2) << total_destruction << '\n';
    return 0;
}
