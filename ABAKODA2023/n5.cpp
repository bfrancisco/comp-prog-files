#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dfs(int u, int p, vector<int>& visited, vector<vector<int>>& adj){
    visited[u] = 1;
    int cyc = 0;
    for (auto v : adj[u]){
        if (!visited[v]){
            cyc += dfs(v, u, visited, adj);
        }
        else if (v != p){
            cyc++;
        }
    }
    return cyc;
}

void solve(){
    int n, m; cin >> n >> m;
    map<string, int> mp;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        mp[s] = i;
    }
    for (int i = 0; i < m; i++){
        string u, v;
        cin >> u >> v;
        adj[mp[u]].push_back(mp[v]);
        adj[mp[v]].push_back(mp[u]);
    }

    vector<int> visited(n, 0);
    int cycles = 0;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            cycles += dfs(i, -1, visited, adj);
        }
    }
    
    vector<int> edg(n+100, 0);
    for (int i = 0; i < n; i++){
        int sz = adj[i].size();
        edg[sz]++;
    }

    cycles /= 2;
    // cout << cycles << endl;
    
    if      (n >= 5 && edg[3] == 2 && edg[1] == 2 && (edg[1]+edg[2]+edg[3]) == n  && cycles == 1 && n == m){
        cout << "Alice";
    }
    else if (n >= 5 && edg[4] == 1                && edg[2]+edg[4] == n         && cycles == 2 && n == m-1){
        cout << "Bob";
    }
    else if (n >= 5 && edg[1] == 2                && edg[1]+edg[2] == n         && cycles == 0 && n-1 == m){
        cout << "Cindy";
    }
    else {
        cout << "PRANKED";
    }

    cout << endl;
    
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