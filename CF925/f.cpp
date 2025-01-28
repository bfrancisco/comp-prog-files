#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool dfs(int u, vector<set<int>>& adj, vector<int>& vis, vector<int>& rec){
    // cout << u << endl;
    if (!vis[u]){
        vis[u] = rec[u] = 1;

        for (auto v : adj[u]){
            // cout << "adj: " << v << endl;
            if (!vis[v] && dfs(v, adj, vis, rec)) return true;
            else if (rec[v]) return true;
        }
    }
    rec[u] = 0;
    return false;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<set<int>> adj(n+1);
    vector<int> indeg(n+1, 0);
    for (int i = 0; i < k; i++){
        vector<int> order(n);
        for (int j = 0; j < n; j++) cin >> order[j];

        for (int j = 1; j < n-1; j++){
            if (adj[order[j]].find(order[j+1]) == adj[order[j]].end()){
                adj[order[j]].insert(order[j+1]);
                indeg[order[j+1]]++;
            }
        }
    }

    if (n <= 2) {cout << "YES\n"; return;}


    vector<int> vis(n+1, 0);
    vector<int> rec(n+1, 0);

    bool cycle = false;
    for (int i = 1; i <= n; i++){
        if (vis[i]) continue;
        cycle = cycle || dfs(i, adj, vis, rec);
    }


    cout << (cycle ? "NO" : "YES") << endl; 

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}