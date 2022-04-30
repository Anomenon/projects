#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
struct Figure{
    virtual bool isPointInside(double x, double y) const = 0;
};
struct Rectangle : public Figure{
    double min_x, max_y, max_x, min_y;

    bool isPointInside(double x, double y) const override {
        return min_x <= x && x <= max_x && min_y <= y && y <= max_y;
    }

    Rectangle(double a, double b, double c, double d) : min_x{a}, max_y{b}, max_x{c}, min_y{d} {}
};

struct Circle : public Figure{
    double x, y, r;

    bool isPointInside(double x, double y) const override {
        return pow((this->x - x), 2) + pow((this->y - y), 2) <= pow(r, 2);
    }

    Circle(double a, double b, double c) : x{a}, y{b}, r{c} {}
};

struct Triangle : public Figure{
    double x1, y1, x2, y2, x3, y3;

    bool isPointInside(double x, double y) const override {
        double Area = (x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0;
        double Area1 = (x1*(y-y3) + x*(y3-y1)+ x3*(y1-y))/2.0;
        double Area2 = (x1*(y2-y) + x2*(y-y1)+ x*(y1-y2))/2.0;
        double Area3 = (x*(y2-y3) + x2*(y3-y)+ x3*(y-y2))/2.0;
        return Area == Area1 + Area2 + Area3;
    }

    Triangle(double a, double b, double c, double d, double e, double f) : x1{a}, x2{b}, x3{c}, y1{d}, y2{e}, y3{f} {}
};


int main(){
    ofstream File("IN_OUT/output.txt");
    char fig;
    double a, b, c, d, e, f, x, y;
    int point = 1;
    vector<Figure*> figures;

    while(cin >> fig, fig != '*'){
        switch (fig){
            case 'c':
                cin >> a >> b >> c;
                figures.push_back(new Circle{a, b, c});
                break;

            case 't':
                cin >> a >> b >> c >> d >> e >> f;
                figures.push_back(new Triangle{a, b, c, d, e, f});
                break;

            case 'r':
                cin >> a >> b >> c >> d;
                figures.push_back(new Rectangle{a, b, c, d});
                break;
        }
    }
    cout << figures.size();
    while(cin >> x >> y, x != 9999.9 && y != 9999.9){
        bool isInside = false;
        for(int i = 0; i < figures.size(); i++){
            Figure* f = figures[i];

            if (f->isPointInside(x, y)){
                isInside = true;
                File << "Point " << point << " is contained in figure " << i + 1 << '\n';
            }
        }
        if(isInside == false){
            File << "Point " << point << " is not contained in any figure\n";
        }
        point++;
    }
    return 0;
}