#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k; cin >> n >> k;
    ll ans = 0;
    for (ll i = k+1; i <= n; i++){
        ans += (i-k)*((ll)(n/i)) + (n%i >=k ? n%i-k + (k ? 1 : 0) : 0);
    }
    cout << ans << endl;

    return 0;
}