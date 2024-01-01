#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int tym, cycles;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& start){
    start[u] = tym++;

    for (auto v : adj[u]){
        if (v == p) continue;
        if (start[v] == -1) dfs(v, u, adj, start);
        else{
            if (v != p && start[v] < start[u]) cycles++;
        }
    }
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

    tym = 0;
    cycles = 0;
    vector<int> start(n, -1);
    int regions = 0;
    for (int i = 0; i < n; i++){
        if (start[i] == -1){
            dfs(i, -1, adj, start);
            regions++;
        }
            
    }
    
    vector<int> edg(n+100, 0);
    for (int i = 0; i < n; i++){
        int sz = adj[i].size();
        edg[sz]++;
    }

    cout << cycles << endl;
    // WA: code outputs Alice where it should be Pranked
    if      (n >= 5 && edg[3] == 2 && edg[1] == 2 && (edg[1]+edg[2]+edg[3]) == n  && cycles == 1 && n == m    && regions==1){
        cout << "Alice";
    }
    else if (n >= 5 && edg[4] == 1                && edg[2]+edg[4] == n         && cycles == 2 && n == m-1  && regions==1){
        cout << "Bob";
    }
    else if (n >= 5 && edg[1] == 2                && edg[1]+edg[2] == n         && cycles == 0 && n-1 == m  && regions==1){
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