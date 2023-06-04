#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;
 
int grid[100][100];
int dp[100][100];
int n, m;
 
bool valid(int r, int c){
    if (r < 0 || c < 0 || ()) return false;
    return true;
}
 
int rec(int r, int c){
    if (!valid(r, c)) return -104206969;
    // cout << r << " " << c :
    if (dp[r][c] > -1) return dp[r][c];

    return grid[r][c] + max(rec(r-2, c-1), rec(r-1, c-2));

}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        cin >> grid[i][j];
        dp[i][j] = -1;
    }

    // rec(n-1,m-1);
    cout << rec(n-1,m-1) << endl;
    return 0;
}