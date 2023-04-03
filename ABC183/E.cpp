#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w;
    cin >> h >> w;
    int dp[2001][2001];
    int hor[2001][2001], ver[2001][2001], dia[2001][2001];
    int mod = 1000000007;
    string grid[2001];

    for (int i = 0; i < h; i++){
        cin >> grid[i];
    }
    
    dp[1][1] = 1;
    for (int r = 1; r <= h; r++){
        for (int c = 1; c <= w; c++){
            if ((r == 0 && c == 0) || (grid[r-1][c-1] == '#'))
                continue;
            hor[r][c] = (hor[r][c-1] + dp[r][c-1]) % mod;
            ver[r][c] = ver[r-1][c] + dp[r-1][c];
            dia[r][c] = dia[r-1][c-1] + dp[r-1][c-1];
            dp[r][c] = (hor[r][c] + ver[r][c] + dia[r][c]) % mod;
        }
    }
    cout << dp[h][w] % mod << endl;
    
    return 0;
}