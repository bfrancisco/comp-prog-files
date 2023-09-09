#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1010;
int gridL[MAX][MAX];
int gridR[MAX][MAX];
int gridT[MAX][MAX];
int gridB[MAX][MAX];
int visited[MAX][MAX];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void processgrid(){
    int n; cin >> n;
    int pr, pc, cr, cc;
    cin >> pr >> pc;
    for (int z = 0; z < n; z++){
        cin >> cr >> cc;
        // process borders
        if (pc == cc){
            for (int i = min(pr, cr)+1; i <= max(pr, cr); i++){
                gridR[i][pc] = 1;
                gridL[i][pc+1] = 1;
            }
        }
        else if (pr == cr){
            for (int j = min(pc, cc)+1; j <= max(pc, cc); j++){
                gridB[pr][j] = 1;
                gridT[pr+1][j] = 1;
            }
        }
        pr = cr; pc = cc;
    }
}

bool valid(int r, int c){
    return (0 < r && r < MAX && 0 < c && c < MAX);
}

bool notColliding(int r, int c, int tor, int toc){
    // if upwards
    if (tor == 1){
        return (gridB[r][c] == 0);
    }
    else if (tor == -1){
        return (gridT[r][c] == 0);
    }
    else if (toc == 1){
        return (gridR[r][c] == 0);
    }
    else if (toc == -1){
        return (gridL[r][c] == 0);
    }
}

int bfs(int sr, int sc){
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = 1;
    while(!q.empty()){
        auto [r, c] = q.front(); q.pop();
        ans++;
        for (int k = 0; k < 4; k++){
            int nr, nc;
            nr = r + dr[k];
            nc = c + dc[k];
            if (valid(nr, nc) && notColliding(r, c, dr[k], dc[k]) && !visited[nr][nc]){
                visited[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    processgrid();

    bfs(1, 1); // trash
    int ans = 0;
    for(int i = 1; i < MAX; i++){
        for (int j = 1; j < MAX; j++){
            if (visited[i][j]) continue;
            ans = max(ans, bfs(i, j));
        }
    }
    cout << ans << endl;

    return 0;
}
