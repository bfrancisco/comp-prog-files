#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int tym = 0;

void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& start, vector<int>& finish, set<pair<int, int>>& bedges){
    start[u] = tym++;

    for (auto v : adj[u]){
        if (start[v] == -1){
            dfs(v, u, adj, start, finish, bedges);
        }
        else if (v != p){
            // cout << u << " " << v << endl;
            if (u <= v) bedges.insert({u, v});
            else bedges.insert({v, u});
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
    vector<int> start(n, -1), finish(n, -1), parent(n, -1);
    set<pair<int, int>> bedges;
    for (int i = 0; i < n; i++){
        if (start[i] == -1)
            dfs(i, -1, adj, start, finish, bedges);
    }
    
    vector<int> edg(n, 0);
    for (int i = 0; i < n; i++){
        int sz = adj[i].size();
        edg[sz]++;
    }

    // cout << bedges.size() << " " << edg[1] << " " << edg[2] << endl;
    int backedge = bedges.size();
    int ppl = 0;
    if (n >= 5      && edg[1] == 2 && edg[3] == 2 && edg[1]+edg[2]+edg[3] == n  && backedge == 1 && n == m){
        cout << "Alice" << " "; ppl++;
    }
    if (n >= 5 && edg[4] == 1                && edg[2]+edg[4] == n         && backedge == 2 && n == m-1){
        cout << "Bob" << " "; ppl++;
    }
    if (n >= 5 && edg[1] == 2                && edg[1]+edg[2] == n         && backedge == 0 && n-1 == m){
        cout << "Cindy" << " "; ppl++;
    }
    if (ppl==0){
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