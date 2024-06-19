#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MX = 1000000;
ll MOD = 1000000007;
ll fact[MX+1];
ll inv[MX+1];

ll mod(ll x, ll m) { // use this instead of x % m
  if (m == 0) return 0;
  if (m < 0) m *= -1;
  return (x%m + m) % m; // always nonnegative
}

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  if (b==0) {x = 1; y = 0; return a;}
  ll g = extended_euclid(b, a%b, x, y);
  ll z = x - a/b*y;
  x = y; y = z; return g;
}

ll modinv(ll a, ll m) {
  ll x, y; ll g = extended_euclid(a, m, x, y);
  if (g == 1 || g == -1) return mod(x * g, m);
  return 0; // 0 if invalid 
}

ll comb(ll N, ll K){
    return mod(mod(fact[N] * inv[N-K], MOD) * inv[K], MOD);
}

void precompute(){
    fact[0] = inv[0] = 1;
    fact[1] = inv[1] = 1;
    for (int i = 2; i <= MX; i++){
        fact[i] = i * fact[i-1];
        fact[i] = mod(fact[i], MOD);
        inv[i] = modinv(fact[i], MOD);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int R, C; cin >> R >> C;
    if (R > C){
        swap(R, C);
    }
    if ((R+C)%3 || R*2 < C){
        cout << 0 << endl;
        return 0;
    }

    ll N = (R+C)/3;
    ll K = 0;
    int a=N, b=N*2;
    while (a != R){
        a++; b--;
        K++;
    }

    precompute();

    // for (int i = 1; i <= 10; i++){
    //     cout << fact[i] << " ";
    //     cout << inv[i] << endl;
    // }
    cout << comb(N, K) << endl;
    
    return 0;
}