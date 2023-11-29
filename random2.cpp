#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// cses 1683

vector<vector<int>> adj;
vector<vector<int>> adj, sccs;
vector<int> disc, low, stck;
int ti = 0;
int dfs(int u){
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    disc.assign(n, -1);
    low.assign(n, -1);

    return 0;
}