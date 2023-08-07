#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> adj;
int good = 1;
void dfs(int u, int c, vector<int>& color, int prev){
    // cout << u << endl;
    if (!good) return;
    color[u] = c;
    for (auto v : adj[u]){
        if (prev == v) continue;
        if (color[v] == color[u]) {good = 0; return;}
        if (color[v] == -1)
            dfs(v, 1-c, color, u);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m, mod; cin >> n >> m >> mod;
    adj.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n+1, -1);
    int paint = 0;
    ll comps = 0;
    for (int u = 1; u <= n; u++){
        if (color[u] == -1){
            dfs(u, 0, color, -1);
            if (!good) {cout << "impossible" << endl; return 0;}
            comps += 1;
        }
    }

    ll ans = 1;
    for (int i = 0; i < comps-1; i++){
        ans *= 2; ans %= mod;
    }
    cout << (ans+1) % mod << endl;

    return 0;
}