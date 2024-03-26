#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> grid;

int f(int a, int b, int c, int d){
    int x = abs(a-c), y = abs(b-d);
    if (x > y) swap(x, y);
    return x + (y-x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H, W; cin >> H >> W;
    grid.resize(H);
    for (int i = 0; i < H; i++)
        grid[i].resize(W);

    map<int, vector<pair<int, int>>> db;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> grid[i][j];
            db[grid[i][j]].push_back({i, j});
        }
    }

    for (auto &[val, ps] : db){
        // cout << "val: " << val << endl;
        for (int i = 0; i < ps.size()-1; i++){
            for (int j = i+1; j < ps.size(); j++){
                int a = ps[i].first, b = ps[i].second, c = ps[j].first, d = ps[j].second;
                if (grid[a][b] != f(a,b,c,d)) continue;
                
                if (grid[0][0] == f(0,0,a,b) + f(0,0,c,d) &&
                    grid[0][W-1] == f(0,W-1,a,b) + f(0,W-1,c,d) &&
                    grid[H-1][0] == f(H-1,0,a,b) + f(H-1,0,c,d) &&
                    grid[H-1][W-1] == f(H-1,W-1,a,b) + f(H-1,W-1,c,d)){
                        cout << a+1 << " " << b+1 << "\n" << c+1 << " " << d+1 << endl;
                        return 0;
                }                 
            }
        }
    }



    return 0;
}