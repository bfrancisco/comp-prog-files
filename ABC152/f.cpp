#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> adj;
ll dp[50][2]; // dp[][0] = white, dp[][1] = black
ll rec(int u, int c, int btset){
    if (adj[u].size() == 0){
        return 1;
    }
    ll bval = 0, wval = 0;
    int bgood = 0, wgood = 0;
    if (dp[u][1] != -1){
        bval = dp[u][0];
        bgood = 1;
    }
    if (dp[u][0] != -1){
        wval = dp[u][1];
        wgood = 1;
    }
    
    for (auto v : adj[u]){
        if (!bgood) bval += rec(v, 1, (1 << u) & btset);
        if (!wgood) wval += rec(v, 0, btset);
    }

    dp[u][0] = bval;
    dp[u][1] = wval;
    return dp[u][0] + dp[u][1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<int> u(n-1), v(n-1);

    for (int i = 0; i < n-1; i++){
        cin >> u[i] >> v[i];
    }

    adj.resize(n);
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n-1; j++){
            if (v[i] == u[j]){
                adj[u[i]-1].push_back(v[j]-1);
            }
        }
    }

    ll ans = 0;
    ans += rec(0, 1, 1); // black
    ans += rec(0, 0, 0);
    

    cout << ans << endl;
    return 0;
}