#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 1; u <= n; u++){
        for (auto v : adj[u]){
            
        }
    }

    return 0;
}