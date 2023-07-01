#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n), pa(n), ppa(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    pa[0] = a[0]; ppa[0] = a[0];
    for (int i = 1; i < n; i++) pa[i] = pa[i-1] + a[i];
    for (int i = 1; i < n; i++) ppa[i] = ppa[i-1] + pa[i];

    vector<ll> mx(n+1);
    mx[0] = max(0ll, pa[0]); mx[n] = 0;
    for (int i = 1; i < n; i++){
        mx[i] = max(mx[i-1], pa[i]);
    }

    ll ans = max(max(0ll, mx[0]), ppa[n-1]);
    for (int i = 1; i < n; i++){
        ans = max(ppa[i-1] + mx[i], ans);
    }
    cout << ans << endl;

    return 0;
}