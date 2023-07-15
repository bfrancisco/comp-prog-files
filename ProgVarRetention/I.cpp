#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define N 10000010ll
ll pfc[N];
ll pref[N];
void sieve(){
    for (ll p = 2; p*p <= N; p++){
        if (pfc[p] == 0){
            pfc[p]++;
            for (ll i = p*p; i <= N; i+=p){
                pfc[i]++;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    sieve();
    for (ll x = 2; x <= 10; x++) cout << pfc[x] << " "; cout << endl;

    pref[1] = 0ll;
    for (ll i = 2; i < N; i++){
        pref[i] = pref[i-1] + (pfc[i]%2ll ? -1ll : 1ll);
    }


    ll q; cin >> q;
    while(q--){
        ll l, r; cin >> l >> r;
        cout << pref[r] - pref[l-1] << endl;
    }
    
    return 0;
}