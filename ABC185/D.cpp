#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    ll a[200005];
    a[0] = 0;
    for (int i = 1; i <= m; i++){
        cin >> a[i];
    }
    ll mn = 1e11;
    sort(a+1, a+1+m);
    a[m+1] = n;

    for (int i = 0; i < m+1; i++){
        mn = min(a[i+1] - a[i], mn);
    }
    cout << mn << endl;
    ll ans = 0;
    for (int i = 0; i < m+1; i++){
        
        ll val = ((a[i+1] - a[i]) + mn - 1) / mn;
        cout << val << endl;
        ans += val;
    }

    cout << ans;
    return 0;
}   