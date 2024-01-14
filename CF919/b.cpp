#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    
    vector<int> pref(n+1);
    for (int i = 1; i <= n; i++){
        pref[i] = a[i-1] + pref[i-1];
    }

    // for (auto e : a) cout << e << " "; cout << endl;
    // for (auto e : pref) cout << e << " "; cout << endl;

    int ans = -1000000000;
    for (int i = 0; i <= k; i++){
        int ind = max(0, n-i-x);
        int rem = pref[ind];
        rem -= (pref[n-i] - pref[ind]);
        ans = max(ans, rem);
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