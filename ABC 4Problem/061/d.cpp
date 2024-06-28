#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int n, m;
vector<vector<pair<int, ll>>> adj;
vector<ll> dist;

bool bellman(){
    dist[1] = 0;
    for (int i = 0; i < n-1; i++){
        for (int u = 1; u <= n; u++){
            for (auto& [v, w] : adj[u]){
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
    ll ans = dist[n];
    for (int u = 1; u <= n; u++){
        for (auto& [v, w] : adj[u]){
            dist[v] = max(dist[v], dist[u] + w);
        }
    }
    return ans == dist[n];
}

int main(){
    cin >> n >> m;
    adj.resize(n+1);
    dist.assign(n+1, -1e18);
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    if (bellman()) cout << dist[n];
    else cout << "inf";

    return 0;
}