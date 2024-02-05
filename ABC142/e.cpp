#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;
    vector<ll> dp(5001, (int)1e9);
    dp[0] = 0;

    for (int i = 0; i < m; i++){
        ll a, b; cin >> a >> b;
        ll bit = 0;
        for (int j = 0; j < b; j++){
            ll c; cin >> c;
            bit |= (1<<(c-1));
        }
        for (int k = 0; k < (1<<n); k++){
            dp[k|bit] = min(dp[k|bit], dp[k] + a);
        }
    }
    if (dp[(1<<n)-1] == (int)1e9) {cout << -1 << endl;}
    else cout << dp[(1<<n)-1] << endl;

    return 0;
}