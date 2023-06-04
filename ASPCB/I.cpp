#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
using namespace std;

vector<string> grid;
bool vis[100][100];
int n, m;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

pair<int, int> translate(int i, int j, int ii, int jj){
    i += ii;
    j += jj;
    if (i >= n) i = 0;
    else if (i < 0) i = n-1;

    if (j >= m) j = 0;
    else if (j < 0) j = m-1;

    return {i, j};
}

void bfs(int sr, int sc){
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;

    while (!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int r = p.first, c = p.second;
        // cout << r << " " << c << endl;
        for (int i = 0; i < 4; i++){
            pair<int,int> np = translate(r, c, dx[i], dy[i]);
            int nr = np.first, nc = np.second;

            if (vis[nr][nc] || grid[nr][nc] == '.') continue;

            vis[nr][nc] = true;
            q.push(np);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
    int ans = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == '#' && !vis[i][j]){
                bfs(i, j);
                // cout << i << " " << j << endl;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}