#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h, w;
ll dp[2001][2001];
ll sum[2001][2001][3];
ll mod = 1000000007;
string grid[2001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> h >> w;
    
    for (int i = 0; i < h; i++){
        cin >> grid[i];
    }
    
    dp[1][1] = 1;
    for (int r = 1; r <= h; r++){
        for (int c = 1; c <= w; c++){
            if ((r == 1 && c == 1) || (grid[r-1][c-1] == '#'))
                continue;
            sum[r][c][0] = sum[r][c-1][0] + dp[r][c-1];
            sum[r][c][1] = sum[r-1][c][1] + dp[r-1][c];
            sum[r][c][2] = sum[r-1][c-1][2] + dp[r-1][c-1];
            dp[r][c] = (sum[r][c][0] + sum[r][c][1] + sum[r][c][2]) % mod;
        }
    }
    cout << dp[h][w] << endl;
    
    return 0;
}