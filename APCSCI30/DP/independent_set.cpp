// https://atcoder.jp/contests/dp/tasks/dp_p
// no dp (yet?)
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MOD = 1e9 + 7;
ll mod(ll x, ll m){
    if (m == 0) return 0;
    if (m < 0) m *= -1;
    return (x%m + m) % m;
}

vector<vector<int>> adj;
 
// pair = cnt(W), cnt(B)
pair<ll, ll> rec(int u, int prev){
    ll W = 1, B = 1;
    for (auto v : adj[u]){
        if (v == prev) continue;
        pair<ll, ll> p = rec(v, u);
        B *= p.first;
        W *= (p.first + p.second);
        B = mod(B, MOD);
        W = mod(W, MOD);
    }

    return {W, B};
}

void solve(){
    int n; cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    pair<ll, ll> p = rec(0, -1);
    cout << mod(p.first + p.second, MOD) << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();    
    return 0;
}