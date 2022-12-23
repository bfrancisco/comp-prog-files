#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
        dp[i][i] = a[i];

    for (int i = 1; i < n; i++){
        for (int j = 0; i+j < n; j++){
            dp[j][i+j] = max(a[j] - dp[j+1][i+j], a[i+j] - dp[j][i+j-1]);
            // cout << j << " " << i+j << endl;
        }
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[0][n-1];
    return 0;
}