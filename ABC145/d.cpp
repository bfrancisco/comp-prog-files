#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> grid;
int R, C; 

int dr[2] = {1, 2};
int dc[2] = {2, 1};

bool valid(int r, int c){
    return (0 <= r && r < R && 0 <= c && c < C);
}

void bfs(){
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});

    while (!q.empty()){
        auto qe = q.front();
        int dep = qe.first;
        int r = qe.second.first;
        int c = qe.second.second;
        q.pop();

        for (int k = 0; k < 2; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (valid(nr,nc) && (grid[nr][nc] == 0 || nr+nc==0)){
                grid[nr][nc] = (valid(nr-2,nc-1) ? grid[nr-2][nc-1] : 0) + (valid(nr-1,nc-2) ? grid[nr-1][nc-2] : 0);
                q.push({dep, {nr, nc}});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    R++; C++;
    grid.resize(R);
    for (int i = 0; i < R; i++){
        grid[i].assign(C, 0);
    }

    grid[0][0] = 1;
    bfs();

    int cnt = 0;
    int ys = 0;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            // cout << grid[i][j] << " ";
            if (grid[i][j] != 0) cnt++;
            if ((i+1+j+1)%3==0 && grid[i][j] != 0) ys++;
        }
        // cout << endl;
    }

    cout << grid[R-1][C-1] << endl;
    cout << R*C << endl;
    cout << cnt << endl;
    cout << ys << endl;

    return 0;
}