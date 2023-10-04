#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int h, w;

bool valid(int x, int y){
    if (x >= 0 && x < h && y >= 0 && y < w) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; i++){
        cin >> grid[i];
    }

    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int ans[51][51];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            
            if (grid[i][j] == '.'){
                int val = 0;
                for (int k = 0; k < 8; k++){
                    if (valid(i+x[k], j+y[k]) && grid[i+x[k]][j+y[k]] == '#'){
                        val++;
                    }
                }
                ans[i][j] = val;
            }
            else ans[i][j] = -1;
        }
    }
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (ans[i][j] == -1) cout << '#';
            else cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}   