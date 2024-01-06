#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<pair<ll, int>> ab(n);
    for (int i = 0; i < n; i++) ab[i] = {a[i] + b[i], i};
    sort(ab.begin(), ab.end(), greater<pair<ll, int>>());
    ll ans = 0;

    for (int i = 0; i < n; i++){
        if (i%2==0){
            ans += a[ab[i].second]-1;
        }
        else{
            ans -= b[ab[i].second]-1;

        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }
    
    return 0;
}