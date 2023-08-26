#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ee;
vector<vector<int>> adj;
vector<vector<int>> c;


void dijkstra(int s, int t){
    vector<int> dist;
    for (int u=0; u<=n; u++){
        dist[u] = INT32_MAX;
    }
    dist[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push()
}
int main(){
    int n, m, a, b, ans=0;
    cin >> n >> m >> a >> b;

    ee.resize(n+1, vector<int>(n+1, 0));
    adj.resize(n+1);

    for (int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        ans += w;
        ee[u][v] = 1;
        ee[v][u] = 1;
        c[u][v] = w;
        c[v][u] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}