#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll n,f,A,b;
    cin >> n >> f >> A >> b;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll pas = 1;
    ll prev = 0;
    for (int i = 0; i < n; i++){
        ll off, on;
        off = b;
        on = (a[i] - prev) * A;
        f -= min(on, off);
        if (f <= 0) {pas = 0; break;}
        prev = a[i];
        // cout << f << endl;
    }
    cout << (pas ? "YES" : "NO") << endl;

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