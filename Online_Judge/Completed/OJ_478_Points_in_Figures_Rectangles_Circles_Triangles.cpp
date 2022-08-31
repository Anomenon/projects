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
        return min_x < x && x < max_x && min_y < y && y < max_y;
    }

    Rectangle(double a, double b, double c, double d) : min_x{a}, max_y{b}, max_x{c}, min_y{d} {}
};

struct Circle : public Figure{
    double x, y, r;

    bool isPointInside(double x, double y) const override {
        return pow((this->x - x), 2) + pow((this->y - y), 2) < pow(r, 2);
    }

    Circle(double a, double b, double c) : x{a}, y{b}, r{c} {}
};

int sgn(double x) {
    return x > 0 ? 1 : x < 0 ? -1 : 0;
}

struct Triangle : public Figure{
    double x1, y1, x2, y2, x3, y3;

    bool isPointInside(double x, double y) const override {
        double A = (x2 - x1) * (y - y1) - (x - x1) * (y2 - y1);
        double B = (x3 - x2) * (y - y2) - (x - x2) * (y3 - y2);
        double C = (x1 - x3) * (y - y3) - (x - x3) * (y1 - y3);

        return sgn(A) == sgn(B) and sgn(A) == sgn(C);
    }

    Triangle(double a, double b, double c, double d, double e, double f) : x1{a}, y1{b}, x2{c}, y2{d}, x3{e}, y3{f} {}
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