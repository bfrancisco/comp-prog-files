#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(ll x){
    return ((x > 0) ? x*(x+1)/2 : 0);
}

void solve(){
    int n; cin >> n;
    ll k, q; cin >> k >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll count = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (a[i] <= q) count++;
        else{
            ans += f(count-k+1); 
            count = 0;
        } 
    }

    cout << ans + f(count-k+1) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) solve();

    return 0;
}