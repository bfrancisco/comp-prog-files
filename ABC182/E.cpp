#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w, n, m; cin >> h >> w >> n >> m;
    // 0 - none, 2 - bulb, -1 - block
    int bulb = 2, block = -1;
    vector<vector<int>> grid(h+1, vector<int>(w+1, 0));
    for (int i = 0; i < n; i++){
        int r, c; cin >> r >> c;
        grid[r][c] = bulb;
    }
    for (int i = 0; i < m; i++){
        int r, c; cin >> r >> c;
        grid[r][c] = block;
    }
    
    int illum;

    // sweep right
    for (int r = 1; r <= h; r++){
        illum = 0;
        for (int c = 1; c <= w; c++){
            if (grid[r][c] == bulb) illum = 1;
            else if (grid[r][c] == block) illum = 0;
            else if (illum) grid[r][c] = 1;
        }
    }
    // sweep left
    for (int r = 1; r <= h; r++){
        illum = 0;
        for (int c = w; c > 0; c--){
            if (grid[r][c] == bulb) illum = 1;
            else if (grid[r][c] == block) illum = 0;
            else if (illum) grid[r][c] = 1;
        }
    }
    // sweep down
    for (int c = 1; c <= w; c++){
        illum = 0;
        for (int r = 1; r <= h; r++){
            if (grid[r][c] == bulb) illum = 1;
            else if (grid[r][c] == block) illum = 0;
            else if (illum) grid[r][c] = 1;
        }
    }
    // sweep up
    for (int c = 1; c <= w; c++){
        illum = 0;
        for (int r = h; r > 0; r--){
            if (grid[r][c] == bulb) illum = 1;
            else if (grid[r][c] == block) illum = 0;
            else if (illum) grid[r][c] = 1;
        }
    }

    int ans = 0;
    for (int r = 1; r <= h; r++){
        for (int c = 1; c <= w; c++){
            if (grid[r][c] > 0)
                ans++;
        }
    }
            

    cout << ans << endl;

    return 0;
}