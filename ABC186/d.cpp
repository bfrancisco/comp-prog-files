#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++){
        pref[i] = pref[i-1] + a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n-1; i++){
        ans += a[i]*(n-i-1ll) - (pref[n-1] - pref[i]);
    }
    cout << ans << endl;

    return 0;
}