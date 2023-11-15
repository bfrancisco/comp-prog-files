#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN = 300;
int dp[2*MAXN - 2][MAXN][MAXN];
int grid[MAXN][MAXN];
int n;
int rec(int t, int r1, int r2) {
    int c1 = t - r1;
    int c2 = t - r2;

    if (r1 == n-1 && r2 == n-1 && c1 == n-1 && c2 == n-1){
        return grid[n-1][n-1];
    }
    if (dp[t][r1][r2] != -1){
        return dp[t][r1][r2];
    }
    int cellval = (r1 != r2 ? grid[r1][c1] + grid[r2][c2] : grid[r1][c1]);
    int ans = -1e9;
    // dd, dr, rd, rr
    if (r1+1 < n && r2+1 < n){
        ans = max(ans, rec(t+1, r1+1, r2+1));
    }
    if (r1+1 < n && c2+1 < n){
        ans = max(ans, rec(t+1, r1+1, r2));
    }
    if (c1+1 < n && r2+1 < n){
        ans = max(ans, rec(t+1, r1, r2+1));
    }
    if (c1+1 < n && c2+1 < n){
        ans = max(ans, rec(t+1, r1, r2));
    }

    dp[t][r1][r2] = ans + cellval;
    return dp[t][r1][r2];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    memset(dp, -1, sizeof(dp));

    cout << rec(0,0,0) << endl;

    return 0;
}