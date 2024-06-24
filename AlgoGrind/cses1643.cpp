#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void solve(){
    int n; cin >> n;
    ll mx = -1e9-10;
    ll cur = 0;
    ll x;
    while(n--){
        cin >> x;
        cur += x;
        mx = max(mx, cur);
        if (cur < 0) cur = 0;
    }
    cout << mx;
}

int main(){
    // int t; cin >> t;
    int t = 1;
    while (t--){
        solve();
    }
    
    return 0;
}