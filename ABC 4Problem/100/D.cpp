#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll x[1000], y[1000], z[1000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> z[i];
    
    ll ans = -(1e15);
    // 0-positive, 1-negative. 3 options
    for (int bit = 0; bit < (1<<3); bit++){
        vector<pair<ll, int>> sums;
        for (int i = 0; i < n; i++){
            ll val = 0;
            val += (bit&(1<<0) ? -x[i] : x[i]);
            val += (bit&(1<<1) ? -y[i] : y[i]);
            val += (bit&(1<<2) ? -z[i] : z[i]);
            sums.push_back({val, i});
        }
        sort(sums.begin(), sums.end(), greater<pair<ll, int>>());
        
        // calculate da shit for the first m items
        ll a = 0, b = 0, c = 0;
        for (int i = 0; i < m; i++){
            a += x[sums[i].second];
            b += y[sums[i].second];
            c += z[sums[i].second];
        }
        ans = max(ans, abs(a) + abs(b) + abs(c));
    }
    cout << ans << endl;
    return 0;
}