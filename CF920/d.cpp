#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll ans = 0;
    for (int i = 0; i < (int)(n/2); i++){
        ans += abs(a[i] - b[m-1-i]);
        ans += abs(a[n-i-1] - b[i]);
    }
    if (n%2){
        ans += max(abs(a[(int)(n/2)] - b[(int)(n/2)]), 
                    abs(a[(int)(n/2)] - b[m-1 - ((int)(n/2))]));
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}