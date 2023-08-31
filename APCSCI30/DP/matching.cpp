// https://atcoder.jp/contests/dp/tasks/dp_o

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
ll dp[22][(1 << 21) + 10];
int mat[21][21];

ll solve(int i, int taken){
    if (i == n) return 1;
    if (dp[i][taken] != -1) return dp[i][taken];

    dp[i][taken] = 0;
    for (int j = 0; j < n; j++){
        // if match and is not yet taken
        if (mat[i][n-j-1] && !(taken & (1 << j))){
            dp[i][taken] += solve(i+1, taken ^ (1 << j));
            dp[i][taken] = mod(dp[i][taken], MOD);
        }
    }

    return dp[i][taken];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << endl;
    return 0;
}