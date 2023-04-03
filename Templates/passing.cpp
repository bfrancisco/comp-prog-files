#include <bits/stdc++.h>
using namespace std;
void f1(pair<int, int> x, pair<int, int> y) { // pass by value: C++ default, Java for primitives
    x = {1, 0};
    y.first = 1;
}
void f2(pair<int, int>* x, pair<int, int>* y) { // pass by sharing: Python, Java for objects
    x = new pair<int, int>(1, 0);
    y->first = 1;
}
void f3(pair<int, int>& x, pair<int, int>& y) { // pass by reference: only in C++
    x = {1, 0};
    y.first = 1;
}
int main() {
    pair<int, int> x1 = {0, 0}, x2 = {0, 0}, x3 = {0, 0};
    pair<int, int> y1 = {0, 0}, y2 = {0, 0}, y3 = {0, 0};
    f1(x1, y1);
    f2(&x2, &y2);
    f3(x3, y3);
    cout << x1.first << " " << x2.first << " " << x3.first << endl;
    cout << y1.first << " " << y2.first << " " << y3.first << endl;
    return 0;
}