#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    
    vector<ll> s; // stores index
    ll i = 0;
    ll ans = 0;
    while (i < n){
        if (s.empty() || a[s.back()] <= a[i]){
            s.push_back(i);
            i++;
        }
        else{
            ll j = s.back();
            s.pop_back();
            ans = max(ans, (!s.empty() ? (i - s.back() - 1) * a[j] : i * a[j]));
        }
    }

    while (!s.empty()){
        ll j = s.back();
        s.pop_back();
        ans = max(ans, (!s.empty() ? (n - s.back() - 1) * a[j] : n * a[j]));
    }

    cout << ans << endl;

    return 0;
}
