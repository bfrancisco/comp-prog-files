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

    string ans = "unknown topology";

    // bus topo
    int one = 0, two = 0, star = 0;
    for (int u = 1; u <= n; u++){
        if (adj[u].size() == 1) one++;
        else if (adj[u].size() == 2) two++;
        else if (adj[u].size() == n-1) star = 1;
    }
    if (one == 2 && one+two == n){
        ans = "bus topology";
    }
    else if (two == n){
        ans = "ring topology";
    }
    else if (star && one == n-1){
        ans = "star topology";
    }

    cout << ans << endl;


    return 0;
}