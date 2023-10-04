#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k; cin >> n >> k;
    ll ones[51];
    ll a[100010];
    for (ll i = 0; i <= 45; i++) ones[i] = 0;
    for (ll i = 0; i < n; i++){
        ll x; cin >> x;
        for (ll j = 45; j >= 0; j--){
            if (x & (1ll << j))
                ones[j]++;
        }
        a[i] = x;
    }
    ll val = 0;
    ll threshold = n/2;
    if (n%2==0) threshold--;

    for (ll j = 45; j >= 0; j--){
        ll toadd = pow(2ll, j);
        if (ones[j] <= threshold && val + toadd <= k){
            val += toadd;
        }
            
    }
    
    // for (ll i = 0; i <= 5; i++){
    //     cout << i << ": " << ones[i] << endl;
    // }
    // cout << val << endl;

    ll ans = 0;
    for (ll i = 0; i < n; i++){
        ans += (a[i] ^ val);
    }

    cout << ans;

    return 0;
}