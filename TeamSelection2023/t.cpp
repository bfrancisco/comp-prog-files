#include<bits/stdc++.h>
using namespace std;

using ll = long long int;
int cap = 3;
string a = "1234";
void rb(string& s){
    if (s.size() == cap){
        cout << s.size() << " ";
        for (auto z : s) cout << z;
        cout << endl;
        return;
    }

    for (auto c : a){
        s.push_back(c);
        rb(s);
        s.pop_back();
    }
}

int main(){

    string s = "";
    rb(s);
    return 0;
}