#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n, m; cin >> n >> m;
    map<string, int> adj;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        adj[s];
    }
    for (int i = 0; i < m; i++){
        string u, v;
        cin >> u >> v;
        adj[u]++;
        adj[v]++;
    }

    map<int, int> edg;
    for (auto &[s, sz] : adj){
        if (edg.find(sz) == edg.end())
            edg[sz] = 1;
        else
            edg[sz]++;
    }
    string ans = "PRANKED";
    if (n >= 5 && edg[1] == 2 && edg[3] == 2 && edg[1]+edg[2]+edg[3] == n){
        ans = "Alice";
    }
    else if (n >= 5 && edg[4] == 1 && edg[2]+edg[4] == n){
        ans = "Bob";
    }
    else if (n >= 5 && edg[1] == 2 && edg[1]+edg[2] == n){
        ans = "Cindy";
    }
    cout << ans << endl;
    
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