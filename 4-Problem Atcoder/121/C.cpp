#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    for (auto e : v){
        ll c = e.first, d = e.second;
        ans += c * min(m, d);
        m -= min(m, d);
        if (m <= 0) break;
    }
    cout << ans;
    return 0;
}