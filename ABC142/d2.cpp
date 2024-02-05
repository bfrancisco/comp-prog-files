#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MX = 10000000;
int prime[MX+1];
void sieve(){
    memset(prime, 1, sizeof(prime));
    int ans = 1;
    for (int p = 2; p*p <= MX; p++){
        if (prime[p]){
            for (int i = p*p; i <= MX; i+=p){
                prime[i] = 0;
            }
        }
    }
}

set<ll> ans;

bool good(ll v){
    for (auto p : ans){
        if (p != 1){
            if (v % p == 0){
                return false;
            }
        } 
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sieve();    
    ll a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    ans.insert(1);
    for (ll p = 2; p*p < a; p++){
        if (!prime[p]) continue;

        if (a%p == 0 && b%p == 0){
            ans.insert(p);
            if (b % (a/p) == 0 && good(a/p)) ans.insert(a/p);
            if (a % (b/p) == 0 && good(b/p)) ans.insert(b/p);
            
        }
    }
    for (auto e : ans) cout << e << " "; cout << endl;
    cout << ans.size() << endl;
    
    return 0;
}