#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int MOD = 1e9 + 7;
int f(int x){
    return x*(x+1)/2;
}

int dp[2][200001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int r, g;
    cin >> r >> g;
    if (r > g) swap(r, g);
    int h = 1;
    while (f(h) <= r+g) h++;
    h--;
    
    // dp[i][j] how many ways to place exactly j reds to pyramid of height i
    // vector<vector<ll>> dp(2, vector<ll>(r+1, 0));
    dp[0][0] = 1; // 1 way to place 0 reds to 0 cells

    // auto& pre = dp[0];
    // auto& cur = dp[1];

    for (int level = 1; level <= h; level++){
        for (int red = 0; red <= r; red++){
            // either place red or green at level h

            dp[level%2][red] = 0;
            // cur[red] = 0;
            int total = f(level);
            int green = total - red;
            // red
            if (red >= level && red <= total){
                dp[level%2][red] = (dp[level%2][red] + dp[(level-1)%2][red-level]) % MOD;
                // cur[red] = (cur[red] + pre[red-level]) % MOD;

            }
            // green
            if (green <= g && green >= 0){
                dp[level%2][red] = (dp[(level-1)%2][red] + dp[level%2][red]) % MOD;
                // cur[red] = (cur[red] + pre[red]) % MOD;
            }
        }
        // swap(pre,cur);
        // cout << "lvl " << level << " : "; for (int i = 0; i <= r; i++) cout << dp[level%2][i] << " "; cout << endl;
    }

    int ans = 0;
    for (int i = 0; i <= r; i++){
        ans = (ans + dp[h%2][i]) % MOD;
        // ans = (ans + pre[i]) % MOD;
    }
    cout << ans << endl;

    
    

    return 0;
}