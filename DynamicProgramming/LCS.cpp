#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-spring-2020/resources/lecture-16-dynamic-programming-part-2-lcs-lis-coins/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i = m-1; i >= 0; i--){
        for (int j = n-1; j >= 0; j--){
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    int r = 0, c = 0;
    string lcs = "";
    while (r < n && c < m){
        if (dp[r][c] == dp[r+1][c+1]+1) { r++; c++; lcs+=a[r]; }
        else if (dp[r][c+1] >= dp[r+1][c]) c++;
        else if (dp[r][c+1] < dp[r+1][c]) r++;
    }
    cout << lcs << endl;
    return 0;
}