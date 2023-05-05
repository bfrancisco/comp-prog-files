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
    ll mod = 1000000007ll;
    ll ans = fastpow(10, n, mod);
    ans -= (fastpow(9, n, mod) + fastpow(9, n, mod) - fastpow(8, n, mod));
    cout << ans % mod << endl;

    return 0;
}