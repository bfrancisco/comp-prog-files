// https://codeforces.com/gym/101853/problem/E
// no dp yet
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
ll MOD = 1e9 + 7;
ll mod(ll x, ll m){
    if (m == 0) return 0;
    if (m < 0) m *= -1;
    return (x%m + m) % m;
}
 
int n;
int dp[17][1 << 17];
int rec(int i, int last_picks, int val, vector<vector<int>>& mat){
    // cout << i << " " << val << endl;
    if (i == n) return val;
    if (dp[i][last_picks] > 0) return dp[i][last_picks];

    // int mx = 0;
    for (int bit = 0; bit < (1 << n); bit++){
        bool good = 1;
        int toadd = 0;
        for (int j = 0; j < n; j++){
            if ( (((bit & (1 << j)) && (bit & (1 << (j+1)))) ) || 
                (bit & (1 << j) && last_picks & (1 << j)) ||
                (bit & (1 << j) && last_picks & (1 << (j+1))) ||
                (bit & (1 << j) && j != 0 && last_picks & (1 << (j-1)))){
                    good = 0;
                    break;
                }
            if (bit & (1 << j))
                toadd += mat[i][n-j-1];
        }
 
        if (good){
            dp[i][last_picks] = max(dp[i][last_picks], rec(i+1, bit, val + toadd, mat));
        }
    }
 
    return dp[i][last_picks];
}
 
int solve(){
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int ret = rec(0, 0, 0, mat);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 1<<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return ret;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    return 0;
}