#include<bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int>& vis, vector<set<int>>& adj, map<int, int>& db){
    // cout << '\t' << u << endl;
    for (auto v : adj[u]){
        db[u]++;
        
        if (vis[v]) continue;
        vis[v] = 1;
        dfs(v, vis, adj, db);
    }
}

void solve(){
    int n; cin >> n;
    vector<set<int>> adj(n+1);
    for (int u = 1; u <= n; u++){
        int v; cin >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // for (int u = 1; u <= n; u++){
    //     cout << u << " : ";
    //     for (auto v : adj[u]) cout << v << " ";
    //     cout << endl; 
    // }

    vector<int> vis(n+1, 0);
    int cycles = 0, ordi = 0;
    int regions = 0;
    for (int u = 1; u <= n; u++){
        if (!vis[u]){
            // cout << u << endl;

            map<int, int> db;
            vis[u] = 1;
            dfs(u, vis, adj, db);
            
            bool isCycle = true;
            for (auto [u, freq] : db){
                // cout << u << " " << freq << endl;
                if (freq != 2) isCycle = false;
            }
            if (isCycle) cycles++;
            else ordi++;

            regions++;
        }
    }
    cout << min(cycles+1, regions) << " " << cycles + ordi << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while (t--){
        solve();
    }
    return 0;
}