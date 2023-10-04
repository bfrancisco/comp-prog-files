#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    int n, m;
    n = s.size(); m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int r = n, c = m;
    vector<char> out = {' '};
    while (r > 0 && c > 0){
        if (s[r-1] == t[c-1]){
            out.push_back(s[r-1]);
            r--; c--;
        }
        else if (dp[r-1][c] >= dp[r][c-1]) r--;
        else c--;
    }

    // for (int i = 0; i <= n; i++){
    //     for (int j = 0; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = out.size() - 1; i >= 0; i--)
        cout << out[i];
    
    return 0;
}