#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

void dfs(int u, vector<vector<int>>& adj, vector<ll>& score, vector<int>& vis){
    int children = 0;
    for (auto v : adj[u]){
        if (vis[v]) continue;
        vis[v] = 1;
        dfs(v, adj, score, vis);
        score[u] += score[v];
        children++;
    }

    if (children == 0){
        score[u] = 1ll;
    }
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> score(n+1);
    vector<int> vis(n+1);
    vis[1] = 1;
    dfs(1, adj, score, vis);

    // for (int i = 1; i <= n; i++){
    //     cout << i << " : " << score[i] << endl;
    // }

    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        cout << score[x] * score[y] << endl;
    }
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