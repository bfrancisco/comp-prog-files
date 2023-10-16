#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll MXN = 100;
const ll MXV = 1000;
// ll dp[MXN+10][MXN*MXV+10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n; ll w; cin >> n >> w;
    vector<ll> W(n+1), V(n+1);
    for (int i = 1; i <= n; i++){
        cin >> W[i] >> V[i];
    }

    vector<vector<ll>> dp(110, vector<ll>(100010, (ll)1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (ll j = 0; j <= n*MXV; j++){
            if (j - V[i] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-V[i]] + W[i]);
        }
    }

    ll ans;
    for (ll val = n*MXV; val >= 0; val--){
        // cout << val << " " << dp[n][val] << endl;
        if (dp[n][val] <= w){
            ans = val;
            break;
        }
    }
    cout << ans << endl;
    
    
    return 0;
}