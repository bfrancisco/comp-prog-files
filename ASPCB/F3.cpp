#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;

int grid[100][100];
int dp[100][100];
int n, m;

bool valid(int r, int c, int i, int j){
    if (r-i < 0 || c-j < 0) return false;
    return true;
}

void bfs(int sr, int sc){
    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        int r = p.first, c = p.second;
        // cout << r << " " << c << endl;
        
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        cin >> grid[i][j];
    }

    bfs(0,0);
    cout << dp[n-1][m-1] << endl;
    return 0;
}