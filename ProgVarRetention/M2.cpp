#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<string> grid;
int n, m;
vector<vector<int>> dp;
vector<pair<int, int>> dxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool isValid(int x, int y){
    return (0 <= x && x < n && 0 <= y && y < m);
}

bool isBorder(int x, int y){
    return (x==n-1 || y==m-1 || x==0 || y==0);
}

bool inDanger(int x, int y, int ox, int oy){
    int danger = 0;
    for (auto &[dx, dy] : dxy){
        if (dx==ox && dy==oy) continue;
        int nx = x+dx;
        int ny = y+dy;
        if (dp[nx][ny] != 0 && dp[nx][ny] <= dp[x][y])
            danger++;
    }
    // if (danger == 3){
    //     cout << "danger:" << x << " " << y << endl;
    // }
    return (danger==3 ? true : false);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }

    if (min(n, m) <= 2) {cout << 1 << endl; return 0;}

    // vector<vector<int>> dp(n, vector<int>(m, 0));
    dp.resize(n);
    for (auto &v : dp) v.resize(m, 0);

    // borders
    for (int c = 0; c < m; c++){
        if (grid[0][c] == '-') continue;
        dp[0][c] = 1;
    }
    for (int r = 1; r < n-1; r++){
        for (int c = 0; c < m; c+=m-1){
            if (grid[r][c] == '-') continue;
            dp[r][c] = 1;
        }
    }
    for (int c = 0; c < m; c++){
        if (grid[n-1][c] == '-') continue;
        dp[n-1][c] = 1;
    }


    for (int r = 1; r < n-1; r++){
        for (int c = 1; c < m-1; c++){
            if (grid[r][c] == '-') continue;

            int placedVal = 0;
            for (auto &[dx, dy] : dxy){
                int nr = r + dx;
                int nc = c + dy;
                // check if any adj is indanger
                if (!isBorder(nr, nc) && inDanger(nr, nc, -dx, -dy)){
                    dp[r][c] = dp[nr][nc] + 1;
                    placedVal = 1;
                    break;
                }
            }
            if (!placedVal)
                dp[r][c] = 1;
        }
    }

   

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            ans = max(ans, dp[i][j]);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;


    return 0;
}