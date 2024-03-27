#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = '-' + s;
    t = '-' + t;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int i, j;
    for (i = 1; i <= n; i++){
        for (j = 1; j <= m; j++){
            dp[i][j] = max({dp[i-1][j], dp[i][j-1], + (s[i]==t[j] ? 1+dp[i-1][j-1] : 0)});
        }
    }

    i = n, j = m;
    vector<char> ans;

    while (i > 0 && j > 0){
        if (s[i] == t[j]){
            ans.push_back(s[i]);
            i--;
            j--;
        }
        else if (dp[i-1][j] >= dp[i][j-1]) i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    for (auto c : ans) cout << c; cout << endl;

    return 0;
}