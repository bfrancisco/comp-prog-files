#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll fastpow(ll b, ll e, ll m){
    ll res = 1ll;
    while (e){
        if (e&1ll) res = (res*b) % m;
        b = (b*b) % m; e >>= 1ll;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    ll ans = 0;
    ll mod = 1000000007;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            ll val = 1;
            if (i > 0){
                val = (val * fastpow(8, i, mod)) % mod;
            }
            if (j - i > 1){
                val = (val * fastpow(9, j-i-1, mod)) % mod;
            }
            if (j < n-1){
                val = (val * fastpow(10, n-j-1, mod)) % mod;
            }
            ans = (ans+val) % mod;
            // cout << i << " " << j << " " << ans << endl;
        }
    }
    ans = (ans*2)%mod;
    cout << ans << endl;

    return 0;
}