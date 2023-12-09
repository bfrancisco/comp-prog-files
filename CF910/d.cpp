#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(ll x){
    return (x)*(x-1)/2;
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> db;
    db[1] = 0;
    db[2] = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[i] = x;
        if (db.find(x) == db.end())
            db[x] = 1;
        else
            db[x]++;
    }
    ll ans = 0;
    for (auto &[k, v] : db){
        ans += f(v);
    }
    for (auto x : a){
        if (x == 1){
            db[1]--;
            ans += max(db[2], 0);
        }
        else if (x == 2){
            db[2]--;
            ans += max(db[1], 0);
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