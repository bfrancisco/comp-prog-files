#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    ll N = pow(2, n);
    ll a[N];
    // first is lower, second is higher
    vector<pair<ll, ll>> twoHighest(N, make_pair(0, 0));
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;
    
    for (ll i = 0; i < N; i++){
        for (ll j = 0; j < n; j++){
            // if i is a subset of j
            if (i | j <= i){
                ll val = a[i];
                
                if (val > twoHighest[i].second) twoHighest[i].second = val;
                else if (val > twoHighest[i].first) twoHighest[i].first = val;
            }
        }
    }

    for (ll i = 0; i < N; i++){
        cout << twoHighest[i].first + twoHighest[i].second << endl;
    }

    return 0;
}