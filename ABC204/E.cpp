#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<pair<int, pair<ll, ll>>>> adj;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    ll mxD = -1;
    for (int i = 0; i < m; i++){
        int a, b; ll c, d;
        cin >> a >> b >> c >> d;
        adj[a].push_back({b, {c, d}});
        adj[b].push_back({a, {c, d}});
        mxD = max(mxD, d);
    }

    

    return 0;
}