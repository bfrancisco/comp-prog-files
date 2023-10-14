#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MXN = 100;
const int MXV = 100;
ll dp[MXN+1][MXN*MXV+1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; ll w; cin >> n >> w;
    vector<ll> W(n), V(n);
    for (int i = 1; i <= n; i++){
        cin >> W[i] >> V[i];
    }

    for (int i = 0; i <= MXN; i++){
        for (int j = 0; j <= n*MXV; j++){
            dp[i][j] = 1e15;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n*MXV; j++){
            if (j - V[i] < 0)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-V[i]] + W[i]);
        }
    }

    int ans = 1e9;
    for (int val = n*MXV; val >= 0; val--){
        // cout << val << " " << dp[n][val] << endl;
        if (dp[n][val] <= w){
            ans = val;
            break;
        }
    }
    cout << ans << endl;
    
    
    return 0;
}