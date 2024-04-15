#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int H, W; cin >> H >> W;
    vector<set<int>> grid(H);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            int x; cin >> x;
            grid[i].insert(x);
        }
    }

    int q; cin >> q;
    while(q--){
        int r, c; cin >> r >> c;
        r--;
        cout << (grid[r].find(c) == grid[r].end() ? "No" : "Yes") << endl;
    }


    return 0;
}