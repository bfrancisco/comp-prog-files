#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int n, m;
vector<ll> city, cell;

bool can(ll r){
    
}

void solve(){
    cin >> n >> m;
    city.resize(n);
    cell.resize(m);
    for (int i = 0; i < n; i++) cin >> city[i];
    for (int i = 0; i < m; i++) cin >> cell[i];

    int l = 0, r = 2*1e9 + 10;
    int m;
    int want = -1;
    while (l < r){
        m = l + (r-l)/2;
        if (!can(m)){
            l = m+1;
            want = l;
        }
        else{
            r = m;
        }
    }

    cout << want+1;
}

int main(){
    // int t; cin >> t;
    int t = 1;
    while (t--){
        solve();
    }
    
    return 0;
}