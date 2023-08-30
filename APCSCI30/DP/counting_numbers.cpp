// https://cses.fi/problemset/task/2181

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[20][10][2];
ll MOD = 1e9 + 7;
ll mod(ll x, ll m){
    if (m == 0) return 0;
    if (m < 0) m *= -1;
    return (x%m + m) % m;
}

ll rec(auto& s, int n, int prev, int free){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        dp[n][prev][free] = (s[s.size() - 1] != prev);
    }

    if (dp[n][prev][free] != -1) return dp[n][prev][free];

    dp[n][prev][free] = 0;
    int r = (free ? 9 : s[s.size() - n] - '0');
    for (int i = 0; i <= r; i++){
        dp[n][prev][free] += dp[n-1][s[s.size() - n] - '0'][(s[s.size() - n - '0' == i])];
        dp[n][prev][free] = mod(dp[n][prev][free], MOD);
    }

    return mod(dp[n][prev][free], MOD);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(dp, -1, sizeof dp);
    string n, m; cin >> n >> m;
    ll R = rec(m, m.size(), -1, 0);
    cout << R << endl;

    return 0;
}
