#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k; cin >> n >> k;
    ll a[200010];
    ll ans = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a+n);
    reverse(a, a+n);
    for (int i = k; i < n; i++){
        ans += a[i];
    }
    
    cout << ans;
    return 0;
}   