#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// i, 2 left top, 2 left bottom
int dp[100005][2][2][2][2];
vector<vector<char>> board;
int n;

// a: top left, b: bottom left, top right, bottom right
// 1 if used, else 0
int rec(int i, int a, int b, int c, int d){
    if (i > n) return 0;
    if (dp[i][a][b][c][d] != -1) 
        return dp[i][a][b][c][d];
    
    int ans = 0, alice = 0;

    if (a+b+c+d == 0){
        int wins = 0;
        for (int r = 0; r < 2; r++){
            alice = 0;
            for (int c = i; c >= i-2; c--){
                alice += (board[r][c] == 'A');
            }
            if (alice >= 2) wins++;
        }
        ans = max(ans, rec(i+1, 1, 1, 1, 1) + wins);
    }

    else if (a && b+c+d == 0){
        alice = 0;
        for (int c = i-2; c <= i; c++)
            alice += (board[1][c] == 'A');
        ans = max(ans, rec(i+1, 0, 1, 0, 1) + (alice >= 2));
    }

    else if (b && a+c+d == 0){
        alice = 0;
        for (int c = i-2; c <= i; c++)
            alice += (board[0][c] == 'A');
        ans = max(ans, rec(i+1, 1, 0, 1, 0) + (alice >= 2));
    }

    else if (a+c == 2 && b+d == 0){
        alice = 0;
        for (int c = i-2; c <= i; c++)
            alice += (board[1][c] == 'A');
        ans = max(ans, rec(i+1, 1, 1, 0, 1) + (alice >= 2)); 
    }

    else if (a+c == 0 && b+d == 2){
        alice = 0;
        for (int c = i-2; c <= i; c++)
            alice += (board[0][c] == 'A');
        ans = max(ans, rec(i+1, 1, 1, 1, 0) + (alice >= 2));
    }

    else if (a+b == 2 && c+d == 0){
        // top right, 2 left
        alice = 0;
        alice += (board[0][i] == 'A');
        alice += (board[0][i-1] == 'A');
        alice += (board[1][i-1] == 'A');
        
        ans = max(ans, rec(i+1, 1, 1, 1, 0) + (alice >= 2));

        // bottom right, 2 left
        alice = 0;
        alice += (board[1][i] == 'A');
        alice += (board[0][i-1] == 'A');
        alice += (board[1][i-1] == 'A');

        ans = max(ans, rec(i+1, 1, 1, 0, 1) + (alice >= 2));
    }

    else if (d == 0 && a+b+c == 3){
        alice = 0;
        alice += (board[1][i-1] == 'A');
        alice += (board[0][i] == 'A');
        alice += (board[1][i] == 'A');

        ans = max(ans, rec(i+1, 1, 1, 1, 1) + (alice >= 2));
    }
    
    else if (c == 0 && a+b+d == 3){
        alice = 0;
        alice += (board[0][i-1] == 'A');
        alice += (board[0][i] == 'A');
        alice += (board[1][i] == 'A');

        ans = max(ans, rec(i+1, 1, 1, 1, 1) + (alice >= 2));
    }

    if (a+b == 2){
        ans = max(ans, rec(i+1, c, d, 0, 0));
    }


    dp[i][a][b][c][d] = ans;

    return ans;
}

void solve(){  
    cin >> n;
    board.assign(2, vector<char>(n+1, '-'));
    for (int z = 0; z < 2; z++){
        for (int i = 1; i <= n; i++){
            cin >> board[z][i];
        }
    }

    for (int i = 0; i <= n; i++){
        for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
        for (int c = 0; c < 2; c++)
        for (int d = 0; d < 2; d++)
            dp[i][a][b][c][d] = -1;
    }

    // for (auto r : board){
    //     for (auto e : r) cout << e << " "; cout << endl;
    // }

    cout << rec(2, 1, 1, 0, 0) << endl;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        solve();
    }

    return 0;
}