#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll f(ll x){
    return x*(x+1)/2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;

    ll ans = 0;
    // ans without edges
    for (int i = 1; i <= n; i++){
        ans += i*(n-i+1);
        // cout << f(i) << endl;
    }

    // more connection means lesser points,
    // subtract per connection
    for (int i = 0; i < n-1; i++){
        ll u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        // first u nodes affect ans by n-v+1 each
        ans -= u*(n-v+1);
    }

    cout << ans << endl;

    return 0;
}