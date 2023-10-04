#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int h, w, k; cin >> h >> w >> k;
    vector<string> grid(h);
    for (int i = 0; i < h; i++){
        cin >> grid[i];
    }
    int ans = 0;
    for (int rbit = 0; rbit < (1 << h); rbit++){
        for (int lbit = 0; lbit < (1 << w); lbit++){
            vector<string> temp(h);
            for (int i = 0; i < h; i++) temp[i] = grid[i];

            for (int r = 0; r < h; r++){
                if (rbit & (1 << r)){
                    for (int i = 0; i < w; i++) temp[r][i] = '.';
                }
            }

            for (int c = 0; c < w; c++){
                if (lbit & (1 << c)){
                    for (int i = 0; i < h; i++) temp[i][c] = '.';
                }
            }
            int count = 0;
            for (auto row : temp){
                for (auto ch : row){
                    if (ch == '#') count++;
                }
            }

            if (count == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}