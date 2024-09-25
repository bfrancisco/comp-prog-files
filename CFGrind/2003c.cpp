#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n; cin >> n;
    vector<pair<int, char>> a;
    map<char, int> f;

    for (int i = 0; i < n; i++){
        char c; cin >> c;
        f[c]++;
    }
    
    for (auto [c, v] : f){
        a.push_back({v, c});
    }

    sort(a.begin(), a.end(), greater<pair<int, char>>());
    
    // for (auto [v, c] : a){
    //     cout << c << " : " << v << endl; 
    // }
    
    int dlt = 0;
    while (true){
        int brk = true;
        for (int i = 0; i < a.size(); i++){
            if (a[i].first == 0) break;
            cout << a[i].second;
            a[i].first--;
            brk = false;
        }
        if (brk) break;

    }

    cout << endl;
    
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}