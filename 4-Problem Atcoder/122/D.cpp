#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[101][4][4][4];
// 0 - A
// 1 - G
// 2 - C
// 3 - T
// AGC ACG GAC A*GC AG*C
// 012 021 102 0*12 01*2
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    ll MOD = 1000000007;
    

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++){
                if ((i == 0 && j == 1 && k == 2) ||
                    (i == 0 && j == 2 && k == 1) ||
                    (i == 1 && j == 0 && k == 2)
                    ) continue;

                dp[3][i][j][k] = 1;
            }
    
    // h = first char
    // i = second
    // j = third
    // k = fourth
    // idea: dp[n][ABC] -> dp[n][BC+D] || dp[n][BC+D] += dp[n][ABC]
    for (int n = 4; n <= N; n++)
        // permutation from AAAA -> TTTT
        for (int h = 0; h < 4; h++)
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    for (int k = 0; k < 4; k++){
                        if ((i == 0 && j == 1 && k == 2) ||
                            (i == 0 && j == 2 && k == 1) ||
                            (i == 1 && j == 0 && k == 2) ||
                            (h == 0 && j == 1 && k == 2) ||
                            (h == 0 && i == 1 && k == 2) 
                            ) continue;
                        
                        dp[n][i][j][k] += dp[n-1][h][i][j];
                        dp[n][i][j][k] = dp[n][i][j][k] % MOD;
                    }
    
    ll ans = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++){
                // cout << dp[N][i][j][k] << " " << i << " " << j << " " << k << endl;
                ans += dp[N][i][j][k];
                ans = ans % MOD;
            }
                
    cout << ans << endl;

    return 0;
}