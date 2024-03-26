#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int R, C, H; cin >> R >> C >> H;     
    char z;
    int id;
    vector<pair<int, pair<int, vector<vector<int>>>>> grids;
    for (int k = 0; k < H; k++){
        cin >> id;
        int hashes = 0;
        vector<vector<int>> tmp(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                cin >> z; 
                if (z=='#'){
                    tmp[i][j] = 1;
                    hashes++;
                }
            }
        }
        grids.push_back({-hashes, {id, tmp}});

    }

    sort(grids.begin(), grids.end());
    int con = 1;
    for (int k = 0; k < H-1; k++){
        auto &grid1 = grids[k].second.second;
        auto &grid2 = grids[k+1].second.second;
        int same = (grids[k].first == grids[k+1].first);
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if (grid1[i][j] == 0 && grid2[i][j] == 1) {cout << "NO" << endl; return 0;}
            }
        }
        if (same) {con = 2;}
    }

    if (con == 2) cout << "MANY" << endl;
    else{
        cout << "UNIQUE" << endl;
        for (int i = 0; i < H; i++) cout << grids[i].second.first << " ";
        cout << endl;
    }




    return 0;
}