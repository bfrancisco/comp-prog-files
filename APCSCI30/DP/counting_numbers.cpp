// https://cses.fi/problemset/task/2181

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll MOD = 1e9 + 7;
ll mod(ll x, ll m){
    if (m == 0) return 0;
    if (m < 0) m *= -1;
    return (x%m + m) % m;
}

ll dp[20][11][2][2];
ll rec(string& s, int n, int prev, int leadzeros, int bounded){
    if (n==0) return 1;
    if (dp[n][prev][leadzeros][bounded] != -1)
        return dp[n][prev][leadzeros][bounded];
    
    dp[n][prev][leadzeros][bounded] = 0;
    int bound = (bounded ? s[s.size() - n] - '0' : 9);

    for (int i = 0; i <= bound; i++){
        if (prev == i && !leadzeros) continue;
        dp[n][prev][leadzeros][bounded] += rec(s, n-1, i, (leadzeros && i == 0), (bounded && i == bound));
    }
    return dp[n][prev][leadzeros][bounded];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll a, b; cin >> a >> b;
    string l = to_string(a-1), r = to_string(b);
    memset(dp, -1, sizeof dp);
    ll R = rec(r, r.size(), 10, 1, 1); // 10 is placeholder
    memset(dp, -1, sizeof dp);
    ll L = rec(l, l.size(), 10, 1, 1);
    cout << R - L << endl;

    return 0;
}
