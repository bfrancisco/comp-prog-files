#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
ll k;
set<int> wormholes;
vector<vector<int>> adj;
vector<ll> dist_to_n;
vector<ll> dist_from_1;
ll wh_sum = 0;

void precompute_dist(int wh, vector<ll>& dist){
    queue<pair<int, ll>> q;
    q.push({wh, 0});
    vector<int> vis(n+1);
    vis[wh] = 1;
    dist[wh] = 0;
    while (!q.empty()){
        auto [u, d] = q.front();
        q.pop();

        for (auto v : adj[u]){
            if (vis[v]) continue;
            dist[v] = min(dist[v], d+1);
            vis[v] = 1;
            q.push({v, d+1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++){
        int w; cin >> w;
        wormholes.insert(w);
    }

    adj.resize(n+1);
    dist_to_n.resize(n+1, 1e18);
    dist_from_1.resize(n+1, 1e18);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    precompute_dist(n, dist_to_n);
    precompute_dist(1, dist_from_1);
    // for (int i = 1; i <= n; i++) cout << i << " : " << dist_to_n[i] << endl; cout << endl;
    for (auto wh : wormholes){
        wh_sum += dist_to_n[wh];
    }

    ll no_wh = dist_to_n[1];
    ll numer = 1e18;
    for (auto wh : wormholes){
        numer = min(numer, dist_from_1[wh]*(k-1) + (wh_sum - dist_to_n[wh]));
        // cout << wh << " : " << (dist_to_n[1] - dist_to_n[wh])*(k-1) + (wh_sum - dist_to_n[wh]) << endl;
    }

    // cout << no_wh << endl;
    if (no_wh*(k-1) < numer){
        cout << no_wh << '/' << 1 << endl;
    }
    else{
        ll gcd = __gcd(numer, k-1);
        cout << numer/gcd << '/' << (k-1)/gcd << endl;
    }

    
 
    return 0;
}