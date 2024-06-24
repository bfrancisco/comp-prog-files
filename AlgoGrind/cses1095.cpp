#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

ll MOD = 1e9 + 7;

ll mod(ll x, ll m){
    return ((x%MOD)+MOD)%MOD;
}

ll fast_expo(ll a, ll b, ll m){
    if (b == 0ll) return 1ll;
    if (a == 0ll) return 0ll;
    if (b == 1ll) return a;
    ll half = fast_expo(a, b/2, m);
    return mod(mod(half * half, m) * (b%2 ? a : 1ll), m);
}

void solve(){
    ll a, b; cin >> a >> b;
    cout << fast_expo(a, b, MOD) << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}