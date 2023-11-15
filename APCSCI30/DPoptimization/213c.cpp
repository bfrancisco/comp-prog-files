#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int MAXN = 300;
int dp[2*MAXN][MAXN][MAXN];
int grid[MAXN][MAXN];
int d;
void rec(int t, int x1, int x2) {
    
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    rec(0,0,0);
    cout << dp[n-1][n-1][n-1] << endl;

    return 0;
}