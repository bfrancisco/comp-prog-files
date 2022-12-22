#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int n, k;
char grid[8][8];
int ans = 0;
vector<pair<int, int>> dir;

bool valid(int i, int j){
    if (0 <= i && i < n && 0 <= j && j < n){
        return true;
    }
    return false;
}

void dfs(int dist){
    if (dist == 0){
        ans += 1;
        return;
    }
    vector<pair<int, int>> toclear;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == '.'){
                bool haveAdj = false;
                for (auto &[dx, dy] : dir){
                    int x = i+dx;
                    int y = j+dy;
                    if (valid(x, y) && grid[x][y] == 'R')
                        haveAdj = true;
                }
                if (haveAdj){
                    grid[i][j] = 'R';
                    dfs(dist-1);
                    grid[i][j] = '#';
                    toclear.push_back({i, j});
                }
            }
        }
    }
    for (auto &[a, b] : toclear){
        grid[a][b] = '.';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    dir.push_back({0, -1});
    dir.push_back({0, 1});
    dir.push_back({1, 0});
    dir.push_back({-1, 0});

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == '.'){
                grid[i][j] = 'R';
                dfs(k-1);
                grid[i][j] = '#';
            }
        }
    }

    cout << ans;
    return 0;
}