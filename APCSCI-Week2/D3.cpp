#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void solve(){
    ll n, N;
    cin >> n;
    N = pow(2, n);
    vector<ll> a(N, 0);
    for (ll i = 0; i < N; i++) cin >> a[i];

    vector<pair<ll, ll>> high2;
    for (ll i = 0; i < N; i++){
        pair<ll, ll> temp = {a[i], 0};
        high2.push_back(temp);
    }

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < N; j++){
            ll power = 1 << i;
            if ((j & power) == 0){
                ll comb = j | power;
                vector<ll> lst{high2[j].first, high2[j].second, high2[comb].first, high2[comb].second};
                sort(lst.begin(), lst.end());
                high2[comb].first = lst[3];
                high2[comb].second = lst[2];
            }
        }
    }

    ll prev = -1;
    for (ll k = 1; k < N; k++){
        ll val = high2[k].first + high2[k].second;
        if (val > prev) prev = val;
        cout << prev << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll t=1;
    //cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}