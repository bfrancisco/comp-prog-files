#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<pair<int, int>>> adj;
map<pair<int, int>, bool> eds; // true if goes through
int dist[101];
int pre[101];

void dijkstra(int s){
    for (int u = 1; u <= n; u++)
        {dist[u] = 1e9; pre[u] = -1;}

    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        // cout << "s: " << u << endl;
        if (dist[u] < d) continue;
        dist[u] = d;
        for (auto &e : adj[u]){
            int v = e.first;
            int w = e.second;
            // cout << v << " " << w << endl;
            if (dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                pre[v] = u;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n+1);

    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        if (u < v) eds[{u, v}] = false;
        else eds[{v, u}] = false;
    }

    for (int u = 1; u <= n; u++){
        if (adj[u].empty()) continue;
        // cout << "dijkstra: " << u << endl;
        dijkstra(u);
        // for (int x = 1; x <= n; x++){
        //     cout << u << " to " << x << " : " << dist[x] << endl;
        // }
        for (int v = u+1; v <= n; v++){
            if (adj[v].empty()) continue;
            // cout << "to " << v << endl;
            int node = v;
            while (node != u){
                if (pre[node] < node){
                    eds[{pre[node], node}] = true;
                }
                else{
                    eds[{node, pre[node]}] = true;
                }
                node = pre[node];
            }
        }
    }

    int ans = 0;
    for (auto e : eds){
        if (!e.second){
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}