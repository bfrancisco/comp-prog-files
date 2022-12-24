#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n, W;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> W;
    
    vector<ll> weight(n+1);
    vector<ll> value(n+1);
    for (int i = 1; i <= n; i++){
        cin >> weight[i] >> value[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(W+1, 0));

    for (int i = 1; i <= n; i++){
        for (int w = 1; w <= W; w++){
            if (weight[i] <= w)
                dp[i][w] = max(dp[i-1][w], value[i] + dp[i-1][w-weight[i]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    // print dp[][]
    for (int i = 0; i <= n; i++){
        for (int w = 0; w <= W; w++){
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }
    cout << dp[n][W];
    return 0;
}