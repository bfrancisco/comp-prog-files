#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int n, p;
ll x, y, c, d;
const int MXN = 3000, B = 100, C = 5, D = 42;
// ll dp[MXN+1][B+1][C+1][D+1];


void solve(){
    cin >> n >> p >> x >> y >> c >> d;

    vector<pair<ll, pair<ll, ll>>> acts(n);
    for (int i = 0; i < n; i++){
        cin >> acts[i].second.first >> acts[i].second.second;
        acts[i].first = acts[i].second.first + acts[i].second.second;
    }

    sort(acts.begin(), acts.end(), greater<pair<ll, pair<ll, ll>>>());

    for (int i = 0; i < p; i++){
        x += acts[i].second.first;
        y += acts[i].second.second;
    }

    ll ex, ey;
    ex = (x+y+1)/2;
    ey = (x+y)/2;
    cout << ex * ey << endl;
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}