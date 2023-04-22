#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, C; cin >> n >> C;
    vector<ll> a(n),b(n),c(n);
    map<ll, ll> da;
    for (int i = 0; i < n; i++){
        cin >> a[i] >> b[i] >> c[i];
        da[a[i]] += c[i];
        da[b[i]+1] -= c[i];
    }
    
    vector<pair<ll, ll>> pnts;
    for (auto p : da)
        pnts.push_back(p);
    
    for (int i = 1; i < pnts.size(); i++)
        pnts[i].second += pnts[i-1].second;

    ll ans = 0;
    for (int i = 0; i < pnts.size()-1; i++){
        ans += min(C, pnts[i].second) * (pnts[i+1].first - pnts[i].first);
    }
    cout << ans << endl;
    return 0;
}