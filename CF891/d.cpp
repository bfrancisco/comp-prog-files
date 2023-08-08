#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    int n; cin >> n;
    vector<ll> a(n), b(n);

    for (int i = 0 ; i < n; i++) cin >> a[i];
    for (int i = 0 ; i < n; i++) cin >> b[i];

    ll mx = -1e18;

    for (int i = 0; i < n; i++){
        mx = max(mx, a[i] - b[i]);
    }

    vector<int> out;
    for (int i = 0 ; i < n; i++){
        if (a[i] - b[i] == mx){
            out.push_back(i+1);
        }
    }
    
    cout << out.size() << endl;
    for (auto x : out) cout << x << " ";
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