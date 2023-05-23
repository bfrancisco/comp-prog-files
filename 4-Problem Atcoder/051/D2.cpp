#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, m;
vector<vector<pair<int, int>>> adj;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    adj.resize(n+1);

    for (int i = 0; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({w, v});
    }

    


    
    return 0;
}