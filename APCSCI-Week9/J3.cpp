// slimes

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    vector<ll> value(N);
    for (int i = 0; i < N; i++)
        cin >> value[i];

    vector<vector<ll>> dp(N, vector<ll>(N, 1e13));
    vector<vector<ll>> val(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++){
        dp[i][i] = 0;       // weight of prev. operations
        val[i][i] = value[i];      // current value 
    }
    
    for (int c = 1; c < N; c++){
        for (int i = 0; i+c < N; i++){
            int j = i+c;
            // cout << i << " " << j << endl;
            for (int k = 0; i+k < j; k++){
                ll tmp1, tmp2;
                // cout << i << " " << i+k << "    " << i+k+1 << " " << j << " ";
                tmp2 = val[i][i+k] + val[i+k+1][j];
                tmp1 = dp[i][i+k] + dp[i+k+1][j] + tmp2;
                if (tmp1 < dp[i][j]){
                    dp[i][j] = tmp1;
                    val[i][j] = tmp2;
                    // cout << "check";
                }
                // cout << endl;
            }
            // cout << dp[i][j] << " " << dp[i][j] << " " << val[i][j] << "\n\n";
        }
    }

    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //         if (i > j) cout << -1 << " ";
    //         else cout << dp[i][j] << " "; 
    //     }
    //     cout << endl;
    // }
    cout << dp[0][N-1];
    return 0;
}