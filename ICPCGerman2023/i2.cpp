#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<pair<int, int>>> adj;
// vector<pair<int, pair<int, int>>> edges;
// map<pair<int, int>, ll> weight;
ll dist[500010];
int vis[500010];

// void bellman_ford(int s) {
//     for (int u = 0; u <= n; u++){
//         dist[u] = 1e18;
//     }
//     dist[s] = 0;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < edges.size(); j++){
//             int u = edges[j].first;
//             int v = edges[j].second.first;
//             ll w = edges[j].second.second;
//             if (dist[u] + w < dist[v])
//                 dist[v] = dist[u] + w;
//         }
//     }
// }

int spfa(int s){
    for (int u = 0; u <= n; u++){
        dist[u] = 1e18;
    }
    dist[s] = 0;

    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = 0;

        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;

            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;

                if (!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n+1);
    for (int i = 0; i < n; i++){
        ll cost; cin >> cost;
        for (int j = 1; j < min(m, n-i)+1; j++){
            ll resale; cin >> resale;
            adj[i].push_back({i+j, cost-resale});
            // edges.push_back({i, {i+j, cost-resale}});
        }
    }

    // bellman_ford(0);
    spfa(0);
    
    cout << dist[n] << endl;

    return 0;
}