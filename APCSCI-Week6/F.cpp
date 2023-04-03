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

vector<ll> dfs(ll start){
    dp[start] = make_pair(0, -1);
    queue<ll> q;
    q.push(start);

    while (!q.empty()){
        ll v = q.front();
        q.pop();
        
        if (v == n){
            optimal = getPath();
            continue;
        }

        for (pair<ll, ll> nw : graph[v]){
            ll next = nw.first;
            ll weight = nw.second;
            if (dp[v].first + weight > T){
                continue;
            }
            dp[next].first = dp[v].first + weight;
            dp[next].second = v;
            q.push(next);
        }
    }
    return optimal;
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
    vector<ll> bestPath = dfs(1);

    cout << bestPath.size() << endl;
    for (ll v : bestPath) cout << v << " ";
    cout << endl;
    
    return 0;
}