#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<int>> adj;
vector<int> indeg;
vector<int> vis;
int ans = 0;
void dfs(int u){
    int end = 1;
    for (auto v : adj[u]){
        if (vis[v]) continue;
        end = 0;
        vis[v] = 1;
        dfs(v);
    }
    if (end){
        cout << "end: " << u << endl;
        ans++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n+1);
    indeg.assign(n+1, 0);
    vis.assign(n+1, 0);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        indeg[u]++;
    }

    set<pair<int, int>> topo;
    for (int u = 1; u <= n; u++){
        topo.insert({indeg[u], u});
    }

    for (auto& [indegree, u] : topo){
        if (vis[u]) continue;
        cout << "u: " << u << endl;
        dfs(u);
    }
    cout << ans << endl;
    

    return 0;
}