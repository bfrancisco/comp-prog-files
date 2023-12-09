#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    vector<ll> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        ll x; cin >> x;
        a[i] = a[i-1] + x;
    }
    ll ans = 0;
    for (int d = 1; d <= n; d++){
        if (n%d) continue;
        ll mn = 1e18, mx = 0;
        for (int i = 1; i <= n; i+=d){
            // s.insert(a[i+d-1] - a[i-1]);
            mn = min(mn, a[i+d-1] - a[i-1]);
            mx = max(mx, a[i+d-1] - a[i-1]);
        }
        ans = max(ans, mx-mn);
    }
    cout << ans << endl;
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