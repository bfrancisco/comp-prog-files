#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    map<ll, int> db;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        db[a[i]] = i;
    }

    cout << db.begin()->first << " " << db.rbegin()->first << endl;

    ll ans = n-1;
    int mn = db.begin()->first, mx = db.rbegin()->first;

    for (int i = 0; i < n; i++){
        if (a[i] == mn) break;
        db.erase(a[i]);
    }
    for (int i = n-1; i >= 0; i--){
        if (a[i] == )
    }

    return 0;
}