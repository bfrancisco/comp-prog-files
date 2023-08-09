#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(ll d){
    ll l = 0, r = 1e10;
    while(r-l > 1){
        ll mid = (l+r)/2ll;
        if (mid*mid <= d) l = mid;
        else r = mid;
    }
    return l;
}

void solve(){
    int n; cin >> n;
    vector<ll> a(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (freq.find(a[i]) == freq.end()) freq[a[i]] = 1;
        else freq[a[i]]++;
    }

    int q; cin >> q;
    while(q--){
        ll b, c; cin >> b >> c;
        ll D = b*b - 4ll*c;
        if (D < 0){ cout << 0 << " "; continue; }

        ll sqrtD = f(D);
        ll r1 = (b - sqrtD) / 2ll, r2 = (b + sqrtD) / 2ll;
        if (r1+r2 != b || r1*r2 != c || freq.find(r1) == freq.end() && freq.find(r2) == freq.end()){
            cout << 0 << " ";
        }
        else {
            if (r1 == r2) cout << freq[r1]*(freq[r1]-1ll)/2ll << " ";
            else cout << freq[r1]*freq[r2] << " ";
        }
    }
    cout << endl;
    
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