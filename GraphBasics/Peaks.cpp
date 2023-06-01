#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> h(n+1);
    for (int i = 1 ; i <= n; i++)
        cin >> h[i];
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;

    for (int u = 1; u <= n; u++){
        int good = 1;
        for (auto v : adj[u]){
            if (h[v] >= h[u]){
                good = 0; 
                break;
            }

        }
        if (good){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}