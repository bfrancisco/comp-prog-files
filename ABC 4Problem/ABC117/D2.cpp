#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(vector<ll>& a, ll x){
    ll val = 0;
    for (auto e : a){
        val += (e ^ x);
    }
    return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll mx = -1;
    ll limit = 10000;
    for (ll x = k; x >= k-limit && x >= 0; x--){
        ll val = f(a, x);
        mx = max(mx, val);
    }
    
    for (ll x = 0; x <= min(limit, k); x++){
        ll val = f(a, x);
        mx = max(mx, val);
    }
    cout << mx;
    return 0;
}