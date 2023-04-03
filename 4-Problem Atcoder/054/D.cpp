#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[41][401][401];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, needA, needB, mx = 400;
    cin >> n >> needA >> needB;
    vector<int> A(n), B(n), C(n);
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i];

    // build combinations through dp. only dp[n] is valid
    for (int i = 0; i <= n; i++)
        for (int a = 0; a <= mx; a++)
            for (int b = 0; b <= mx; b++)
                dp[i][a][b] = 1e9;
    
    dp[0][0][0] = 0;
    
    for (int z = 0; z < n; z++){
        // cout << z << endl << endl;
        for (int i = 0; i <= mx; i++){
            for (int j = 0; j <= mx; j++){
                if (dp[z][i][j] == 1e9) continue;
                // dont include zth (1-index)
                dp[z+1][i][j] = min(dp[z][i][j], dp[z+1][i][j]);
                // include zth
                dp[z+1][i+A[z]][j+B[z]] = min(dp[z][i][j] + C[z], dp[z+1][i+A[z]][j+B[z]]);
                // cout << i << " " << j << " : " << dp[z][i][j] << endl;
            }
        }
    }

    int ans = 1e9;
    for (int a = 1; a <= mx; a++)
        for (int b = 1; b <= mx; b++)
            if (needA*b == needB*a){
                ans = min(ans, dp[n][a][b]);
                // cout << a << " " << b << " : " << dp[n][a][b] << endl;
            }
    
    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}