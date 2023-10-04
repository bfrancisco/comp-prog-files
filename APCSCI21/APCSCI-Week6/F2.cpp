#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<ll, ll>> graph[5001];
ll n, m, T;
pair<ll, ll> dp[5001];
vector<ll> optimal;

vector<ll> getPath(){
    vector<ll> revpath;
    ll v = n;
    while (v != -1){
        revpath.push_back(v);
        v = dp[v].second;
    }
    reverse(revpath.begin(), revpath.end());
    return revpath; 
}

void dfs(ll v){
    //cout << v << endl;
    if (v == n){
        vector<ll> path = getPath();
        if (path.size() > optimal.size()){
            optimal = path;
        }
        return;
    }

    for (pair<ll, ll> nw : graph[v]){
        ll next = nw.first;
        ll weight = nw.second;
        if (dp[v].first + weight > T) return;
        
        dp[next].first = dp[v].first + weight;
        dp[next].second = v;
        dfs(next);
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> T;

    for (ll i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    for (ll i = 1; i <= n; i++){
        dp[i] = make_pair(10000000000, -1);
    }
    dp[1].first = 0;
    dfs(1);

    cout << optimal.size() << endl;
    for (ll v : optimal) cout << v << " ";
    cout << endl;
    
    return 0;
}