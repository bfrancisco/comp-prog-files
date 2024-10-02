#include<bits/stdc++.h>
using namespace std;

struct line{
    double x1, x2, y1, y2;
    double A, B, C;
    line(int a, int b, int c, int d){
        x1 = a;
        y1 = b;
        x2 = c;
        y2 = d;

        A = y2 - y1;
        B = x1 - x2;
        C = A*(x1) + B*(y1);
    }
    
    pair<double, double> does_intersect(line other){
        double det = A*other.B - other.A*B;
        if (fabs(det) <= 0.000001) return {DBL_MAX, DBL_MAX};
        double x, y;
        x = (other.B*C - B*other.C)/det;
        y = (A*other.C - other.B*C)/det;
        return {x, y};
    }
    

    void print(){
        cout << "(" << x1 << ", " << y1 << ") to " << "(" << x2 << ", " << y2 << ")" << endl;
    }
};

int main(){
    int n;
    cin >> n;

    vector<line> lines;
    double a,b,c,d;
    for (int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        lines.push_back(line(a,b,c,d));
    }


    for (auto line : lines) line.print();

    pair<double, double> z = lines[0].does_intersect(lines[1]);
    cout << z.first << " " << z.second << endl;
    
    return 0;
}