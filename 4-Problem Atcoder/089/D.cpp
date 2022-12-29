#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int LIM = 90010;

int f(int i, int j, int k, int l){
    return abs(i-k) + abs(j-l);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int h, w, d;
    cin >> h >> w >> d;
    int grid[305][305];
    pair<int, int> coor[LIM];
    for (int i = 0; i < h; i++)
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
            coor[grid[i][j]] = {i, j};
        }
    
    vector<int> prefix(h*w+1);
    // 2D prefix sum smashed to 1 row

    for (int una = 1; una <= d; una++){
        int fx, fy, cx, cy;
        fx = coor[una].first;
        fy = coor[una].second;
        prefix.push_back(0);
        int val = una + d;
        // cout << una << " ";
        while (val <= h*w){
            cx = coor[val].first;
            cy = coor[val].second;
            prefix[val] = prefix[val-d] + f(fx, fy, cx, cy);
            // cout << val << " ";
            fx = cx;
            fy = cy;
            val += d;
            
        }
        // cout << endl;
    }
    // for (int i = 1; i <= h*w; i++){
    //     cout << i <<": " << prefix[i] << endl;
    // }
    int q; cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a] << endl;
    }
    return 0;
}