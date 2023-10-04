#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int dp[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, q; cin >> n >> m >> q;
    
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        dp[a][b]++;
    }

    // left -> right
    for (int r = 1; r <= n; r++){
        for (int c = 1; c <= n; c++){
            dp[r][c] += dp[r][c-1];
        }
    }

    // bottom -> up
    for (int c = 1; c <= n; c++){
        for (int r = n-1; r >= 1; r--){
            dp[r][c] += dp[r+1][c];
        }
    }

    // for (int r = 1; r <= n; r++){
    //     for (int c = 1; c <= n; c++){
    //         cout << dp[r][c] << " ";
    //     }
    //     cout << endl;
    // }

    while (q--){
        int l, r; cin >> l >> r;
        cout << dp[l][r] << endl;
    }

    
    

    return 0;
}