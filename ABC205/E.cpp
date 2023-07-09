#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod = 1000000007;
ll fact[2000001];
ll invf[2000001];

ll modd(ll x, ll m){
    if (m==0) return 0;
    if (m < 0) m *= -1;
    return (x%m+m) % m;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y) { 
 if (b==0) {x = 1; y = 0; return a;} 
 ll g = extended_euclid(b, a%b, x, y); 
 ll z = x - a/b*y; 
 x = y; y = z; return g;
}

ll modinv(ll a, ll m){
    ll x, y; ll g = extended_euclid(a, m, x, y);
    if (g == 1 || g == -1) return modd(x * g, m);
    return 0;
}

ll C(ll n, ll r){
    return ((((fact[n] * invf[n-r]) % mod) * invf[r]) % mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll W, B, K;
    cin >> W >> B >> K;

    if (W > B+K){
        cout << 0 << endl;
        return 0;
    }

    invf[0] = 1;
    fact[0] = 1;
    fact[1] = 1;
    for (ll i = 2; i < 2000001; i++){
        fact[i] = (fact[i-1] * i) % mod;
        // fact[i] %= mod;
    }

    // for (int i = 0 ;i < 5; i++) cout << fact[i] << " ";
    invf[2000000] = modinv(fact[2000000], mod);
    for (ll i = 2000000-1; i > 1; i--){
        invf[i] = (invf[i+1] * (i+1)) % mod;
    }

    ll full = C(W+B, B) - C(W+B, B+K+1);
    cout << full << endl;

    return 0;
}