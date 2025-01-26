#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool dfs(int u, vector<set<int>>& adj, vector<int>& vis){
    bool ret = true;
    // cout << u << endl;
    for (auto v : adj[u]){
        if (vis[v]){
            ret = false;
            // cout << "FALSE: " << v << endl;            
            break;
        }
        
        vis[v] = 1;
        ret = ret && dfs(v, adj, vis);
        vis[v] = 0;

        if (!ret) break;
    }

    return ret;

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

    int root = -1;
    for (int i = 1; i <= n; i++){
        if (indeg[i] == 0) {root = i; break;}
    }
    if (root == -1) {cout << "NO\n"; return;}

    vector<int> vis(n+1, 0);
    vis[root] = 1;

    // cout << "root: " << root << endl;
    // for (int i = 1; i <= n; i++){
    //     cout << i << " : ";
    //     for (auto j : adj[i]) cout << j << " ";
    //     cout << endl; 
    // }cout << endl;

    if (dfs(root, adj, vis)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}