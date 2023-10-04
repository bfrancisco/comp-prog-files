#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n;
vector<vector<pair<int, int>>> adj;
vector<int> color;
void dfs(int u, int odd, int prev){
    // cout << u << " " << odd << endl; 
    color[u] = odd;
    for (auto &[v, w] : adj[u]){
        if (prev == v) continue;
        (w%2 ? dfs(v, 1-odd, u) : dfs(v, odd, u));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    adj.resize(n+1);
    color.resize(n+1);
    for (int i = 0; i < n-1; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(1, 0, -1);

    // cout << endl;
    for (int u = 1; u <= n; u++){
        cout << color[u] << endl;
    }

    return 0;
}