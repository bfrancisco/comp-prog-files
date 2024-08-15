#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dfs(int u, int n, vector<vector<int>>& adj, vector<ll>& val){
    if (adj[u].empty()) return val[u];

    ll min_child = 1e18;

    for (auto v : adj[u]){
        min_child = min(min_child, dfs(v, n, adj, val));
    }

    if (u == 0) return val[u] + min_child;

    if (val[u] <= min_child){
        // cout << "U: " << u << "\t" << val[u] + (ll)((min_child - val[u])/2) << endl;
        return val[u] + (ll)((min_child - val[u])/2);
    }
    else{
        // cout << "U: " << u << "\t" << min_child << endl;

        return min_child;
    }
}

void solve(){

    int n; cin >> n;
    vector<ll> val(n);
    for (int i = 0; i < n; i++) cin >> val[i];
    
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++){
        int u; cin >> u;
        u--;
        adj[u].push_back(i);
    }

    // for (int u = 0; u < n; u++){
    //     cout << u << ": ";
    //     for (auto v : adj[u]) cout << v << " ";
    //     cout << endl;
    // }

    cout << dfs(0, n, adj, val) << endl;
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