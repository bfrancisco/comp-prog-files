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

    vector<vector<pair<ll, ll>>> dp(N, vector<pair<ll, ll>>(N, {1e13,1e13}));

    for (int i = 0; i < N; i++){
        dp[i][i].first = value[i];
        dp[i][i].second = 0;
    }
    
    for (int c = 1; c < N; c++){
        for (int i = 0; i+c < N; i++){
            int j = i+c;
            cout << i << " " << j << endl;
            for (int k = 0; i+k < j; k++){
                ll tmp1, tmp2;
                cout << i << " " << i+k << "    " << i+k+1 << " " << j << " ";
                tmp2 = dp[i][i+k].first + dp[i+k+1][j].first;
                tmp1 = tmp2 + (dp[i][i+k].second + dp[i+k+1][j].second);
                if (tmp1 < dp[i][j].first){
                    dp[i][j].first = tmp1;
                    dp[i][j].second = tmp2;
                    cout << "check";
                }
                cout << endl;
            }
            cout << dp[i][j].first << " " << dp[i][j].second << "\n\n";
        }
    }

    // for (int i = 0; i < N; i++){
    //     for (int j = 0; j < N; j++){
    //         if (i > j) cout << -1 << " ";
    //         else cout << dp[i][j].first << " "; 
    //     }
    //     cout << endl;
    // }
    cout << dp[0][N-1].first;
    return 0;
}