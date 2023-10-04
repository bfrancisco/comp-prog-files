#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(int u, vector<vector<int>>& adj, vector<int>& vis){
    vis[u] = 1;
    for (auto v : adj[u]){
        if (!vis[v])
            dfs(v, adj, vis);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++){
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> vis(n+1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            // cout << i << endl;
            dfs(i, adj, vis);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}