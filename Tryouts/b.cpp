#include<bits/stdc++.h>
using namespace std;

int main(){
    set<char> a;
    string s; cin >> s;
    int ans = 1;
    for (auto c : s){
        if (a.find(c) == a.end())
            a.insert(c);
        else{
            ans = 0;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}