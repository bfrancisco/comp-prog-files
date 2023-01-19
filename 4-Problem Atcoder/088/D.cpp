#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h, w;
vector<string> grid;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

bool valid(int a, int b){
    if (0 <= a && a < h && 0 <= b && b < w) return true;
    return false;
}

int bfs(int a, int b){
    queue<tuple<int, int, int>> q;
    q.push({a, b, 0});
    bool vis[h][w];
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
        vis[i][j] = false;
        
    vis[0][0] = true;
    while (!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int c = get<2>(q.front());
        q.pop();
        // cout << x << " " << y << endl;
        if (x==h-1 && y==w-1){
            return c;
        }

        for (int d = 0; d < 4; d++){
            if (valid(x + dirx[d], y + diry[d]) && !vis[x + dirx[d]][y + diry[d]] && grid[x + dirx[d]][y + diry[d]] == '.'){
                vis[x + dirx[d]][y + diry[d]] = true;
                q.push({x + dirx[d], y + diry[d], c+1});
            }
        }
    }
    return -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> h >> w;
    grid.resize(h);
    for (int i = 0; i < h; i++)
        cin >> grid[i];

    int least = bfs(0, 0);
    if (least == -1){cout << -1; return 0;}

    int white = 0, black = 0;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++){
        if (i+j==0) continue;
        if (grid[i][j] == '.') white++;
        else black++;
    }
    // cout << white << " " << least << endl;
    cout << white - least;
    return 0;
}