#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w; cin >> h >> w;
    int grid[501][501];
    int bank = 0;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w; j++){
            cin >> grid[i][j];
            bank += grid[i][j];
        }
    }
    vector<vector<int>> ops;
    for (int i = 1; i <= h; i++){
        for (int j = 1; j <= w-1; j++){
            if (grid[i][j] % 2){
                grid[i][j+1]++;
                ops.push_back({i, j, i, j+1});
            }
        }
    }
    
    for (int i = 1; i <= h-1; i++){
        if (grid[i][w] % 2){
            grid[i+1][w]++;
            ops.push_back({i, w, i+1, w});
        }
    }


    cout << ops.size() << endl;
    for (auto v : ops){
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    }
    return 0;
}