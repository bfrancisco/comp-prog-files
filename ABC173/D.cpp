#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());
    ll ans = a[0];

    for (int i = 2, ad = 0; i < n; i++){
        if (i%2==0) ad++;
        ans += a[ad];
    }
    cout << ans << endl;
    return 0;
}