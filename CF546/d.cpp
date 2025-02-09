#include<bits/stdc++.h>
using namespace std;

int dfs(int u, vector<int>& vis, vector<vector<int>>& adj){
    int mx_depth = 1;
    // cout << "u: " << u << endl;
    for (auto v : adj[u]){
        if (!vis[v]){
            vis[v] = 1;
            mx_depth = max(mx_depth, dfs(v, vis, adj) + 1);
        }
    }

    return mx_depth;

}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++){
        int v, u; cin >> v >> u;
        adj[u].push_back(v);
    }

    vector<int> vis(n+1, 0);
    vis[p[n-1]] = 1;
    cout << dfs(p[n-1], vis, adj) - 1 << endl;

    return 0;
}