#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MOD = 998244353;

ll mod(ll x, ll m){
    if (m==0) return 0;
    if (m < 0) m *= -1;
    return (x%m+m) % m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, k; cin >> n >> k;
    vector<pair<int, int>> LR(k);
    for (int i = 0; i < k; i++){
        int l, r; cin >> l >> r;
        LR[i] = {l, r};
    }

    vector<ll> dp(n+1), prefix(n+1);
    dp[0] = 0;
    dp[1] = 1;
    prefix[0] = 0; prefix[1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 0; j < k; j++){
            int L = max(0, i - LR[j].second - 1);
            int R = max(0, i - LR[j].first);
            dp[i] = mod(dp[i] + (prefix[R] - prefix[L]), MOD);
        }
        prefix[i] = mod(dp[i] + prefix[i-1], MOD);
    }
    // for (int i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
    cout << dp[n] << endl;

    return 0;
}