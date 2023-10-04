#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll a[100010], l[100010], r[100010];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    l[0] = a[0];
    for (ll i = 1; i < n; i++){
        l[i] = gcd(a[i], l[i-1]);
    }

    r[n-1] = a[n-1];
    for (ll i = n-2; i >= 0; i--){
        r[i] = gcd(a[i], r[i+1]);
    }

    ll ans = -1;
    ans = max(ans, l[n-2]);
    ans = max(ans, r[1]);
    ans = max(ans, l[n-1]);

    for (ll i = 1; i < n-1; i++){
        ans = max(ans, gcd(l[i-1], r[i+1]));
    }

    cout << ans << endl;
    return 0;
}