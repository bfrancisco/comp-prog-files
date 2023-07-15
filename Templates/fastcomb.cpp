#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MOD = 1000000007;
int N = 2000000;
ll fact[N+1];
ll invf[N+1];
invf[0] = 1;
fact[0] = 1;
fact[1] = 1;

void generatefact(){
    for (int i = 2; i <= N; i++){
        fact[i] = mod((fact[i-1] * i), MOD);
    }
    invf[N] = modinv(fact[N], MOD);
    for (ll i = N-1; i > 1; i--){
        invf[i] = mod((invf[i+1] * (i+1)), MOD);
    }

}

ll mod(ll x, ll m){
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
    if (g == 1 || g == -1) return mod(x * g, m);
    return 0;
}

ll C(ll n, ll r){
    return mod((mod((fact[n] * invf[n-r]), MOD) * invf[r]), MOD);
}