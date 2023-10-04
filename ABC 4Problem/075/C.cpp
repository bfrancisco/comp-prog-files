#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<int>> adj;
vector<pair<int, int>> edges;

bool bfs(int a, int b){
    queue<int> q;
    q.push(a);
    vector<bool> vis(n+1, false);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = true;
        for (auto v : adj[u]){
             if ((u == a && v == b) || (u == b && v == a) || vis[v]) continue;
             if (v == b){
                // cout << a << " " << b << endl;
                return false;
             }

             q.push(v);
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;

    adj.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    int ans = 0;
    for (auto edge : edges){
        if (bfs(edge.first, edge.second)) ans++;
    }

    cout << ans;
    return 0;
}   