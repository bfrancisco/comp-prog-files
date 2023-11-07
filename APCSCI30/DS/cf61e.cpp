#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll ans = 0;

ll f(ll depth){
    if (depth < 3) return 0;
    return depth*(depth-1)*(depth-2)/6;
}

void dfs(ll u, ll prev, ll depth, unordered_map<ll, vector<ll>>& adj){
    // if leaf node
    if (adj.find(u) == adj.end()){
        ans += f(depth);
    }

    for (auto v : adj[u]){
        if (v == prev) continue;
        dfs(v, u, depth+1, adj);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    set<ll> bank;
    bank.insert(0);
    unordered_map<ll, vector<ll>> adj;
    for (int i = n-1; i >= 0; i--) {
        bank.insert(a[i]);
        auto it = lower_bound(bank.begin(), bank.end(), a[i]);
        it--;
        // if (*it == 0) continue;
        ll u = *it;
        adj[u].push_back(a[i]);
    }

    for (auto [k, v] : adj) {
        cout << k << " : ";
        for (auto x : v) cout << x << " ";
        cout << endl;
    }

    dfs(0, -1, 0, adj);
    cout << ans << endl;
    return 0;
}