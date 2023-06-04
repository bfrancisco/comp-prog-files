#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;
 
int grid[100][100];
int dp[100][100];
int n, m;
 
bool valid(int r, int c, int i, int j){
    if (r+i >= n || c+j >= m) return false;
    return true;
}
 
void rec(int r, int c, int val){
    if (val <= dp[r][c] && r!=0){
        return;
    }
    dp[r][c] = val;
    if (valid(r,c,1,2)){
        rec(r+1, c+2, dp[r][c] + grid[r+1][c+2]);
    }

    if (valid(r,c,2,1)){
        rec(r+2, c+1, dp[r][c] + grid[r+2][c+1]);
    }
    

}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        cin >> grid[i][j];
    }

    rec(0,0,0);
    cout << dp[n-1][m-1] << endl;
    return 0;
}