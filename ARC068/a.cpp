#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll x; cin >> x;
    ll ans = (ll)(x/11ll) * 2;
    x = x%11;
    if (x >= 6) { x-= 6; ans++; }
    if (x) ans++;
    cout << ans << endl;

    return 0;
}