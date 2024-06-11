#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve(){
    ll r, c; cin >> r >> c;
    ll ans = 1 + max(r, c)*(max(r, c)-1);
    if (r < c){
        ans += abs(c-r)*(c%2 ? 1 : -1);
    }
    else{
        ans += abs(c-r)*(r%2 ? -1 : 1);
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