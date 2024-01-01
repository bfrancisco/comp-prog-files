#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dfs(int u, int p, vector<int>& visited, vector<set<int>>& adj){
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

int dfs2(int u, int p, vector<set<int>>& adj){
    // dfs from node having 1 neighbor, end at node with 3 neighbors
    if ((int)adj[u].size() == 3){
        return u;
    }
    for (auto v : adj[u]){
        if (v != p){
            return dfs2(v, u, adj);
        }
    }

    return -1;
}

void solve(){
    int n, m; cin >> n >> m;
    map<string, int> mp;
    vector<set<int>> adj(n);
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        mp[s] = i;
    }
    for (int i = 0; i < m; i++){
        string u, v;
        cin >> u >> v;
        adj[mp[u]].insert(mp[v]);
        adj[mp[v]].insert(mp[u]);
    }

    vector<int> visited(n, 0);
    int cycles = 0;
    for (int i = 0; i < n; i++){
        if (!visited[i]){
            cycles += dfs(i, -1, visited, adj);
        }
    }
    cycles /= 2;
    // cout << cycles << endl;

    set<int> threes, ones;
    vector<int> edg(n+100, 0);
    for (int i = 0; i < n; i++){
        int sz = adj[i].size();
        edg[sz]++;
        if (sz == 1) ones.insert(i);
    }

    if (edg[3] == 2 && edg[1] == 2){
        for (auto u : ones){
            threes.insert(dfs2(u, -1, adj));
        }
    }
    
    
    
    if      (n >= 5 && edg[3] == 2 && edg[1] == 2 && (edg[1]+edg[2]+edg[3]) == n  && cycles == 1 && n == m && (int)threes.size() == 2){

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