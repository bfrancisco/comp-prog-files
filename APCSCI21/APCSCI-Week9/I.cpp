#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int W, n, c0, d0;
    cin >> W >> n >> c0 >> d0;

    vector<int> weight, value;
    for (int i = 0; i < W/c0; i++){
        weight.push_back(c0);
        value.push_back(d0);
    }
    for (int i = 1; i <= n; i++){
        int r,t,y,u; cin>>r>>t>>y>>u;
        for (int j = 0; j < r/t; j++){
            weight.push_back(y);
            value.push_back(u);
        }
    }

    // for (auto x : weight) cout << x << " ";
    // cout << endl;
    // for (auto x : value) cout << x << " ";
    // cout << endl;
    int N = weight.size();
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    for (int i = 1; i <= N; i++){
        for (int w = 1; w <= W; w++){
            if (weight[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], value[i-1] + dp[i-1][w-weight[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    // print dp[][]
    // for (int i = 0; i <= N; i++){
    //     for (int w = 0; w <= W; w++){
    //         cout << dp[i][w] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][W];
    
    return 0;
}