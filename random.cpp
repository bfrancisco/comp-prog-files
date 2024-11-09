#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll dfs(ll u, map<ll, vector<ll>>& mp, map<ll, int>& vis){
    ll ret = u;
    for (auto v : mp[u]){
        if (vis[v]) continue;
        vis[v] = 1;
        ret = max(ret, dfs(v, mp, vis));
    }

    return ret;
}

void solve(){  
    ll n; cin >> n;
    vector<ll> a(n+1);
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += i-1;
    }
    
    map<ll, vector<ll>> mp; // val+i, i-1
    map<ll, int> vis;
    for (ll i = 2; i <= n; i++){
        mp[a[i]].push_back(a[i] + (i-1));
        vis[a[i]] = 0;
    }

    // for (auto [k, v] : mp){
    //     cout << "Node: " << k << endl;
    //     for (auto e : v) cout << e << " "; cout << endl;
    // }

    vis[n] = 1;
    cout << dfs(n, mp, vis) << endl;    
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