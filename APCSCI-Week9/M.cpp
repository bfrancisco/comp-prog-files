#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int R, C, k; 
ll grid[3005][3005];
ll dp[3005][3005][4];
// 0 - dont choose value of grid[r][c]. copy highest value from up or left
// 1 - max value if we only chose 1 from rth row
// 2 - max value if we only chose 2 from rth row
// 3 - max value if we chose 3 from rth row
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> R >> C >> k;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            // grid[i][j] = 0;
            for (int l = 0; l < 4; l++)
                dp[i][j][l] = -1;
        }
    }

    for (int i = 0; i < k; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        grid[a-1][b-1] = c;
    }
    dp[0][0][0] = 0;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            // fix current i j
            for (int l = 2; l >= 0; l--){
                if (dp[i][j][l] >= 0){
                    dp[i][j][l+1] = max(dp[i][j][l+1], dp[i][j][l] + grid[i][j]);
                }
            }
            // fix right and bottom cell
            for (int l = 0; l < 4; l++){
                // adjust values on right cell
                dp[i][j+1][l] = max(dp[i][j+1][l], dp[i][j][l]);
                // adjust values on bottom cell, only on 0-index since it's a new row
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][l]);
            }
        }
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                for (int l = 0; l < 4; l++){
                    cout << dp[i][j][l] << " ";
                }
                cout << " |  ";
            }
            cout << endl; 
        }
    }

    // for (int i = 0; i < R; i++){
    //     for (int j = 0; j < C; j++){
    //         for (int l = 0; l < 4; l++){
    //             cout << dp[i][j][l] << " ";
    //         }
    //         cout << " |  ";
    //     }
    //     cout << endl; 
    // }

    cout << max({dp[R-1][C-1][0], dp[R-1][C-1][1], dp[R-1][C-1][2], dp[R-1][C-1][3]});

    return 0;
}