#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; 
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<vector<int>> dp(n+1, vector<int>(3, 10000));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i){
        dp[i+1][0] = min({dp[i][0], dp[i][1], dp[i][2]}) + 1;
        if (a[i] == 1){
            dp[i+1][1] = min(dp[i][0], dp[i][2]);
        }
        else if (a[i] == 2){
            dp[i+1][2] = min(dp[i][0], dp[i][1]);
        }
        else if (a[i] == 3){
            dp[i+1][1] = min(dp[i][0], dp[i][2]);
            dp[i+1][2] = min(dp[i][0], dp[i][1]);
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]});
    
    return 0;
}