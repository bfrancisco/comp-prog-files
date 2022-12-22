#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int N = 5010;
const int inf = 1e10;
int n, m, T;
vector<vector<pair<ll,ll>>> adj(N);
ll dp[N][N];
int dfs(ll node, ll rem){
    if (node == n - 1 && rem == 0) return 0;
    if (rem <= 0) return inf;
    ll &ret = dp[node][rem];
    if (~ret) return ret;
    ret = inf;
    for (pair<ll, ll> &p : adj[node]){
        ret = min(ret, p.second + dfs(p.first, rem - 1));
    }
    return ret;
}

void path(int node, int rem, int time){
    cout << node + 1 << " ";
    if (node == n -1 && rem == 0) return;
    for (pair<ll, ll> &p : adj[node]){
        if (dfs(p.first, rem - 1) + p.second <= time){
            path(p.first, rem - 1, time - p.second);
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> T;
    for (int i = 0; i < m; i++){
        ll u ,v, x;
        cin >> u >> v >> x;
        u--; v--;
        adj[u].push_back({v, x});
    }
    memset(dp, -1, sizeof(dp)); // initialize all values to -1
    
    ll ans = 0;
    for (ll i = n-1; i >= 0; i--){
        if (dfs(0, i) <= T) {ans = i + 1; break;}
    }
    cout << ans << endl;
    path(0, ans-1, T);
    
    return 0;
}