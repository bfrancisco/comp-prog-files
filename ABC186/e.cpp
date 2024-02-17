#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll mod(ll x, ll m){
    return (x%m + m) % m;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y){
    if (b==0) {x=1; y=0; return a;}
    ll g = extended_euclid(b, a%b, x, y);
    ll z = x - a/b*y;
    x = y;
    y = z;
    return g;
}

ll modinv(ll a, ll m){
    ll x, y;
    ll g = extended_euclid(a, m, x, y);
    if (g==1 || g==-1) return mod(x*g, m);
    return 0;
}

void solve(){
    ll n, s, k;
    cin >> n >> s >> k;
    
    ll kngcd = __gcd(k, n);
    ll rhs = n-s;
    if (rhs % kngcd == 0){
        rhs /= kngcd;
        n /= kngcd;
        k /= kngcd;
    }
    else{
        cout << -1 << endl;
        return;
    }

    ll minv = modinv(k, n);
    if (minv == 0){
        cout << -2 << endl;
        return;
    }
    cout << mod((rhs)*minv, n) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) solve();

    return 0;
}